#include "Database.h"

using namespace std;

Database::Database(const string& host, const string& user, const string& pass, const string& dbname) {
    driver = sql::mysql::get_mysql_driver_instance();
    con.reset(driver->connect(host, user, pass));
    con->setSchema(dbname);
}

sql::Connection* Database::getConnection() {
    return con.get();
}