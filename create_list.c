#include "header.h"

// Function to insert a node at the beginning of the doubly linked list
void insert_at_beginning(cal **head, cal **tail, int value)
{
    cal *new_node = malloc(sizeof(cal)); // Allocate memory for a new node
    if (new_node == NULL)                // Check if memory allocation fails
    {
        printf("Memory allocation failed\n");
        return;
    }

    new_node->data = value; // Set the node's data to the passed value
    new_node->prev = NULL;  // No previous node for the new node
    new_node->next = NULL;  // No next node for the new node

    // If the list is empty, set both head and tail to the new node
    if (*head == NULL)
    {
        *head = new_node; // Set head to the new node
        *tail = new_node; // Set tail to the new node
    }
    else
    {
        // Insert at the beginning by adjusting pointers
        new_node->next = *head;   // Make the new node point to the old head
        (*head)->prev = new_node; // Make the old head point back to the new node
        *head = new_node;         // Update the head to the new node
    }
}

// Function to create a linked list from a string representation of a number
// The number could be negative, and is processed in chunks of 4 digits
void create_linked_list_from_string(cal **head, cal **tail, const char *number, int *is_negative)
{
    // Check if the number is negative
    if (number[0] == '-')
    {
        *is_negative = 1; // Set the negative flag
        number++;         // Skip the negative sign
    }
    else if (number[0] == '+')
    {
        *is_negative = 0; // Set the positive flag
        number++;         // Skip the positive sign
    }

    int length = strlen(number); // Get the length of the number string
    while (length > 0)
    {
        int len = (length >= 4) ? 4 : length; // Process the number in chunks of 4 digits
        char digits[5];                       // Temporary buffer to store up to 4 digits
        int start = length - len;             // Calculate the starting index for the chunk
        for (int i = 0; i < len; i++)         // Copy the digits into the buffer
        {
            digits[i] = number[start + i];
        }
        digits[len] = '\0'; // Null-terminate the digits string

        int value = atoi(digits);               // Convert the chunk of digits to an integer
        insert_at_beginning(head, tail, value); // Insert the integer value at the beginning of the list
        length -= len;                          // Decrease the remaining length to process
    }
}

// Function to free the memory allocated for the linked list
void free_linked_list(cal *head)
{
    while (head != NULL)
    {
        cal *temp = head;  // Store the current node
        head = head->next; // Move to the next node
        free(temp);        // Free the current node
    }
}

// Function to print the linked list
// If the number is negative, it prints a negative sign before the digits
void print_list(cal *head, int is_negative)
{
    if (head == NULL) // Check if the list is empty
    {
        printf("INFO : List is empty\n");
        return;
    }

    if (is_negative) // Print the negative sign if the number is negative
    {
        printf("-");
    }

    // Traverse the linked list and print each node
    while (head)
    {
        // Add leading zeros for numbers less than 4 digits (except for the first node)
        if (head->prev != NULL)
        {
            if (head->data < 10)
                printf("000"); // Print three leading zeros
            else if (head->data < 100)
                printf("00"); // Print two leading zeros
            else if (head->data < 1000)
                printf("0"); // Print one leading zero
        }

        printf("%d", head->data); // Print the current node's data

        head = head->next; // Move to the next node
    }
    printf("\n"); // New line after printing the list
}

// Function to compare two linked lists (head1 and head2)
// Returns 1 if the first list is greater, -1 if the second is greater, and 0 if they are equal
int compare_linked_lists(cal *head1, cal *head2)
{
    // Compare lengths of the linked lists
    int node_count1 = 0, node_count2 = 0;
    cal *temp1 = head1, *temp2 = head2;
    while (temp1) // Count the nodes in the first list
    {
        node_count1++;
        temp1 = temp1->next;
    }
    while (temp2) // Count the nodes in the second list
    {
        node_count2++;
        temp2 = temp2->next;
    }

    // Compare the lengths of the lists
    if (node_count1 > node_count2)
    {
        return 1; // List 1 is greater
    }
    else if (node_count1 < node_count2)
    {
        return -1; // List 2 is greater
    }

    // If lengths are equal, compare the data in each node
    cal *node1 = head1, *node2 = head2;
    while (node1 && node2)
    {
        if (node1->data > node2->data)
        {
            return 1; // List 1 is greater
        }
        else if (node1->data < node2->data)
        {
            return -1; // List 2 is greater
        }
        node1 = node1->next; // Move to the next node in the first list
        node2 = node2->next; // Move to the next node in the second list
    }

    return 0; // Lists are equal
}

// Function to print the list in a readable format with arrows showing the links between nodes
void print(cal *head)
{
    if (head == NULL) // Check if the list is empty
    {
        printf("INFO : List is empty\n");
    }
    else
    {
        printf("Head -> ");
        while (head) // Traverse and print the list
        {
            printf("%d <-", head->data); // Print the data of the current node

            head = head->next; // Move to the next node
            if (head)          // If there's a next node, print an arrow
                printf("> ");
        }
        printf(" Tail\n"); // Print "Tail" at the end of the list
    }
}
