#include "conexionServidor.h"
#include "../libs/XmlRpc.h"
#include <iostream>

ConexionServidor::ConexionServidor(const std::string& direccion, int puerto)
    : direccion(direccion), puerto(puerto) {}

bool ConexionServidor::establecerConexion() {
    // Acá iría la lógica para establecer la conexión usando XmlRpcClient
    return true; // Retornar true si se conecta exitosamente
}

void ConexionServidor::cerrarConexion() {
    // Cerrar conexión
}

std::string ConexionServidor::enviarDatos(const std::string& datos) {
    // Lógica para enviar datos al servidor usando XmlRpcClient
    return "Datos enviados";
}

std::string ConexionServidor::recibirDatos() {
    // Lógica para recibir datos desde el servidor usando XmlRpcClient
    return "Datos recibidos";
}
