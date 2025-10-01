#include "Data_Storage_Project.h"
#include "fileRead.h"
#include "fileWrite.h"
#include <iostream>

int main(){
	FileWrite fw;
	FileRead fr;
	DataStorage ds;
	std::vector<std::string> v;
	fw.makeFile("input.txt");
	fr.readFile("input.txt", v);
	fw.writeFile("output.txt", v);
	ds.addData(42);
	return 0;
}