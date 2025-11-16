#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H
#include <string>
#include <vector>
#include <filesystem>

class DataStorage {
	public:
		enum directoryList {
			//file
			SETTING,
			TAG,
			OFFSET,
			BACKUP,
			//folder
			INFILES,
			OUTFILES,
			DATA,
			DS,
			ROOT
		};
		DataStorage(std::filesystem::path root, std::string storageName);
		~DataStorage();
		void deleteDataStorage(const std::string& name);
		void makeTag();
		void deleteTag();
		void findTag();
		void saveData(const std::string& key, const std::string& value);
		std::string loadData(const std::string& key) const;
		void deleteData(const std::string& key);
	private:
		std::vector<std::filesystem::path> dsDirect;
		std::vector<std::string> subFolder;
		std::string dsName;
		std::filesystem::path rootPath;
		std::filesystem::path currentPath;
};
#endif // DATA_STORAGE_H