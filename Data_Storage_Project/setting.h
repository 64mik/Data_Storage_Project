#ifndef SETTING_H
#define SETTING_H
#include <string>
#include <vector>
#include <map>
class setting {
	public:
		setting() = delete;
		~setting() = delete;
		static void integrityCheck(const std::map<std::string, std::string>& settingMap);
		static void makeSettingFile(const std::map<std::string,std::string>& settingMap);
	private:
		std::map<std::string, std::string> settingMap = {
			{"user",""},
			{"",""},
			{"",""},
			{"",""},
			{"",""},
			{"",""},
			{"",""},
			{"",""},
			{"",""}
		};
};

#endif // !SETTING_H
