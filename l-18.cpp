// COMSC-210 | Lab 18 | Annie Morales
// IDE used: Visual Studio Code

// This program collects user input to be implemented into a linked list where 
// each node contains a rating and a comment. The user can choose to add new nodes
// at either the head or the tail of the linked list. After collecting the reviews,
// the program outputs all reviews along with the average rating. 

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
void deleteList(Node*& head); // Function to delete the linked list and free memory

int main() 
{
    Node* head = nullptr; // Initialize the head of the linked list

    cout << endl;
    cout << "Which linked list method should we use?" << endl;
    cout << "[1] New nodes are added at the head of the linked list." << endl;
    cout << "[2] New nodes are added at the tail of the linked list." << endl;
    cout << "--------------------------------------------------------" << endl;

    int method;
    cout << "Enter your choice (1 or 2): ";
    cin >> method;
    while (method != 1 && method != 2) {
        cout << "Invalid choice. Please enter 1 or 2: ";
        cin >> method;
    }

    // Collects reviews from the user and add them to the linked list
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
        if (anotherReview == 'Y' || anotherReview == 'y')
        cout << "You chose to enter another review." << endl;
        else if (anotherReview == 'N' || anotherReview == 'n')
        break; 
        else
        cout << "Invalid choice. Please enter either Y or N." << endl;
    }
    cout << endl;
    cout << "Outputting all reviews: " << endl;
    outputList(head); // Pass head pointer to outputList
    cout << endl;
    deleteList(head); // Free memory allocated for the linked list
    return 0;
}

// Outputs the linked list of reviews with rating first then comments
// Arguments: head pointer
// Returns: void
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

    // Displays the average rating of all reviews
    if (head == nullptr) 
    { // If the list is empty
        cout << "No reviews to calculate average rating." << endl;
    } 
    else 
    {
        double sum = 0.0; // Sum of ratings
        int count = 0; // Count of reviews
        current = head; // Reset current to head
        while (current != nullptr) 
        {
            sum += current->rating; // Add rating to sum
            count++; // Increment count
            current = current->next; // Move to the next node
        }
        double average = sum / count; // Calculate average
        cout << "   > Average: " << average << endl; // Output average rating
    }
}

// Adds a new node at the head of the linked list
// Arguments: reference to head pointer, rating, comments
// Returns: void
void addAtHead(Node*& head, double rating, string comments)
{
    Node* newNode = new Node; // Create a new node
    newNode->rating = rating; // Set the rating
    newNode->comments = comments; // Set the comments
    newNode->next = head; // Point new node to the current head
    head = newNode; // Update head to the new node
}

// Adds a new node at the tail of the linked list
// Arguments: reference to head pointer, rating, comments
// Returns: void
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

// Deletes the entire linked list to free memory
// Arguments: reference to head pointer
// Returns: void
void deleteList(Node*& head)
{
    Node* current = head;
    Node* nextNode;

    while (current != nullptr) {
        nextNode = current->next; // Store the next node
        delete current; // Delete the current node
        current = nextNode; // Move to the next node
    }
    head = nullptr; // Set head to nullptr after deletion
    cout << "Linked list deleted and memory freed." << endl << endl;
}