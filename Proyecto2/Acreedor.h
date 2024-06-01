#pragma once
#include <string>
#include "Database.h"

using namespace std;

class Acreedor {
public:
    string nombre;

    Acreedor(const string& nombre) : nombre(nombre) {}

    void guardar(Database& db);
    static void consultarTodos(Database& db);
};