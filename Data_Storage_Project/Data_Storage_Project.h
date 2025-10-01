#ifndef DATA_STORAGE_PROJECT_H
#define DATA_STORAGE_PROJECT_H
	class DataStorage {
	public:
		DataStorage();
		~DataStorage();

		void addData(int data);
		int getData(size_t index);
	};
#endif // !DATA_STORAGE_PROJECT_H