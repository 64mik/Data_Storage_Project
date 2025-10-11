#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include <vector>
class InterFace {
	public:
		InterFace();
		~InterFace();
		//print
		void print(std::string text);
		void printColored(std::string text, char textColor, char bgColor = C_BLACK);
		void printFile(std::string fileName);
		void printFormatted();
		//set
		void setTextColor();
		void setFormat();
		enum Color
		{
			C_BLACK= 0,
			C_BLUE = 1,
			C_GREEN = 2,
			C_CYAN = 3,
			C_RED = 4,
			C_MAGENTA = 5,
			C_BROWN = 6,
			C_LIGHTGRAY = 7,
			C_DARKGRAY = 8,
			C_LIGHTBLUE = 9,
			C_LIGHTGREEN = 10,
			C_LIGHTCYAN = 11,
			C_LIGHTRED = 12,
			C_LIGHTMAGENTA = 13,
			C_YELLOW = 14,
			C_WHITE = 15
		};
	private:
		char textColor;
		char bgColor;
		char format;

};
#endif // !INTERFACE_H