#include "FileRead.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
FileRead::FileRead(){
}
FileRead::~FileRead(){
}

void FileRead::readFile(const std::string& filePath, std::vector<std::string>& v){
	std::ifstream file(filePath);
	if(!file.is_open()){
		std::cerr << "Error opening file: " << filePath << std::endl;
		return;
	}
	else {
		std::string line;
		while(std::getline(file, line)) {
			v.push_back(line);
		}
		file.close();
	}
}