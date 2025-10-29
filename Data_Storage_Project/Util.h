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
		static inline float toPercent(float input, float maxInput) {
			if (maxInput == 0) return 0.0f;
			input = clamp(input, 0.0f, maxInput);
			return (input / maxInput) * 100.0f;
		}
		static inline float clamp(float input, float min, float max){
			return (input < min) ? min : (input > max) ? max : input;
		}
};
#endif // !UTIL_H