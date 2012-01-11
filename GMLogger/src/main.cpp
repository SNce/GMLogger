#include <rapidxml\rapidxml.hpp>
#include <direct.h>

#include "project.h"
#include "xmlreader.h"

using namespace rapidxml;

int main(int args, char** argv)
{
	Project* project = new Project();
	project->getList("obj");
	project->getList("spr");
	project->getList("bg");
	project->getList("room");
	project->getList("sound");
	std::cout<<"over";
}