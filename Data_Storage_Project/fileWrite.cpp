#include "fileWrite.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
FileWrite::FileWrite(){
}
FileWrite::~FileWrite(){
}
void FileWrite::writeFile(const std::string& filePath, std::vector<std::string>& v){
	std::ofstream file(filePath);
	if(!file.is_open()){
		std::cerr << "Error opening file: " << filePath << std::endl;
		return;
	}
	else {
		for(const auto& line : v) {
			file << line << std::endl;
		}
		file.close();
	}
}
void FileWrite::makeFile(const std::string& filePath){
	std::ofstream file(filePath, std::ios::app);
	if(!file.is_open()){
		std::cerr << "Error creating file: " << filePath << std::endl;
		return;
	}
	else {
		file.close();
	}
}