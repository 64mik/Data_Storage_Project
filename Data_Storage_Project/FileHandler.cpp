#include "FileHandler.h"
#include "InterFace.h"
#include <filesystem>
#include <iostream>
#include <fstream>
#include <shlobj.h>
#include <string>
#include <vector>
//file
//edit file 함수 만들고,맵에서 각종 수정 마치면 파일에 쓰는 기능으로
std::streampos FileHandler::findInsideFile(const std::string& searchString, std::fstream& file) {
	std::string line;
	file.clear();
	file.seekg(0, std::ios::beg);
	while (std::getline(file, line)) {
		if (line.find(searchString) != std::string::npos) {
			return file.tellg();
		}
	}
	return -1; // Return empty string if not found
}
void FileHandler::readFileToVector(const std::string & filePath, std::vector<std::string>&v) {
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
void FileHandler::readFileToMap(const std::string& filePath, std::map<std::string,std::string>& settingMap, const char& delim) {
	std::ifstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filePath << std::endl;
		return;
	}
	else {
		std::string line;
		while (std::getline(file, line)) {
			size_t delimiterPos = line.find(delim);
			if (delimiterPos != std::string::npos) {	//구분자 있으면,
				std::string key = line.substr(0, delimiterPos);
				std::string value = line.substr(delimiterPos + 1);
				settingMap[key] = value;
			}
		}
		file.close();
	}
}
void FileHandler::writeVectorToFile(const std::string& filePath, const std::vector<std::string>& v) {
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
void FileHandler::writeMapToFile(const std::string& filePath, const std::map<std::string,std::string>& settingMap, const char& delim) {
	std::ofstream file(filePath);
	if (!file.is_open()) {
		std::cerr << "Error opening file: " << filePath << std::endl;
		return;
	}
	else {
		for (const auto& kv : settingMap) {
			file << kv.first << delim << kv.second << std::endl;
		}
		file.close();
	}
}
std::string FileHandler::findFile(const std::string& fileName, const std::string& directory){
	if (std::filesystem::exists(directory)) {
		for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
			if (std::filesystem::is_regular_file(entry)) {
				if (entry.path().filename() == fileName)
					return entry.path().string();
			}
		}
	}
	else {
		std::cerr << "File not found: " << fileName << " in directory: " << directory << std::endl;
		return "";
	}
}
std::string FileHandler::findFolder(const std::string& folderName, const std::string& directory ){
	//Placeholder for findFolder logic
	for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
		if (std::filesystem::is_directory(entry)) {
			if(entry.path().filename() == folderName)
				return entry.path().string();
		}
	}
	return "";
}
std::string FileHandler::findExtension(const std::string& extention, const std::string& directory){
	for (const auto& entry : std::filesystem::recursive_directory_iterator(directory)) {
		if (std::filesystem::is_regular_file(entry) && entry.path().extension() == extention) {
			return entry.path().string();
		}
	}
	return "";
}
void FileHandler::deleteFile(const std::string& filePath, bool showWarning){
	if(filePath=="")
		std::cerr << "Error deleting file: File path is empty." << std::endl;
		return;
	if (showWarning) {
		InterFace::ClearConsole();
		InterFace::gotoxy(0, 3);
		InterFace::printColored("Warning: Deleting a file will remove all its contents permanently.\nAre you sure you want to delete the file : "+filePath, InterFace::C_RED, InterFace::C_LIGHTGRAY);
		if (InterFace::selectMenu({ "Yes","No" }, 2) != 0)
			return;
	}
	if (std::filesystem::remove_all(filePath))
		return;
	else
		std::cerr << "Error deleting folder: " << filePath << std::endl;
}
void FileHandler::deleteFolder(const std::string& folderPath, bool showWarning) {
	if (showWarning) {
		InterFace::ClearConsole();
		InterFace::gotoxy(0, 3);
		InterFace::printColored("Warning: Deleting a folder will remove all its contents permanently.\nAre you sure you want to delete the folder : "+folderPath, InterFace::C_RED);
		if (InterFace::selectMenu({ "Yes","No" }, 2) != 0) 
			return;
	}
	if (std::filesystem::remove_all(folderPath))
		return;
	else
		std::cerr << "Error deleting folder: " << folderPath << std::endl;
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
//folder
void FileHandler::makeSubFolders(const std::string& parentDirectory, const std::vector<std::string>& subFolders) {
	for (const auto& dir : subFolders) {
		std::filesystem::create_directories(std::filesystem::path(parentDirectory)/std::filesystem::path(dir));
	}	//나중에 예외	처리 넣기
}
