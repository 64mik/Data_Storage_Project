#ifndef FILE_WRITE_H
#define FILE_WRITE_H
#include <string>
#include <vector>
class FileWrite {
	public:
		FileWrite();
		~FileWrite();
		void writeFile(const std::string& filePath, std::vector<std::string>& v);
		void makeFile(const std::string& filePath);
};

#endif // !FILE_WRITE_H