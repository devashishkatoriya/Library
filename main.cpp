//Program to Store Book records using Hash Table

/*
 * Created by Devashish Katoriya on 11-03-2017
 */

#include <iostream>
#include <cstring>

using namespace std;

#define MAX 10

//Class Definitions
class Book                                                          //Book Class
{
public :
    int id;
    char title[MAX],author[MAX];
};

class HashTable                                                     //Hash Table Class
{
    Book ht[MAX];
    void insert(Book);
    void insertQ(Book);
    inline int HashFunc(int);
public :
    HashTable()
    {
        for(int i=0;i<MAX;i++)
        {
            ht[i].id = 0;
            strcpy(ht[i].title,"");
            strcpy(ht[i].author,"");
        }
    }
    bool isFull()
    {
        for(int i=0;i<MAX;i++)
        {
            if(ht[i].id==0)
            {
                return false;
            }
        }
        return true;
    }
    void clr()
    {
        for(int i=0;i<MAX;i++)
        {
            ht[i].id = 0;
            strcpy(ht[i].title,"");
            strcpy(ht[i].author,"");
        }
    }
    void construct();
    void display();
    void search();
};

void HashTable::construct()                                           //Function for Insertion
{
    if(isFull())
    {
        cout<<"\nSorry, the Hash Table is Full.";
        return;
    }
    
    int ch = 0;
    cout<<"\n\n 1 for Linear Hashing.";
    cout<<"\n 2 for Quadratic Hashing.";
    cout<<"\nEnter which Hashing Technique to use ? ";
    cin>>ch;
    if(ch==1)
    {
        Book B;
        cout<<"\nEnter Book Details :- ";
        cout<<"\nEnter ID   \t: ";
        cin>>B.id;
        cout<<"Enter Title \t: ";
        cin>>B.title;
        cout<<"Enter Author \t: ";
        cin>>B.author;
        insert(B);
    }
    else if(ch==2)
    {
        Book B;
        cout<<"\nEnter Book Details :- ";
        cout<<"\nEnter ID   \t: ";
        cin>>B.id;
        cout<<"Enter Title \t: ";
        cin>>B.title;
        cout<<"Enter Author \t: ";
        cin>>B.author;
        insertQ(B);
    }
    else
        cout<<"\nInvalid Option!";
}

void HashTable::insert(Book B)                                         //Insertion using Linear Probing
{
    int pos;
    pos = HashFunc(B.id);
    if(ht[pos].id==0)
    {
        ht[pos] = B;
    }
    else
    {
        int i=pos;
        do
        {
            if(ht[i].id==0)
            {
                ht[i] = B;
                break;
            }
            i=(i+1)%MAX;
        }while(i!=pos);
    }
}

void HashTable::insertQ(Book B)                                         //Insertion using Quadratic Probing
{
    int pos;
    pos = HashFunc(B.id);
    if(ht[pos].id==0)
    {
        ht[pos] = B;
    }
    else
    {
        for(int i=1; i<(MAX-1)/2; i++)
        {
            if(ht[(pos+(i*i))%MAX].id==0)
            {
                ht[(pos+(i*i))%MAX] = B;
                break;
            }
        }
    }
}

inline int HashTable::HashFunc(int key)                                 //Hash Function
{
    return key % MAX;
}

void HashTable::display()                                               //Display
{
    cout<<"\n\t\tHash Table";
    cout<<"\n---------------------------------------------";
    cout<<"\nPos.\tID\tTitle\t\tAuthor";
    cout<<"\n---------------------------------------------";
    for(int i=0;i<MAX;i++)
    {
        cout<<"\n"<<i<<"\t"<<ht[i].id<<"\t"<<ht[i].title<<"\t\t"<<ht[i].author;
    }
    cout<<"\n---------------------------------------------";
    cout<<"\nMAX is "<<MAX;
}

void HashTable::search()                                                //Search
{
    int id,pos;
    cout<<"\nEnter ID to search : ";
    cin>>id;
    pos = HashFunc(id);
    if(ht[pos].id==id)
    {
        cout<<"\nID   \t: "<<ht[pos].id;
        cout<<"\nTitle\t: "<<ht[pos].title;
        cout<<"\nAuthor\t: "<<ht[pos].author;
        return;
    }
    else
    {
        int i=pos;
        do
        {
            if(ht[i].id==id)
            {
                cout << "\nID   \t: " << ht[i].id;
                cout << "\nTitle\t: " << ht[i].title;
                cout << "\nAuthor\t: " << ht[i].author;
                return;
            }
            i=(i+1)%MAX;
        }while(i!=pos);
        cout<<"\nRecord NOT found!";
    }
}

//main()
int main()
{
    HashTable obj;
    char choice;
    int ch;
    cout<<"\nProgram to Store Book records using Hash Table.";
    do
    {
        ch = 0;
        choice = 'n';
        cout<<"\n\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
        cout<<"\n 1 for Insertion";
        cout<<"\n 2 for Display Hash Table";
        cout<<"\n 3 for Searching";
        cout<<"\n 4 for IsFull";
        cout<<"\n -1 to Clear whole Tree";
        cout<<"\n  0 to Quit";
        cout<<"\nEnter your choice : ";
        cin>>ch;
        cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        switch(ch) {
            case 1 :
                obj.construct();
                break;
            case 2 :
                obj.display();
                break;
            case 3 :
                obj.search();
                break;
            case 4 :
                if(obj.isFull())
                    cout<<"\nYes, the Hash Table is Completely Full.";
                else
                    cout<<"\nNo, the Hash Table is Not full.";
                break;
            case -1 : cout<<"\nAre you sure you want to clear table (y/n) ? ";
                cin>>choice;
                if(choice=='y'||choice=='Y')
                {
                    obj.clr();
                    cout<<"\nHash Table Cleared Successfully!";
                }
                else
                    cout<<"\nCancelled!";
            case 0 : break;
            default : cout<<"\nInvalid Option!";
        }
        
        /*
        if(ch!=0)
        {
            cout<<"\n\n\n\n\n\n\nPress any key to continue...";
            cin.ignore();
            cin.get();
        }
        */
    }while(ch!=0);
    
    cout<<"\nThank you for using this program :) \n\n";
    return 0;
}