#include "Data_Storage_Project.h"
#include <iostream>
#include <vector>

DataStorage::DataStorage(){}
DataStorage::~DataStorage(){}
unsigned char DataStorage::binaryToChar(const bool binaryArray[8]){
	unsigned char result = 0;
	for(int i = 0; i < 8; ++i){
		if(binaryArray[i]){
			result |= (1 << (7 - i));
		}
	}
	return result;
}

void DataStorage::addData(int data) {
	std::cout << data;
}
int DataStorage::getData(size_t index){
	return 0;
}