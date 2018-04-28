#include "CLEF.h"
#include <iostream>
#include <fstream> 


void CLEF::parse(CDesign * desing)const {
	std::ifstream input(m_file_path);
	std::string line;

	if (!input.is_open()) {
		std::cout << "couldn't open file!!! Wrong path\n";
	}
	while (input >> line)
	{
		if (line == "MACRO") {
			std::cout << "MACRO ";
			CCell newCell;
			detectCell(input, newCell);
			desing->addCell(newCell);
		}
	}
}

void CLEF::detectCell(std::ifstream & stream, CCell & cell)const {
	std::string line;
	stream >> line;
	unsigned count = 1;
	std::cout << line << std::endl;
	cell.setName(line);
	while (stream >> line) {
		if (line == "PIN" | line == "OBS") {
			++count;
			//std::cout << "PIN ";
			CPin newPin;
			detectPin(stream, newPin);
			cell.addPin(newPin);
		}
		else
		{
			if (line == "END") {
				--count;
				//std::cout << "END\n";
				if (!count)
					return;
			}
		}
	}
}

void CLEF::detectPin(std::ifstream & stream, CPin & pin)const {
	std::string line;
	stream >> line;
	double coordinate;

	if (line == "LAYER")
		line = "OBS";
	pin.setName(line);

	while (stream >> line) {
		if (line == "RECT") {
			CRectangle newRectangle;
			CCoordinate ur;
			CCoordinate dl;
			stream >> coordinate;
			dl.setX(coordinate);
			stream >> coordinate;
			dl.setY(coordinate);
			stream >> coordinate;
			ur.setX(coordinate);
			stream >> coordinate;
			ur.setY(coordinate);
			newRectangle.setDL(dl);
			newRectangle.setUR(ur);
			pin.addPolygon(newRectangle);
		}
		else
		{
			if (line == "END") {
				return;
			}
		}
	}

}
