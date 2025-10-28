#ifndef SETTING_H
#define SETTING_H
#include <string>
#include <vector>
#include <map>
class Setting {
	public:
		Setting();
		~Setting();
		static void makeSettingFile(const std::string& path);
		static void integrityCheck(const std::map<std::string, std::string>& settingMap);
		inline static std::map<std::string, std::string> currentSettingMap;
	private:
		inline static std::map<std::string, std::string> defaultSettingMap = {
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
			{"modified","2025-10-25|18:30|user|"},
			{"system_color","YELLOW"},
			{"print_color","GRAY" },
			{"error_color","RED" },
			{"default_color","BRIGHT_GRAY" },
			{"highlight_color","BRIGHT_YELLOW" },
		};
		//세팅 항목 수정하는 함수 만들기(INT만 받거나 T/F, 색상 등)
};
#endif // !SETTING_H
