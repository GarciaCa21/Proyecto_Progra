#pragma once
#include <string>
#include "Database.h"

using namespace std;

class Personal {
public:
    string nombre;
    string puesto;

    Personal(const string& nombre, const string& puesto) : nombre(nombre), puesto(puesto) {}

    void guardar(Database& db);
    static void consultarTodos(Database& db);
};