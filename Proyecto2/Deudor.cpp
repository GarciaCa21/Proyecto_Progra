#include "Deudor.h"
#include <iostream>

using namespace std;

void Deudor::guardar(Database& db) {
    unique_ptr<sql::PreparedStatement> pstmt(db.getConnection()->prepareStatement("INSERT INTO Deudores (nombre, email) VALUES (?, ?)"));
    pstmt->setString(1, nombre);
    pstmt->setString(2, email);
    pstmt->executeUpdate();
}

void Deudor::consultarTodos(Database& db) {
    unique_ptr<sql::Statement> stmt(db.getConnection()->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Deudores"));

    while (res->next()) {
        cout << "ID: " << res->getInt("id") << " Nombre: " << res->getString("nombre") << " Email: " << res->getString("email") << endl;
    }
}