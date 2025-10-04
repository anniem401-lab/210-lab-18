// COMSC-210 | Lab 18 | Annie Morales
// IDE used: Visual Studio Code

#include <iostream>
#include <string>
using namespace std;

void userChoice();
void userRatings();
void userComments();

int main() 
{
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list." << endl;
    cout << "[2] New nodes are added at the tail of the linked list." << endl;
    userChoice();

    cout << "Enter review rating (0-5): ";
    userRatings();

    cout << "Enter review comments: ";
    userComments();

    cout << "Add another review? (Y/N): ";
    char anotherReview;
    cin >> anotherReview;


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

void userRatings()
{
    int rating;
    cin >> rating;
    if (rating >= 0 && rating <= 5)
        cout << "Rating: " << rating << endl;
    else
        cout << "Invalid rating. Please enter a number between 0 and 5." << endl;
}

void userComments()
{
    string comments;
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, comments);
    cout << "Comments: " << comments << endl;
}