#pragma once
#include<string>
#include<list>

class Table
{
public:
	Table();
	Table(std::string, std::string);
	~Table();

	std::string get_name() const;
	std::string get_file() const;

	void set_name(std::string);
	void set_file(std::string);
	void rename_to_file(std::string);
	void print_columns_info(std::string);
	void print_rows(std::string);
	void table_export(std::string, std::string);
	std::string select_from_column(int, std::string);
	std::list<std::string> get_column_value(int);

	static std::string get_name_from_file(std::string);

private:
	std::string name;
	std::string file;

};

