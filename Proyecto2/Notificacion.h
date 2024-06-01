#pragma once
#include <string>
#include "Database.h"

using namespace std;

class Notificacion {
public:
    int deudor_id;
    string mensaje;
    string fecha;

    Notificacion(int deudor_id, const std::string& mensaje, const string& fecha) : deudor_id(deudor_id), mensaje(mensaje), fecha(fecha) {}

    void guardar(Database& db);
    static void consultarTodos(Database& db);
};