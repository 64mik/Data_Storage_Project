#ifndef USER_DATA
#define USER_DATA	
#include <string>
#include <vector>
#include <map>
class UserData{
	public:
		UserData();
		~UserData();
		void addData(int data);
		void removeData(int data);
		bool findData(int data);
		void printData() const;
	private:
		std::vector<int> dataStorage;
		std::map<std::string, std::string> settingMap = {
			{"user name","user"},
			{"current infile direct","infile.txt"},
			{"current outfile direct","outfile.txt"},
			{"current inFolder direct","-"},
			{"current outFolder direct","-"},
			{"current file direct","infile.txt"},
			{"current folder direct","-"},
			{"data storage type","vector"},
			{"data storage size","0"},
			{"data storage capacity","0"},
			{"data storage max size","0"},
		};

		

		
};
#endif // USER_DATA
