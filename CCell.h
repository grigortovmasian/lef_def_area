#ifndef CCELL__H
#define CCELL__H

#include "CPin.h"
#include <string>
#include<sys/types.h>
#include<sys/wait.h>
#include <unistd.h>

class CCell {
public:
	CCell();
	~CCell();

	void setName(std::string &);
	const std::string& getName() const;
    void showCell() const; 
	void addPin(CPin &);
	double getCellArea() const;
	double getCellAreaMultiProc() const;
	void createProcess(double &,int) const;

private:
	std::string m_cell_name;
	std::vector<CPin> m_pins;
};

#endif
