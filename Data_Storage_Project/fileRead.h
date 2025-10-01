#ifndef FILE_READ_H
#define FILE_READ_H
#include <string>
#include <vector>
class FileRead {
	public:
		FileRead();
		~FileRead();
		void readFile(const std::string& filePath, std::vector<std::string>& v);
};

#endif // !FILE_READ_H