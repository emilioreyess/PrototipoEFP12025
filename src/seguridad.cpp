#include "seguridad.h"
#include <fstream>
#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

void obtenerFechaHoraActual(char* buffer, size_t size) {
    time_t ahora = time(nullptr);
    tm* tiempo = localtime(&ahora);
    strftime(buffer, size, "%Y-%m-%d %H:%M:%S", tiempo);
}

void registrarBitacora(const char* nombreUsuario, const char* accion, int codigoAplicacion) {
    ofstream archivo("datos/bitacora.dat", ios::binary | ios::app);
    if (!archivo) {
        cout << "Error al abrir bitácora para escribir.\n";
        return;
    }

    Bitacora registro;
    strncpy(registro.nombreUsuario, nombreUsuario, sizeof(registro.nombreUsuario));
    strncpy(registro.accion, accion, sizeof(registro.accion));
    registro.codigoAplicacion = codigoAplicacion;
    obtenerFechaHoraActual(registro.fechaHora, sizeof(registro.fechaHora));

    archivo.write(reinterpret_cast<char*>(&registro), sizeof(Bitacora));
    archivo.close();
}

void mostrarBitacora() {
    ifstream archivo("datos/bitacora.dat", ios::binary);
    if (!archivo) {
        cout << "No existe archivo de bitácora o no se puede abrir.\n";
        return;
    }

    Bitacora registro;
    cout << "\n--- Bitácora de Seguridad ---\n";
    while (archivo.read(reinterpret_cast<char*>(&registro), sizeof(Bitacora))) {
        cout << "Usuario: " << registro.nombreUsuario
             << " | Acción: " << registro.accion
             << " | Código: " << registro.codigoAplicacion
             << " | Fecha y Hora: " << registro.fechaHora << "\n";
    }
    archivo.close();
}
