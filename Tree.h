#ifndef TREE_H
#define TREE_H
#include <iostream>
using namespace std;
    struct node{
    node *parent=NULL;
    node *child=NULL;
    node *right=NULL;
    node *left=NULL;
    node *searchParent=NULL;
    node *searchLeft=NULL;
    node *searchRight=NULL;
    string key="";
    int level=-1;
    };
class Tree
{

    public:
        Tree();
        void AddNode(string name,string parent);
        void CreateSearchTree();
        void DeleteNode(string name);
        void ChainOfCommand(string name);
        void ShiftChildren(string name,string newChild);
        void AssignLevels();
        void FindLevel(string name);
        void BFT();
        void CountEmployees();
        void Promote(string name);
        void EmployeesAtLevel(int l);
        virtual ~Tree();
    protected:
    private:
        node *root;
        bool searchable;
        bool levelFound;
        node* findNode(string name);
};


#endif // TREE_H
