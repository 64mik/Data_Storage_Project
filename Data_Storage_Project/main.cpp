#include "PathManager.h"
#include "DataStroage.h"
#include <iostream>

int main(){
	PathManager pm(".datastorage");
	DataStorage ds(pm.getRootPath(), "diary");	//루트에 ds 객체 하나 생성
	return 0;
}