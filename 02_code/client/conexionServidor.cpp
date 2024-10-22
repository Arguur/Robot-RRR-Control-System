// ConexionServidor.cpp
#include "ConexionServidor.h"
#include "../xml-rpc-lib/XmlRpc.h"
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

bool ConexionServidor::establecerConexion() {
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        // Verificar conexión con una llamada simple
        XmlRpcValue noArgs, result;
        if (cliente.execute("ping", noArgs, result)) {
            conectado = true;
            return true;
        }
    }
    catch (const std::exception& e) {
        // Manejar error de conexión
        conectado = false;
    }
    return false;
}

void ConexionServidor::cerrarConexion() {
    if (conectado) {
        // Realizar limpieza necesaria
        conectado = false;
    }
}

std::string ConexionServidor::enviarDatos(const std::string& datos) {
    if (!conectado) {
        throw std::runtime_error("No hay conexión establecida con el servidor");
    }
    
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue args, result;
        args[0] = datos;
        
        if (cliente.execute("enviarComando", args, result)) {
            return std::string(result);
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al enviar datos: " + std::string(e.what()));
    }
    return "";
}

std::string ConexionServidor::recibirDatos() {
    if (!conectado) {
        throw std::runtime_error("No hay conexión establecida con el servidor");
    }
    
    try {
        XmlRpcClient cliente(direccion.c_str(), puerto);
        XmlRpcValue noArgs, result;
        
        if (cliente.execute("recibirEstado", noArgs, result)) {
            return std::string(result);
        }
    }
    catch (const std::exception& e) {
        throw std::runtime_error("Error al recibir datos: " + std::string(e.what()));
    }
    return "";
}