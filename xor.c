 
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
 
// Structure of a node
// in XOR linked list

struct Node {
 

    // Stores data value

    // of a node

    int data;
 

    // Stores XOR of previous

    // pointer and next pointer

    struct Node* nxp;
};
 
// Function to find the XOR of two nodes

struct Node* XOR(struct Node* a,

                 struct Node* b)
{

    return (struct Node*)((uintptr_t)(a)

                          ^ (uintptr_t)(b));
}
 
// Function to insert a node with
// given value at given position

struct Node* insert(struct Node** head,

                    int value, int position)
{

    // If XOR linked list is empty

    if (*head == NULL) {
 

        // If given position

        // is equal to 1

        if (position == 1) {
 

            // Initialize a new Node

            struct Node* node

                = (struct Node*)malloc(

                    sizeof(struct Node));
 

            // Stores data value in

            // the node

            node->data = value;
 

            // Stores XOR of previous

            // and next pointer

            node->nxp = XOR(NULL, NULL);
 

            // Update pointer of head node

            *head = node;

        }
 

        // If required position was not found

        else {

            printf("Invalid Position\n");

        }

    }
 

    // If the XOR linked list

    // is not empty

    else {
 

        // Stores position of a node

        // in the XOR linked list

        int Pos = 1;
 

        // Stores the address

        // of current node

        struct Node* curr = *head;
 

        // Stores the address

        // of previous node

        struct Node* prev = NULL;
 

        // Stores the XOR of next

        // node and previous node

        struct Node* next

            = XOR(prev, curr->nxp);
 

        // Traverse the XOR linked list

        while (next != NULL && Pos < position - 1) {
 

            // Update prev

            prev = curr;
 

            // Update curr

            curr = next;
 

            // Update next

            next = XOR(prev, curr->nxp);
 

            // Update Pos

            Pos++;

        }
 

        // If the position of the current

        // node is equal to the given position

        if (Pos == position - 1) {
 

            // Initialize a new Node

            struct Node* node

                = (struct Node*)malloc(

                    sizeof(struct Node));
 

            // Stores pointer to previous Node

            // as (prev ^ next ^ next) = prev

            struct Node* temp

                = XOR(curr->nxp, next);
 

            // Stores XOR of prev and new node

            curr->nxp = XOR(temp, node);
 

            // Connecting new node with next

            if (next != NULL) {
 

                // Update pointer of next

                next->nxp = XOR(node,

                                XOR(next->nxp, curr));

            }
 

            // Connect node with curr and

            // next curr<--node-->next

            node->nxp = XOR(curr, next);

            node->data = value;

        }
 

        // Insertion node at beginning

        else if (position == 1) {
 

            // Initialize a new Node

            struct Node* node

                = (struct Node*)malloc(

                    sizeof(struct Node));
 

            // Update curr node address

            curr->nxp = XOR(node,

                            XOR(NULL, curr->nxp));
 

            // Update new node address

            node->nxp = XOR(NULL, curr);
 

            // Update head

            *head = node;
 

            // Update data value of

            // current node

            node->data = value;

        }

        else {

            printf("Invalid Position\n");

        }

    }

    return *head;
}
 
// Function to print elements of
// the XOR Linked List

void printList(struct Node** head)
{

    // Stores XOR pointer

    // in current node

    struct Node* curr = *head;
 

    // Stores XOR pointer of

    // in previous Node

    struct Node* prev = NULL;
 

    // Stores XOR pointer of

    // in next node

    struct Node* next;
 

    // Traverse XOR linked list

    while (curr != NULL) {
 

        // Print current node

        printf("%d ", curr->data);
 

        // Forward traversal

        next = XOR(prev, curr->nxp);
 

        // Update prev

        prev = curr;
 

        // Update curr

        curr = next;

    }
}
 
// Driver Code

int main()
{

    /* Create following XOR Linked List

    head-->20<-->40<-->10<-->30 */

    struct Node* head = NULL;

    insert(&head, 10, 1);

    insert(&head, 20, 1);

    insert(&head, 30, 3);

    insert(&head, 40, 2);
 

    // Print the new list

    printList(&head);
 

    return (0);
}
