#ifndef VISTACLIENTE_H
#define VISTACLIENTE_H

#include <string>

class VistaCliente {
public:
    void mostrarMenu();
    void mostrarEstadoRobot(const std::string& estado);
    void mostrarLogActividades(const std::string& log);
};

#endif // VISTACLIENTE_H
