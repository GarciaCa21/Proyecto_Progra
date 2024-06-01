#pragma once
#include <string>
#include "Database.h"

using namespace std;

class Articulo {
public:
    string nombre;
    double precio;

    Articulo(const string& nombre, double precio) : nombre(nombre), precio(precio) {}

    void guardar(Database& db);
    static void consultarTodos(Database& db);
};