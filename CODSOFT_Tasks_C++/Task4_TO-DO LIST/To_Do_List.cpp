#include <iostream>
#include <string.h>
#include<cstring>
#include <limits>
using namespace std;

/**Make a Class Node To Store The Data **/
class Node {
public:

    Node* next;
    string Task_str;
    char mark ;
    Node(string value) : Task_str(value),mark('P'), next(NULL) {}
};

/**Make LinkedList To Store The Tasks In It **/
/**We have in it 4 functions **/
/**(1) Add Node**/
/**(2) Delete Node**/
/**(3) Mark Node **/
/**(4) Print Nodes**/
/**Make LinkedList To Store The Tasks In It **/
class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(NULL) {}

    // Function to add a node at the end of the linked list
    void addNode(string value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    // Function to print all nodes in the linked list
    void printNodes() {
        cout<<"==================="<<endl;
        unsigned int counter =1;
        if(head != NULL)
        {
        Node* current = head;
        while (current != NULL) {
            cout <<counter++<<" - "<<current->Task_str << " ("<<current->mark<<")"<<endl;
            current = current->next;
        }
        }
        else{
            cout<<"Your List Is Empty"<<endl;
        }
        cout<<"==================="<<endl;
    }

    // Function to delete a node by its index
    void deleteNode(int index) {
        if (index <=0) {
            cout << "Invalid index." << endl;
            return;
        }

        if (index == 1) {
            if (head != NULL) {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        } else {
            Node* current = head;
            Node* previous = NULL;
            int currentIndex = 1;

            while (current != NULL && currentIndex < index) {
                previous = current;
                current = current->next;
                currentIndex++;
            }

            if (current != NULL) {
                previous->next = current->next;
                delete current;
            } else {
                cout << "Index out of range." << endl;
            }
        }
    }

     void MarkNode(int index) {
        if (index <=0) {
            cout << "Invalid index." << endl;
            return;
        }
        if (index == 1) {
            if (head != NULL) {
                head->mark = 'C';
            }
        } else {
            Node* current = head;
            Node* previous = NULL;
            int currentIndex = 1;

            while (current != NULL && currentIndex < index) {
                previous = current;
                current = current->next;
                currentIndex++;
            }

            if (current != NULL) {
                current->mark = 'C';
            } else {
                cout << "Index out of range." << endl;
            }
        }
    }
};

int main() {
    short choice = 0;
    /**The user string Task**/
    string StrTask = " ";
    int Index = 0;
    LinkedList ToDoList ;
    cout<<  "-----------------------------"<<endl;
    cout << "Welcome To TO-DO LIST" << endl;
    cout<<  "-----------------------------"<<endl<<endl;
    cout<<  "Important Note >>>>> (P) >> Pending &&& (C) >> Completed"<<endl;
    cout<<  "--------------------------------------------------------"<<endl<<endl;

   while (1)
   {
    cout<<"-----------------------------"<<endl;
    cout<<"Enter Your Choice"<<endl;
    cout<<"1 - Add Task"<<endl;
    cout<<"2 - View Tasks"<<endl;
    cout<<"3 - Mark Task as Complete"<<endl;
    cout<<"4 - Remove Task"<<endl;
    cout<<"5 - Exit From The Program"<<endl;
    cout<<"-----------------------------"<<endl;
    cout<<"Enter Your Choice : ";
    cin>>choice;
    /**Repeat until enter from 1 to 5**/
    while (!((choice>0)&&(choice<6)))
        {
        cout<<"Wrong!!Enter Your Choice Correct : ";
        cin>>choice;

        }
    if(choice == 5)
    {
        cout << endl<<"Exit From The Program\n"<<endl;
        break;
    }

        switch(choice)
        {
        case(1):
            cout<<"Please Write Your Task : ";
            /**Delete buffer**/
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(cin,StrTask);
            ToDoList.addNode(StrTask);
            cout<<endl;
            StrTask = " ";
            break;

        case(2):
            cout<<endl;
            ToDoList.printNodes();
            cout<<endl;
            break;

        case(3):
            cout<<"Please Enter The Index Of The Task : ";
            cin>>Index;
            ToDoList.MarkNode(Index);
            cout<<endl;
            Index = 0;
            break;

        case(4):
            cout<<"Please Enter The Index Of The Task : ";
            cin>>Index;
            ToDoList.deleteNode(Index);
            cout<<endl;
            Index = 0;
            break;
        }
   }
    return 0;
}
