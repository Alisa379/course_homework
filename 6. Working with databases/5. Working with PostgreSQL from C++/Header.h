#pragma once
#include <pqxx/pqxx>

class database {
public:
	database();
	pqxx::connection* conn;
	void SetConnection();
	void create(pqxx::connection& conn);
	void add_client(pqxx::connection& conn);
	void add_client_phone(pqxx::connection& conn);
	void update_client_data(pqxx::connection& conn);
	void delete_phone(pqxx::connection& conn);
	void delete_client(pqxx::connection& conn);
	void find_client(pqxx::connection& conn);
};