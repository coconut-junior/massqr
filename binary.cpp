#include "binary.h"
#include <fstream>
#include <vector>
#include <iostream>
#include <string>

std::vector<BYTE> readFile(const char* filename)
{
    // open the file:
    std::streampos fileSize;
    std::ifstream file(filename, std::ios::binary);

    // get its size:
    file.seekg(0, std::ios::end);
    fileSize = file.tellg();
    file.seekg(0, std::ios::beg);

    // read the data:
    std::vector<BYTE> fileData(fileSize);
    file.read((char*) &fileData[0], fileSize);
    return fileData;
}

void writeFile(std::vector<BYTE> data, const char* filename) {

	std::ofstream textout(filename, std::ios::out | std::ios::binary);
	textout.write((const char*)&data[0], data.size());
	textout.close();  
}