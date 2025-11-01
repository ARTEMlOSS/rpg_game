#include "MapLoader.h"
#include <fstream>
#include <string>

//void MapLoader::Save(std::string filename)
//{
//	std::ofstream file;
//	file.open(filename);
//	file << "This is my map" << std::endl;
//	file << "124, 125, 126, 144, 145, 146" << std::endl;
//	file.close();
//}

void MapLoader::Load(std::string filename)
{
	std::string line;
	std::ifstream file(filename);

	bool isMapValid = false;

	if (file.is_open()) {	// PARCING
		while (std::getline(file, line)) //reeds line by line from file to line
		{
			if (!isMapValid){ // PARCE THE FIRS LINE if it's [Map] - means all is correct
				if (line == "[Map]"){
					isMapValid = true;
					continue;
				}
				else{
					std::cout << "failed to open map file" << std::endl;
					break;
				}
			}

			if (isMapValid)	{ // PARCE THE LINES
				int index = line.find('='); // returns index of a char
				std::string variable = line.substr(0, index); // (where to start, how many chars)
				std::string value = line.substr(index + 1, line.length() - index);

				std::cout << variable << " : ";
				std::cout << value << std::endl;
			}

		}
		file.close();
	}
	else{
		std::cout << "unable to open " << filename << std::endl;
	}
}
