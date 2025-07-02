#include <iostream>
using namespace std;

class Book
{
    private:
    int id;
    string title;
    string name;
    bool status;

    public:
    Book(int i, string t, string n) : id(i), title(t), name(n), status(true) {}
    Book() {status = true;}
    int getid(){return id;}
    string gettitle(){return title;}
    string getname(){return name;}

    bool isavailable()
    {
        if(status == true)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void borrowbook(){status = false;}
    void returnbook(){status = true;}

    void display()
    {
        cout << "Book Title : " << title << endl;
        cout << "Author name : " << name << endl;
    }
};

class user
{
    private:
    int userid;
    string name;

    public:
    user (int i, string n) : userid(i), name(n){}
    int getuserid(){return userid;}
    string getname(){return name;}
    virtual ~user(){}

};

class admin
{

};

class member
{

};

class Library
{

};

int main()
{
    return 0;
}