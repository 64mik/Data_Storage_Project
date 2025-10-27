#include "InterFace.h"
#include <iostream>
#include <windows.h>
#include <vector>
#include <string>

InterFace::InterFace() : textColor(C_LIGHTGRAY), bgColor(C_BLACK), format(0) {}
InterFace::~InterFace() {}
void InterFace::gotoxy(int x, int y) {
	COORD pos = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void InterFace::hideCursor(bool hide) {
	CONSOLE_CURSOR_INFO info;
	info.dwSize = 1;
	info.bVisible = !hide;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}
void InterFace::print(std::string text) {
	std::cout << text << std::endl;
}
void InterFace::ClearConsole() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	if (h == INVALID_HANDLE_VALUE) return;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(h, &csbi)) return;

	DWORD cells = csbi.dwSize.X * csbi.dwSize.Y;
	DWORD written;
	COORD home = { 0, 0 };

	FillConsoleOutputCharacter(h, ' ', cells, home, &written);
	FillConsoleOutputAttribute(h, csbi.wAttributes, cells, home, &written);
	SetConsoleCursorPosition(h, home);
}
int InterFace::keyboardListener() {
	while(true) {
		if(GetAsyncKeyState(VK_UP) & 0x8000) {
			return InterFace::K_UP;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			return InterFace::K_DOWN;
		}
		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			return InterFace::K_LEFT;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			return InterFace::K_RIGHT;
		}
		else if (GetAsyncKeyState(VK_ESCAPE) & 0x8000) {
			return InterFace::K_ESCAPE;
		}
		else if( GetAsyncKeyState(VK_RETURN) & 0x8000) {
			return InterFace::K_ENTER;
		}
		else if (GetAsyncKeyState(VK_BACK) & 0x8000) {
			return InterFace::K_BACKSPACE;
		}
		else if (GetAsyncKeyState(VK_TAB) & 0x8000) {
			return InterFace::K_TAB;
		}
		else if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
			return InterFace::K_SPACE;
		}

		Sleep(100); // Reduce CPU usage
	}
}
int InterFace::selectMenu(const std::vector<std::string>& v, int x, std::string space) {
	if (v.empty()) {
		std::cerr << "Error: Menu options are empty." << std::endl;
		return -1; // Indicate error
	}
	else if (x <= 0) {
		std::cerr << "Error: x cannot be zero or negative." << std::endl;
		return -1; // Indicate error
	}
	int kb = 0;
	size_t select = 0;
	while (true) {
		InterFace::gotoxy(0, 0);
		std::cout << "\nSelect an option(" << select << ") \n"; 
		printVector(v, x, space, select);
		Sleep(80); // To prevent flickering
		//입력
		kb = InterFace::keyboardListener();
		switch (kb) {
		case InterFace::K_UP:
			if (select >= x) {
				select -= x;
			}
			break;
		case InterFace::K_DOWN:
			if (select + x <= v.size()) {
				select += x;
			}
			break;
		case InterFace::K_LEFT:
			if (select != 0) {
				select--;
			}
			break;
		case InterFace::K_RIGHT:
			if (select != v.size() - 1) {
				select++;
			}
			break;
		case InterFace::K_ENTER:
			InterFace::ClearConsole();
			return select;
		case InterFace::K_ESCAPE:
			return -1;
		default:
			break;
		}
		if(select >= v.size()) {
			select = v.size() - 1;
		}else if(select < 0) {
			select = 0;
		}
	}

		
}
void InterFace::printColored(std::string text, char textColor, char bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attributes = (bgColor << 4) | textColor;
	SetConsoleTextAttribute(hConsole, attributes);
	std::cout << text;
	SetConsoleTextAttribute(hConsole, (C_BLACK << 4) | C_LIGHTGRAY); // Reset to default
}
void InterFace::printVector(const std::vector<std::string>& v, size_t x, std::string space, int select) {
	if (v.empty()) {
		std::cerr << "Error: Menu options are empty." << std::endl;
		return;
	}
	if (x <= 0) {
		std::cerr << "Error: x cannot be zero or negative." << std::endl;
		return;
	}

	size_t longest = 0;
	for (const auto& line : v)
		if (line.size() > longest) longest = line.size();

	int width = (longest + space.size()) * x;
	int height = v.size() / x + (v.size() % x == 0 ? 0 : 1);

	std::vector<std::vector<char>> screen(height, std::vector<char>(width, ' '));

	for (int i = 0; i < height; ++i) {
		int startX = 0;
		for (int j = 0; j < (int)x; ++j) {
			int idx = i * x + j;
			if (idx >= (int)v.size()) break;

			const std::string& line = v[idx];

			// 한 글자씩 출력
			for (size_t z = 0; z < line.size(); ++z) {
				char c = line[z];
				if (idx == select) {
					InterFace::printColored(std::string(1, c), C_BLACK, C_LIGHTGRAY);
				}
				else {
					std::cout << c;
				}
			}
			// line 끝난 뒤 space 출력
			std::cout << space;
			startX += line.size() + space.size();
		}
		std::cout << '\n';
	}
}
void InterFace::printFile(std::string n) {
	// Placeholder for file printing logic
	std::cout << "Printing file content..." << std::endl;
}
void InterFace::printFormatted() {
	// Placeholder for formatted printing logic
	std::cout << "Printing formatted content..." << std::endl;
}
void InterFace::setTextColor() {
	// Placeholder for setting text color logic
	std::cout << "Setting text color..." << std::endl;
}
void InterFace::setFormat() {
	// Placeholder for setting format logic
	std::cout << "Setting format..." << std::endl;
}
// Note: Actual implementations for printFile, printFormatted, setTextColor, and setFormat would depend on specific requirements.
// The above implementations are placeholders.
	
