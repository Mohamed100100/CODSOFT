#include <iostream>

using namespace std;

float Add(float x, float y);
float Subtract(float x, float y);
float Multiply(float x, float y);
short Divide(float x, float y,float *z);

int main() {
    int operation_ID = 0;
    float operand1;
    float operand2;
    float result = 0;
    /**This Variable Control Division On Zero **/
    short state = 1;
    cout << "---------------------------\n";
    cout << "Welcome In The Program\n";

while(1)
{
    cout << "---------------------------\n";
    cout << "Enter Your Operation\n";
    cout << "---------------------------\n";
    cout << "1-Add\n";
    cout << "2-Subtract\n";
    cout << "3-Multiply\n";
    cout << "4-Divide\n";
    cout << "5-Exit\n";
    cout << "---------------------------\n";

    cout << "Please Enter the operation ID : ";
    cin >> operation_ID;
    cout<<endl;

    if(operation_ID == 5)
    {
        cout << "Exit From The Program\n";
        break;
    }

    switch (operation_ID) {
        case 1: {
            cout << "Now Enter Two operands \n";
            cout << "Enter First operand : ";
            cin >> operand1;
            cout << "Enter second operand : ";
            cin >> operand2;
            result = Add(operand1, operand2);
            cout << "Result = " << result << endl<< endl;
            break;
        }
        case 2:
            cout << "Now Enter Two operands \n";
            cout << "Enter First operand : ";
            cin >> operand1;
            cout << "Enter second operand : ";
            cin >> operand2;
            result = Subtract(operand1, operand2);
            cout << "Result = " << result << endl<< endl;
            break;

        case 3:
            cout << "Now Enter Two operands \n";
            cout << "Enter First operand : ";
            cin >> operand1;
            cout << "Enter second operand : ";
            cin >> operand2;
            result = Multiply(operand1, operand2);
            cout << "Result = " << result << endl<< endl;
            break;

        case 4:
            cout << "Now Enter Two operands \n";
            cout << "Enter First operand : ";
            cin >> operand1;
            cout << "Enter second operand : ";
            cin >> operand2;

            state = Divide(operand1, operand2,&result);
            if(state ==1)
            cout << "Result = " << result << endl<< endl;
            break;

        default : cout <<"Wrong Choice!!"<<endl<< endl;break;
        }


}
    return 0;
}

float Add(float x, float y) {
    return x + y;
}

float Subtract(float x, float y) {
    return x - y;
}

float Multiply(float x, float y) {
    return x * y;
}

short Divide(float x, float y,float *z) {
    if (y == 0) {
        cout << "Wrong ,Divide On Zero!!" << endl<< endl;
        return 0;
    } else {
        *z = x/y;
        return 1;
    }
}

