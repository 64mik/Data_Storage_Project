#ifndef PATH_MANAGER_H
#define PATH_MANAGER_H
#include <string>
#include <vector>
#include <filesystem>
class PathManager {
	public:
		PathManager() : PathManager("untitled") {};
		PathManager(std::string rootFolderName);
		~PathManager();
		std::filesystem::path getRootPath();
	private:
		std::filesystem::path rootPath;
		std::string currentPath;
		
		

};
#endif // !PATH_MANAGER_H
