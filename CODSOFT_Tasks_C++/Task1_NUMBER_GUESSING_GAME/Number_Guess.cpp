#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

#define MAX_NUM    1000
#define MIN_NUM    0

/** This Function Will Generate Random Number Between MAX_NUM & MIN_NUM**/
int generateRandomNumber(void);

int main() {
    /**This Flag To Check If The User Guess The Number Or Not**/
    unsigned short flag  =0;
    /**This Variable For Know If The User Want To Try Again Or Not**/
    unsigned short state =0;
    /**This Variable For Know How Many Counts does The User Take To Guess The Number**/
    unsigned short Counter =0;
    /**This Variable For Store The User Number**/
    unsigned int User_Random_Number = 0;
    /**This Variable For Store Real Random Number**/
    unsigned int random_number = generateRandomNumber();
    cout<< "-----WELCOME-----" << endl<< endl;

while (1)
{   flag = 0;
   while (flag ==0)
   {
    cout<< "Guess The Number : ";
    cin >> User_Random_Number;

    if(User_Random_Number == random_number )
    {
        cout<< endl<<"Congratulations " << endl;
        cout<< "You Take " << (Counter+1)<<" Times"<<endl;
        cout<< "The Random Number Is : " << User_Random_Number<<endl<<endl;
        Counter = 0;
        flag = 1;
    }
    else if(User_Random_Number > random_number)
        {
            Counter++;
            cout<< "Too High" << endl<<endl;
        }
        else if(User_Random_Number < random_number)
            {
                Counter++;
                cout<< "Too Low" << endl<<endl;
            }
   }

   cout<<"(1)Try Again"<<endl;
   cout<<"(2)Exit"<<endl;
   cout<<endl;
   cout<<"Your Choice : ";
   cin  >>state;
   cout<<endl;
   if(state == 1)
   {
    random_number = generateRandomNumber();
   }
   else if(state == 2)
    {
    cout << "Exit From The Program\n";
    break;
    }
    else
    {
    cout<<"Wrong Choice !!"<<endl;
    break;
    }
}
    return 0;
}


int generateRandomNumber(void)
{
    /**Set The Seed For the random number generator (Using the current time)**/
    srand(time(0));
    /**Generate The Random Number Between 0 and 100 to Set Another Seed not linear With time**/
    unsigned int RealSeed = rand()%100;
    srand(RealSeed);
    /**Generate The Random Number Between The MAX_NUM & MIN_NUM **/
    /**You Can Change This Range Using The Macros At The Beginning of The Code **/
    return (rand()%(MAX_NUM-MIN_NUM-1));
}
