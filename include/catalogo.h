#ifndef CATALOGO_H
#define CATALOGO_H

#include "usuario.h"

struct Catalogo {
    int id;
    char nombre[50];
    char descripcion[100];
    bool activo; //Para marcar si está eliminado o no
};

void altaCatalogo(const Usuario& usuario);
void bajaCatalogo(const Usuario& usuario);
void modificacionCatalogo(const Usuario& usuario);
void consultaCatalogo();

#endif
