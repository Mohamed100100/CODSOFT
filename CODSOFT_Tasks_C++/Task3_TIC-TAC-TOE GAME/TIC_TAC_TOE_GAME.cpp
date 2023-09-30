#include <iostream>
using namespace std;

bool CheckWin(char player);
bool CheckDraw(void) ;
void DisplayBoard(void);
void InitializeBoard(void);

/**The Content Of The Board**/
char Array_Board[3][3] ;

int main() {
    cout<<  "-----------------------------"<<endl;
    cout << "Welcome To Tic-Tac-Toe-Game" << endl;
    cout<<  "-----------------------------"<<endl;
    cout<<  endl<<"Let's Play"<<endl;
    cout<<  "------------------"<<endl;
    InitializeBoard();
    /**This Variable Cary The Player Char X or O**/
    char currentPlayer = 'X';
    /**This Variable Check If GameOver or Not**/
    bool gameover = false;
    /**This Variable Control If The User Want to Continue Playing Or Not**/
    short state =0;

 while(1)
 {
     state =0;
     do {
        DisplayBoard();

        int row, col;
        cout << "Player " << currentPlayer << ", Enter Your Move (Row Then Space Then Column): ";
        cin >> row >> col;

        if (row < 1 || row > 3 || col < 1 || col > 3 || Array_Board[row - 1][col - 1] != ' ') {
            cout << "Invalid Move! Try Again." << endl;
        } else {
            Array_Board[row - 1][col - 1] = currentPlayer;

            if (CheckWin(currentPlayer)) {
                DisplayBoard();
                cout << "Player " << currentPlayer << " Wins! Congratulations!" << endl;
                gameover = true;
            } else if (CheckDraw()) {
                DisplayBoard();
                cout << "It's a Draw!" << endl;
                gameover = true;
            } else {
                if(currentPlayer== 'X')
                    currentPlayer = 'O';
                else
                currentPlayer = 'X';
            }
        }
    } while (!gameover);

    cout<<endl<<"(1)Play Again"<<endl;
    cout<<"(2)Exit"<<endl;
    cout<<endl;
    cout<<"Your Choice : ";
    cin  >>state;
    cout<<endl;
    if(state == 1)
   {
    cout<<  endl<<"Let's Play"<<endl;
    cout<<  "------------------"<<endl;
    InitializeBoard();
    currentPlayer = 'X';
    gameover = false;
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

void InitializeBoard(void)
{
    /**Make All Elements On The Board Are Spaces**/
    for(short row = 0;row<3;row++)
    {
        for(short col = 0;col<3;col++)
        {
            Array_Board[row][col] = ' ';
        }
    }
}

void DisplayBoard(void)
{
    short counter1 = 1;
    short counter2 = 1;
    cout<<  "------------------"<<endl;
    cout<<"    ";
    for(short row = 0;row<4;row++)
    {
        for(short col = 0;col<4;col++)
        {
            /**Print 1 2 3 On The First Row**/
            if((row == 0)&&(col!=0))
                cout<<" "<<(counter1++)<<"  ";

            /**Print 1 2 3 On The First Col**/
            if((col == 0)&&(row!=0))
                cout<<" "<<(counter2++)<<" "<<"|";

            /**Print The Content Of The Array Board**/
            if((row!=0)&&(col!=0))
           cout<<" "<<Array_Board[row-1][col-1]<<" "<<"|";
        }
        cout << endl;
    }
    cout<<  "------------------"<<endl;
}

bool CheckWin(char player)
 {
    // Check rows, columns, and diagonals
    for (int i = 0; i < 3; ++i) {
        if (Array_Board[i][0] == player && Array_Board[i][1] == player && Array_Board[i][2] == player) return true;
        if (Array_Board[0][i] == player && Array_Board[1][i] == player && Array_Board[2][i] == player) return true;
    }
    if (Array_Board[0][0] == player && Array_Board[1][1] == player && Array_Board[2][2] == player) return true;
    if (Array_Board[0][2] == player && Array_Board[1][1] == player && Array_Board[2][0] == player) return true;
    return false;
}

bool CheckDraw(void) {
    /**We Will Check On The Draw By Search On Empty Cell**/
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (Array_Board[i][j] == ' ') return false; // If any empty cell is found, the game is not a draw
        }
    }
    return true; // All cells are filled
}


