#include <iostream>
#include <string>
#include <vector>
#include <fstream> 

//#include <ifstream>

//structures and classes

class CCoordinate {
public:
	CCoordinate() {}
	~CCoordinate() {}

	void setX(double x) {
		m_x = x;
	}

	void setY(double y) {
		m_y = y;
	}

	double getX()const {
		return m_x;
	}

	double getY()const {
		return m_y;
	}

private:
	 double m_x;
	 double m_y;
};

class CRectangle {
public:
	CRectangle() {}
	~CRectangle() {}

	void setName(std::string & name) {
		m_layer_name = name;
	}

	void setDL(CCoordinate & dl) {
		m_dl = dl;
	}

	void setUR(CCoordinate & ur) {
		m_ur = ur;
	}

private:
	 std::string m_layer_name;
	 CCoordinate m_dl;
	 CCoordinate m_ur;
};

class CPin {
public:
	CPin() {}
	~CPin() {}

	void setName(std::string & name) {
		m_pin_name = name;
	}

	void addPolygon(CRectangle & newItem) {
		m_polygons.push_back(newItem);
	}

private:
	std::string m_pin_name;
	std::vector<CRectangle> m_polygons;
};

class CCell {
public:
	CCell() {}
	~CCell() {}

	void setName(std::string & name) {
		m_cell_name = name;
	}

	void addPin(CPin & newPin) {
		m_pins.push_back(newPin);
	}

private:
	std::string m_cell_name;
	std::vector<CPin> m_pins;
};

class CDesing {
public:
	CDesing() {};
	~CDesing() {};

	void addCell(CCell & newCell) {
		m_design.push_back(newCell);
	}
protected:
	std::vector <CCell> m_design;
};

class CLEF_file {
public:
	CLEF_file() {}
	CLEF_file(const std::string & path):m_file_path(path) {}
	inline ~CLEF_file() {};
	
	void setName(std::string & path) {
		m_file_path = path;
	}

	void parse(CDesing *)const;
	void detectCell(std::ifstream &, CCell &)const;
	void detectPin(std::ifstream &, CPin &)const;
private:
	 std::string m_file_path;
};


void CLEF_file::parse(CDesing * desing)const {
	std::ifstream input(m_file_path);
	std::string line;

	if (!input.is_open()) {
		std::cout << "couldn't open file!!! Wrong path\n";
	}
	while (input>>line)
	{
		if (line == "MACRO") {
			std::cout << "MACRO ";
			CCell newCell;
			detectCell(input, newCell);
			desing->addCell(newCell);
		}
	} 		
}

void CLEF_file::detectCell(std::ifstream & stream, CCell & cell)const {
	std::string line;
	stream >> line;
	unsigned count = 1;
	std::cout << line << std::endl;
	cell.setName(line);
	while (stream >> line) {
		if (line == "PIN" | line =="OBS") {
			++count;
			std::cout << "PIN ";
			CPin newPin;
			detectPin(stream, newPin);
			cell.addPin(newPin);
		}
		else
		{
			if (line == "END") {
				--count;
				std::cout << "END\n";
				if (!count)  
					return;
			}
		}
	}
}

void CLEF_file::detectPin(std::ifstream & stream, CPin & pin)const {
	std::string line;
	stream >> line;

	double coordinate;
	

	if (line == "LAYER")
		line = "OBS";
	pin.setName(line);
	
	std::cout << line << std::endl;

	while (stream >> line) {
		if (line == "RECT") {
			std::cout << "RECT";
			CRectangle newRectangle;
			CCoordinate ur;
			CCoordinate dl;
			stream >> coordinate;
			std::cout << coordinate;
			dl.setX(coordinate);
			stream >> coordinate;
			std::cout << coordinate;
			dl.setY(coordinate);
			stream >> coordinate;
			std::cout << coordinate;
			ur.setX(coordinate);
			stream >> coordinate ;
			std::cout << coordinate << std::endl;
			ur.setY(coordinate);
	
			newRectangle.setDL(dl);
			newRectangle.setUR(ur);
		}
		else
		{
			if (line == "END") {
				std::cout<<"END\n";
				return;
			}
		}
	}

}

int main(int argc, char *argv[]) {
	CDesing *design = new CDesing();
	CLEF_file lef_file(argv[1]);
	lef_file.parse(design);

	delete design;
}