#pragma once
#include <string>
#include "Database.h"

using namespace std;

class FormaPago {
public:
    string tipo;

    FormaPago(const string& tipo) : tipo(tipo) {}

    void guardar(Database& db);
    static void consultarTodos(Database& db);
};