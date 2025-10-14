#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H
#include <string>
#include <vector>
class FileHandler {
	public:
		FileHandler() = delete;
		~FileHandler() = delete;
		static void readFile(const std::string& filePath, std::vector<std::string>& v);
		static void writeFile(const std::string& filePath, std::vector<std::string>& v);
		static void makeFile(const std::string& filePath);
		static void setFormat(const std::string& format);
		static void makeSubFolders(const std::string& parentDirectory, const std::vector<std::string>& subFolders);	//
};

#endif // !FILE_HANDLER_H