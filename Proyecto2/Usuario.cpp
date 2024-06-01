#include "Usuario.h"
#include <iostream>

using namespace std;

Usuario::Usuario(const string& nombre, const string& perfil) : nombre(nombre), perfil(perfil) {}

bool Usuario::esPerfilValido(const string& perfil) {
    return perfil == "consulta" || perfil == "pagos" || perfil == "administrador";
}
void Usuario::guardar(Database& db) {
    unique_ptr<sql::PreparedStatement> pstmt(db.getConnection()->prepareStatement("INSERT INTO Usuarios(nombre, perfil) VALUES (?, ?)"));
    pstmt->setString(1, nombre);
    pstmt->setString(2, perfil);
    pstmt->execute();
    cout << "Usuario guardado exitosamente.\n";
}

void Usuario::consultarTodos(Database& db) {
    unique_ptr<sql::Statement> stmt(db.getConnection()->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Usuarios"));

    while (res->next()) {
        cout << "ID: " << res->getInt("id") << " Nombre: " << res->getString("nombre") << " Perfil: " << res->getString("perfil") << endl;
    }
}