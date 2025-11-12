#include "PathManager.h"
#include "FileHandler.h"
#include <iostream>
#include <filesystem>
#include <windows.h>
#include <shlobj.h>

PathManager::PathManager(std::string rootFolderName) {
	char userFolderPath[MAX_PATH];
	if (SUCCEEDED(SHGetFolderPathA(nullptr, CSIDL_PROFILE, nullptr, 0, userFolderPath))) {
		rootPath = std::filesystem::path(userFolderPath) /rootFolderName;
	}
}
PathManager::~PathManager(){}
std::filesystem::path PathManager::getRootPath() {
	return rootPath;
}