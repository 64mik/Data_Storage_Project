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

	private:
		std::map<std::string, std::string> defaultSettingMap = { 
			{"version", "1.0.0"},
			{"owner","user"},
			{"id","user"},
			{"type","text"},	//or binary
			{"title","Sample Data"},
			{"last_accessed_by","user"},
			{"access_level","private"}, //public, private		
			{"shared_with","user1,user2"},
			{"tags","tag1,tag2,tag3"},
			{"created","2025-10-25|18:00|user|"},
			{"modified","2025-10-25|18:30|user|"}
		};
		std::map<std::string, std::string> currentSettingMap = defaultSettingMap;
};
#endif // !SETTING_H
