#pragma once
#include <string>
#include "Database.h"

using namespace std;

class Usuario {
private:
    string nombre;
    string perfil;

public:
    Usuario(const string& nombre, const string& perfil);
    void guardar(Database& db);
    static void consultarTodos(Database& db);
    static bool esPerfilValido(const string& perfil);

};