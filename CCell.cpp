#include "CCell.h"

CCell::CCell() {}
CCell::~CCell() {}

void CCell::setName(std::string & name) {
	m_cell_name = name;
}


const std::string&  CCell::getName() const{
	return m_cell_name;
}


void CCell::addPin(CPin & newPin) {
	m_pins.push_back(newPin);
}


void CCell::showCell() const {	
   for(CPin pin:m_pins){
	   pin.showPin();
   }
}


double CCell::getCellArea() const {
	double cellArea=0;
	for (int i=0;i<m_pins.size();++i) {
		cellArea+=m_pins[i].getPinArea();
		std::cout<<"Current Cell Area: "<<cellArea<<std::endl;
	}
	return cellArea;
}


double CCell::getCellAreaMultiProc() const {
    double cellArea=0;
	double pinArea=0;
	for (int i=0;i<m_pins.size();++i) {
		createProcess(pinArea,i);
		cellArea+=pinArea;
		std::cout<<"Current Cell Area: "<<cellArea<<std::endl;
	}
	return cellArea;
}


void CCell::createProcess(double &area,int pinIndex) const{
    int fd[2];
    double pinArea=0;
    pipe(fd);

	if (fork() >0)
	{
		close(fd[1]);
		read(fd[0], &area, sizeof(area));
		std::cout<<"[ "<<getpid()<<"] Parent  received value: "<<area<<std::endl;
		close(fd[0]);
		wait(NULL);
		return;
	}
	else 
	{
		close(fd[0]);
		pinArea =m_pins[pinIndex].getPinArea();
		write(fd[1], &pinArea, sizeof(pinArea));
		std::cout<<"[ "<<getpid()<<"] Child  send value: "<<pinArea<<std::endl;
		close(fd[1]);	
		exit(0);	
	}
}
