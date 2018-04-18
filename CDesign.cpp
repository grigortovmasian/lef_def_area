#include "CDesign.h"

CDesing::CDesing() {};

CDesing::~CDesing() {};

void CDesing::addCell(CCell & newCell) {
	m_design.push_back(newCell);
}