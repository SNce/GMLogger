#include <rapidxml\rapidxml.hpp>
#include <direct.h>

#include "project.h"
#include "xmlreader.h"

using namespace rapidxml;

int main(int args, char** argv)
{
	Project* project = new Project();
	project->getObjList();
}