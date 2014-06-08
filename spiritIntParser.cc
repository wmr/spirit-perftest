// ===========================================================================
// spiritIntParser.cc
//
// Simple integer parser using boost::spirit.
// The intended usage is performance comparison.
//
// Copyright 2011 wmr. All rights reserved.
// ===========================================================================

// std::
#include <cstdio>
#include <string>
#include <fstream>
#include <vector>
// boost::format::
#include <boost/format.hpp>
// boost::spirit::
#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>

// namespace shortcuts
namespace sp    = boost::spirit;
namespace qi    = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace ph    = boost::phoenix;

//
// Spirit parser for comma separated integers
//////////////////////////////////////////////////////

template <typename Iterator>
bool parse_numbers(Iterator first, Iterator last, std::vector<int>& vect)
{
	// This makes the grammar much more readable
	using qi::int_;
	using qi::phrase_parse;
	using qi::_1;
	using ascii::space;
	using ph::push_back;

	bool ret = qi::phrase_parse(
					first,
					last,

					// Grammar
					(
						// another syntax:
                        // int_[push_back(ref(vect), _1)] >> *( ',' >> int_)
						int_[push_back(ph::ref(vect), _1)] % ','
					),
					space
			);

	if (first != last) {
		return false;
    }

	return ret;
}

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
		return -1;
	}

	std::vector<int> vect;
	std::ifstream ifs(fname.c_str());
	std::string line;

	while (getline(ifs, line)) {
		parse_numbers(line.begin(),line.end(),vect);
	}

	std::cout << boost::format("parsed %d integers from %s")
				% vect.size() % fname
			  << std::endl;
}

