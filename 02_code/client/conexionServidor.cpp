// ConexionServidor.cpp    compilador: g++ 02_code/client/*.cpp 02_code/libs/*.cpp -I 02_code/libs -lws2_32 -o cliente
#include "ConexionServidor.h"
#include "XmlRpc.h"
#include <stdexcept>
#include <sstream>

using namespace XmlRpc;

ConexionServidor::ConexionServidor(const std::string& dir, int port) 
    : direccion(dir), puerto(port), conectado(false),
      modo_coordenadas(false), x(0), y(0), z(0),
      gripper(false), motores(false) {
}

ConexionServidor::~ConexionServidor() {
    if (conectado) {
        cerrarConexion();
    }
}

bool ConexionServidor::establecerConexion(const std::string& user, const std::string& pass, const std::string& userAlias) {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = user;
        args[1] = pass;
        args[2] = userAlias;
        
        if (cliente.execute("validar_usuario", args, result)) {
            if (bool(result)) {
                usuario = user;
                password = pass;
                alias = userAlias;
                
                args.clear();
                args[0] = true;  // conectar = true
                if (cliente.execute("connexion_robot", args, result)) {
                    conectado = true;
                    return true;
                }
            }
        }
    } catch (const std::exception& e) {
        conectado = false;
    }
    return false;
}

void ConexionServidor::cerrarConexion() {
    if (!conectado) return;
    
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = false;  // conectar = false
        
        if (cliente.execute("connexion_robot", args, result)) {
            conectado = false;
        }
    } catch (...) {
        // Aseguramos que el estado local se actualice incluso si hay error
        conectado = false;
    }
}

std::string ConexionServidor::enviarDatos(const std::string& comando, const std::string& parametros) {
    if (!conectado) {
        throw std::runtime_error("No hay conexion establecida con el servidor");
    }

    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        args[1] = comando;
        if (!parametros.empty()) {
            args[2] = parametros;
        }

        if (cliente.execute("enviarComando", args, result)) {
            return std::string(result);
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al enviar comando: " + std::string(e.what()));
    }
    return "";
}

bool ConexionServidor::activarDesactivarMotores() {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        
        if (cliente.execute("activar_desactivar_motores", args, result)) {
            std::string respuesta = std::string(result);
            motores = !motores;
            return true;
        }
    } catch (...) {}
    return false;
}

bool ConexionServidor::cambiarModoTrabajo(bool modo) {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        
        if (cliente.execute("modo_trabajo", args, result)) {
            return true;
        }
    } catch (...) {}
    return false;
}

bool ConexionServidor::cambiarModoCoordenadas() {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        
        if (cliente.execute("modo_coordenadas", args, result)) {
            modo_coordenadas = !modo_coordenadas;
            return true;
        }
    } catch (...) {}
    return false;
}

bool ConexionServidor::moverRobot(double newX, double newY, double newZ, double velocidad) {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        args[1] = newX;
        args[2] = newY;
        args[3] = newZ;
        
        std::string metodo = (velocidad == 100) ? "movimiento_lineal" : "movimiento_lineal_con_velocidad";
        if (velocidad != 100) {
            args[4] = velocidad;
        }
        
        if (cliente.execute(metodo.c_str(), args, result)) {
            x = newX;
            y = newY;
            z = newZ;
            return true;
        }
    } catch (...) {}
    return false;
}

bool ConexionServidor::activarDesactivarGripper() {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        
        if (cliente.execute("activar_desactivar_gripper", args, result)) {
            gripper = !gripper;
            return true;
        }
    } catch (...) {}
    return false;
}

bool ConexionServidor::realizarHoming() {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        
        if (cliente.execute("realizar_homing", args, result)) {
            x = y = z = 0;
            return true;
        }
    } catch (...) {}
    return false;
}

std::string ConexionServidor::obtenerEstadoRobot() {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        
        if (cliente.execute("reporte_informacion_general", args, result)) {
            return std::string(result);
        }
    } catch (...) {}
    return "Error al obtener estado del robot";
}

std::string ConexionServidor::obtenerLogActividades() {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = alias;
        
        if (cliente.execute("reporte_log", args, result)) {
            return std::string(result);
        }
    } catch (...) {}
    return "Error al obtener log de actividades";
}