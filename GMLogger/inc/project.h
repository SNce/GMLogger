#ifndef _PROJECT_
#define _PROJECT_

#include <list>

using namespace std;

class Project
{
private:
	char* projectName;
	list<char*> objList;
	list<char*> sprList;
	list<char*> bgList;
	list<char*> roomList;
	list<char*> soundList;
public:
	Project();
	void getList(char* type);
};

#endif
