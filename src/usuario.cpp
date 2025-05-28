#include "usuario.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool autenticarUsuario(Usuario &usuarioAutenticado) {
    char usuarioInput[20], contrasenaInput[20];

    cout << "Ingrese usuario: ";
    cin >> usuarioInput;
    cout << "Ingrese contraseña: ";
    cin >> contrasenaInput;

    ifstream archivo("datos/usuarios.dat", ios::binary);
    if (!archivo) {
        cout << "Error: No se pudo abrir el archivo de usuarios.\n";
        return false;
    }

    Usuario temp;
    while (archivo.read(reinterpret_cast<char*>(&temp), sizeof(Usuario))) {
        if (strcmp(temp.usuario, usuarioInput) == 0 &&
            strcmp(temp.contrasena, contrasenaInput) == 0) {
            usuarioAutenticado = temp;
            archivo.close();
            return true;
        }
    }

    archivo.close();
    cout << "Usuario o contraseña incorrectos.\n";
    return false;
}
