#pragma once
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <statement.h>
#include <prepared_statement.h>
#include <resultset.h>
#include <memory>
#include <string>

using namespace std;

class Database {
private:
    sql::mysql::MySQL_Driver* driver;
    unique_ptr<sql::Connection> con;

public:
    Database(const string& host, const string& user, const string& pass, const string& dbname);
    sql::Connection* getConnection();
};