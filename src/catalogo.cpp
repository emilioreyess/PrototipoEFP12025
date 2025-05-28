#include "catalogo.h"
#include "seguridad.h"
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

const char* archivoCatalogo = "datos/catalogos.dat";

void altaCatalogo(const Usuario& usuario) {
    Catalogo item;

    cout << "Alta de catálogo\n";
    cout << "Ingrese ID (entero): ";
    cin >> item.id;

    cout << "Ingrese nombre: ";
    cin.ignore();
    cin.getline(item.nombre, 50);

    cout << "Ingrese descripción: ";
    cin.getline(item.descripcion, 100);

    item.activo = true;

    ofstream archivo(archivoCatalogo, ios::binary | ios::app);
    if (!archivo) {
        cout << "No se pudo abrir el archivo para guardar.\n";
        return;
    }

    archivo.write(reinterpret_cast<char*>(&item), sizeof(Catalogo));
    archivo.close();

    registrarBitacora(usuario.usuario, "Alta catálogo", 2001);
    cout << "Catálogo agregado correctamente.\n";
}

void bajaCatalogo(const Usuario& usuario) {
    int id;
    cout << "Baja de catálogo\n";
    cout << "Ingrese ID a eliminar: ";
    cin >> id;

    fstream archivo(archivoCatalogo, ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    Catalogo item;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&item), sizeof(Catalogo))) {
        if (item.id == id && item.activo) {
            encontrado = true;
            item.activo = false;
            archivo.seekp(-static_cast<int>(sizeof(Catalogo)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&item), sizeof(Catalogo));
            cout << "Catálogo eliminado correctamente.\n";
            registrarBitacora(usuario.usuario, "Baja catálogo", 2002);
            break;
        }
    }
    if (!encontrado) cout << "ID no encontrado o ya eliminado.\n";

    archivo.close();
}

void modificacionCatalogo(const Usuario& usuario) {
    int id;
    cout << "Modificación de catálogo\n";
    cout << "Ingrese ID a modificar: ";
    cin >> id;

    fstream archivo(archivoCatalogo, ios::binary | ios::in | ios::out);
    if (!archivo) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    Catalogo item;
    bool encontrado = false;

    while (archivo.read(reinterpret_cast<char*>(&item), sizeof(Catalogo))) {
        if (item.id == id && item.activo) {
            encontrado = true;

            cout << "Nombre actual: " << item.nombre << "\nIngrese nuevo nombre: ";
            cin.ignore();
            cin.getline(item.nombre, 50);

            cout << "Descripción actual: " << item.descripcion << "\nIngrese nueva descripción: ";
            cin.getline(item.descripcion, 100);

            archivo.seekp(-static_cast<int>(sizeof(Catalogo)), ios::cur);
            archivo.write(reinterpret_cast<char*>(&item), sizeof(Catalogo));
            cout << "Catálogo modificado correctamente.\n";
            registrarBitacora(usuario.usuario, "Modificación catálogo", 2003);
            break;
        }
    }
    if (!encontrado) cout << "ID no encontrado o está eliminado.\n";

    archivo.close();
}

void consultaCatalogo() {
    ifstream archivo(archivoCatalogo, ios::binary);
    if (!archivo) {
        cout << "No se pudo abrir el archivo.\n";
        return;
    }

    Catalogo item;
    cout << "\n--- Consulta Catálogos Activos ---\n";
    bool encontrado = false;
    while (archivo.read(reinterpret_cast<char*>(&item), sizeof(Catalogo))) {
        if (item.activo) {
            cout << "ID: " << item.id << " | Nombre: " << item.nombre << " | Descripción: " << item.descripcion << "\n";
            encontrado = true;
        }
    }

    if (!encontrado) cout << "No hay catálogos activos.\n";

    archivo.close();
}
