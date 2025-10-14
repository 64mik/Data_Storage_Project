#include "FileHandler.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <shlobj.h>
#include <string>
#include <vector>
void FileHandler::readFile(const std::string& filePath, std::vector<std::string>& v){
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
void FileHandler::writeFile(const std::string& filePath, std::vector<std::string>& v) {
	std::ofstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filePath << std::endl;
		return;
	}
	else {
		for (const auto& line : v) {
			file << line << std::endl;
		}
		file.close();
	}
}
void FileHandler::makeFile(const std::string& filePath) {
	std::ofstream file(filePath, std::ios::app);
	if (!file.is_open()) {
		std::cerr << "Error| makeFile: " << filePath << std::endl;
		return;
	}
	else {
		file.close();
	}
}
void FileHandler::makeSubFolders(const std::string& parentDirectory, const std::vector<std::string>& subFolders) {
	for (const auto& dir : subFolders) {
		std::filesystem::create_directories(std::filesystem::path(parentDirectory)/std::filesystem::path(dir));
	}	//나중에 예외	처리 넣기
}
