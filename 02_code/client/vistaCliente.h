// VistaCliente.h
#ifndef VISTA_CLIENTE_H
#define VISTA_CLIENTE_H

#include <string>

class VistaCliente {
public:
    void mostrarMenu() const;
    int obtenerOpcion() const;
    void mostrarMensaje(const std::string& mensaje) const;
    void mostrarError(const std::string& error) const;
    std::string obtenerComando() const;
    void limpiarPantalla() const;
};

#endif // VISTA_CLIENTE_H