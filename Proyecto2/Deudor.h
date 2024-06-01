#pragma once
#include <string>
#include "Database.h"

using namespace std;

class Deudor {
public:
    string nombre;
    string email;

    Deudor(const std::string& nombre, const std::string& email) : nombre(nombre), email(email) {}

    void guardar(Database& db);
    static void consultarTodos(Database& db);
};