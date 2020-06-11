#include "Table.h"

Table::Table()
{
}

Table::Table(std::string name, std::string file)
{
	this->name = name;
	this->file = file;
}

Table::~Table()
{
}

std::string Table::get_name() const
{
	return this->name;
}

std::string Table::get_file() const
{
	return this->file;
}

void Table::set_name(std::string name)
{
	this->name = name;
}

void Table::set_file(std::string file)
{
	this->file = file;
}
