#include "setting.h"
#include "FileHandler.h"
#include <string>
#include <vector>

void setting::integrityCheck(const std::map<std::string, std::string>& settingMap) {
	//settingMap의 무결성 검사
}
void setting::makeSettingFile(const std::map<std::string,std::string>& settingMap) {
	std::string path = "root + file name";
	FileHandler::makeFile(path);
	//FileHandler::writeFile(path, );
}
