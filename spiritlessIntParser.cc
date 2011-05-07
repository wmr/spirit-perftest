// ===========================================================================
// spiritlessIntParser.cc
//
// Simple integer parser using boost::spirit.
// The intended usage is performance comparison.
//
// Copyright 2011 wmr. All rights reserved.
// ===========================================================================

// std::
#include <string>
#include <fstream>
#include <vector>
#include <iostream>

// boost::format::
#include <boost/format.hpp>

// 
// Entry point
//////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	std::string fname;
	if (argc > 1) {
		fname = std::string(argv[1]);
	}
	else {
		return 1;
	}

	std::vector<int> vect;

	std::ifstream ifs(fname.c_str());
	std::string line;

	while (getline(ifs, line)) {
		int a,b;
		sscanf(line.c_str(), "%d,%d",&a,&b);
		vect.push_back(a);
		vect.push_back(b);
	}
	std::cout << boost::format("parsed %d integers from %s")
			% vect.size() % fname << std::endl;
	
}

