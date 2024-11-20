#include <iostream>
#include <pqxx/pqxx>
#include <Windows.h>
#include "Header.h"
#pragma execution_character_set("utf-8")


int main() {
	//setlocale(LC_ALL, "Russian");
	SetConsoleCP(CP_UTF8);
	SetConsoleOutputCP(CP_UTF8);
	setvbuf(stdout, nullptr, _IOFBF, 1000);

	try {
		database d;
		d.SetConnection();
		pqxx::connection* conn = d.conn;

		d.create(*conn);
		d.add_client(*conn);
		d.add_client_phone(*conn);
		d.update_client_data(*conn);
		d.delete_phone(*conn);
		d.delete_client(*conn);
		d.find_client(*conn);
	}

	catch (const std::exception& e) {
		std::cout << e.what() << std::endl;
	};

}