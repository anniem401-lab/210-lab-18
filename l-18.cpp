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
void outputList(Node *); // Function to output the linked list
void addAtHead(Node*&, double, string); // Function to add a node at the head
void addAtTail(Node*&, double, string); // Function to add a node at the tail

int main() 
{
    Node* head = nullptr; // Initialize the head of the linked list

    cout << endl;
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list." << endl;
    cout << "[2] New nodes are added at the tail of the linked list." << endl;

    int method;
    cout << "Enter your choice (1 or 2): ";
    cin >> method;
    while (method != 1 && method != 2) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin >> method;
    }

    // Collect reviews
    for (int i = 0; i < SIZE; ++i)
    {
        double rating;
        string comments;

        cout << "Enter review rating (0-5): ";
        cin >> rating;
        while (rating < 0 || rating > 5)
        {
            cout << "Invalid rating. Please enter a number between 0 and 5: ";
            cin >> rating;
        }

        cout << "Enter review comments: ";
        cin.ignore();
        getline(cin, comments);

        if (method == 1)
            addAtHead(head, rating, comments);
        else
            addAtTail(head, rating, comments);

        
        cout << "Enter another review? (Y/N): ";
        char anotherReview;
        cin >> anotherReview;
        anotherReview = toupper(anotherReview); // Convert to uppercase for consistency
        
        if (anotherReview == 'Y')
        cout << "You chose to enter another review." << endl;
        else if (anotherReview == 'N' && i == 4)
        break;
        else
        cout << "Invalid choice. Please enter either Y or N." << endl;
    }

    cout << "Outputting all reviews: " << endl;
    outputList(head); // Pass head pointer to outputList

    return 0;
}

// Outputs the linked list of reviews with rating first then comments
void outputList(Node *head)
{
    Node* current = head; // Pointer to traverse the list
    int reviewNum = 1; // Counter for review number
    while (current != nullptr) // Traverse until the end of the list
    {
        cout << "   > Review #" << reviewNum << ": " << current->rating << ": " << current->comments << endl; // Output ratings with comments
        current = current->next; // Move to the next node
        reviewNum++; // Increment review number
    }
}

// Adds a new node at the head of the linked list
void addAtHead(Node*& head, double rating, string comments)
{
    Node* newNode = new Node; // Create a new node
    newNode->rating = rating; // Set the rating
    newNode->comments = comments; // Set the comments
    newNode->next = head; // Point new node to the current head
    head = newNode; // Update head to the new node
}

// Adds a new node at the tail of the linked list
void addAtTail(Node*& head, double rating, string comments) 
{
    Node* newNode = new Node; // Create a new node
    newNode->rating = rating; // Set the rating
    newNode->comments = comments; // Set the comments
    newNode->next = nullptr; // New node will be the last node, so next is nullptr

    if (head == nullptr) // If the list is empty, new node becomes the head
    {
        head = newNode;
    }
    else // Otherwise, traverse to the end of the list and add the new node
    {
        Node* current = head;
        while (current->next != nullptr)
        {
            current = current->next; // Move to the next node
        }
        current->next = newNode; // Link the last node to the new node
    }
}