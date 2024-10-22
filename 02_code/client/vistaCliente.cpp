// VistaCliente.cpp
#include "VistaCliente.h"
#include <iostream>
#include <limits>

void VistaCliente::mostrarMenu() const {
    std::cout << "\n=== Cliente Robot RRR ===\n";
    std::cout << "1. Conectar al servidor\n";
    std::cout << "2. Desconectar del servidor\n";
    std::cout << "3. Enviar comando\n";
    std::cout << "4. Ver estado del robot\n";
    std::cout << "5. Ver log de actividades\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
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