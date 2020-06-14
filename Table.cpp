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

void Table::print_columns_info(std::string file_name)
{
	std::string tmp_buffer;
	FileSystem fs;
	fs.read(this->file, tmp_buffer);
	int first_line_length = (tmp_buffer.find("\n") != -1) ? tmp_buffer.find("\n") : tmp_buffer.size();
	std::string second_line = tmp_buffer.substr(first_line_length, tmp_buffer.find("\n", first_line_length));
	std::cout << second_line;
}

void Table::print_rows(std::string file_name) //приемаме че една страница съдържа 5 реда
{
	std::string buffer_array[100];
	std::string buffer;
	FileSystem fs;
	fs.read(file_name, buffer);
	int n = 0;
	int pos = 0;
	std::string paging_command;
	while (!buffer.empty()) {
		pos = (buffer.find("\n") != -1) ? buffer.find("\n") : buffer.size();
		std::string line = buffer.substr(0, pos);
		buffer.erase(0, pos + 1);
		if (n > 1) {
			//std::cout<< line << std::endl;
			buffer_array[n - 2] = line;
		}
		n++;
	}
	for (int i = 0; i < n - 2; i++) {
				
		if (i % 5 == 0 && i !=0 ) {
			std::cout << "Paging commands (previous, next or exit) : ";
			std::cin >> paging_command;
			if (paging_command.compare("previous") == 0) {
				if (i == 5) {
					std::cout << "No previous elements! Enter new command: ";
					std::cin >> paging_command;
				}
				else {
					i -= 10; 		
				}
			}
			if (paging_command.compare("next") == 0) {
				if (i == n-2) {
					std::cout << "No next elements! Enter new command: ";
					std::cin >> paging_command;
				}
				
			}
			if (paging_command.compare("exit") == 0) {
				break;
			}
		}
		std::cout << buffer_array[i] << std::endl;
	}
}

void Table::table_export(std::string old_file, std::string new_file)
{
	std::string buffer;
	FileSystem fs;
	fs.read(old_file, buffer);
	fs.write(new_file, buffer);

}

std::string Table::select_from_column(int column, std::string argument)
{
	int counter = 0;
	std::list<std::string> column_values = get_column_value(column);
	for (std::list<std::string>::iterator it = column_values.begin(); it != column_values.end(); it++) {

		if (*it == argument) {
			return *it;
		}
		counter++;
	}

}

std::list<std::string> Table::get_column_value(int column)
{
	std::string buffer;
	FileSystem fs;
	std::list<std::string> result;
	int delimiter_pos = 0;
	int i = 0;

	fs.read(this->file, buffer);
	while (!buffer.empty()) {
		delimiter_pos = (buffer.find(" ") != -1) ? buffer.find(" ") : buffer.size();
		if (i == column) {
			result.push_back(buffer.substr(0, delimiter_pos));
		}
		buffer.erase(0, delimiter_pos + 1);
		i++;	
	}
	return result;

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