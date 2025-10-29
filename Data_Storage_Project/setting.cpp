#include "Setting.h"
#include "Util.h"
#include "FileHandler.h"
#include <string>
#include <map>
#include <iostream>

Setting::Setting() {

}
Setting::~Setting() {

}
void Setting::makeSettingFile(const std::string& path){
	if(Setting::currentSettingMap.empty()){
		Setting::currentSettingMap = Setting::defaultSettingMap;
		FileHandler::writeMapToFile(path, Setting::currentSettingMap);
	}
	else {
		FileHandler::writeMapToFile(path, Setting::currentSettingMap);
	}
}
void Setting::integrityCheck(const std::map<std::string, std::string>& settingMap) {
	for(const auto& [key, value] : settingMap) {
		if (settingMap.find(key) == settingMap.end()) {	// unknown key
			std::cerr << "Warning: Unknown setting key found: " << key << std::endl;
		}
		else {//�迭�� �޾Ƽ� �Լ� �ϳ��� �˻�?
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
			// �߰� Ű�� �˻� �ʿ� �� ���⿡ �߰�
		}
		// �߰����� ���Ἲ �˻�(��ȣ ������ ��)�� ���ϸ� �̰��� ����
	}
}

