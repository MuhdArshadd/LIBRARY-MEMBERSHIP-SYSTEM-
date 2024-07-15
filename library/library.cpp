#include "library.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <vector>

using namespace std;
vector<string> members;
vector<string> temp;

library::library()
{
}
library::~library()
{
}
void library::addMember(string name, string id)
{
    fstream file("members.txt", ios::app);
    if (!file) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }
    cout << "Enter member's name: ";
    cin.ignore();
    getline(cin, name);
    file << name << endl;
    srand(static_cast<unsigned>(time(0)));
    id = generateID();
    cout << "Member ID: " << id << endl;
    file << id << endl;
    file.close();
    cout << "Member added successfully" << endl << endl;
}
string library::generateID()
{
    string id;
    bool idExist;
    do {
        // Generate uppercase letter (M)
        id = "M";

        // Generate a random 4-digit number (0000 - 9999)
        int num = 1000 + rand() % (9999 - 1000 + 1);
        id += to_string(num);
        idExist = checkID(num);
    } while (idExist);
    return id;
}
bool library::checkID(int num)
{
    ifstream file("members.txt");
    string line;
    string check = "M" + num;
    while (getline(file, line)) {
        if (line == check)
        {
            return true;
        }
        else
            return false;
    }

}
void library::displayMember()
{
    ifstream file("members.txt");
    if (!file) {
        cout << "No members file found. Starting with an empty library.\n";
        return;
    }
    string line;
    cout << left << setw(20) << "Name:" << left << setw(40) << "Member ID : " << endl;
    int i = 0; //count
    while (getline(file, line)) {
        i++;
        cout << left << setw(20) << line << left;
        if (i % 2 == 0) {
            cout << endl;
        }
        else {
        }
    }
    file.close();
}

void library::loadMember()
{
    ifstream file("members.txt");
    if (!file) {
        cout << "File not found" << endl;
    }

    string line;
    int i = 0;
    members.clear();
    temp.clear();
    while (getline(file, line)) {
        if (i % 2 == 0)
            members.push_back(line);
        else
            temp.push_back(line);
        i++;
    }


}

int library::checkMember(string name)
{
    string line;
    int i = 1;

    ifstream file("members.txt");
    while (getline(file, line)) {
        //check sorted name is on line number
        if (name == line) {
            return i;
        }
        else {
            i++;
        }
    }
    return 0;
}

void library::sortMember()
{
    loadMember();
    sort(members.begin(), members.end());

    for (int i = 0; i < members.size(); i++) {

        cout << left << setw(20) << members[i] << left;

        int number = ((checkMember(members[i]) + 1) / 2) - 1;
        cout << temp[number];
        cout << endl;
    }
}
void library::sortMemberId()
{

    loadMember();
    sort(temp.begin(), temp.end());
    for (int i = 0; i < temp.size(); i++) {
        cout << left << setw(20) << left;
        int number = ((checkMember(temp[i]) / 2) - 1);
        cout << members[number];
        cout << left << setw(20) << temp[i] << left;
        cout << endl;
    }
}
bool library::sequentialSearch() 
{
    string fileName = "members.txt"; // Replace with your file name
    string searchData; // Replace with the data you want to search for
    cout << "Search member ID (M####): ";
    cin.ignore();
    getline(cin, searchData);


    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        bool found = false;
        string name;

        while (getline(file, line)) //read text file
        {


            if (line.find(searchData) != string::npos) //compare the input with the current text file line 
            {
                cout << "Data found in the file." << endl;
                cout << "Member name : " << name << " ID: " << line << endl;

                found = true;
                break;
            }
            else { //if the not true
                name = line;
            }
        }

        file.close();

        if (!found) {

            cout << "Data not found in the file." << endl;

        }

    }
    return false;
}
void library::deleteMember()
{

    string targetid, line;
    cout << "Enter the Member ID to be delete : ";
    cin >> targetid;
    if (checkMember(targetid) == 0) // check if Member ID entered exist or not
    {
        cout << "\nMemberID does not exist.\n";
    }
    else
    {
        ifstream file1("members.txt");
        ofstream file2("temporary.txt");
        int d_line1 = checkMember(targetid);
        int d_line2 = checkMember(targetid) - 1;

        while (getline(file1, line)) {


            if (checkMember(line) == d_line2 || checkMember(line) == d_line1) {
                //ignore the line that want to be deleted ( name and id line )
            }
            else {
                file2 << line << endl; // store new memberlist into a temporary.txt
            }
        }
        rewriteMember();
        file1.close();
        file2.close();
    }
}

void library::rewriteMember()
{
    ifstream file1("temporary.txt");
    ofstream file2("members.txt");
    string line;

    while (getline(file1, line))
    {
        file2 << line << endl;  // rewrite the members.txt file with a new memberlist from temporary.txt
    }
    cout << endl << "MemberID successfully deleted." << endl << endl;
    file1.close();
    file2.close();
}