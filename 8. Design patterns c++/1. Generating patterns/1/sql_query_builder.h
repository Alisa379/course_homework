#pragma once
#include <string>
#include <vector>
#include <map>

class SqlSelectQueryBuilder {
public:
	std::string table;
	std::vector<std::string> columns;
	std::map<std::string, std::string> conditions;
	SqlSelectQueryBuilder& AddColumn(const std::string&)  noexcept;
	SqlSelectQueryBuilder& AddFrom(const std::string&)  noexcept;
	SqlSelectQueryBuilder& AddWhere(const std::string&, const std::string&)  noexcept;
	std::string BuildQuery();
};
