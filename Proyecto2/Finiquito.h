#pragma once
#include <string>
#include "Database.h"

using namespace std;

class Finiquito {
public:
    int deudor_id;
    double monto;
    string fecha;

    Finiquito(int deudor_id, double monto, const string& fecha) : deudor_id(deudor_id), monto(monto), fecha(fecha) {}

    void guardar(Database& db);
    static void consultarTodos(Database& db);
};