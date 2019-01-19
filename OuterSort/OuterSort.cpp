#include <iostream>
#include <fstream>
#include "OuterSorter.h"

int main(int argc, char **argv) {
	std::string fileIn;
	std::string fileOut;
	if (argc < 4) {
		std::cout << "Not enought command line parameters" << std::endl;
		return 0;
	}
	int numChunks;
	numChunks = std::atoi(argv[3]);
	if (numChunks <= 0) {
		std::cout << "Not correct number of chunks" << std::endl;
		return 0;
	}
	OuterSorter sorter(std::string(argv[1]), std::string(argv[2]), 1000);
	sorter.doSort();

	return 0;
}