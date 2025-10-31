#ifndef UTIL_H
#define UTIL_H
#include <string>
#include <vector>
class Util {
	public:
		Util() = delete;
		~Util() = delete;
		static void checkKeyValue(const std::string key, const std::string& input, const std::string& value);
		static bool isBool(std::string s);
		static std::vector<std::string> splitString(const std::string& str, char delimiter);
};
#endif // !UTIL_H