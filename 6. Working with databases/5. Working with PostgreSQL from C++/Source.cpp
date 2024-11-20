#include "Header.h"
#include <iostream>

database::database() {
	
}

void database::SetConnection() {
	conn = new pqxx::connection(
		"dbname = clients "
		"host=127.0.0.1 "
		"port=5432 "
		"user=postgres "
		"password=postLGS");
}

/*
pqxx::connection database::conn(
	"dbname = clients "
	"host=127.0.0.1 "
	"port=5432 "
	"user=postgres "
	"password=postLGS");
*/

void database::create(pqxx::connection& conn) {

	pqxx::transaction tx{ conn };

		tx.exec("create table if not exists public.client ("
			"id serial PRIMARY KEY, "
			"name text NOT NULL, "
			"last_name text NOT NULL, "
			"email text NOT NULL);");

		tx.exec("create table if not exists public.clients_and_phones ("
			"id serial PRIMARY KEY, "
			"client integer NOT NULL REFERENCES client(id), "
			"phone integer);");

		tx.commit();

		std::cout << "Successfully!" << std::endl;
}

void database::add_client(pqxx::connection& conn) {

		pqxx::transaction tx{ conn };
		conn.prepare("insert_data", "INSERT INTO client (name, last_name, email) VALUES($1, $2, $3)");

		std::string name, last_name, email;

		std::cout << "Insert new client's name: ";
		std::getline(std::cin, name);

		std::cout << "Insert new client's last name: ";
		std::getline(std::cin, last_name);

		std::cout << "Insert new client's email: ";
		std::getline(std::cin, email);

		if (name.size() > 0 and last_name.size() > 0 and email.size() > 0) {
			tx.exec_prepared("insert_data", name, last_name, email);
			tx.commit();
			std::cout << "Successfully!" << std::endl;
		}
}

void database::add_client_phone(pqxx::connection& conn) {

		pqxx::transaction tx{ conn };
		conn.prepare("insert_newPhone", "INSERT INTO clients_and_phones (client, phone) VALUES($1, $2)");

		int client, phone;

		std::cout << "Insert client's id: ";
		std::cin >> client;

		std::cout << "Insert new client's phone number: ";
		std::cin >> phone;


		if (client != 0) {
			tx.exec_prepared("insert_newPhone", client, phone);
			tx.commit();
			std::cout << "Successfully!" << std::endl;
		}
}

void database::update_client_data(pqxx::connection& conn) {
		pqxx::transaction tx{ conn };
		conn.prepare("update_client", "UPDATE client SET name = $1, last_name = $2, email  = $3 WHERE id = $4");

		int client;
		std::string name, last_name, email;

		std::cout << "Insert client's id: ";
		std::cin >> client;
		std::cin.ignore();

		std::cout << "Insert client's name: ";
		std::getline(std::cin, name);

		std::cout << "Insert client's last name: ";
		std::getline(std::cin, last_name);

		std::cout << "Insert client's email: ";
		std::getline(std::cin, email);

		assert(std::cin);

		if (client != 0) {
			tx.exec_prepared("update_client", name, last_name, email, client);
			tx.commit();
			std::cout << "Successfully!" << std::endl;
		}
}

void database::delete_phone(pqxx::connection& conn) {
		pqxx::transaction tx{ conn };
		conn.prepare("delete_phone", "DELETE FROM clients_and_phones WHERE id = $1");

		int id;

		std::cout << "Insert phone's id: ";
		std::cin >> id;

		if (id != 0) {
			tx.exec_prepared("delete_phone", id);
			tx.commit();
			std::cout << "Successfully!" << std::endl;
		}

}

void database::delete_client(pqxx::connection& conn) {

		pqxx::transaction tx{ conn };
		conn.prepare("delete_client", "DELETE FROM client WHERE id = $1");

		int id;

		std::cout << "Insert client's id: ";
		std::cin >> id;

		if (id != 0) {
			tx.exec_prepared("delete_client", id);
			tx.commit();
			std::cout << "Successfully!" << std::endl;
		}
}

void database::find_client(pqxx::connection &conn) {

		pqxx::transaction tx{ conn };

		std::string name, last_name, email;
		int phone, answer;

		std::cout << "How do you want to find the client?" << std::endl;
		std::cout << "1 - by name" << std::endl << "2 - by last name" << std::endl << "3 - by email" << std::endl << "4 - by phone number" << std::endl;
		std::cout << "Your answer: ";
		std::cin >> answer;
		std::cin.ignore(32767, '\n');

		switch (answer) {
		case 1:
			std::cout << "Insert client's name: ";
			std::getline(std::cin, name);
			if (name.size() > 0) {
				auto client = tx.query<int, std::string, std::string, std::string>("SELECT * FROM client WHERE name LIKE '%" + tx.esc(name) + "%'");
				for (auto [id, name, last_name, email] : client) {
					std::cout << id << " " << name << " " << last_name << " " << email << std::endl;
				}
			}
			break;
		case 2:
			std::cout << "Insert client's last name: ";
			std::getline(std::cin, last_name);
			if (last_name.size() > 0) {
				auto client = tx.query<int, std::string, std::string, std::string>("SELECT * FROM client WHERE last_name LIKE '%" + tx.esc(last_name) + "%'");
				for (auto [id, name, last_name, email] : client) {
					std::cout << id << " " << name << " " << last_name << " " << email << std::endl;
				}
			}
			break;
		case 3:
			std::cout << "Insert client's email: ";
			std::getline(std::cin, email);
			if (email.size() > 0) {
				auto client = tx.query<int, std::string, std::string, std::string>("SELECT * FROM client WHERE email LIKE '%" + tx.esc(email) + "%'");
				for (auto [id, name, last_name, email] : client) {
					std::cout << id << " " << name << " " << last_name << " " << email << std::endl;
				}
			}
			break;
		case 4:
			std::cout << "Insert client's phone: ";
			std::cin >> phone;
			if (phone != 0) {
				auto client = tx.query<int, std::string, std::string, std::string>("SELECT c.id, name, last_name, email FROM client as c join clients_and_phones as cap on c.id = cap.client WHERE cap.phone = '" + tx.esc(std::to_string(phone)) + "'");
				for (auto [id, name, last_name, email] : client) {
					std::cout << id << " " << name << " " << last_name << " " << email << std::endl;
				}
			}
			break;
		default:
			std::cout << "unknown answer" << std::endl;
		}

}
