#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include <string>
#include <vector>
#include <map>
class FileHandler {
	public:
		FileHandler() = delete;
		~FileHandler() = delete;
		//file
		static void readFileToVector(const std::string& filePath, std::vector<std::string>& v);
		static void readFileToMap(const std::string& filePath, std::map<std::string,std::string>& settingMap, const char& delim = '|');
		static void writeVectorToFile(const std::string& filePath, const std::vector<std::string>& v);
		static void writeMapToFile(const std::string& filePath, const std::map<std::string,std::string>& settingMap, const char& delim = '|');
		static void makeFile(const std::string& filePath);
		//folder
		static void makeSubFolders(const std::string& parentDirectory, const std::vector<std::string>& subFolders);	//
};

#endif // !FILE_HANDLER_H