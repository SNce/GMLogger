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

void Project::getList(char* type)
{
	char* path;
	xml_document<> _resources;

	list<char*>* lst;
	
	if(!strcmp(type, "obj"))
	{
		lst = &this->objList;
		path = getPath("Objects\\_resources.list.xml");
	}
	else if(!strcmp(type, "spr"))
	{
		lst = &this->sprList;
		path = getPath("Sprites\\_resources.list.xml");
	}
	else if(!strcmp(type, "bg"))
	{
		lst = &this->bgList;
		path = getPath("Backgrounds\\_resources.list.xml");
	}
	else if(!strcmp(type, "room"))
	{
		lst = &this->roomList;
		path = getPath("Rooms\\_resources.list.xml");
	}
	else if(!strcmp(type, "sound"))
	{
		lst = &this->soundList;
		path = getPath("Sounds\\_resources.list.xml");
	}

	parseXML(_resources, path);

	for(xml_node<>* node = _resources.first_node()->first_node();
			node;
			node = node->next_sibling())
	{
		xml_attribute<>* name = node->first_attribute();
		lst->push_back(name->value());
	}
}
