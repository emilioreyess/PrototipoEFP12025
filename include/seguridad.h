#ifndef SEGURIDAD_H
#define SEGURIDAD_H

struct Bitacora {
    char nombreUsuario[20];
    char accion[50];
    int codigoAplicacion;
    char fechaHora[30];
};

void registrarBitacora(const char* nombreUsuario, const char* accion, int codigoAplicacion);
void mostrarBitacora();

#endif
