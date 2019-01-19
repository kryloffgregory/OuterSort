#pragma once
#include <string>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <iostream>
#include <functional> 

class OuterSorter
{
public:
	OuterSorter(const std::string &filenameInput, const std::string &filenameOutput, long long _chunkSize);
	~OuterSorter();
	void doSort();

private:
	bool readChunk(std::ifstream &in, std::vector<std::string> &chunk);
	void writeChunk(std::ofstream &out, const std::vector<std::string> &chunk);
	void mergeChunks();
	const std::string filenameInput;
	const std::string filenameOutput;
	const long long chunkSize;
	int numChunks;
};

