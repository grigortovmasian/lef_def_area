#ifndef CCELL_H
#define CCELL_H

#include <iostream>
#include <string>
#include <vector>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "CLayer.h"

class CCell {

public:
	CCell();
	~CCell();
	void setName(std::string &);
	const std::string& getName() const;
	void addLayer(CLayer & newLayer);
	CLayer& getLayer(const std::string &);
	void printNames();
	double getCellArea() const;
	double getCellAreaMultiProc() const;
	double getCellOverlapArea();
	double getCellOverlapAreaMultiProc();
private:
	void createProcess(double &, int) const;
	void createProcessWithOverlap(CLayer&);
	std::string m_cell_name;
	std::vector<CLayer> m_layers;

};

#endif