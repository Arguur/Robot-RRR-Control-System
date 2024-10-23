// VistaCliente.h
#ifndef VISTA_CLIENTE_H
#define VISTA_CLIENTE_H

#include <string>
#include <utility>  // Para std::pair

class VistaCliente {
public:
    void mostrarMenu() const;
    int obtenerOpcion() const;
    void mostrarMensaje(const std::string& mensaje) const;
    void mostrarError(const std::string& error) const;
    std::string obtenerComando() const;
    void limpiarPantalla() const;
    
    // Método para obtener credenciales
    std::pair<std::string, std::string> obtenerCredenciales() const;
};

#endif // VISTA_CLIENTE_H