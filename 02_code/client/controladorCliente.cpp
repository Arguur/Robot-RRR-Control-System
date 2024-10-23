// ControladorCliente.cpp
#include "ControladorCliente.h"
#include <iostream>

// Constructor con IP y puerto predefinidos
ControladorCliente::ControladorCliente() 
    : direccionServidor("127.0.0.1"), puerto(8080) { 
}

ControladorCliente::~ControladorCliente() {
    if (conexion && conexion->estaConectado()) {
        desconectar();
    }
}

bool ControladorCliente::conectar(const std::string& user, const std::string& pass) {
    try {
        std::cout << "\nIntentando conectar a " << direccionServidor << ":" << puerto << "..." << std::endl;
        
        conexion = std::make_unique<ConexionServidor>(direccionServidor, puerto);
        usuario = user;
        password = pass;
        
        bool resultado = conexion->establecerConexion(usuario, password);
        if (resultado) {
            std::cout << "Conexinn establecida exitosamente como usuario: " << usuario << std::endl;
        } else {
            std::cout << "No se pudo establecer la conexion. Verifique sus credenciales." << std::endl;
        }
        return resultado;
    }
    catch (const std::exception& e) {
        std::cerr << "Error al conectar: " << e.what() << std::endl;
        return false;
    }
}

void ControladorCliente::desconectar() {
    if (conexion) {
        conexion->cerrarConexion();
        std::cout << "Usuario " << usuario << " desconectado." << std::endl;
    }
}

std::string ControladorCliente::enviarComando(const std::string& comando) {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    return conexion->enviarDatos(comando);
}

std::string ControladorCliente::recibirRespuesta() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    return conexion->recibirDatos();
}

void ControladorCliente::mostrarEstadoRobot() {
    try {
        if (!conexion || !conexion->estaConectado()) {
            throw std::runtime_error("No hay conexion activa con el servidor");
        }
        std::string estado = enviarComando("getEstado");
        std::cout << "Estado actual del robot:\n" << estado << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error al obtener estado: " << e.what() << std::endl;
    }
}

void ControladorCliente::mostrarLogActividades() {
    try {
        if (!conexion || !conexion->estaConectado()) {
            throw std::runtime_error("No hay conexion activa con el servidor");
        }
        std::string log = enviarComando("getLog");
        std::cout << "Log de actividades:\n" << log << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error al obtener log: " << e.what() << std::endl;
    }
}