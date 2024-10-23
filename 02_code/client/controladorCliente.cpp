#include "controladorCliente.h"
#include <iostream>

ControladorCliente::ControladorCliente(const std::string& direccion, int puerto, const std::string& usuario, const std::string& password)
    : conexion(direccion, puerto), direccionServidor(direccion), puerto(puerto), alias(usuario) {
    // Guardamos el alias del usuario tras autenticación exitosa
}

bool ControladorCliente::autenticar() {
    std::string credenciales = alias + ":" + "password";  // Ejemplo simple, deberías enviar también la contraseña
    conexion.enviarDatos("AUTENTICAR " + credenciales);
    std::string respuesta = conexion.recibirDatos();
    return respuesta == "OK";
}

void ControladorCliente::conectar() {
    if (conexion.establecerConexion()) {
        std::cout << "Conectado al servidor.\n";
    } else {
        std::cout << "Error al conectar con el servidor.\n";
    }
}

void ControladorCliente::desconectar() {
    conexion.cerrarConexion();
    std::cout << "Desconectado del servidor.\n";
}

void ControladorCliente::enviarComando(const std::string& comando) {
    std::string comando_con_alias = alias + ":" + comando;  // Adjuntar alias al comando
    conexion.enviarDatos(comando_con_alias);
}

std::string ControladorCliente::recibirRespuesta() {
    return conexion.recibirDatos();
}

void ControladorCliente::mostrarEstadoRobot() {
    std::string estado = recibirRespuesta();
    vista.mostrarEstadoRobot(estado);
}

void ControladorCliente::mostrarLogActividades() {
    std::string log = recibirRespuesta();
    vista.mostrarLogActividades(log);
}

void ControladorCliente::mostrarMenu() {
    vista.mostrarMenu();
}
