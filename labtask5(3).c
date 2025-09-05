#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10   // size of hash table

// Node structure for chaining
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Hash Table (array of pointers)
Node* hashTable[SIZE];

// Hash function
int hashFunction(int key) {
    return key % SIZE;
}

// Insert into hash table
void insert(int key) {
    int index = hashFunction(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("%d inserted successfully.\n", key);
}

// Search in hash table
bool search(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key)
            return true;
        temp = temp->next;
    }
    return false;
}

// Delete from hash table
void delete(int key) {
    int index = hashFunction(key);
    Node* temp = hashTable[index];
    Node* prev = NULL;

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("%d not found in Hash Table.\n", key);
        return;
    }

    if (prev == NULL) {
        // first node in chain
        hashTable[index] = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("%d deleted successfully.\n", key);
}

// Display hash table
void display() {
    for (int i = 0; i < SIZE; i++) {
        printf("[%d]: ", i);
        Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int choice, key;

    while (1) {
        printf("\n--- Hash Table Menu ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search(key))
                    printf("%d found in Hash Table.\n", key);
                else
                    printf("%d not found in Hash Table.\n", key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
