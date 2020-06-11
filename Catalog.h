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

	void set_file(std::string);

	//std::string list_of_tables(std::string);
	void load_from_file(std::string);
	static Table fromString(std::string input);
	void print();

private:
	std::string file;
	std::list<Table> list_of_table;
};

