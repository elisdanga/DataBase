#include "Catalog.h"
#include "FileSystem.h"

Catalog::Catalog()
{
}

Catalog::Catalog(std::string file)
{
	this->file = file;
	load_from_file(file);
}

Catalog::~Catalog()
{
}

std::string Catalog::get_file() const
{
	return this->file;
}

void Catalog::set_file(std::string file)
{
	this->file = file;
}

Table Catalog::fromString(std::string input)
{
	Table c;
	std::string params[8];
	int delimiter_pos = 0;
	int i = 0;

	std::string delimiter = " ";

	while (!input.empty()) {
		delimiter_pos = (input.find(" ") != -1) ? input.find(" ") : input.size();
		params[i] = input.substr(0, delimiter_pos);
		input.erase(0, delimiter_pos + 1);
		i++;
	}
	c.set_name(params[0]);
	c.set_file(params[1]);
	return c;
}

void Catalog::print()
{
	for (std::list<Table>::iterator it = this->list_of_table.begin(); it != this->list_of_table.end(); it++) {
		std::cout << it->get_name() << ' ';

		std::cout << '\n';
	}
}

void Catalog::load_from_file(std::string file)
{
	std::string buffer;
	FileSystem fs;
	fs.read(file, buffer);
	int n = 0;
	int pos = 0;
	//std::cout << buffer.find("\n");
	//while ((pos = buffer.find("\n")) != std::string::npos) {
	while (!buffer.empty()) {
		pos = (buffer.find("\n") != -1) ? buffer.find("\n") : buffer.size();
		std::string line = buffer.substr(0, pos);
		std::cout << line;
		Table t = fromString(line);
		this->list_of_table.push_back(t);

		buffer.erase(0, pos + 1);
		n++;

	}
}
