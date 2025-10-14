#include "InterFace.h"
#include <iostream>
#include <windows.h>


InterFace::InterFace() : textColor(C_LIGHTGRAY), bgColor(C_BLACK), format(0) {}
InterFace::~InterFace() {}
void InterFace::print(std::string text) {
	std::cout << text << std::endl;
}
void InterFace::printColored(std::string text, char textColor, char bgColor) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	WORD attributes = (bgColor << 4) | textColor;
	SetConsoleTextAttribute(hConsole, attributes);
	std::cout << text << std::endl;
	SetConsoleTextAttribute(hConsole, (C_BLACK << 4) | C_LIGHTGRAY); // Reset to default
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
	
