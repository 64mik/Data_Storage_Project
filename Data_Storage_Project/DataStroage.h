#ifndef DATA_STORAGE_H
#define DATA_STORAGE_H
#include <string>
#include <vector>
#include <filesystem>

class DataStorage {
	public:
		enum directoryList {
			//file
			DR_SETTING,
			DR_TAG,
			DR_OFFSET,
			DR_BACKUP,
			//folder
			DR_INFILES,
			DR_OUTFILES,
			DR_DATA,
			DR_DS,
			DR_ROOT

		};
			//ds 마다 객체 생성, 단 이미 생성된 ds 폴더는 따로 불러오기 함수 이전에는 객체 생성 없음
			//태그는 ds 내에서 관리
			//ds 내의 offset은 파일에 저장 후 불러오기 필요.
			//ds 불러올 때, 기존 파일인지 아닌지, 생성 여부 띄울 것
			//
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