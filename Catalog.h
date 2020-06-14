#pragma once
#include <string>
#include <list>
#include <iterator>
#include "Table.h"

class Catalog
{
public:
	Catalog();
	Catalog(std::string);
	~Catalog();

	std::string get_file() const;
	std::list<Table>& get_list_of_table();
	void set_file(std::string);

	//std::string list_of_tables(std::string);
	void load_from_file(std::string);
	static Table fromString(std::string input);
	void print();
	bool has_table(std::string);
	void save_to_file(std::string);
	Table get_table(std::string);
	void rename_table(std::string, std::string);

private:
	std::string file;
	std::list<Table> list_of_table;
};

