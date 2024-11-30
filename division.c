#include "header.h"
#include <stdlib.h>
#include <stdio.h>

// Function to perform division of two large numbers represented as linked lists
// The result (quotient) is stored in the linked list *head_result and *tail_result
void division(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result)
{
    cal *quotient_head = NULL, *quotient_tail = NULL;   // Linked list for storing the quotient
    cal *remainder_head = NULL, *remainder_tail = NULL; // Linked list for storing the remainder

    // Check if the divisor is zero (leading to division by zero error)
    if (head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Error: Division by zero.\n");
        return; // Exit the function if division by zero is attempted
    }

    // Initialize the remainder to 0 (insert a node with 0)
    insert_at_beginning(&remainder_head, &remainder_tail, 0);

    // Traverse through the dividend (head1 represents the dividend)
    while (head1 != NULL)
    {
        // Append the current digit from the dividend to the remainder
        insert_at_end(&remainder_head, &remainder_tail, head1->data);
        head1 = head1->next; // Move to the next digit of the dividend

        // Remove any leading zeros from the remainder
        while (remainder_head != NULL && remainder_head->data == 0)
        {
            cal *temp = remainder_head;
            remainder_head = remainder_head->next; // Remove the leading zero
            if (remainder_head != NULL)
                remainder_head->prev = NULL; // Adjust the previous pointer of the new head
            free(temp);                      // Free the node that was removed
        }

        // If the remainder is smaller than the divisor, add 0 to the quotient
        if (compare_linked_lists(remainder_head, head2) < 0)
        {
            insert_at_end(&quotient_head, &quotient_tail, 0); // Add 0 to quotient
        }
        else
        {
            // If the remainder is larger or equal to the divisor, divide
            int quotient_digit = 0;

            // Perform repeated subtraction to find how many times the divisor fits into the remainder
            while (compare_linked_lists(remainder_head, head2) >= 0)
            {
                cal *temp_result_head = NULL, *temp_result_tail = NULL;

                // Subtract the divisor from the remainder to update the remainder
                sub(remainder_head, remainder_tail, head2, tail2, &temp_result_head, &temp_result_tail);

                remainder_head = temp_result_head; // Update the remainder to the result of subtraction
                remainder_tail = temp_result_tail;
                quotient_digit++; // Increment the quotient digit for each successful subtraction
            }

            // Add the quotient digit to the quotient linked list
            insert_at_end(&quotient_head, &quotient_tail, quotient_digit);
        }
    }

    // Remove leading zeros from the quotient (if any)
    while (quotient_head != NULL && quotient_head->data == 0)
    {
        cal *temp = quotient_head;
        quotient_head = quotient_head->next; // Remove the leading zero
        if (quotient_head != NULL)
            quotient_head->prev = NULL; // Adjust the previous pointer of the new head
        free(temp);                     // Free the node that was removed
    }

    // If the quotient is empty, it means the result is 0, so we set the quotient to 0
    if (quotient_head == NULL)
    {
        insert_at_beginning(&quotient_head, &quotient_tail, 0); // Set quotient to 0 if empty
    }

    // Set the result pointers to the head and tail of the quotient
    *head_result = quotient_head;
    *tail_result = quotient_tail;
}
