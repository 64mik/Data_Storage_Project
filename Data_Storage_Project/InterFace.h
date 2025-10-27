#ifndef INTERFACE_H
#define INTERFACE_H
#include <string>
#include <vector>
class InterFace {
	public:
		InterFace();
		~InterFace();
		//print
		static void gotoxy(int x, int y);
		static void hideCursor(bool hide = true);
		static void ClearConsole();
		static int keyboardListener();
		static int selectMenu(const std::vector<std::string>& v, int x=1, std::string space = "  ");
		static void printVector(const std::vector<std::string>& v, size_t x = 1, std::string space = "  ", int select = -1);
		static void print(std::string text);
		static void printColored(std::string text, char textColor, char bgColor = C_BLACK);
		static void printFile(std::string fileName);
		static void printFormatted();
		//set
		void setTextColor();
		void setFormat();
		enum keyState
		{
			K_ESCAPE = 27,
			K_SPACE = 32,
			K_UP = 38,
			K_DOWN = 40,
			K_LEFT = 37,
			K_RIGHT = 39,
			K_ENTER = 13,
			K_BACKSPACE = 8,
			K_TAB = 9

		};
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