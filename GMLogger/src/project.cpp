#include "project.h"
#include "xmlreader.h"

#include <direct.h>
#include <string>

using namespace rapidxml;

inline char* getPath(char* folder)
{
	char* path;
	path = _getcwd(NULL, 256);
	string pathStr(path);

#ifdef _DEBUG
	pathStr += "\\..\\Debug\\Project\\";
#else
	pathStr += "\\Project\\";
#endif
	pathStr += folder;

	char* pathText = new char[pathStr.size() + 1];
	copy(pathStr.begin(), pathStr.end(), pathText);
	pathText[pathStr.size()] = '\0';

	return pathText;
}

Project::Project()
{
}

void Project::getObjList()
{
	char* path;
	path = getPath("Objects\\_resources.list.xml");
	xml_document<> obj_resources;
	parseXML(obj_resources, path);

	for(xml_node<>* node = obj_resources.first_node()->first_node();
			node;
			node = node->next_sibling())
	{
		xml_attribute<>* name = node->first_attribute();
		this->objList.push_back(name->value());
	}
}