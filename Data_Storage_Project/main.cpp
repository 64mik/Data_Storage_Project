#include "System.h"
#include "DataStroage.h"
#include <iostream>
#include <memory>

int main(){
	std::unique_ptr<System> s = std::make_unique<System>();
	s->setRootPath(s->DOCUMENTS,".datastorage");
	std::cout << "Root Path: " << s->getPath(s->ROOT) << std::endl;
	std::cout << "new Data Storage Name: ";
	std::string dsName;
	std::cin >> dsName;	//ds 이름 예외처리	필요
	std::unique_ptr<DataStorage> d = std::make_unique<DataStorage>(s->getPath(s->ROOT), dsName);	//루트에 ds 객체 하나 생성
	return 0;
}