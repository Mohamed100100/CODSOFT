

#include <iostream>
#include<cstring>
#include <string.h>
#include <limits>
using namespace std;


class Book {
public:
    string Author;
    string Title;
    string ISBN;
    string ID;
    bool IsBorrowed;

    Book( string author,  string title,  string isbn)
        : Author(author), Title(title), ISBN(isbn),ID(" "), IsBorrowed(false) {}
};

class Node {
public:
    Book book;
    Node* next;

    Node(Book b) : book(b), next(NULL) {}
};

class BookList {
private:
    Node* head;

public:
    BookList() : head(NULL) {}

    // Function to add a new node (book) to the linked list
    void AddNewBook( string author,  string title,  string isbn) {
        Book newBook(author, title, isbn);
        Node* newNode = new Node(newBook);

        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }


    // Function to check the state of a node (book) using author, title, or ISBN
    short CheckBookState(string key) {
        Node* current = head;
        while (current) {
            if (current->book.Author == key || current->book.Title == key || current->book.ISBN == key) {
               if(current->book.IsBorrowed == true)
                return 1;
               return 0;
            }
            current = current->next;
        }
        cout << "Book with Author/Title/ISBN " << key << " not found." << endl;
        return 3;
    }

    short CheckBookUserId(string key ,string Id) {
        Node* current = head;
        while (current) {
            if (current->book.Author == key || current->book.Title == key || current->book.ISBN == key) {
               if(current->book.ID == Id)
                return 1;
               return 0;
            }
            current = current->next;
        }
        cout << "Book with Author/Title/ISBN " << key << " not found." << endl;
        return 3;
    }

    // Function to borrow a book
    void BorrowBook( string key,string Id) {
        Node* current = head;
        while (current) {
            if (current->book.Author == key || current->book.Title == key || current->book.ISBN == key) {
                if (current->book.IsBorrowed) {
                    cout << "Book is already borrowed." << endl;
                } else {
                    current->book.IsBorrowed = true;
                    current->book.ID = Id;
                    cout << "Book with Author/Title/ISBN " << key << " has been borrowed." << endl;
                }
                return ;
            }
            current = current->next;
        }
        cout << "Book with Author/Title/ISBN " << key << " not found." << endl;
    }

    // Function to return a book
    void ReturnBook( string key) {
        Node* current = head;
        while (current) {
            if (current->book.Author == key || current->book.Title == key || current->book.ISBN == key) {
                if (current->book.IsBorrowed) {
                    current->book.IsBorrowed = false;
                    cout << "Book with Author/Title/ISBN " << key << " has been returned." << endl;
                } else {
                    cout << "Book is not currently borrowed." << endl;
                }
                return;
            }
            current = current->next;
        }
        cout << "Book with Author/Title/ISBN " << key << " not found." << endl;
    }
};


class User_Node {
public:
    string ID;
    bool flag;
    User_Node* next;

    User_Node(string id) : ID(id), flag(false),next(NULL) {}
};

class UserList {
private:
    User_Node* head;

public:
    UserList() : head(NULL) {}

