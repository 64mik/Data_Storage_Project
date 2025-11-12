#include "DataStroage.h"
#include "setting.h"
#include "FileHandler.h"
#include <iostream>
#include <filesystem>
#include <shlobj.h>
#include <Windows.h>
#include <vector>
DataStorage::DataStorage(std::filesystem::path root, std::string storageName) {
	dsName = storageName;
	subFolder = {
		"inFiles\\", "outFiles\\", "data\\"
	};
	rootPath = root / "Data Storages" / dsName;
	FileHandler::makeSubFolders(root.string(), {"Data Storages", "Settings", ("Data Storages\\" + dsName)});
	FileHandler::makeSubFolders(rootPath.string(), subFolder);
	//Setting::makeSettingFile(rp);
	std::string fileName[4]= { " tags.txt"," offset.txt"," setting.txt"," umm.ds" };
	currentPath = rootPath / subFolder[0];
	for (auto f : fileName) {
		FileHandler::makeFile(currentPath.string()+ dsName + f);
	}
}
DataStorage::~DataStorage(){}
void DataStorage::deleteDataStorage(const std::string& name) {
	FileHandler::deleteFolder(rootPath.string());
}
void DataStorage::makeTag() {}
void DataStorage::deleteTag() {}
void DataStorage::findTag() {}
void DataStorage::saveData(const std::string& key, const std::string& value) {}
std::string DataStorage::loadData(const std::string& key) const {
	return "";
}
void DataStorage::deleteData(const std::string& key) {}

