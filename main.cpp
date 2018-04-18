#include "CLEF.h"



int main(int argc, char *argv[]) {
	CDesing *design = new CDesing();
	CLEF lef_file(argv[1]);
	lef_file.parse(design);

	delete design;
}