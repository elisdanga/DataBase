#include "Table.h"
#include "FileSystem.h"

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

void Table::rename_to_file(std::string new_name)
{
	std::string tmp_buffer;
	FileSystem fs;
	fs.read(this->file, tmp_buffer);
	int first_line_length = (tmp_buffer.find("\n") != -1) ? tmp_buffer.find("\n") : tmp_buffer.size();
	tmp_buffer.erase(0, first_line_length);
	tmp_buffer.insert(0, new_name);
	fs.write(this->file, tmp_buffer);
}

std::string Table::get_name_from_file(std::string file)
{
	std::string buffer;
	FileSystem fs;
	fs.read(file, buffer);
	int first_line_length = (buffer.find("\n") != -1) ? buffer.find("\n") : buffer.size();
	std::string table_name = buffer.substr(0, first_line_length);
	
	return table_name;
}