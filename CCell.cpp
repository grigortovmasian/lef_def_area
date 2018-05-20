#include "CCell.h"


CCell::CCell() {}

CCell::~CCell() {}

void CCell::setName(std::string & name) {
    m_cell_name = name;
}

const std::string&  CCell::getName() const{
    return m_cell_name;
}

void  CCell::addLayer(CLayer & newLayer){
    m_layers.push_back(newLayer);
}

CLayer&  CCell::getLayer(const std::string& layerName){
    for (int i = 0; i < m_layers.size(); ++i) {
        if (m_layers[i].getName() == layerName)
            return m_layers[i];
    }
    CLayer layer = CLayer();
    layer.setName(layerName);
    m_layers.push_back(layer);
    return m_layers[m_layers.size() - 1];
}

double  CCell::getCellArea() const {
    double cellArea = 0;
    for (int i = 0; i < m_layers.size(); ++i) {
        cellArea += m_layers[i].area();
    }
    return cellArea;
}


double CCell::getCellOverlapArea() {
	std::vector<polygon> p_vec;
	polygon p1 = m_layers[0].getPolygon();
	p_vec.push_back(p1);
	for (int i = 1; i < m_layers.size(); ++i){
		m_layers[i].overlapArea();
		p_vec = std::vector<polygon>();
		polygon p2 = m_layers[i].getPolygon();
		boost::geometry::union_(p1, p2, p_vec);

		BOOST_FOREACH(polygon const& p, p_vec){
			p1 = p;
		}
	}
	double overlap_area = 0;
	BOOST_FOREACH(polygon const& p, p_vec){
		overlap_area = boost::geometry::area(p);
	}
	return overlap_area;
}



double CCell::getCellAreaMultiProc() const {
    double cellArea=0;
	double layerArea=0;
	for (int i=0;i<m_layers.size();++i) {
		createProcess(layerArea,i);
		cellArea+=layerArea;
	}
	return cellArea;
}



void CCell::createProcess(double &area,int layerIndex) const{
    int fd[2];
    double layerArea=0;
    pipe(fd);

	if (fork() >0){
		close(fd[1]);
		read(fd[0], &area, sizeof(area));
		close(fd[0]);
		wait(NULL);
		return;
	}
	else {
		close(fd[0]);
		layerArea =m_layers[layerIndex].area();
		write(fd[1], &layerArea, sizeof(layerArea));
		close(fd[1]);	
		exit(0);	
	}
}



