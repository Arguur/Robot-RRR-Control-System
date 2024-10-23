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
    std::cout << "|  (1) Conexion / desconexion de Robot                  |\n";
    std::cout << "|  (2) Activacion / desactivacion de motores            |\n";
    std::cout << "|  (3) Seleccion de modo de trabajo                     |\n";
    std::cout << "|  (4) Control (en base a modo trabajo)                 |\n";
    std::cout << "|  (5) Reporte de informacion general                   |\n";
    std::cout << "|  (6) Reporte log de trabajo del servidor              |\n";
    std::cout << "|  (7) Salir                                            |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opcion: ";
}

void VistaCliente::mostrarMenuConexion() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|  1. Conexion / desconexion de Robot                   |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  (1) Conectar                                         |\n";
    std::cout << "|  (2) Desconectar                                      |\n";
    std::cout << "|  (3) Volver                                           |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opcion: ";
}

void VistaCliente::mostrarMenuMotores() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|  2. Activacion / desactivacion de motores             |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  (1) Activar/Desactivar motores                       |\n";
    std::cout << "|  (2) Volver                                           |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opcion: ";
}

void VistaCliente::mostrarMenuModoTrabajo() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|  3. Seleccion de modo de trabajo                      |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "|  (1) Cambiar modo de trabajo (Manual/Automático)      |\n";
    std::cout << "|  (2) Cambiar modo de coordenadas (Absoluto/Relativo)  |\n";
    std::cout << "|  (3) Volver                                           |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "Seleccione una opcion: ";
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
    std::cout << "Seleccione una opcion: ";
}

void VistaCliente::mostrarAyuda() const {
    limpiarPantalla();
    std::cout << "\n+-------------------------------------------------------+\n";
    std::cout << "|                     MENSAJE DE AYUDA                  |\n";
    std::cout << "+-------------------------------------------------------+\n";
    std::cout << "| 1. Conexion/Desconexion:                              |\n";
    std::cout << "|    - Establece o cierra la conexion con el robot      |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 2. Activacion de motores:                             |\n";
    std::cout << "|    - Activa o desactiva los motores del robot         |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 3. Modo de trabajo:                                   |\n";
    std::cout << "|    - Manual: Control directo del robot                |\n";
    std::cout << "|    - Automático: Ejecucion de secuencias programadas |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 4. Control:                                           |\n";
    std::cout << "|    - Permite controlar el robot segun el modo activo  |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 5. Informacion general:                               |\n";
    std::cout << "|    - Muestra el estado actual del robot               |\n";
    std::cout << "|                                                       |\n";
    std::cout << "| 6. Log de trabajo:                                    |\n";
    std::cout << "|    - Muestra el historial de operaciones              |\n";
    std::cout << "+-------------------------------------------------------+\n";
    esperarEnter();
}

void VistaCliente::mostrarEstadoConexion(bool conectado) const {
    std::cout << "\nEstado de conexion: " << (conectado ? "Conectado" : "Desconectado") << std::endl;
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

int VistaCliente::obtenerOpcion() const {
    int opcion;
    std::cin >> opcion;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return opcion;
}

std::tuple<std::string, std::string, std::string> VistaCliente::obtenerCredenciales() const {
    std::string usuario, password, alias;
    std::cout << "\n=== Inicio de Sesion ===\n";
    std::cout << "Usuario: ";
    std::getline(std::cin, usuario);
    std::cout << "Password: ";
    std::getline(std::cin, password);
    std::cout << "Alias: ";
    std::getline(std::cin, alias);
    return std::make_tuple(usuario, password, alias);
}

std::tuple<double, double, double, double> VistaCliente::obtenerParametrosMovimiento() const {
    double x, y, z, velocidad;
    std::cout << "Ingrese coordenada X: ";
    std::cin >> x;
    std::cout << "Ingrese coordenada Y: ";
    std::cin >> y;
    std::cout << "Ingrese coordenada Z: ";
    std::cin >> z;
    std::cout << "Ingrese velocidad (Enter para valor por defecto 100): ";
    std::string velStr;
    std::cin.ignore();
    std::getline(std::cin, velStr);
    velocidad = velStr.empty() ? 100.0 : std::stod(velStr);
    return std::make_tuple(x, y, z, velocidad);
}

void VistaCliente::mostrarMensaje(const std::string& mensaje) const {
    std::cout << mensaje << std::endl;
}

void VistaCliente::mostrarError(const std::string& error) const {
    std::cerr << "ERROR: " << error << std::endl;
}

void VistaCliente::limpiarPantalla() const {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void VistaCliente::esperarEnter() const {
    std::cout << "\nPresione Enter para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}