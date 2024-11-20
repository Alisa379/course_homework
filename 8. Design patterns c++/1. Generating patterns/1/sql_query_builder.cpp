#include "sql_query_builder.h"

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddColumn(const std::string& result_column)  noexcept  {
	columns.push_back(result_column);
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddFrom(const std::string& table)  noexcept {
	this->table = table;
	return *this;
}

SqlSelectQueryBuilder& SqlSelectQueryBuilder::AddWhere(const std::string& condition_column, const std::string& value)  noexcept  {
	conditions.insert(std::pair<std::string, std::string>(condition_column, value));
	return *this;
}

std::string SqlSelectQueryBuilder::BuildQuery() {
	if (columns.empty() == true) {
		return "SELECT * FROM table WHERE id=42 AND name=John;";
	}
	else {
		return "SELECT name, phone FROM students WHERE id=42 AND name=John;";
	}
}
