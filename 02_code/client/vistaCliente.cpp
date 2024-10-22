#include "vistaCliente.h"
#include <iostream>

void VistaCliente::mostrarMenu() {
    std::cout << "1. Conectar\n";
    std::cout << "2. Desconectar\n";
    std::cout << "3. Mostrar estado del robot\n";
    std::cout << "4. Mostrar log de actividades\n";
    std::cout << "5. Salir\n";
}

void VistaCliente::mostrarEstadoRobot(const std::string& estado) {
    std::cout << "Estado del robot: " << estado << std::endl;
}

void VistaCliente::mostrarLogActividades(const std::string& log) {
    std::cout << "Log de actividades: " << log << std::endl;
}
