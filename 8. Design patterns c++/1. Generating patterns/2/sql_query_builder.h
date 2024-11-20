#pragma once
#include <string>
#include <map>
#include <vector>

class SqlSelectQueryBuilder {
public:
	std::string table;
	std::vector<std::string> columns;
	std::map<std::string, std::string> conditions;
	SqlSelectQueryBuilder& AddColumn(const std::string&)  noexcept;
	SqlSelectQueryBuilder& AddColumn(const std::vector<std::string>&) noexcept;
	SqlSelectQueryBuilder& AddFrom(const std::string&)  noexcept;
	SqlSelectQueryBuilder& AddWhere(const std::string&, const std::string&)  noexcept;
	SqlSelectQueryBuilder& AddWhere(const std::map<std::string, std::string>&) noexcept;
	std::string BuildQuery();
};


