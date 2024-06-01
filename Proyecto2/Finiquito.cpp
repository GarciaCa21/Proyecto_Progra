#include "Finiquito.h"
#include <iostream>

using namespace std;

void Finiquito::guardar(Database& db) {
    unique_ptr<sql::PreparedStatement> pstmt(db.getConnection()->prepareStatement("INSERT INTO Finiquitos (deudor_id, monto, fecha) VALUES (?, ?, ?)"));
    pstmt->setInt(1, deudor_id);
    pstmt->setDouble(2, monto);
    pstmt->setString(3, fecha);
    pstmt->executeUpdate();
}

void Finiquito::consultarTodos(Database& db) {
    unique_ptr<sql::Statement> stmt(db.getConnection()->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Finiquitos"));

    while (res->next()) {
        cout << "ID: " << res->getInt("id") << " DeudorID: " << res->getInt("deudor_id") << " Monto: " << res->getDouble("monto") << " Fecha: " << res->getString("fecha") << endl;
    }
}