#pragma once
#include <iostream>
#include <fstream>
#include <string>

class FileSystem
{
public:
	bool read(std::string file_name, std::string& output);
	bool write(std::string file_name, std::string& input);

private:
	std::fstream stream;
};

