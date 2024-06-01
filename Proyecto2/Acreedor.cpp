#include "Acreedor.h"
#include <iostream>

using namespace std;

void Acreedor::guardar(Database& db) {
    unique_ptr<sql::PreparedStatement> pstmt(db.getConnection()->prepareStatement("INSERT INTO Acreedores (nombre) VALUES (?)"));
    pstmt->setString(1, nombre);
    pstmt->executeUpdate();
}

void Acreedor::consultarTodos(Database& db) {
    unique_ptr<sql::Statement> stmt(db.getConnection()->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Acreedores"));

    while (res->next()) {
        cout << "ID: " << res->getInt("id") << " Nombre: " << res->getString("nombre") << endl;
    }
}