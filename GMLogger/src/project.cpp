#include "project.h"
#include "xmlreader.h"

#include <iostream>
#include <direct.h>
#include <string>

using namespace rapidxml;

/*************
getPath(char* arg) 
arg = "" returns the path of the current working directory.
arg = "folder" returns path to current working directory/folder.
arg = "filename" returns path to file in current working directory.
*************/
inline char* getPath(char* folder)
{
	char* path;
	path = _getcwd(NULL, 256);
	string pathStr(path);

#ifdef _DEBUG
	pathStr += "\\..\\Debug";
#endif

	pathStr += "\\";
	pathStr += folder;

	char* pathText = new char[pathStr.size() + 1];
	copy(pathStr.begin(), pathStr.end(), pathText);
	pathText[pathStr.size()] = '\0';

	return pathText;
}

Project::Project()
{
	char* filePath = getPath(OUT_FILE);
	this->logFile.open(filePath, ios::in);

	// If file doesnt exist write a new logfile.
	if(!logFile.is_open())
	{
		this->noFileFlag = true;
		this->logFile.close();
	}
	else
	{
		//@Todo: read existing logfile.
		this->noFileFlag = false;
		this->logFile.close();
	}
}

bool Project::checkLogFile()
{
	return this->noFileFlag;
}

void Project::_getList(char* type)
{
	char* path;
	xml_document<> _resources;

	list<char*>* lst;
	
	if(!strcmp(type, "obj"))
	{
		lst = &this->objList;
		path = getPath("Project\\Objects\\_resources.list.xml");
	}
	else if(!strcmp(type, "spr"))
	{
		lst = &this->sprList;
		path = getPath("Project\\Sprites\\_resources.list.xml");
	}
	else if(!strcmp(type, "bg"))
	{
		lst = &this->bgList;
		path = getPath("Project\\Backgrounds\\_resources.list.xml");
	}
	else if(!strcmp(type, "room"))
	{
		lst = &this->roomList;
		path = getPath("Project\\Rooms\\_resources.list.xml");
	}
	else if(!strcmp(type, "sound"))
	{
		lst = &this->soundList;
		path = getPath("Project\\Sounds\\_resources.list.xml");
	}

	if(parseXML(_resources, path) == -1)
	{
		reportError(type);
	}

	for(xml_node<>* node = _resources.first_node()->first_node();
			node;
			node = node->next_sibling())
	{
		xml_attribute<>* name = node->first_attribute();
		lst->push_back(name->value());
	}
}

void Project::_writeList(char* type, ofstream& stream)
{
	list<char*>* lst;
	
	if(!this->objList.empty() && !strcmp(type, "obj"))
	{
		lst = &this->objList;
		stream<<"Objects:\n";
	}
	else if(!this->sprList.empty() && !strcmp(type, "spr"))
	{
		lst = &this->sprList;
		stream<<"Sprites:\n";
	}
	else if(!this->bgList.empty() && !strcmp(type, "bg"))
	{
		lst = &this->bgList;
		stream<<"Backgrounds:\n";
	}
	else if(!this->roomList.empty() && !strcmp(type, "room"))
	{
		lst = &this->roomList;
		stream<<"Rooms:\n";
	}
	else if(!this->soundList.empty() && !strcmp(type, "sound"))
	{
		lst = &this->soundList;
		stream<<"Sounds:\n";
	}

	list<char*>::iterator it;
	for(it = lst->begin(); it != lst->end(); it++)
		stream<<"\t"<<*it<<std::endl;

	stream<<std::endl;
}

void Project::getResources()
{
	_getList("obj");
	_getList("spr");
	_getList("bg");
	_getList("room");
	_getList("sound");
}

void Project::writeResources()
{
	char* path;
	path = getPath(OUT_FILE);
	this->logFile.open(path, std::ios::out);
	this->logFile<<"Resources\n---------\n\n";
	
	_writeList("obj", logFile);
	_writeList("spr", logFile);
	_writeList("bg", logFile);
	_writeList("room", logFile);
	_writeList("sound", logFile);
}

void Project::directoryCheck()
{
	char* path;
	path = getPath("Project\\Global Game Settings.xml");
	ifstream file;
	file.open(path, std::ios::in);
	if(file.is_open())
	{
		file.close();
		return;
	}
	std::cout<<"Error: Could not find the Project folder.Please run gmksplit.exe and generate a Project folder"<<std::endl;
	exit(1);
}

void Project::reportError(char* type)
{
	std::cout<<"Error loading type: "<<type<<std::endl;
}
