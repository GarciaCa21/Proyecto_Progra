#include "Articulo.h"
#include <iostream>

using namespace std;

void Articulo::guardar(Database& db) {
    unique_ptr<sql::PreparedStatement> pstmt(db.getConnection()->prepareStatement("INSERT INTO Articulos (nombre, precio) VALUES (?, ?)"));
    pstmt->setString(1, nombre);
    pstmt->setDouble(2, precio);
    pstmt->executeUpdate();
}

void Articulo::consultarTodos(Database& db) {
    unique_ptr<sql::Statement> stmt(db.getConnection()->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Articulos"));

    while (res->next()) {
        cout << "ID: " << res->getInt("id") << " Nombre: " << res->getString("nombre") << " Precio: " << res->getDouble("precio") << endl;
    }
}