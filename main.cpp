#include <iostream>
#include "binary.h"
#include <cstring>
#include <string>
#include "qrcodegen.hpp"
#include "generator.h"

bool verbose = false;

int main() {

	std::vector<BYTE> fileData = readFile("sunset.txt");

	int b = fileData.size();
	if (verbose) {
		for (int i=0;i < b;i++){
			std::cout << fileData[i] << std::endl;
		}
	}
	std::cout<<fileData.size()<<std::endl;
	
	int code_count = (b / 1000)+1;
	std::cout<<code_count;
	std::cout<< " codes needed"<<std::endl;
	
	int codes;
	int current = 0;
	int code = 0;
	int size = 1000;
	std::vector<BYTE> content = {};
	for (int i = 0;i <= b;++i) {
		++current;
		content.push_back(fileData[i]);
		
		if (current > size -1 or i == b-1) {
			current = 0;
			/*split the text every 1000 chars and save out*/
			std::string s = "codes/" + std::to_string(code)+".svg";
			
			/*byte vector to char**/
			std::vector<unsigned char> v = content;
			char *res;
			res = new char[v.size() + 1]; // +1 for the final 0
			res[v.size() + 1] = 0; // terminate the string
			for (size_t i = 0; i < v.size(); ++i) {
			  res[i] = v[i];
			}
			std::copy(v.begin(), v.end(), res);
			
			std::string svg = toQR(res);
			
			/*string to unsigned byte vector*/
			std::vector<BYTE> myVector;
			const char* str = svg.c_str();
			myVector.assign( str, str+strlen(str) );

			writeFile(myVector,s.c_str());			
			
			std::cout<<code+1;std::cout<<" of ";std::cout<<code_count<<std::endl;
			content.clear();
			++code;
		}

	}
	
	writeFile(fileData,"new.txt");
	std::cout<<"done."<<std::endl;
	return 0;
	
	
}