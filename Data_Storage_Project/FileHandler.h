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
		static std::string findFile(const std::string& fileName, const std::string& directory);
		static std::string findFolder(const std::string& folderName, const std::string& path);
		static std::string findExtension(const std::string& extension, const std::string& directory);
		static std::streampos findInsideFile(const std::string& searchString, std::fstream& file);
		static void deleteFile(const std::string& filePath, bool showWarning=true);
		static void deleteFolder(const std::string& folderPath, bool showWarning=true);

		static void readFileToVector(const std::string& filePath, std::vector<std::string>& v);
		static void readFileToMap(const std::string& filePath, std::map<std::string,std::string>& settingMap, const char& delim = '|');
		static void writeVectorToFile(const std::string& filePath, const std::vector<std::string>& v);
		static void writeMapToFile(const std::string& filePath, const std::map<std::string,std::string>& settingMap, const char& delim = '|');
		static void makeFile(const std::string& filePath);
		//folder
		static void makeSubFolders(const std::string& parentDirectory, const std::vector<std::string>& subFolders);	//
};

#endif // !FILE_HANDLER_H