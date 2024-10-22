#include "controladorCliente.h"
#include <iostream>

ControladorCliente::ControladorCliente(const std::string& direccion, int puerto)
    : conexion(direccion, puerto), direccionServidor(direccion), puerto(puerto) {}

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
    conexion.enviarDatos(comando);
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
