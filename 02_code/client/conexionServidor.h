#ifndef CONEXIONSERVIDOR_H
#define CONEXIONSERVIDOR_H

#include <string>

class ConexionServidor {
private:
    std::string direccion;
    int puerto;

public:
    ConexionServidor(const std::string& direccion, int puerto);
    bool establecerConexion();
    void cerrarConexion();
    std::string enviarDatos(const std::string& datos);
    std::string recibirDatos();
};

#endif // CONEXIONSERVIDOR_H
