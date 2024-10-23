// ControladorCliente.cpp
#include "ControladorCliente.h"
#include <iostream>

ControladorCliente::ControladorCliente() 
    : direccionServidor("127.0.0.1"), puerto(8080), modo_trabajo(false) {
}

ControladorCliente::~ControladorCliente() {
    if (conexion && conexion->estaConectado()) {
        desconectar();
    }
}

bool ControladorCliente::conectar(const std::string& user, const std::string& pass, const std::string& alias) {
    try {
        conexion = std::make_unique<ConexionServidor>(direccionServidor, puerto);
        return conexion->establecerConexion(user, pass, alias);
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

bool ControladorCliente::activarDesactivarMotores() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    return conexion->activarDesactivarMotores();
}

bool ControladorCliente::cambiarModoTrabajo() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    if (conexion->cambiarModoTrabajo(!modo_trabajo)) {
        modo_trabajo = !modo_trabajo;
        return true;
    }
    return false;
}

bool ControladorCliente::cambiarModoCoordenadas() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    return conexion->cambiarModoCoordenadas();
}

bool ControladorCliente::moverRobot(double x, double y, double z, double velocidad) {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    return conexion->moverRobot(x, y, z, velocidad);
}

bool ControladorCliente::activarDesactivarGripper() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    return conexion->activarDesactivarGripper();
}

bool ControladorCliente::realizarHoming() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    return conexion->realizarHoming();
}

void ControladorCliente::mostrarEstadoRobot() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    std::cout << conexion->obtenerEstadoRobot() << std::endl;
}

void ControladorCliente::mostrarLogActividades() {
    if (!conexion || !conexion->estaConectado()) {
        throw std::runtime_error("No hay conexion activa con el servidor");
    }
    std::cout << conexion->obtenerLogActividades() << std::endl;
}

bool ControladorCliente::estaConectado() const {
    return conexion && conexion->estaConectado();
}

bool ControladorCliente::estanMotoresActivos() const {
    return conexion && conexion->getMotoresActivos();
}

bool ControladorCliente::esModoRelativo() const {
    return conexion && conexion->getModoRelativo();
}

bool ControladorCliente::estaGripperActivo() const {
    return conexion && conexion->getGripperActivo();
}

void ControladorCliente::obtenerPosicionActual(double& x, double& y, double& z) const {
    if (conexion) {
        conexion->getPosicionActual(x, y, z);
    } else {
        x = y = z = 0.0;
    }
}