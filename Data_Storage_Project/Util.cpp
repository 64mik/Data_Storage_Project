#include "Util.h"
#include <string>
#include <iostream>




bool Util::isBool(std::string s) {
	if (s == "true" || s == "false" || s == "t" || s == "f") {
		return true;
	}
	else {
		std::cerr << "Error: Invalid boolean string: " << s << ". Expected 'true' or 'false'." << std::endl;
		return false; // default value
	}
}
void Util::checkKeyValue(const std::string key, const std::string& input, const std::string& value) {
	if (key.empty()) {
		std::cerr << "Error: Key cannot be empty." << std::endl;
	}
	else if (value.empty()) {
		std::cerr << "Error: Value cannot be empty for key: " << key << std::endl;
	}
		if (key==input) {
			if (Util::isBool(value)) {}
			else{
				std::cerr << "Error: Invalid value for" << key << ": " << value << ". Expected 'true' or 'false'." << std::endl;
			}
		}
}
std::vector<std::string> Util::splitString(const std::string& str, char delimiter) {
	std::vector<std::string> result;
	std::string current;
	for (char ch : str) {
		if (ch == delimiter) {
			if (!current.empty()) {
				result.push_back(current);
				current.clear();
			}
		}
		else {
			current += ch;
		}
	}
	if (!current.empty()) {
		result.push_back(current);
	}
	return result;
}