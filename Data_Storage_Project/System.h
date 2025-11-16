#ifndef SETTING_H
#define SETTING_H
#include <string>
#include <vector>
#include <map>
#include <filesystem>
#include <shlobj.h>
#include <KnownFolders.h>
class System {
	public:
		enum PathType {
			USERPROFILE,
			DOCUMENTS,
			DESKTOP,
			DOWNLOADS,
			ROOT,
			CURRENT,
			SETTINGS
		};
		System();
		~System();
		static void makeSettingFile(const std::string& path);
		static void integrityCheck(const std::map<std::string, std::string>& settingMap);
		inline static std::map<std::string, std::string> currentSettingMap;
		void setRootPath(int parentFolder, std::string folderName);
		std::filesystem::path getPath(int pathType);
		const KNOWNFOLDERID& ToFolderID(PathType type) {
			switch (type) {
			case PathType::USERPROFILE:
				return FOLDERID_Profile;
			case PathType::DOCUMENTS:
				return FOLDERID_Documents;
			case PathType::DESKTOP:
				return FOLDERID_Desktop;
			case PathType::DOWNLOADS:
				return FOLDERID_Downloads;
			default:
				return FOLDERID_Profile;
			}
		}
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
		std::filesystem::path rootPath;
		std::string currentPath;
};
#endif // !SETTING_H
