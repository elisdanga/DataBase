#include <iostream>
#include <string>
#include "FileSystem.h"
#include "Catalog.h"
#include "Table.h"


int main()
{
	std::string buffer;
	std::string catalog;
	FileSystem fs;
	Catalog c1;
	c1.load_from_file("Catalog.txt");
	c1.print();

	/*while (true) {
		std::cout << '>';
		std::string input;
		std::string command;
		std::string args[4];
		int i = 0;
		std::getline(std::cin, input);

		int delimiter_pos = input.find(' ');
		command = input.substr(0, delimiter_pos);

		input.erase(0, delimiter_pos + 1);

		if (delimiter_pos != -1) {
			while (!input.empty()) {
				delimiter_pos = (input.find(" ") != -1) ? input.find(" ") : input.size();
				args[i] = input.substr(0, delimiter_pos);
				input.erase(0, delimiter_pos + 1);
				i++;
			}
		}

		if (command.compare("open") == 0) {
			if (args[0].size()) {
				catalog = args[0];
				bool is_open = fs.read(catalog, buffer);
				if (is_open) {
					int number_of_product_in_buffer = std::count(buffer.begin(), buffer.end(), '\n');
					std::cout << buffer<<std::endl;

					std::cout << "Successfully opened file: " << catalog << std::endl;
				}
				else {
					std::cout << "Can't open file";
					catalog = "";
					buffer = "";
				}
			}
			else {
				std::cout << "Please use format: \"open file.txt\" ";
			}
		} 
	
		if (command.compare("import") == 0) {
			if (args[0].size() && args[1].size()) {
				
			}
		}

	}*/

	return 0;
}