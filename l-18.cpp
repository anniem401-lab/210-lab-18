// COMSC-210 | Lab 18 | Annie Morales
// IDE used: Visual Studio Code

// This program collects user input to be implemented into a linked list where each node contains a rating and a comment.

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 5; // Define the number of reviews to collect

struct Node // Node structure for linked list
{
    double rating; // Rating (0-5)
    string comments; // User comments
    Node *next; // Pointer to the next node
};

// Function prototypes
Node* userChoice(); // Function to store and display user choice
void outputList(Node *); // Function to output the linked list

int main() 
{
    Node* head = nullptr; // Declare and initialize head pointer
    head = userChoice(); // Call function to get user choice
    
    cout << "Outputting all reviews: " << endl;
    outputList(head); // Call function to output the linked list

    return 0;
}

// Stores and displays user choice
Node* userChoice()
{
    Node* userchoice = new Node;
    cout << endl;
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list." << endl;
    cout << "[2] New nodes are added at the tail of the linked list." << endl;

    while (true) // Loop to ensure valid input
    {
        cin >> userchoice->rating;
    if (userchoice->rating == 1)
        cout << "Choice: 1" << endl;
    else if (userchoice->rating == 2)
        cout << "Choice: 2" << endl;
    else if (userchoice->rating != 1 && userchoice->rating != 2)
        cout << "Invalid choice. Please enter either 1 or 2." << endl;

    cout << "Enter review rating (0-5): ";
    double rating;
        cin >> rating;
    if (rating >= 0 && rating <= 5)
        cout << "Rating: " << rating << endl;
    else
        cout << "Invalid rating. Please enter a number between 0 and 5." << endl;
    
        cout << "Enter review comments: ";
    string userComment;
    cin.ignore(); // To ignore the newline character left in the buffer
    getline(cin, userComment);
    cout << "Comments: " << userComment << endl;

    cout << "Enter another review? (Y/N): ";
    char anotherReview;
    cin >> anotherReview;
    anotherReview = toupper(anotherReview); // Convert to uppercase for consistency
    if (anotherReview == 'Y')
        cout << "You chose to enter another review." << endl;
    else if (anotherReview == 'N')
        cout << "You chose not to enter another review." << endl;
    else
        cout << "Invalid choice. Please enter either Y or N." << endl;
    
    if (anotherReview == 'N')
        break; // Exit the loop if user does not want to enter another review
    }
    return userchoice; // Return the user choice node
}

// Outputs the linked list
void outputList(Node *head)
{
    Node *current = head; // Start from the head of the list
    Node *tail = nullptr; // Pointer to the tail of the linked list
    for (int i = 0; i < SIZE; i++) // Loop to create nodes
    {
        Node* newNode = new Node; // Dynamically allocate memory for a new node

        cin >> newNode->rating; // Get user rating
        cin.ignore(); // To ignore the newline character left in the buffer
        getline(cin, newNode->comments); // Get user comments

        newNode->next = nullptr; // Initialize next pointer to nullptr

        if (head == nullptr) // If the list is empty
        {
            head = newNode; // Set head to the new node
            tail = newNode; // Set tail to the new node
            current = head; // Update current pointer
        }
        else 
        {
            if (i % 2 == 0) // If user chose to add at head
            {
                newNode->next = head; // New node points to current head
                head = newNode; // Update head to the new node
                current = head; // Update current pointer
            }
            else // If user chose to add at tail
            {
                tail->next = newNode; // Current tail points to new node
                tail = newNode; // Update tail to the new node
            }
        }
    }

    current = head; // Reset current to head for traversal
    while (current != nullptr) // Traverse the list
    {
        cout << "Rating: " << current->rating << endl; // Output rating
        cout << "Comments: " << current->comments << endl; // Output comments
        current = current->next; // Move to the next node
    }
}