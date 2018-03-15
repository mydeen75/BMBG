//LRU.cpp

#include<bits/stdc++.h>
#define MAX_CACHE_SIZE 5
using namespace std;
 
struct node{
int data;
node *next;
node *prev;
};
 
node *Front=NULL;
node *Rear=NULL;
map<int,node*> Hash;
 
void removeLast()
{
    cout<<"Removing last element"<<endl;
    node *temp=Rear->prev;
    temp->next=NULL;
    int pageNo=Rear->data;
    delete Rear;
    Rear=temp;
    map<int,node*>::iterator it;
    it=Hash.find(pageNo);
    Hash.erase(it);
}
 
void insertFront(int pageNo)
{
    if(Hash.size()==MAX_CACHE_SIZE)
    {
        cout<<"Maximum Cache Size reached"<<endl;
        removeLast();
    }
 
    node *temp=new node;
    temp->data=pageNo;
    temp->next=Front;
    temp->prev=NULL;
    if(Front!=NULL)Front->prev=temp;
    Front=temp;
 
    if(Rear==NULL)
    {
        cout<<"Cache is empty..."<<endl;
        Rear=Front;
    }
    Hash.insert(pair<int,node*> (pageNo,temp));
    cout<<"Inserting "<<pageNo<<" in front"<<endl;
}
 
void moveTofront(node *temp)
{
    node *next=temp->next;
    node *prev=temp->prev;
 
    if(temp==Rear)
    {
        cout<<"Rear page referenced..."<<endl;
        Rear=temp->prev;
        Rear->next=NULL;
    }
    else
    {
        prev->next=next;
        next->prev=prev;
    }
 
    cout<<"Moving pageNo "<<temp->data<<" to front"<<endl;
    temp->next=Front;
    temp->prev=NULL;
    Front=temp;
}
 
node* findPage(int pageNo)
{
    map<int, node*>:: iterator it;
    cout<<"Finding pageNo "<<pageNo<<endl;
    it=Hash.find(pageNo);
    if(it!=Hash.end())return it->second;
    else return NULL;
}
 
void printList()
{
    cout<<"---------------------------------------------"<<endl;
    node *temp=Front;
    while(temp!=NULL)
    {
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"---------------------------------------------"<<endl;
    cout<<"The Hash Map is as Follows"<<endl;
    map<int,node*>::iterator it;
    cout<<"Key\t"<<"Node address"<<endl;
    for(it=Hash.begin();it!=Hash.end();it++)
    {
        cout<<"|"<<it->first<<"|\t|"<<it->second<<"|"<<endl;
    }
}
 
void ReferencePage(int pageNo)
{
    node *refPage=findPage(pageNo);
 
    if(refPage==NULL)
    {
        cout<<"PageNo "<<pageNo<<" not found"<<endl;
        insertFront(pageNo);
    }
 
    else
    {
        cout<<"PageNo "<<pageNo<<" found"<<endl;
        moveTofront(refPage);
    }
 
    cout<<"The list is as follows"<<endl;
    printList();
 
}
int main()
{
    int k;
    while(1)
    {
    cout<<"Enter a page number"<<endl;
    cin>>k;
    //InitializeList();
    ReferencePage(k);
    }
 
}
 