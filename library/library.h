#ifndef LIBRARY_H
#define LIBRARY_H
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class library
{
private:
	string name;
	string id;
	vector<string> members;
	vector<string> temp;

public:
	library();
	~library();
	void addMember(string name, string id);
	void displayMember();
	string generateID();
	void sortMember();
	void sortMemberId();
	void loadMember();
	int checkMember(string);
	bool sequentialSearch();
	bool checkID(int);
	void deleteMember();
	void rewriteMember();
};

#endif