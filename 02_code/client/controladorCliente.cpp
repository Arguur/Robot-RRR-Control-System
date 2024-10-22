// ControladorCliente.cpp
#include "ControladorCliente.h"
#include <iostream>

ControladorCliente::ControladorCliente() 
    : direccionServidor("localhost"), puerto(8080) {
}

ControladorCliente::~ControladorCliente() {
    if (conexion && conexion->estaConectado()) {
        desconectar();
    }
}

bool ControladorCliente::conectar() {
    try {
        conexion = std::make_unique<ConexionServidor>(direccionServidor, puerto);
        return conexion->establecerConexion();
    }
    catch (const std::exception& e) {
        std::cerr << "Error al conectar: " << e.what() << std::endl;
        return false;
    }
}

void ControladorCliente::desconectar() {
    if (conexion) {
        conexion->cerrarConexion();
    }
}

std::string ControladorCliente::enviarComando(const std::string& comando) {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexión activa con el servidor");
    }
    return conexion->enviarDatos(comando);
}

std::string ControladorCliente::recibirRespuesta() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexión activa con el servidor");
    }
    return conexion->recibirDatos();
}

void ControladorCliente::mostrarEstadoRobot() {
    try {
        std::string estado = enviarComando("getEstado");
        std::cout << "Estado actual del robot:\n" << estado << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error al obtener estado: " << e.what() << std::endl;
    }
}

void ControladorCliente::mostrarLogActividades() {
    try {
        std::string log = enviarComando("getLog");
        std::cout << "Log de actividades:\n" << log << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Error al obtener log: " << e.what() << std::endl;
    }
}