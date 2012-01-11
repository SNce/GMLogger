#ifndef _XML_READER_
#define _XML_READER_

#include <rapidxml/rapidxml.hpp>

using namespace rapidxml;

// Parse a given XML document to form a DOM tree.
void parseXML(xml_document<>& doc, char* filename);

// Returns a node of given name.


#endif