#include <iostream>
#include <string>
#include "FileSystem.h"
#include "Catalog.h"
#include "Table.h"


int main()
{
	std::string buffer;
	std::string catalog = "Catalog.txt";
	FileSystem fs;
	Catalog c1;
	Table t1;
	c1.load_from_file(catalog);
	std::cout << "Using: " << catalog << std::endl;
	//c1.print();

	while (true) {
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
	
		if (command.compare("close") == 0) {
			catalog = "";
			buffer = "";
			std::cout << "Successfully closed file!" << std::endl;
		}

		if (command.compare("save") == 0) {
			if (catalog.size()) { //провер€ва дали има отворен файл
				c1.save_to_file(catalog);

				std::cout << "File saved!\n";
			}
			else {
				std::cout << "Open file first!\n";
			}
		}

		if (command.compare("saveas") == 0) {
			if (catalog.size()) {
				if (args[0].size()) {
					fs.write(args[0], buffer);
					std::cout << "File saved as " << args[0] << std::endl;
				}
				else {
					std::cout << "Please use format: \"saveas file.txt\" ";
				}
			}
			else {
				std::cout << "Open file first!\n";
			}
		}

		if (command.compare("exit") == 0) {
			std::cout << "Exiting the program...\n";
			break;
		}

		if (command.compare("help") == 0) {
			std::cout << "The following commands are supported: \n\n";

			std::cout << "open <file>\t\t\topens <file> \n";
			std::cout << "close\t\t\t\tcloses currently opened file\n";
			std::cout << "save\t\t\t\tsaves the currently open file\n";
			std::cout << "saveas <file>\t\t\tsaves the currently open file in <file>\n";
			std::cout << "help\t\t\t\tprints this information\n";
			std::cout << "exit\t\t\t\texit program\n";
			std::cout << "import <file name>\t\ttadds a new file table\n";
			std::cout << "showtables\t\t\tdisplays a list of the names of all loaded tables\n";
			std::cout << "describe <name>\t\t\tdisplays information about the column types of a table\n";
			std::cout << "print <name>\t\t\tprint all rows in a table\n";
			std::cout << "export <name> <file name>\t\t\tsaves a table to a file\n";
			std::cout << "select <column-n> <value> <table name>\t\t\tdisplays all rows in the table that contain the value <value> in the cell with the given sequence number\n";
			std::cout << "addcolumn <table name> <column name> <column type>\t\t\tadds a new column (with the largest number) to a table\n";
			std::cout << "update <table name> <search column n> <search value> <target column n> <target value>\t\t\ttFor all rows in the table whose column with sequence number <search column n> contains the value <search column value> are changed so that their column with sequence number <target column n> gets value <target value>\n";
			std::cout << "delete <table name> <search column n> <search value>\t\t\tdeletes all rows in the table whose column <search column n> contains the value <search column value>\n";
			std::cout << "insert <table name> <column 1> Е <column n>\t\t\tinserts a new row in the table with the corresponding values\n";
			std::cout << "innerjoin <table 1> <column n1> <table 2> <column n2>\t\t\tPerforms the Inner Join operation on two tables relative to the columns <column n1> in the first table and <column n2> in the second\n";
			std::cout << "rename <old name> <new name>\t\t\ttrenames a table\n";
			std::cout << "count <table name> <search column n> <search value>\t\t\tfinds the number of rows in the table whose columns contain the given value\n";
			std::cout << "aggregate <table name> <search column n> <search value> <target column n> <operation>\t\t\tperforms an operation on the values in the <target column n> column of all rows whose columns numbered <search column n> contain the value <search value>\n";
		}

		if (command.compare("import") == 0) {
			if (args[0].size()) {
				std::string table_name = Table::get_name_from_file(args[0]);
				if (c1.has_table(table_name)) {
					std::cout << "Error, there is another table with this name!\n";
					continue;
				}
				else {
					Table import_table;
					import_table.set_file(args[0]);
					import_table.set_name(table_name);
					c1.get_list_of_table().push_back(import_table);
					std::cout << "The table has been imported!\n";
				}
			}
			else {
				std::cout << "Please use format: \"import file.txt\" \n";
			}
		}

		if (command.compare("showtables") == 0){
			c1.print();
		}

		if (command.compare("describe") == 0) {
			if (args[0].size()) {
				Table t = c1.get_table(args[0]);
				t.print_columns_info(t.get_file());

			}
			else {
				std::cout << "Please use format: \"describe <name>\" \n";
			}
		}

		if (command.compare("print") == 0) {
			if (args[0].size()) {
				Table t = c1.get_table(args[0]);
				t.print_rows(t.get_file());

			}
			else {
				std::cout << "Please use format: \"print <name>\" \n";
			}
		}
		
		if (command.compare("export") == 0) {
			if (args[0].size() && args[1].size()) {
				Table t = c1.get_table(args[0]);
				t.table_export(t.get_file(), args[1]);


			}
			else {
				std::cout << "Please use format: \"export <name> <file name>\" \n";
			}
		}
		
		if (command.compare("select") == 0) {
			if (args[0].size() && args[1].size() && args[2].size()) {
				Table t = c1.get_table(args[2]);
				//t.select_from_column(args[0], args[1]);
			}
			else {
				std::cout << "Please use format: \"select <column-n> <value> <table name>\" \n";
			}
		}
		
		if (command.compare("addcolumn") == 0) {
			if (args[0].size() && args[1].size() && args[2].size()) {



			}
			else {
				std::cout << "Please use format: \"addcolumn <table name> <column name> <column type>\" \n";
			}
		}
		
		if (command.compare("update") == 0) {
			if (args[0].size() && args[1].size() && args[2].size() && args[3].size() && args[4].size()) {



			}
			else {
				std::cout << "Please use format: \"update <table name> <search column n> <search value> <target column n> <target value>\" \n";
			}
		}
		
		if (command.compare("delete") == 0) {
			if (args[0].size() && args[1].size() && args[2].size() && args[3].size()) {



			}
			else {
				std::cout << "Please use format: \"delete <table name> <search column n> <search value>\" \n";
			}
		}
		
		if (command.compare("insert") == 0) {
			if (args[0].size() && args[1].size() && args[2].size() && args[3].size()) { //как ще стане с безбрпй аргументи



			}
			else {
				std::cout << "Please use format: \"insert <table name> <column 1> Е <column n>\" \n";
			}
		}
		
		if (command.compare("innerjoin") == 0) {
			if (args[0].size() && args[1].size() && args[2].size() && args[3].size()) {



			}
			else {
				std::cout << "Please use format: \"innerjoin <table 1> <column n1> <table 2> <column n2>\" \n";
			}
		}
		
		if (command.compare("rename") == 0) {
			if (args[0].size() && args[1].size()) {
				if (c1.has_table(args[1])) {
					std::cout << "Error! The name isn't unique\n";
				}
				else {
					c1.rename_table(args[0], args[1]);
					std::cout << "The name was changed\n";
				}
			}
			else {
				std::cout << "Please use format: \"rename <old name> <new name>\" \n";
			}
		}
		
		if (command.compare("count") == 0) {
			if (args[0].size() && args[1].size() && args[2].size()) {



			}
			else {
				std::cout << "Please use format: \"count <table name> <search column n> <search value>\" \n";
			}
		}
		
		if (command.compare("aggregate") == 0) {
			if (args[0].size() && args[1].size() && args[2].size() && args[3].size() && args[4].size()) {



			}
			else {
				std::cout << "Please use format: \"aggregate <table name> <search column n> <search value> <target column n> <operation>\" \n";
			}
		}
	}

	return 0;
}