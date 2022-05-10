#include <vector>
#include <fstream>
typedef unsigned char BYTE;
std::vector<BYTE> readFile(const char* filename);
void writeFile(std::vector<BYTE> data,const char* filename);