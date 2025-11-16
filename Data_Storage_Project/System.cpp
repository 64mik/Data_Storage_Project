#include "System.h"
#include "Util.h"
#include "FileHandler.h"
#include <string>
#include <map>
#include <iostream>
#include <filesystem>
#include <windows.h>
#include <shlobj.h>
#include <KnownFolders.h>

System::System() {}
System::~System() {}
void System::setRootPath(int parentFolder,std::string folderName) {
	PWSTR tempPath = nullptr;
	auto folderID = ToFolderID(static_cast<PathType>(parentFolder));
	if (SUCCEEDED(SHGetKnownFolderPath(folderID, 0, NULL, &tempPath))) {
		rootPath = std::filesystem::path(tempPath) / folderName;
	}
	else {
		std::cerr << "Error: Specified root path does not exist." << std::endl;
		return;
	}
}
std::filesystem::path System::getPath(int pathType) {
	switch (pathType) {
	case ROOT:
		return rootPath;
	case CURRENT:
		return currentPath;
	case SETTINGS:
		return rootPath / "Settings";
	default:
		std::cerr << "Invalid path type requested." << std::endl;
		return "";
	}
}
void System::makeSettingFile(const std::string& path){
	if(System::currentSettingMap.empty()){
		System::currentSettingMap = System::defaultSettingMap;
		FileHandler::writeMapToFile(path, System::currentSettingMap);
	}
	else {
		FileHandler::writeMapToFile(path, System::currentSettingMap);
	}
}
void System::integrityCheck(const std::map<std::string, std::string>& settingMap) {
	for(const auto& [key, value] : settingMap) {
		if (settingMap.find(key) == settingMap.end()) {	// unknown key
			std::cerr << "Warning: Unknown setting key found: " << key << std::endl;
		}
		else {//배열로 받아서 함수 하나로 검사?
			if (key == "autosave") {
				if (Util::isBool(value)) {
					std::cerr << "Error: Invalid value for 'autosave': " << value << ". Expected 'true' or 'false'." << std::endl;
				}
			}
			else if (key == "backup_interval") {
				try {
					int interval = std::stoi(value);
					if (interval <= 0) {
						std::cerr << "Error: 'backup_interval' must be a positive integer. Found: " << value << std::endl;
					}
				} catch (const std::invalid_argument&) {
					std::cerr << "Error: 'backup_interval' must be an integer. Found: " << value << std::endl;
				} catch (const std::out_of_range&) {
					std::cerr << "Error: 'backup_interval' value out of range. Found: " << value << std::endl;
				}
			}
			// 추가 키별 검사 필요 시 여기에 추가
		}
		// 추가적인 무결성 검사(상호 의존성 등)를 원하면 이곳에 구현
	}
}

