#include <iostream>
using namespace std;

class Node 
{
public:
    int data;
    string insertedFrom;
    Node* next;

    Node(int data, string insertedFrom) 
    {
        this->data = data;
        this->insertedFrom = insertedFrom;
        this->next = nullptr;
    }
};

class LinkedList 
{
private:
    Node* head;
    Node* tail;
    bool insertAtHead; // To alternate between head and tail insertion

public:
    LinkedList() 
    {
        head = nullptr;
        tail = nullptr;
        insertAtHead = true; // Start with inserting at the head
    }

    void insert(int data) 
    {
        if (insertAtHead) 
        {
            // Insert at head
            Node* newNode = new Node(data, "Head");
            newNode->next = head;
            head = newNode;
            if (tail == nullptr) 
            {
                tail = head; // If it's the first node, head and tail are the same
            }
        } 
        else 
        {
            // Insert at tail
            Node* newNode = new Node(data, "Tail");
            if (tail != nullptr) 
            {
                tail->next = newNode;
            }
            tail = newNode;
            if (head == nullptr) 
            {
                head = tail; // If it's the first node, head and tail are the same
            }
        }
        insertAtHead = !insertAtHead; // Toggle between head and tail
    }

    void display() 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            cout << "Data: " << temp->data << ", Inserted from: " << temp->insertedFrom << endl;
            temp = temp->next;
        }
    }

    ~LinkedList() 
    {
        // Free the memory to avoid memory leaks
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) 
        {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() 
{
    LinkedList list;

    // Inserting nodes
    list.insert(60);
    list.insert(70);
    list.insert(20);
    list.insert(800);

    // Display the list
    cout << "Linked List:" << endl;
    list.display();

    return 0;
}