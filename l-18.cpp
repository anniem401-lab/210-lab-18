// COMSC-210 | Lab 18 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream>
using namespace std;

void userChoice();

int main() 
{
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list." << endl;
    cout << "[2] New nodes are added at the tail of the linked list." << endl;
    userChoice();
    
    return 0;
}

void userChoice()
{
    int userchoice;
    cin >> userchoice;
    if (userchoice == 1)
        cout << "Choice: 1" << endl;
    else if (userchoice == 2)
        cout << "Choice: 2" << endl;
    else
        cout << "Invalid choice. Please enter either 1 or 2." << endl;
}