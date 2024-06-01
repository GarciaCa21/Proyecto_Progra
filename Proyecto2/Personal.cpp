#include "Personal.h"
#include <iostream>

using namespace std;

void Personal::guardar(Database& db) {
    unique_ptr<sql::PreparedStatement> pstmt(db.getConnection()->prepareStatement("INSERT INTO Personal (nombre, puesto) VALUES (?, ?)"));
    pstmt->setString(1, nombre);
    pstmt->setString(2, puesto);
    pstmt->executeUpdate();
}

void Personal::consultarTodos(Database& db) {
    unique_ptr<sql::Statement> stmt(db.getConnection()->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Personal"));

    while (res->next()) {
        cout << "ID: " << res->getInt("id") << " Nombre: " << res->getString("nombre") << " Puesto: " << res->getString("puesto") << endl;
    }
}