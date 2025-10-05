#ifndef FOLDER_MAKE_H
#define FOLDER_MAKE_H
#include <string>
#include <vector>
class FolderMake {
public:
	FolderMake();
	~FolderMake();
	void makeFolder(const std::string& filePath, std::vector<std::string>& v);
};
#endif // !FOLDER_MAKE_H