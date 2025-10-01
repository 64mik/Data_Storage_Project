#include "Data_Storage_Project.h"
#include <iostream>
#include <vector>

DataStorage::DataStorage(){
	// 생성자 구현
}
DataStorage::~DataStorage(){
	// 소멸자 구현
}
void DataStorage::addData(int data) {
	dataList.push_back(data);
}
int DataStorage::getData(size_t index) const {
	if (index < dataList.size()) {
		return dataList[index];
	}
	throw std::out_of_range("Index out of range");
}