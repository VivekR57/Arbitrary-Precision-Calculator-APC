#include "header.h"
#include <stdlib.h>
#include <stdio.h>

// Function to multiply two large numbers represented as linked lists
void multiply(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result)
{
    *head_result = NULL; // Initialize the result linked list (quotient) to be empty
    *tail_result = NULL;

    cal *temp_tail2 = tail2; // Pointer to traverse the second number (head2 to tail2)
    int shift = 0;           // Number of places to shift the partial result for each digit of the second number

    // Traverse the second number from least significant to most significant digit (tail to head)
    while (temp_tail2 != NULL)
    {
        int carry = 0;                                          // To hold any carry from multiplying digits
        cal *temp_result_head = NULL, *temp_result_tail = NULL; // Temporarily store the current result
        cal *temp_tail1 = tail1;                                // Pointer to traverse the first number (head1 to tail1)

        // Multiply each digit of the first number by the current digit of the second number
        while (temp_tail1 != NULL)
        {
            int product = temp_tail1->data * temp_tail2->data + carry;          // Multiply and add carry from previous digit
            carry = product / 10000;                                            // Calculate the new carry (carry over for the next digit)
            product = product % 10000;                                          // Get the remainder (the current product digit)
            insert_at_beginning(&temp_result_head, &temp_result_tail, product); // Insert the product digit at the beginning of the partial result
            temp_tail1 = temp_tail1->prev;                                      // Move to the previous digit of the first number
        }

        // If there is any remaining carry, add it to the result
        if (carry > 0)
        {
            insert_at_beginning(&temp_result_head, &temp_result_tail, carry); // Insert the carry as a new node
        }

        // Shift the result to the left by the current shift amount (multiply by 10^shift)
        for (int i = 0; i < shift; i++)
        {
            insert_at_end(&temp_result_head, &temp_result_tail, 0); // Append 0s to the end of the result (shifting left)
        }

        // Add the current partial result to the accumulated result (head_result holds the total result)
        cal *accumulated_result_head = NULL, *accumulated_result_tail = NULL;
        add(*head_result, *tail_result, temp_result_head, temp_result_tail, &accumulated_result_head, &accumulated_result_tail); // Add the two numbers

        // Update the result with the accumulated result
        *head_result = accumulated_result_head;
        *tail_result = accumulated_result_tail;

        // Move to the next digit of the second number (move leftwards in the linked list)
        temp_tail2 = temp_tail2->prev;
        shift++; // Increment the shift (for the next digit of the second number)
    }
}

// Function to insert a value at the end of a doubly linked list
void insert_at_end(cal **head, cal **tail, int value)
{
    cal *new_node = (cal *)malloc(sizeof(cal)); // Allocate memory for the new node
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return; // Return if memory allocation fails
    }

    new_node->data = value; // Set the data of the new node
    new_node->next = NULL;  // The new node will be the last node, so next is NULL
    new_node->prev = *tail; // Set the previous pointer of the new node to the current tail

    if (*tail != NULL)
    {
        (*tail)->next = new_node; // Link the old tail's next pointer to the new node
    }

    *tail = new_node; // Update the tail pointer to the new node

    if (*head == NULL) // If the list is empty, set the new node as the head
    {
        *head = new_node;
    }
}
