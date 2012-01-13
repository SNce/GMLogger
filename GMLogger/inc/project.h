#ifndef _PROJECT_
#define _PROJECT_

#include <list>
#include <fstream>

#define OUT_FILE "output_log.txt"

using namespace std;

class Project
{
private:
	char* projectName;
	ofstream logFile;
	bool noFileFlag;

	list<char*> objList;
	list<char*> sprList;
	list<char*> bgList;
	list<char*> roomList;
	list<char*> soundList;

protected:
	void _getList(char* type);
	void _writeList(char* type, ofstream& stream);

public:
	Project();

	bool checkLogFile();
	void getResources();
	void writeResources();

	static void directoryCheck();
	void reportError(char* type);
};

#endif
