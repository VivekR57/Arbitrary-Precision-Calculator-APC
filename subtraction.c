#include "header.h"
#include <stdlib.h>
#include <stdio.h>

// Function to subtract two large numbers represented as linked lists
void sub(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result)
{
    int borrow = 0; // To track borrowing during subtraction

    // Initialize the result linked list to be empty
    *head_result = NULL;
    *tail_result = NULL;

    // Traverse both lists from least significant to most significant digit
    // The loop continues until all nodes are processed, and there is no more borrow
    while (tail1 != NULL || tail2 != NULL || borrow != 0)
    {
        // Get the current digit of both numbers, or 0 if the list has ended
        int data1 = (tail1 != NULL) ? tail1->data : 0; // Current digit of the first number
        int data2 = (tail2 != NULL) ? tail2->data : 0; // Current digit of the second number

        // Calculate the difference between the current digits, considering the borrow
        int difference = data1 - data2 - borrow;

        // Handle borrowing if the difference is negative
        if (difference < 0)
        {
            difference += 10000; // Assuming 4-digit segments, wrap around the difference
            borrow = 1;          // Set the borrow flag for the next iteration
        }
        else
        {
            borrow = 0; // No borrow needed if the difference is non-negative
        }

        // Insert the calculated difference into the result linked list at the beginning
        insert_at_beginning(head_result, tail_result, difference);

        // Move to the previous nodes in both lists (move left in the linked list)
        if (tail1 != NULL)
        {
            tail1 = tail1->prev; // Move to the previous node in the first number
        }
        if (tail2 != NULL)
        {
            tail2 = tail2->prev; // Move to the previous node in the second number
        }
    }

    // Remove leading zeros from the result (if any)
    while (*head_result != NULL && (*head_result)->data == 0)
    {
        cal *temp = *head_result;
        *head_result = (*head_result)->next;

        // Set the previous pointer of the new head to NULL
        if (*head_result != NULL)
        {
            (*head_result)->prev = NULL;
        }

        // Free the memory of the removed node
        free(temp);
    }

    // If the result list is empty (i.e., no digits left), insert 0 as the result
    if (*head_result == NULL)
    {
        insert_at_beginning(head_result, tail_result, 0);
    }
}
