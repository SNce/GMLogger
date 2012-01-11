#include <rapidxml\rapidxml.hpp>

#include "project.h"
#include "xmlreader.h"

int main(int args, char** argv)
{
	Project* project = new Project();
	project->getList("obj");
	project->getList("spr");
	project->getList("bg");
	project->getList("room");
	project->getList("sound");
}