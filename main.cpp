#include <vector>
#include <stdlib.h>
#include "CLEF_File.h"
#include "CDEF_File.h"


bool has_suffix(const std::string &str, const std::string &suffix) {
	unsigned pos = str.find_last_of('\\');
	return str.substr(pos+1).size() - suffix.size()>=2 &&
		str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}


int main(int argc, char *argv[]) {

	if (argc > 1) {
		CDesign* designPtr = new CDesign();
		unsigned lefFileCount=0;
		unsigned defFileCount=0;
		CLEF_File lefFile;
		CDEF_File defFile;
		std::string defFilePath="";

		for (int i = 1; i < argc; ++i) {
			if (has_suffix(argv[i], "lef")) {
			        lefFile.setFilePath(argv[i]);
				    lefFile.parse(designPtr);
					++lefFileCount;
			}
            else if (has_suffix(argv[i], "def")) {
				    defFile.setFilePath(argv[i]);
					defFile.parse();
					++defFileCount;
			}
			else {
				std::cout <<argv[i]<<" FILE HAS WRONG FILE FORMAT"<< std::endl;
			}
		}

		if (lefFileCount>=1 && defFileCount>=1) {
			std::string topCell=defFile.getTopCellName();
			std::cout<<"Top cell is: "<<topCell<<std::endl;
			std::cout<<"Calculating area..."<<std::endl;
			double cellArea=designPtr->getAreaByCellName(topCell);
			std::cout<<"Top cell area [ with overlap calculation ] = "<<cellArea<<std::endl;
		}

		delete designPtr;
	}

	else {
		std::cout << "THE LEF/DEF FILES WEREN'T FOUND" << std::endl;
	}

	return 0;

}
