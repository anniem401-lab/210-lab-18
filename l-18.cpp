// COMSC-210 | Lab 18 | Annie Morales
// IDE used: Visual Studio Code

// This program collects user input to be implemented into a linked list where each node contains a rating and a comment.

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5; // Define the number of reviews to collect

struct Node // Node structure for linked list
{
    int rating; // Rating (0-5)
    string comments; // User comments
    Node *next; // Pointer to the next node
};

// Function prototypes
void userChoice(Node *); // Function to store and display user choice

int main() 
{
    Node *head = nullptr; // Pointer to the head of the linked list
    Node *tail = nullptr; // Pointer to the tail of the linked list
    Node *current = nullptr; // Pointer for traversing the list

    userChoice(head); // Call function to get user choice

    for (int i = 0; i < SIZE; i++) // Loop to create nodes
    {
        Node* newNode = new Node; // Dynamically allocate memory for a new node

        cout << "Enter review rating (0-5): ";
        cin >> newNode->rating; // Get user rating
        cout << "Enter review comments: ";
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, newNode->comments); // Get user comments

        newNode->next = nullptr; // Initialize next pointer to nullptr

        if (head == nullptr) // If the list is empty
        {
            head = newNode; // Set head to the new node
            tail = newNode; // Set tail to the new node
        }
        else 
        {
            if (i % 2 == 0) // If user chose to add at head
            {
                newNode->next = head; // New node points to current head
                head = newNode; // Update head to the new node
            }
            else // If user chose to add at tail
            {
                tail->next = newNode; // Current tail points to new node
                tail = newNode; // Update tail to the new node
            }
        }
    }

    cout << "Outputting all reviews: " << endl;

    return 0;
}

// Stores and displays user choice
void userChoice(Node *choice)
{
    int userchoice;
    cout << endl;
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list." << endl;
    cout << "[2] New nodes are added at the tail of the linked list." << endl;

    while (true) // Loop to ensure valid input
    {
        cin >> userchoice;
    if (userchoice == 1)
        cout << "Choice: 1" << endl;
    if (userchoice == 2)
        cout << "Choice: 2" << endl;
    if (userchoice != 1 && userchoice != 2)
        cout << "Invalid choice. Please enter either 1 or 2." << endl;
    }

    cout << "Enter review rating (0-5): ";
    int rating;
    while (true) // Loop to ensure valid input
    {
        cin >> rating;
    if (rating >= 0 && rating <= 5)
        cout << "Rating: " << rating << endl;
    else
        cout << "Invalid rating. Please enter a number between 0 and 5." << endl;
    }

    cout << "Enter review comments: ";
    string userComment;
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, userComment);
    cout << "Comments: " << userComment << endl;

    cout << "Enter another review? (Y/N): ";
    char anotherReview;
    cin >> anotherReview;
}