    // Function to add a new node to the linked list
    void AddNewNode(string id) {
        User_Node* newNode = new User_Node(id);

        if (!head) {
            head = newNode;
        } else {
            User_Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to view a node using ID
    void ViewNodeByID(string id) {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        User_Node* current = head;
        while (current) {
            if (current->ID == id) {
                cout << "ID: " << current->ID << endl;
                return;
            }
            current = current->next;
        }
        cout << "User with ID " << id << " not found." << endl;
    }
bool SearchNodeByID(string id) {
        if (!head) {
            return false;
        }
        User_Node* current = head;
        while (current) {
            if (current->ID == id) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void SetFlagByID(string id) {
        if (!head) {
            return ;
        }
        User_Node* current = head;
        while (current) {
            if (current->ID == id) {
                current->flag = true;
                return ;
            }
            current = current->next;
        }
        return ;
    }

    void ClrFlagByID(string id) {
        if (!head) {
            return ;
        }
        User_Node* current = head;
        while (current) {
            if (current->ID == id) {
                current->flag = false;
                return ;
            }
            current = current->next;
        }
        return ;
    }

    short RetFlagByID(string id) {
        if (!head) {
            return 3 ;
        }
        User_Node* current = head;
        while (current) {
            if (current->ID == id) {
                if(current->flag == false)
                return 0 ;
                return 1;
            }
            current = current->next;
        }
        return 3;
    }


    // Function to delete a node using ID
    void DeleteNodeByID(string id) {
        if (!head) {
                cout << "List is empty." << endl;
                return;
            }

        if (head->ID == id) {
            User_Node* temp = head;
            head = head->next;
            delete temp;
            cout << "User with ID " << id << " has been deleted." << endl;
            return;
        }

        User_Node* current = head;
        while (current->next) {
            if (current->next->ID == id) {
                User_Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "User with ID " << id << " has been deleted." << endl;
                return;
            }
            current = current->next;
        }

        cout << "User with ID " << id << " not found." << endl;
    }
};

class Admin_Node {
public:
    string ID;
    Admin_Node* next;

    Admin_Node(string id) : ID(id), next(NULL) {}
};

class AdminList {
private:
    Admin_Node* head;

public:
    AdminList() : head(NULL) {}

    // Function to add a new node to the linked list
    void AddNewNode(string id) {
        Admin_Node* newNode = new Admin_Node(id);

        if (!head) {
            head = newNode;
        } else {
            Admin_Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

bool SearchNodeByID(string id) {
        if (!head) {
            return false;
        }
        Admin_Node* current = head;
        while (current) {
            if (current->ID == id) {
                return true;
            }
            current = current->next;
        }
        return false;
    }


    // Function to delete a node using ID
    void DeleteNodeByID(string id) {
        if (!head) {
                cout << "List is empty." << endl;
                return;
            }

        if (head->ID == id) {
            Admin_Node* temp = head;
            head = head->next;
            delete temp;
            cout << "User with ID " << id << " has been deleted." << endl;
            return;
        }

        Admin_Node* current = head;
        while (current->next) {
            if (current->next->ID == id) {
                Admin_Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                cout << "User with ID " << id << " has been deleted." << endl;
                return;
            }
            current = current->next;
        }

        cout << "User with ID " << id << " not found." << endl;
    }
};

//bookList.AddNewBook("Author1", "Title1", "ISBN1");

int main() {
    BookList book_List;
    UserList user_List;
    AdminList admin_List;
    admin_List.AddNewNode("1111");
    short choice1 = 0;
    short choice2 = 0;
    short choice3 = 0;
    short flag = 1;
    short flag1 = 1;
    string User_Id;
    string Book_Key;
    string Admin_Id;
    string Book_Author;
    string Book_title;
    string Book_ISBN;
    cout<<  "--------------------------------------"<<endl;
    cout << "Welcome To LIBRARY MANAGEMENT SYSTEM" << endl;
    cout<<  "--------------------------------------"<<endl<<endl;
    cout<<  "Important Note >>>>> You Can Borrow One Book Only "<<endl;
    cout<<  "--------------------------------------------------------"<<endl<<endl;
while(1)
{
    cout<<"-----------------------------"<<endl;
    cout<<"1- Sign In As User\n";
    cout<<"2- Sign Up For New Users\n";
    cout<<"3- Sign In As Admin\n";
    cout<<"-----------------------------"<<endl;
    cout<<"Your Choice : ";
    cin>>choice1;
    /**Repeat until enter from 1 to 3**/
    while (!((choice1>0)&&(choice1<4)))
        {
        cout<<"Wrong!!Enter Your Choice Correct : ";
        cin>>choice1;
        }
   switch (choice1)
   {
    case(1):
        cout<<"Please Enter Your ID : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,User_Id);
        if(user_List.SearchNodeByID(User_Id) == true)
          {
            cout<<"Welcome :)\n\n";
            flag = 1;
            while (flag == 1)
            {

            cout<<"-----------------------------"<<endl;
            cout<<"1- Take Book\n";
            cout<<"2- Return Book\n";
            cout<<"3- Check Book\n";
            cout<<"4- Return To Home Page\n";
            cout<<"-----------------------------"<<endl;
            cout<<"Your Choice : ";
            cin>>choice2;
            while (!((choice2>0)&&(choice2<5)))
            {
            cout<<"Wrong!!Enter Your Choice Correct : ";
            cin>>choice2;
            }
            switch(choice2)
              {
            case (1):
                cout << "Please Enter The Author Or Title Or ISBN Of The Book : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,Book_Key);
                if((!(book_List.CheckBookState(Book_Key)== 3))&&(!(user_List.RetFlagByID(User_Id)==3)))
                {
                if((book_List.CheckBookState(Book_Key)== 0)&&(user_List.RetFlagByID(User_Id)==0))
                    {cout<<"Successful Borrow\n";
                    user_List.SetFlagByID(User_Id);
                    book_List.BorrowBook(Book_Key,User_Id);
                    }
                    else if((book_List.CheckBookState(Book_Key)== 1)||(user_List.RetFlagByID(User_Id)==1))
                            {cout<<"Filed To Borrow\n";}
                }
                        break;
            case(2):
                cout << "Please Enter The Author Or Title Or ISBN Of The Book : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,Book_Key);
                if(!(book_List.CheckBookState(Book_Key)== 3))
                {
                if(book_List.CheckBookState(Book_Key)== 1)
                    if(book_List.CheckBookUserId(Book_Key,User_Id)==1)
                    {
                    cout<<"Successful Return\n";
                    user_List.ClrFlagByID(User_Id);
                    book_List.ReturnBook(Book_Key);
                    }
                    else{cout<<"You Can't Do This\n";}
                    else if(book_List.CheckBookState(Book_Key)== 0)
                        {cout<<"Filed To Return\n";}
                }
                        break;

            case(3):
                cout << "Please Enter The Author Or Title Or ISBN Of The Book : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,Book_Key);
                if(!(book_List.CheckBookState(Book_Key)== 3))
                {
                if(book_List.CheckBookState(Book_Key)== 1)
                    {cout<<"This Book Is Not Free\n";}
                    else if(book_List.CheckBookState(Book_Key)== 0)
                        {cout<<"This Book Is  Free\n";}
                }
                        break;

            case(4):
                cout << "Return To Home Page\n";
                flag = 0;
                break;
              }
              }
          }
        else {cout<<"Wrong ID !!\n";}
    break;
    case(2):
        cout<<"Please Enter Your ID : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,User_Id);

        if(user_List.SearchNodeByID(User_Id) == false)
          {
              user_List.AddNewNode(User_Id);
              cout<<"Successful Registration\n";

          }
        else {cout<<"Not Allowed ID !!\n";
              cout<<"Failed Registration\n";}
        break;
    case(3):
        cout<<"Please Enter Your ID : ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,Admin_Id);
        if(admin_List.SearchNodeByID(Admin_Id) == true)
        {   flag1 = 1;
        cout<<"Welcome :)\n\n";
            while(flag1 == 1)
            {
            cout<<"-----------------------------"<<endl;
            cout<<"1- Add Book\n";
            cout<<"2- Add Admin\n";
            cout<<"3- Delete Admin\n";
            cout<<"4- Return To Home Page\n";
            cout<<"-----------------------------"<<endl;
            cout<<"Your Choice : ";
            cin>>choice3;
            while (!((choice3>0)&&(choice3<5)))
            {
            cout<<"Wrong!!Enter Your Choice Correct : ";
            cin>>choice3;
            }
            switch(choice3)
            {
            case(1):
                cout<<"Please Enter Book Title  : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,Book_title);

                cout<<"Please Enter Book Author : ";
                getline(cin,Book_Author);

                cout<<"Please Enter Book ISBN   : ";
                getline(cin,Book_ISBN);

                book_List.AddNewBook(Book_Author,Book_title,Book_ISBN);
                cout<<"\nSuccessful Add\n";
                break;
            case(2):
                cout<<"Please Enter Your ID : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,Admin_Id);

                if(admin_List.SearchNodeByID(Admin_Id) == false)
                  {
                      admin_List.AddNewNode(Admin_Id);
                      cout<<"Successful Registration\n";

                  }
                else {cout<<"Not Allowed ID !!\n";
                      cout<<"Failed Registration\n";}
                break;


            case(3):
                cout<<"Please Enter Your ID : ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                getline(cin,Admin_Id);

                if(admin_List.SearchNodeByID(Admin_Id) == true)
                  {
                      admin_List.DeleteNodeByID(Admin_Id);
                      cout<<"Successful Delete\n";

                  }
                else {cout<<"Not Allowed ID !!\n";
                      cout<<"Failed To Delete\n";}
        break;

            case(4):
                cout << "Return To Home Page\n";
                flag1 = 0;
                break;
            }
        }

   }
   else{cout<<"Wrong Id !!\n";}
   }
}
    return 0;
}

