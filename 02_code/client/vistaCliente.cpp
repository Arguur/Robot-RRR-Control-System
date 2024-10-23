// VistaCliente.cpp
#include "VistaCliente.h"
#include <iostream>
#include <limits>
#include <utility>

void VistaCliente::mostrarMenu() const {
    std::cout << "\n=== Cliente Robot RRR ===\n";
    std::cout << "1. Iniciar sesion\n";
    std::cout << "2. Desconectar sesion\n";
    std::cout << "3. Enviar comando\n";
    std::cout << "4. Ver estado del robot\n";
    std::cout << "5. Ver log de actividades\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opcion: ";
}

int VistaCliente::obtenerOpcion() const {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcion;
}

void VistaCliente::mostrarMensaje(const std::string& mensaje) const {
    std::cout << mensaje << std::endl;
}

void VistaCliente::mostrarError(const std::string& error) const {
    std::cerr << "ERROR: " << error << std::endl;
}

std::string VistaCliente::obtenerComando() const {
    std::string comando;
    std::cout << "Ingrese el comando: ";
    std::getline(std::cin, comando);
    return comando;
}

void VistaCliente::limpiarPantalla() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

std::pair<std::string, std::string> VistaCliente::obtenerCredenciales() const {
    std::string usuario, password;
    std::cout << "\n=== Inicio de Sesion ===\n";
    std::cout << "Usuario: ";
    std::getline(std::cin, usuario);
    std::cout << "Password: ";
    std::getline(std::cin, password);
    return std::make_pair(usuario, password);
}