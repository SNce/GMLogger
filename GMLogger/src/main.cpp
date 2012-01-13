#include <rapidxml\rapidxml.hpp>

#include "project.h"
#include "xmlreader.h"
#include <iostream>

int main(int args, char** argv)
{
	// Check if the "Project" directory is present.
	Project::directoryCheck();
	Project* project = new Project();
	project->getResources();
	project->writeResources();
	return 0;
}