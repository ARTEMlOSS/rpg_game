#pragma once
#include<iostream>
#include "MapData.h"

class MapLoader
{
public:
	//void Save(std::string filename);
	void Load(std::string filename, MapData& mapData);
};

