#include "map_file_manager.hpp"

#include "logger.hpp"

#include <string>
#include <sstream>
#include <fstream>

MapFileManager::MapFileManager(Logger* inLogger, MapManager* inMapManager) {
	myLogger = inLogger;
	myMapManager = inMapManager;

	LoadMap("default_map.txt");
}

node* MapFileManager::NodifyString(std::string inStringNode) {
	myLogger->log("====");
	myLogger->log(inStringNode);
	myLogger->log("====");
}

void MapFileManager::LoadMap(std::string inMapName) {
	std::fstream myInStream;
	myInStream.open(
		inMapName.c_str(),
		std::fstream::in
	);
	while (myInStream.peek() != EOF) {
		std::string text_object;
		std::getline(myInStream, text_object, '}');
		NodifyString(text_object);
	}

	myInStream.close();
}

std::string MapFileManager::itoa(int inInteger) {
	std::stringstream myStringstreamConv;
	myStringstreamConv << inInteger;
	std::string myConv = myStringstreamConv.str();
	return myConv;
}

std::string MapFileManager::btoa(bool inBoolean) {
	if (inBoolean) {
		return std::string("true");
	}
	else if(!inBoolean) {
		return std::string("false");
	}
}

std::string MapFileManager::stringifyNode(node* inNode) {
	std::string stringifiedNode("{\n");
	stringifiedNode.append("TerrainType: " + itoa(inNode->TerrainType) + ",\n");
	stringifiedNode.append("isPassable: " + btoa(inNode->isPassable) + ",\n");
	stringifiedNode.append("DrawX: " + itoa(inNode->DrawX) + ",\n");
	stringifiedNode.append("DrawY: " + itoa(inNode->DrawY) + ",\n");
	stringifiedNode.append("cartesianGridX: " + itoa(inNode->cartesianGridX) + ",\n");
	stringifiedNode.append("cartesianGridY: " + itoa(inNode->cartesianGridY) + "\n");
	stringifiedNode.append("}");
	return stringifiedNode;
}

std::string stringifyMapMetadata() {
	//cartesian, triagonal, etc.
}

void MapFileManager::SaveMap(std::string outMapName) {
	std::fstream myOutStream;
	myOutStream.open(
		outMapName.c_str(),
		std::fstream::out | std::fstream::ate
	);
	std::vector<node*>::iterator myIter = myMapManager->myMap.begin();
	std::vector<node*>::iterator myLast = --myMapManager->myMap.end();
	std::vector<node*>::iterator myEnd = myMapManager->myMap.end();
	while (myIter != myEnd) {
		myOutStream << stringifyNode((*myIter));
		if (myIter != myLast) {
			myOutStream << ",";
		}
		myOutStream << "\n";
		++myIter;
	}
	myOutStream.close();
}