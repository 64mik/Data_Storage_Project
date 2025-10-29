#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include <vector>
#include <array>

class InterFace {
	public:
		InterFace();
		~InterFace(); 
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
		struct ProgressBarOption
		{
			int totalUnit = 10;
			char filledColor = C_GREEN;
			char unfilledColor = C_DARKGRAY;
			int x = 0;
			int y = 0;
			std::array<std::string, 5> ui = {"[", "=", ">", "-", "]"};
		};

		//print
		static void printProgressBar(float percent, const std::string& text = "", const ProgressBarOption & op = ProgressBarOption{});
		static void gotoxy(int x, int y);
		static void hideCursor(bool hide = true);
		static void ClearConsole();
		static int keyboardListener();
		static int selectMenu(const std::vector<std::string>& v, int lineWidth =1, std::string space = "  ", int y=0);
		static void printVector(const std::vector<std::string>& v, size_t lineWidth = 1, std::string space = "  ", int select = -1);
		static void print(std::string text);
		static void printColored(std::string text, char textColor, char bgColor = C_BLACK);
		//set
	private:
		char textColor;
		char bgColor;
		char format;

};
#endif // !INTERFACE_H