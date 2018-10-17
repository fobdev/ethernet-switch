#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::string value_array[2] = { "on", "off" };
	std::string null_string = "";

	std::string file = "state";

	std::string value_loaded;
	std::ifstream loader(file, std::ios::binary);
	loader >> value_loaded;

	std::ofstream saver(file, std::ios::binary);
	std::string current_value = value_array[0];
	saver << null_string;

	if(value_loaded == value_array[0])
	{
		std::cout << "netsh must be disabled right now." << std::endl;
		system("netsh interface set interface ethernet admin=disable");
		saver << "";
		saver << value_array[1];
		exit(0);
	}
	else if(value_loaded == value_array[1])
	{
		std::cout << "netsh must be enabled right now." << std::endl;
		system("netsh interface set interface ethernet admin=enable");
		saver << "";
		saver << value_array[0];
		exit(0);
	}
	else if(value_loaded == null_string)
	{
		std::cout << "Created file to save the current state, please restart the program." << std::endl;
		saver << value_array[0];
		system("pause");
	}
}