#include <iostream>
#include <vector>
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

class Library
{
    private:
    vector<Book> books;

    public:
    void addbook(Book b)
    {
        books.push_back(b);
    }

    void removebook(int bid)
    {
        for(auto i = books.begin(); i != books.end(); i++)
        {
            if(i -> getid() == bid)
            {
                books.erase(i);
                break;
            }
        }
    }

    Book* search(int bid)
    {
        for(auto i = books.begin(); i != books.end(); i++)
        {
            if(i -> getid() == bid)
            {
                return &(*i);
            }
        }
        return nullptr;
    }

    void displaybooks()
    {
        for(Book& i : books)
        {
            cout << i.gettitle() << ", " << i.getname() << ", available: " << i.isavailable() << endl;
        }
    }
};

class member : public user
{
    private:
    int limit = 3;
    vector<int> borrowedbooks;

    public:

    member(int i, string n) : user(i, n){}

     void displayuserbooks(Library& lib)
    {
        for(int id : borrowedbooks)
        {
            Book* b = lib.search(id);
            if(b != nullptr)
            {
                cout << b -> gettitle() << " by " << b -> getname() << endl;
            }
        }
    }

    void borrowbook(Library& lib, int id)
    {
        if(borrowedbooks.size() < limit)
        {
            Book* b = lib.search(id);
            if(b != nullptr && b-> isavailable())
            {
                b -> borrowbook();
                borrowedbooks.push_back(id);
            }
        }
    }

    void returnbook(Library& lib, int id)
    {
        Book* b = lib.search(id);
            if(b != nullptr)
            {
                b-> returnbook();
            }
        for(auto i = borrowedbooks.begin(); i != borrowedbooks.end(); i++)
        {
            if(*i == id)
            {
                borrowedbooks.erase(i);
                break;
            }
        }
    }
};

class admin : public user
{
    public:

    admin(int i, string n) : user(i, n)  {}

    void add(Library& lib, Book b)
    {
        lib.addbook(b);
    }

    void remove(Library& lib, int bid)
    {
        lib.removebook(bid);
    }

    void display(Library& lib)
    {
        lib.displaybooks();
    }

    void displayusers(vector<member>& list)
    {
        for(auto it = list.begin(); it != list.end(); it++)
        {
            cout << "Member ID : " << it->getuserid()
                 << ", Name : " << it->getname() << endl;
        }
    }
};

int main()
{
    Library lib;
    admin admin1(001, "Hercule");
    admin admin2(002, "joshua");

    Book b1(1, "1984", "George Orwell");
    Book b2(2, "Sapiens", "Yuval Noah Harari");
    Book b3(3, "Dune", "Frank Herbert");

    member m1(1, "Emily");
    member m2(2, "alexander");

    admin1.add(lib, b1);
    admin2.add(lib, b2);
    admin1.add(lib, b3);

    cout << "All the books in the library are : " << endl;
    admin1.display(lib);

    cout << "All the members of library are : " << endl;
    vector<member> members = {m1, m2};
    admin1.displayusers(members);

    m1.borrowbook(lib, 1);
    m1.borrowbook(lib, 2);

    cout << "Emily's Borrowed Books: " << endl;
    m1.displayuserbooks(lib);

    m1.returnbook(lib, 1);

    cout << "Emily's Books after return : " << endl;
    m1.displayuserbooks(lib);

    m2.borrowbook(lib, 3);

    cout << "alexander's Borrowed Books : " << endl;
    m2.displayuserbooks(lib);

    return 0;
}