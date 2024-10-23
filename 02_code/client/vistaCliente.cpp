// VistaCliente.cpp
#include "VistaCliente.h"
#include <iostream>
#include <limits>
#include <iomanip>

void VistaCliente::mostrarMenu() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|  Panel de control Robot RRR (Cliente)                 |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  (0) Ayuda                                            |\n";
    std::cout << "|  (1) Conexión / desconexión de Robot                  |\n";
    std::cout << "|  (2) Activación / desactivación de motores            |\n";
    std::cout << "|  (3) Selección de modo de trabajo                     |\n";
    std::cout << "|  (4) Control (en base a modo trabajo)                 |\n";
    std::cout << "|  (5) Reporte de información general                   |\n";
    std::cout << "|  (6) Reporte log de trabajo del servidor              |\n";
    std::cout << "|  (7) Salir                                           |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opción: ";
}

void VistaCliente::mostrarMenuConexion() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|  1. Conexión / desconexión de Robot                   |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  (1) Conectar                                         |\n";
    std::cout << "|  (2) Desconectar                                      |\n";
    std::cout << "|  (3) Volver                                           |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opción: ";
}

void VistaCliente::mostrarMenuMotores() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|  2. Activación / desactivación de motores             |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  (1) Activar/Desactivar motores                       |\n";
    std::cout << "|  (2) Volver                                           |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opción: ";
}

void VistaCliente::mostrarMenuModoTrabajo() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|  3. Selección de modo de trabajo                      |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  (1) Cambiar modo de trabajo (Manual/Automático)      |\n";
    std::cout << "|  (2) Cambiar modo de coordenadas (Absoluto/Relativo) |\n";
    std::cout << "|  (3) Volver                                           |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opción: ";
}

void VistaCliente::mostrarMenuControl() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|  4. Control del Robot                                 |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  (1) Activar/Desactivar Gripper                       |\n";
    std::cout << "|  (2) Realizar Homing                                  |\n";
    std::cout << "|  (3) Mover Robot                                      |\n";
    std::cout << "|  (4) Volver                                           |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opción: ";
}

void VistaCliente::mostrarAyuda() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|                     MENSAJE DE AYUDA                  |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "| 1. Conexión/Desconexión:                              |\n";
    std::cout << "|    - Establece o cierra la conexión con el robot       |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 2. Activación de motores:                             |\n";
    std::cout << "|    - Activa o desactiva los motores del robot          |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 3. Modo de trabajo:                                   |\n";
    std::cout << "|    - Manual: Control directo del robot                |\n";
    std::cout << "|    - Automático: Ejecución de secuencias programadas  |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 4. Control:                                           |\n";
    std::cout << "|    - Permite controlar el robot según el modo activo  |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 5. Información general:                               |\n";
    std::cout << "|    - Muestra el estado actual del robot               |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 6. Log de trabajo:                                    |\n";
    std::cout << "|    - Muestra el historial de operaciones              |\n";
    std::cout << "+-------------------------------------------------------+\n";
    esperarEnter();
}


void VistaCliente::mostrarEstadoConexion(bool conectado) const {
    std::cout << "\nEstado de conexión: " << (conectado ? "Conectado" : "Desconectado") << std::endl;
}

void VistaCliente::mostrarEstadoRobot(bool conectado, bool motoresActivos, 
                                     bool modoRelativo, bool gripperActivo,
                                     double x, double y, double z) const {
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|               Estado actual del Robot                 |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  Conexión:         " << (conectado ? "Conectado" : "Desconectado") << "                |\n";
    std::cout << "|  Motores:          " << (motoresActivos ? "Activos" : "Inactivos") << "                  |\n";
    std::cout << "|  Modo coordenadas: " << (modoRelativo ? "Relativo" : "Absoluto") << "                  |\n";
    std::cout << "|  Gripper:          " << (gripperActivo ? "Activo" : "Inactivo") << "                   |\n";
    std::cout << "|                                                       |\n";
    std::cout << "|  Posición actual:                                      |\n";
    std::cout << "|     - X: " << x << "                                    |\n";
    std::cout << "|     - Y: " << y << "                                    |\n";
    std::cout << "|     - Z: " << z << "                                    |\n";
    std::cout << "+-------------------------------------------------------+\n";
}

}

int VistaCliente::obtenerOpcion() const {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcion;
}

std::tuple<std::string, std::string, std::string> VistaCliente::obtenerCredenciales() const {
    std::string usuario, password, alias;
    std::cout << "\n=== Inicio de Sesión ===\n";
    std::cout << "Usuario: ";
    std::getline(std::cin, usuario);