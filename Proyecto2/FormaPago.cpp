#include "FormaPago.h"
#include <iostream>

using namespace std;

void FormaPago::guardar(Database& db) {
    unique_ptr<sql::PreparedStatement> pstmt(db.getConnection()->prepareStatement("INSERT INTO FormasPago (tipo) VALUES (?)"));
    pstmt->setString(1, tipo);
    pstmt->executeUpdate();
}

void FormaPago::consultarTodos(Database& db) {
    unique_ptr<sql::Statement> stmt(db.getConnection()->createStatement());
    unique_ptr<sql::ResultSet> res(stmt->executeQuery("SELECT * FROM FormasPago"));

    while (res->next()) {
        cout << "ID: " << res->getInt("id") << " Tipo: " << res->getString("tipo") << endl;
    }
}