// keyIDstoCSVFile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream> 
#include <fstream>
#include <string>
#include <sstream>

int main()
{
	std::cout << "\"" << std::endl;
	std::ifstream keyIDs;
	std::ofstream CSV;
	std::stringstream ss;
	int chapter_count = 1;
	int num_of_keyIDs = 0;
	int chapter = 0;
	float key_id_number = 0.;
	char c = ' ';
	std::string key_id_start;
	std::string line;
	std::string key_id_topic;
	std::string key_id_description;

	CSV.open("every_sherwin_key_id.csv");
	keyIDs.open("sherwin_keyIDs.txt");
	CSV << "chapter, key_id_number, \"key_id_topic\", \"key_id_description\"" << std::endl;
	getline(keyIDs, key_id_start);


	while (!keyIDs.eof())
	{

		keyIDs >> key_id_start >> chapter;
		std::cout << key_id_start << " chapter: " << chapter << std::endl;
		getline(keyIDs, line);
		keyIDs >> key_id_number;
		// std::cout << "key_id_number: " << key_id_number <<  std::endl;
		getline(keyIDs, key_id_topic);
		key_id_description = "";
		line = "";

		while (!isdigit(line[0]))
		{
			
			key_id_description += (" " + line);
			getline(keyIDs, line);
		}

		CSV << chapter_count << ", " << key_id_number << ", \""
			<< key_id_topic << "\",\"" << key_id_description << "\"" << std::endl;

		// keyIDs.clear();

		while (!keyIDs.eof() && line != "Key ID's")
		{

			ss.clear();
			ss << line;
			// std::cout << line << std::endl;
			ss >> key_id_number;
			getline(ss, key_id_topic);
			key_id_description = "";
			line = "";
			while (!isdigit(line[0]) && line[0] != ' ' && !keyIDs.eof() && line != "Key ID's")
			{
				
				key_id_description += (" " + line);
				getline(keyIDs, line);
			}
			if (key_id_number == 1)
			{
				chapter_count++;
			}
			CSV << chapter_count << ", " << key_id_number << ",\""
				<< key_id_topic << "\",\"" << key_id_description << "\"" << std::endl;
		}
	}


	keyIDs.close();
	CSV.close();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
