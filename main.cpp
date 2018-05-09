#include <iostream>
#include <string>
#include <vector>
#include "CLEF.h"


bool has_suffix(const std::string &str, const std::string &suffix) {
	unsigned pos = str.find_last_of('\\');
	std::cout << pos << " " << str.substr(pos + 1).size() - suffix.size() << std::endl;
	return str.substr(pos+1).size() - suffix.size()>=2 &&
		str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
}


int main(int argc, char *argv[]) {

	if (argc > 1) {
		CDesign* design_ptr1 = new CDesign();
		for (int i = 1; i < argc; ++i) {
			if (has_suffix(argv[i], "lef")) {
					CLEF lef_file(argv[i]);
				    lef_file.parse(design_ptr1);
			}
			else {
				std::cout <<argv[i]<<" FILE HAS WRONG FILE FORMAT"<< std::endl;
			}
		}

		double cellArea=design_ptr1->getAreaByCellName("MDN_FSDPQ_4");
		std::cout<<"Area: "<<cellArea<<std::endl;
		delete design_ptr1;
	}

	else {
		std::cout << "THE LEF/DEF FILES WEREN'T FOUND" << std::endl;
	}

	return 0;

}
