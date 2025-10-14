#include "UserData.h"
#include <iostream>
#include <vector>
#include <string>

UserData::UserData(){}
UserData::~UserData(){}
void UserData::addData(int data){
	dataStorage.push_back(data);
}
void UserData::removeData(int data){
	auto it = std::remove(dataStorage.begin(), dataStorage.end(), data);
	if(it != dataStorage.end()){
		dataStorage.erase(it, dataStorage.end());
	}
}
bool UserData::findData(int data){
	return std::find(dataStorage.begin(), dataStorage.end(), data) != dataStorage.end();
}
void UserData::printData() const{
	for(const auto& data : dataStorage){
		std::cout << data << " ";
	}
	std::cout << std::endl;
}
