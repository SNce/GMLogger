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
	list<char*> sounds;
public:
	Project();
	void getObjList();
	void getSprList();
	void getBgList();
	void getRoomList();
	void getSoundList();
};

#endif
