#include "menu.h"
#include "seguridad.h"
#include "catalogo.h"
#include <iostream>

using namespace std;

void mostrarMenuGeneral(const Usuario& usuario) {
    int opcion;

    do {
        cout << "\n=== Men� General ===\n";
        cout << "Usuario: " << usuario.usuario
             << " | Carn�: " << usuario.carnet
             << " | Nombre: " << usuario.nombre << "\n\n";

        cout << "1. Cat�logos\n";
        cout << "2. Informes\n";
        cout << "3. Seguridad\n";
        cout << "4. Salir\n";
        cout << "Seleccione opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                menuCatalogos(usuario);
                break;
            case 2:
                menuInformes(usuario);
                break;
            case 3:
                menuSeguridad(usuario);
                break;
            case 4:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opci�n no v�lida. Intente de nuevo.\n";
        }
    } while (opcion != 4);
}

void menuCatalogos(const Usuario& usuario) {
    int opcion;
    do {
        cout << "\n-- Submen� Cat�logos --\n";
        cout << "1. Alta\n2. Baja\n3. Modificaci�n\n4. Consulta\n5. Regresar\n";
        cout << "Seleccione opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                altaCatalogo(usuario);
                break;
            case 2:
                bajaCatalogo(usuario);
                break;
            case 3:
                modificacionCatalogo(usuario);
                break;
            case 4:
                consultaCatalogo();
                break;
            case 5:
                cout << "Regresando al men� general...\n";
                break;
            default:
                cout << "Opci�n no v�lida.\n";
        }
    } while (opcion != 5);
}

void menuInformes(const Usuario& usuario) {
    int opcion;
    do {
        cout << "\n-- Submen� Informes --\n";
        cout << "1. Generar informe (pendiente)\n2. Regresar\n";
        cout << "Seleccione opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "[Funci�n de informe no implementada a�n]\n";
                // registrarBitacora(usuario.usuario, "Generar informe", 3001);
                break;
            case 2:
                cout << "Regresando al men� general...\n";
                break;
            default:
                cout << "Opci�n no v�lida.\n";
        }
    } while (opcion != 2);
}

void menuSeguridad(const Usuario& usuario) {
    int opcion;
    do {
        cout << "\n-- Submen� Seguridad --\n";
        cout << "1. Consultar bit�cora\n2. Regresar\n";
        cout << "Seleccione opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                mostrarBitacora();
                break;
            case 2:
                cout << "Regresando al men� general...\n";
                break;
            default:
                cout << "Opci�n no v�lida.\n";
        }
    } while (opcion != 2);
}
