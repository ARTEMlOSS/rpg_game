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

void MapLoader::Load(std::string filename, MapData& mapData)
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
					std::cout << "failed to open map file " << filename << std::endl;
					break;
				}
			}

			if (isMapValid)	{ // PARCE THE LINES
				try	{
					int index = line.find('='); // returns index of a char
					std::string variable = line.substr(0, index); // (where to start, how many chars)
					std::string value = line.substr(index + 1, line.length() - index);

					// STORE TO THE VARIABLES
					if (variable == "version") { mapData.version = std::stoi(value); }
					else if (variable == "tilesheet") { mapData.tilesheet = value; }
					else if (variable == "name") { mapData.name = value; }

					else if (variable == "mapWidth") { mapData.mapWidth = std::stoi(value); }
					else if (variable == "mapHeight") { mapData.mapHeight = std::stoi(value); }

					else if (variable == "tileWidth") { mapData.tileWidth = std::stoi(value); }
					else if (variable == "tileHeight") { mapData.tileHeight = std::stoi(value); }
					else if (variable == "scaleX") { mapData.scaleX = std::stoi(value); }
					else if (variable == "scaleY") { mapData.scaleY = std::stoi(value); }
					else if (variable == "dataSize") { mapData.dataSize = std::stoi(value); }
					// STORE TO THE ARRAY
					else if (variable == "data") {
						mapData.data = new int[mapData.dataSize];//now points to heap
						int offset = 0;
						int i = 0;

						while (true) {
							int commaIndex = value.find(',', offset);//comma index with proper offset
							// commaIndex is always greater thatn offset by 3
							std::string number = value.substr(offset, commaIndex - offset);
							if (number == ";")
								break;
							mapData.data[i] = std::stoi(number);// store to the array
							offset = commaIndex + 1; //to start in next iteration with next comma
							i++;
						}
					}// END ARRAY STORING
				}
				catch (const std::exception&){
					std::cout << "MAP PARCING ERROR in " << filename << std::endl;
				}
			}
		}
		std::cout << "Loaded map from " << filename << std::endl;

		file.close();
	}
	else{
		std::cout << "unable to open map from " << filename << std::endl;
	}

	//return mapData;
}
