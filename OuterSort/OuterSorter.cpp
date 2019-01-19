#include "OuterSorter.h"




OuterSorter::OuterSorter(const std::string & _filenameInput, const std::string & _filenameOutput, long long _chunkSize) : 
	filenameInput(_filenameInput), filenameOutput(_filenameOutput), chunkSize(_chunkSize), numChunks(0)
{
}

OuterSorter::~OuterSorter()
{
}

bool OuterSorter::readChunk(std::ifstream &in, std::vector<std::string> &chunk) {
	std::string curString;
	chunk.clear();
	while (chunk.size() < chunkSize && in >> curString ) {
		chunk.push_back(curString);
	}
	return !chunk.empty();
}

void OuterSorter::writeChunk(std::ofstream & out, const std::vector<std::string>& chunk)
{
	for (auto str : chunk) {
		out << str << std::endl;
	}
}

void OuterSorter::doSort() {
	std::ifstream fin(filenameInput);
	std::vector<std::string> curChunk;
	while (readChunk(fin, curChunk)) {
		numChunks++;
		std::sort(curChunk.begin(), curChunk.end());
		std::ofstream curOut("chunk" + std::to_string(numChunks-1) + ".txt");
		writeChunk(curOut, curChunk);
		curOut.close();
	}
	fin.close();
	mergeChunks();
}

void OuterSorter::mergeChunks() {
	std::ofstream outStream(filenameOutput);
	std::priority_queue<std::pair<std::string, int>,std::vector<std::pair<std::string, int>>, std::greater<std::pair<std::string, int>>> queue;
	std::vector<std::ifstream *> inStreams(numChunks);
	for (int i = 0; i < numChunks; ++i) {
		inStreams[i] = new std::ifstream("chunk" + std::to_string(i) + ".txt");
		std::string firstStr;
		(*inStreams[i]) >> firstStr;
		queue.push(std::make_pair(firstStr, i));
	}
	while (!queue.empty()) {
		auto minElem = queue.top();
		queue.pop();
		outStream << minElem.first << std::endl;
		int chunkNumber = minElem.second;
		std::string stringToAdd;
		if ((*inStreams[chunkNumber]) >> stringToAdd) {
			queue.push(std::make_pair(stringToAdd, chunkNumber));
		}
	}
	for (auto stream : inStreams) {
		stream->close();
		delete stream;
	}
	outStream.close();
}