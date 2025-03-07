// Function to perform addition of two numbers represented as doubly linked lists
#include "header.h"
/*  
 * Addition of Large Numbers Using Doubly Linked Lists  
 *  
 * Adds two large numbers represented as doubly linked lists.  
 *  
 * Input: Two linked lists representing numbers, each node storing up to 4 digits.  
 * Output: A new linked list representing the sum.  
 */

void add(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result)
{
    int carry = 0;
    while (tail1 != NULL || tail2 != NULL || carry != 0)
    {
        int sum = carry; 
        if (tail1 != NULL)
        {
            sum = sum + tail1->data; 
            tail1 = tail1->prev;    
        }
        if (tail2 != NULL)
        {
            sum = sum + tail2->data; 
            tail2 = tail2->prev;     
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
