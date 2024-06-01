#include "Notificacion.h"
#include <iostream>

using namespace std;

void Notificacion::guardar(Database& db) {
    unique_ptr<sql::PreparedStatement> pstmt(db.getConnection()->prepareStatement("INSERT INTO Notificaciones (deudor_id, mensaje, fecha) VALUES (?, ?, ?)"));
    pstmt->setInt(1, deudor_id);
    pstmt->setString(2, mensaje);
    pstmt->setString(3, fecha);
    pstmt->executeUpdate();
}

void Notificacion::consultarTodos(Database& db) {
    unique_ptr<sql::Statement> stmt(db.getConnection()->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM Notificaciones"));

    while (res->next()) {
        cout << "ID: " << res->getInt("id") << " DeudorID: " << res->getInt("deudor_id") << " Mensaje: " << res->getString("mensaje") << " Fecha: " << res->getString("fecha") << endl;
    }
}