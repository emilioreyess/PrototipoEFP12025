#include <iostream>
#include "usuario.h"
#include "menu.h"

using namespace std;

int main() {
    Usuario usuarioActual;

    cout << "=== Bienvenido a la Corporación ===\n";

    if (autenticarUsuario(usuarioActual)) {
        cout << "Bienvenido, " << usuarioActual.nombre << "!\n";
        mostrarMenuGeneral(usuarioActual);
    }

    return 0;
}
