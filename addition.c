#include "header.h"
#include <stdlib.h>
#include <stdio.h>

// Function to perform addition of two numbers represented as doubly linked lists
void add(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result)
{
    int carry = 0; // Initialize carry to 0 for addition

    // Loop through both lists from their least significant digit (tail) to the most significant digit (head)
    while (tail1 != NULL || tail2 != NULL || carry != 0)
    {
        int sum = carry; // Start with the carry from the previous addition

        // Add the data from the first list if it is not NULL
        if (tail1 != NULL)
        {
            sum = sum + tail1->data; // Add the current digit of the first list
            tail1 = tail1->prev;     // Move to the previous node in the first list
        }

        // Add the data from the second list if it is not NULL
        if (tail2 != NULL)
        {
            sum = sum + tail2->data; // Add the current digit of the second list
            tail2 = tail2->prev;     // Move to the previous node in the second list
        }

        // Calculate the carry for the next iteration
        carry = sum / 10000; // Each node can hold up to 4 digits (base 10,000)
        sum = sum % 10000;   // Extract the remaining 4-digit value

        // Insert the calculated sum into the result list at the beginning
        insert_at_beginning(head_result, tail_result, sum);
    }

    // If there is any remaining carry after processing both lists, add it to the result list
    if (carry != 0)
    {
        insert_at_beginning(head_result, tail_result, carry);
    }
}
