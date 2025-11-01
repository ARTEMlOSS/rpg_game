#pragma once
#include<iostream>

struct MapData // struct is used only for storing data, no functions
{
	int version = 0;

	std::string tilesheet = "";
	std::string name = "";

	int mapWidth = 0;
	int mapHeight = 0;

	int tileWidth = 0;
	int tileHeight = 0;

	int scaleX = 0;
	int scaleY = 0;

	int dataSize = 0;
	int* data = nullptr; // pointer to null used as an array
};