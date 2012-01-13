#include "xmlreader.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace rapidxml;

int parseXML(xml_document<>& doc, char* filename)
{
	char* docText;

	std::string buffer;
	std::string line;

	std::ifstream file;

	file.open(filename, std::ios::in);
	if(file.is_open())
	{
		while(getline(file, line))
			buffer += line;
	}
	else
	{
		file.close();
		return -1;
	}

	file.close();
	
	docText = new char[buffer.size() + 1];
	copy(buffer.begin(), buffer.end(), docText);
	docText[buffer.size()] = '\0';

	doc.parse<0>(docText);
	return 1;
}