// Function to subtract two large numbers represented as linked lists
#include "header.h"
/*
 * Subtraction of Large Numbers Using Doubly Linked Lists
 *
 * Subtracts two large numbers represented as doubly linked lists.
 *
 * Input: Two linked lists representing numbers, each node storing up to 4 digits.
 * Output: A new linked list representing the difference.
 */

void sub(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result)
{
    int borrow = 0;
    *head_result = NULL;
    *tail_result = NULL;
    while (tail1 != NULL || tail2 != NULL || borrow != 0)
    {
        int data1 = (tail1 != NULL) ? tail1->data : 0;
        int data2 = (tail2 != NULL) ? tail2->data : 0;
        int difference = data1 - data2 - borrow;

        // Handle borrowing if the difference is negative
        if (difference < 0)
        {
            difference += 10000;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        // Insert the calculated difference into the result linked list at the beginning
        insert_at_beginning(head_result, tail_result, difference);
        if (tail1 != NULL)
        {
            tail1 = tail1->prev; // Move to the previous node in the first number
        }
        if (tail2 != NULL)
        {
            tail2 = tail2->prev; // Move to the previous node in the second number
        }
    }
    while (*head_result != NULL && (*head_result)->data == 0)
    {
        cal *temp = *head_result;
        *head_result = (*head_result)->next;
        if (*head_result != NULL)
        {
            (*head_result)->prev = NULL;
        }
        free(temp);
    }
    if (*head_result == NULL)
    {
        insert_at_beginning(head_result, tail_result, 0);
    }
}
