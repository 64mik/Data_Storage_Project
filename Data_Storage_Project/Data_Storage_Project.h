#ifndef DATA_STORAGE_PROJECT_H
#define DATA_STORAGE_PROJECT_H
#include <string>
class DataStorage {
	public:
		DataStorage();
		~DataStorage();
		void addData(int data);
		int getData(size_t index);
		unsigned char binaryToChar(const bool binaryArray[8]);
	private:
		std::string currentPath;
		std::string fileName;
		bool binaryArray[8];

};
#endif // !DATA_STORAGE_PROJECT_H