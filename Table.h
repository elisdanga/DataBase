#pragma once
#include<string>
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

private:
	std::string name;
	std::string file;

};
