#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Tree.h"
using namespace std;

int main()
{
    Tree a;
    string st,en;
    int c=0;
    int b=0;
    while(c!=11){
        cout << "======Main Menu======" << endl;
        cout << "1. Add Node" << endl;
        cout << "2. Delete Node" << endl;
        cout << "3. Print Chain of Command" << endl;
        cout << "4. Change Order of Subordinates" << endl;
        cout << "5. Assign Employee Levels" << endl;
        cout << "6. Find an Empoyee's Level" << endl;
        cout << "7. List Employees by Level" << endl;
        cout << "8. Count Number of Employees" << endl;
        cout << "9. Promote an Employee" << endl;
        cout << "10. Count Employees at Certain Level" << endl;
        cout << "11. Quit" << endl;
        cin>>c;
        if(c==1){
            cout << "Enter a new employee:" << endl;
            getline(cin,st);
            getline(cin,st);
            cout << "Enter their manager:" << endl;
            getline(cin,en);
            a.AddNode(st,en);
            a.CreateSearchTree();

        }
        if(c==2){
            cout << "Enter an employee to remove:" << endl;
            getline(cin,st);
            getline(cin,st);
            a.DeleteNode(st);
            a.CreateSearchTree();
        }
        if(c==3){
            cout << "Enter an employee:" << endl;
            getline(cin,st);
            getline(cin,st);
            a.ChainOfCommand(st);
        }
        if(c==4){
            cout << "Enter an employee to shift:" << endl;
            getline(cin,st);
            getline(cin,st);
            cout << "Enter their new left neighbor (or NULL):" << endl;
            getline(cin,en);
            a.ShiftChildren(st,en);
            a.CreateSearchTree();
        }
        if(c==5){
            a.AssignLevels();
        }
        if(c==6){
            cout << "Enter an employee:" << endl;
            getline(cin,st);
            getline(cin,st);
            a.FindLevel(st);
        }
        if(c==7){
            a.BFT();
        }
        if(c==8){
            a.CountEmployees();
        }
        if(c==9){
            cout << "Enter an employee:" << endl;
            getline(cin,st);
            getline(cin,st);
            a.Promote(st);
            a.CreateSearchTree();
        }
        if(c==10){
            cout << "Enter a level to count:" << endl;
            cin>>b;
            if(b!=1){
                a.EmployeesAtLevel(b);
            }
            else{
                cout<<"There is 1 employee at level 1"
            }
        }
    }
    cout<<"Goodbye!"<<endl;
    return 0;
}
