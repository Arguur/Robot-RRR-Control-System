// ConexionServidor.cpp
#include "ConexionServidor.h"
#include "XmlRpc.h"
#include <stdexcept>

using namespace XmlRpc;

ConexionServidor::ConexionServidor(const std::string& dir, int port) 
    : direccion(dir), puerto(port), conectado(false) {
}

ConexionServidor::~ConexionServidor() {
    if (conectado) {
        cerrarConexion();
    }
}

bool ConexionServidor::establecerConexion(const std::string& user, const std::string& pass) {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        
        // Preparar los argumentos de autenticación
        args[0] = user;
        args[1] = pass;
        
        // Intentar autenticar con el servidor
        if (cliente.execute("autenticar", args, result)) {
            if (bool(result)) {  // Si la autenticación fue exitosa
                usuario = user;
                password = pass;
                
                // Ahora intentamos establecer la conexión con el robot
                XmlRpcValue robotArgs;
                robotArgs[0] = user;  // Incluimos el usuario autenticado
                if (cliente.execute("connexion_robot", robotArgs, result)) {
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
    if (conectado) {
        try {
            XmlRpcClient cliente(direccion.c_str(), puerto);
            XmlRpcValue args, result;
            args[0] = usuario;  // Incluimos el usuario en la desconexión
            cliente.execute("desconectar", args, result);
        } catch (...) {
            // Ignoramos errores en la desconexión
        }
        conectado = false;
    }
}

std::string ConexionServidor::enviarDatos(const std::string& datos) {
    if (!conectado) {
        throw std::runtime_error("No hay conexinn establecida con el servidor");
    }

    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = usuario;  // Incluimos el usuario autenticado
        args[1] = datos;    // El comando/datos a enviar

        if (cliente.execute("enviarComando", args, result)) {
            return std::string(result);
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al enviar datos: " + std::string(e.what()));
    }
    return "";
}

std::string ConexionServidor::recibirDatos() {
    if (!conectado) {
        throw std::runtime_error("No hay conexion establecida con el servidor");
    }

    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = usuario;  // Incluimos el usuario autenticado

        if (cliente.execute("recibirEstado", args, result)) {
            return std::string(result);
        }
    } catch (const std::exception& e) {
        throw std::runtime_error("Error al recibir datos: " + std::string(e.what()));
    }
    return "";
}