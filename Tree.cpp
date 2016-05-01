#include "Tree.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
using namespace std;

Tree::Tree()
{
    searchable=true;
    levelFound=false;
    root=NULL;
}

Tree::~Tree()
{
    //dtor
}
        void Tree::CreateSearchTree(){
            if(root!=NULL){
                vector<node*> nodes;
                node *tmp;
                bool left=true;
                node *par=NULL;
                nodes.push_back(root);
                root->searchLeft=NULL;
                root->searchRight=NULL;
                root->searchParent=NULL;
                int n=0;
                while(n<nodes.size()){
                    if(nodes[n]->child!=NULL){
                        tmp = nodes[n]->child;
                        //cout<<nodes[n]->child->key<<endl;
                        while(tmp!=NULL){
                            nodes.push_back(tmp);
                            tmp->searchLeft=NULL;
                            tmp->searchRight=NULL;
                            tmp->searchParent=NULL;
                            //cout<<tmp->key<<endl;
                            tmp=tmp->right;
                        }
                    }

                    tmp=root;

                    while(tmp!=NULL&&tmp->key!=nodes[n]->key){
                        //cout<<"test"<<endl;
                        char t[100];
                        for (int a=0;a<=tmp->key.length();a++){
                            t[a]=tmp->key[a];
                        }
                        //cout<<"test2"<<endl;
                        char k[100];
                        for (int a=0;a<=nodes[n]->key.length();a++){
                            k[a]=nodes[n]->key[a];
                        }
                        int b=0;
                        while(k[b]==t[b]){
                            b+=1;
                        }

                        if(k[b]<t[b]){
                            par=tmp;
                            tmp=tmp->searchLeft;
                            left=true;
                        }
                        else{
                            par=tmp;
                            tmp=tmp->searchRight;
                            left=false;
                        }
                    }
                    //cout<<nodes[n]->key<<"test"<<endl;
                    if(left){
                        nodes[n]->searchParent=par;
                        if(par!=NULL){
                            par->searchLeft=nodes[n];
                        }
                    }
                    else{
                        nodes[n]->searchParent=par;
                        if(par!=NULL){
                            par->searchRight=nodes[n];
                        }
                    }
                    n+=1;
                }
            }
            searchable=true;

        }
        node* Tree::findNode(string name){
            node *tmp=root;
            if(searchable){
                while(tmp!=NULL&&tmp->key!=name){
                    char t[100];
                    for (int a=0;a<=tmp->key.length();a++){
                        t[a]=tmp->key[a];
                    }
                    char k[100];
                    for (int a=0;a<=name.length();a++){
                        k[a]=name[a];
                    }
                    int b=0;
                    while(k[b]==t[b]){
                        b+=1;
                    }
                    if(k[b]<t[b]){
                        tmp=tmp->searchLeft;
                    }
                    else{
                        tmp=tmp->searchRight;
                    }
                }
            }
            else{
                tmp=NULL;
            }
            return tmp;
        }
        void Tree::AddNode(string name,string parent){
            //cout<<searchable<<endl;
            if(root==NULL){
               root=new node;
               root->key=name;
            }
            else{
                if(searchable){
                    //cout<<"searching"<<endl;
                    node *par = findNode(parent);
                    if(par!=NULL){
                        //cout<<"found"<<endl;
                        node *tmp=par->child;
                        node *tmp2=NULL;
                        while(tmp!=NULL){
                            tmp2=tmp;
                            tmp=tmp->right;
                        }
                        node *nn=new node;
                        nn->key=name;
                        nn->parent=par;
                        //cout<<par->key<<"->"<<nn->key;
                        if(tmp2!=NULL){
                            tmp2->right=nn;
                            nn->left=tmp2;
                        }
                        else{
                            par->child=nn;
                        }
                    }
                    else{
                        cout<<"Manager not found!"<<endl;
                    }
                }
                else{
                    cout<<"Please create/recreate search tree first!"<<endl;;
                }
            }
            levelFound=false;
            searchable=false;
        }
        void Tree::DeleteNode(string name){
            if(searchable){
                node *del =findNode(name);
                bool left;
                bool noc=false;
                if(del!=NULL){
                    if(del!=root){
                        node *newPar;
                        if(del->left==NULL){
                            if(del->right==NULL){
                                newPar=del->parent;
                                left=false;
                                noc=true;
                                //cout<<del->child->key<<del->parent->key<<endl;
                                del->parent->child=del->child;
                                if(del->child!=NULL){
                                    del->child->parent=del->parent;
                                }
                            }
                            else{
                                newPar=del->right;
                                left=true;
                                del->parent->child=del->right;
                                del->right->left=NULL;
                            }
                        }
                        else{
                            newPar=del->left;
                            left=false;
                            del->left->right=del->right;
                            if(del->right!=NULL){
                                del->right->left=del->left;
                            }
                        }
                        if(!noc){
                            if(left){
                                node *c=del->child;
                                if(c!=NULL){
                                    while(c->right!=NULL){
                                        c->parent=newPar;
                                        c=c->right;
                                    }
                                    c->parent=newPar;
                                    c->right=newPar->child;
                                    newPar->child=del->child;
                                }
                            }
                            else{
                                node *c=newPar->child;
                                if(c!=NULL){
                                    while(c->right!=NULL){
                                        c=c->right;
                                    }
                                    c->right=del->child;
                                    del->child->left=c;
                                }
                                else{
                                    newPar->child=del->child;
                                }
                                node *d=del->child;
                                if(d!=NULL){
                                    while(d->right!=NULL){
                                        d->parent=newPar;
                                        d=d->right;
                                    }
                                    d->parent=newPar;
                                }
                            }
                        }
                    }
                    else{
                        if(del->child!=NULL){
                            root=del->child;
                            root->parent=NULL;
                            if(root!=NULL){
                                if(root->right!=NULL){
                                    if(root->child==NULL){
                                        root->child=root->right;
                                        root->right=NULL;
                                        root->child->left=NULL;
                                        root->child->parent=root;
                                        node *temp=root->child;
                                        while(temp->right!=NULL){
                                            temp->parent=root;
                                            temp=temp->right;
                                        }
                                        temp->parent=root;
                                    }
                                    else{
                                        node *c=root->child;
                                        root->child=root->right;
                                        root->right=NULL;
                                        root->child->left=NULL;
                                        root->child->parent=root;
                                        node *temp=root->child;
                                        while(temp->right!=NULL){
                                            temp->parent=root;
                                            temp=temp->right;
                                        }
                                        temp->parent=root;
                                        temp->right=c;
                                    }
                                }
                            }
                        }
                        else{
                            root=NULL;
                        }
                    }
                }
                else{
                    cout<<"Employee not found!"<<endl;
                }
            }
            else{
                cout<<"Please create/recreate search tree first!"<<endl;;
            }
            searchable=false;
            levelFound=false;
        }
        void Tree::ChainOfCommand(string name){
            if(searchable){
                node *a=findNode(name);
                if(a!=NULL){
                    vector <node*> parents;
                    node *tmp=a;
                    while(tmp!=NULL){
                        parents.push_back(tmp);
                        tmp=tmp->parent;
                    }
                    vector <node*> children;
                    tmp=a->child;
                    while(tmp!=NULL){
                        //cout<<tmp->key<<endl;
                        children.push_back(tmp);
                        tmp=tmp->right;
                    }
                    cout<<endl;
                    for(int i=parents.size()-1;i>=0;i--){
                        cout<<parents[i]->key<<endl<<"|"<<endl;
                    }
                    if(children.size()!=0){
                        cout<<children[0]->key;
                        //cout<<children[1]->key;
                        for(int i=1;i<children.size();i++){
                            cout<<"->"<<children[i]->key;
                        }
                    }
                    else{
                        cout<<"NULL";
                    }
                    cout<<endl;
                }
                else{
                    cout<<"Employee not found!"<<endl;
                }

            }
            else{
                cout<<"Please create/recreate search tree first!"<<endl;
            }
        }
        void Tree::ShiftChildren(string name,string newChild){
            if(searchable){
               node *a=findNode(name);
               node *b=findNode(newChild);
               if(a!=NULL){
                    if(b!=NULL){
                        if(a->parent==b->parent){
                            if(a->left!=NULL){
                                a->left->right=a->right;
                                if(a->right!=NULL){
                                    a->right->left=a->left;
                                }
                            }
                            else{
                                if(a->right!=NULL){
                                    a->right->left=a->left;
                                    a->parent->child=a->right;
                                }
                            }
                            if(b->right!=NULL){
                                a->right=b->right;
                                a->right->left=a;
                            }
                            else{
                                a->right=NULL;
                            }
                            b->right=a;
                            a->left=b;

                        }
                        else{
                            cout<<"These Employees don't have the same manager!"<<endl;
                        }
                    }
                    else{
                        if(a->left!=NULL){
                            a->left->right=a->right;
                            if(a->right!=NULL){
                                a->right->left=a->left;
                            }
                        }
                        if(a->parent->child!=a){
                            a->right=a->parent->child;
                            a->right->left=a;
                        }
                        if(a->parent!=NULL){
                            a->parent->child=a;
                        }
                        a->left=NULL;

                    }
               }
               else{
                    cout<<"The first employee could not be found!"<<endl;
               }
            }
            else{
                cout<<"Please create/recreate search tree first!"<<endl;
            }
            searchable=false;
        }
        void Tree::AssignLevels(){
            vector<node*> nodes;
            nodes.push_back(root);
            int n=0;
            node *tmp;
            while(n<nodes.size()){
                if(nodes[n]->child!=NULL){
                    tmp = nodes[n]->child;
                    //cout<<nodes[n]->child->key<<endl;
                    while(tmp!=NULL){
                        nodes.push_back(tmp);
                        //cout<<tmp->key<<endl;
                        tmp=tmp->right;
                    }
                }
                n+=1;
            }
            root->level=1;
            for(int i=1;i<nodes.size();i++){
                nodes[i]->level=nodes[i]->parent->level+1;
                //cout<<nodes[i]->key<<nodes[i]->level<<endl;
            }
            levelFound=true;
        }
        void Tree::FindLevel(string name){
            if(levelFound){
                if(searchable){
                    node *b=findNode(name);
                    if(b!=NULL){
                        cout<<"Employee "<<name<<" is at level "<<b->level<<endl;
                    }
                    else{
                        cout<<"The employee could not be found!"<<endl;
                    }
                }
                else{
                    cout<<"Please create/recreate search tree first!"<<endl;
                }
            }
            else{
                cout<<"Please assign levels!"<<endl;
            }
        }
        void Tree::BFT(){
            if(levelFound){
                vector<node*> nodes;
                nodes.push_back(root);
                int n=0;
                node *tmp;
                while(n<nodes.size()){
                    if(nodes[n]->child!=NULL){
                        tmp = nodes[n]->child;
                        //cout<<nodes[n]->child->key<<endl;
                        while(tmp!=NULL){
                            nodes.push_back(tmp);
                            //cout<<tmp->key<<endl;
                            tmp=tmp->right;
                        }
                    }
                    n+=1;
                }
                cout<<"Employees: "<<endl;
                for(int i=0;i<nodes.size();i++){
                    cout<<nodes[i]->key<<": "<<nodes[i]->level<<endl;
                    //cout<<nodes[i]->key<<nodes[i]->level<<endl;
                }
            }
            else{
                cout<<"Please assign levels first!"<<endl;
            }
        }
        void Tree::CountEmployees(){
            vector<node*> nodes;
            if(root!=NULL){
                nodes.push_back(root);
            }
            int n=0;
            node *tmp;
            while(n<nodes.size()){
                if(nodes[n]->child!=NULL){
                    tmp = nodes[n]->child;
                    //cout<<nodes[n]->child->key<<endl;
                    while(tmp!=NULL){
                        nodes.push_back(tmp);
                        //cout<<tmp->key<<endl;
                        tmp=tmp->right;
                    }
                }
                n+=1;
            }
            cout<<"There are currently "<<nodes.size()<<" employees!"<<endl;
        }
        void Tree::Promote(string name){
            if(levelFound){
                if(searchable){
                    node *a=findNode(name);
                    if(a!=NULL){
                        if(a->level>2){
                            node *par=a->parent;
                            DeleteNode(name);
                            CreateSearchTree();
                            AddNode(name,par->parent->key);
                        }
                        else{
                            cout<<"This employee can no longer be promoted!"<<endl;
                        }
                    }
                    else{
                        cout<<"Employee not found!"<<endl;
                    }
                }
                else{
                    cout<<"Please create/recreate search tree first!"<<endl;
                }
            }
            else{
                cout<<"Please assign levels first!"<<endl;
            }
            searchable=false;
            levelFound=false;
        }
        void Tree::EmployeesAtLevel(int l){
            if(levelFound){
                vector<node*> nodes;
                if(root!=NULL){
                    nodes.push_back(root);
                }
                int n=0;
                int i=0;
                node *tmp;
                while(n<nodes.size()){
                    if(nodes[n]->child!=NULL){
                        tmp = nodes[n]->child;
                        //cout<<nodes[n]->child->key<<endl;
                        while(tmp!=NULL){
                            if (tmp->level==l){
                                i+=1;
                            }
                            nodes.push_back(tmp);
                            //cout<<tmp->key<<endl;
                            tmp=tmp->right;
                        }
                    }
                    n+=1;
                }
                cout<<"There are "<<i<<" employees at level "<<l<<"."<<endl;
            }
            else{
                cout<<"Please assign levels first!"<<endl;
            }
        }
