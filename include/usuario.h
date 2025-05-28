#ifndef USUARIO_H
#define USUARIO_H

struct Usuario {
    char carnet[10];
    char nombre[50];
    char usuario[20];
    char contrasena[20];
};

bool autenticarUsuario(Usuario &usuarioAutenticado);

#endif
