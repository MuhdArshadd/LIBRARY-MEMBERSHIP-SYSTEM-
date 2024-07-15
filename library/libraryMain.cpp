#include <iostream>
#include "library.h"
using namespace std;
int main()
{
    library Lib;
    string name;
    string id;
    int choice;
    int sort;

    do {
        system("cls");
        cout << "------------------- Library Membership System -------------------\n";
        cout << "1. Add Member\n";
        cout << "2. Display Members\n";
        cout << "3. Search Member\n";
        cout << "4. Sort Member\n";
        cout << "5. Remove Member\n";
        cout << "6. Exit\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "\nAdding Member\n*****" << endl;
            Lib.addMember(name, id);
            system("pause");
            break;
        }
        case 2: {
            cout << "\nMember List\n********" << endl;
            Lib.displayMember();
            system("pause");
            break;
        }
        case 3: {
            Lib.sequentialSearch();
            system("pause");
            break;
        }

        case 4: {
            cout << "1. Sort by Name" << endl;
            cout << "2. Sort by ID" << endl;
            cout << "Choose 1 or 2: ";
            cin >> sort;
            cout << "\nMember List\n********" << endl;
            if (sort == 1)
                Lib.sortMember();
            else if (sort == 2)
                Lib.sortMemberId();
            system("pause");
            break;
        }
        case 5: {
            Lib.deleteMember();
            system("pause");
            break;
        }
        case 6: {
            cout << "\n\n****PROGRAM TERMINATED****\n\n";
            exit(0);
            break;
        }
        default: {
            cout << "Invalid choice. Please try again.\n";
            system("pause");
            break;
        }
        }

        cout << "\n";
    } while (choice != 6);

    return 0;
}