// Function to multiply two large numbers represented as linked lists
#include "header.h"
/*Multiplies two large numbers stored as linked lists and computes the product.
 * Input: Multiplicand (head1, tail1), Multiplier (head2, tail2)
 * Output: Product (head_result, tail_result)  */
void multiply(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result)
{
    *head_result = NULL;
    *tail_result = NULL;

    cal *temp_tail2 = tail2;
    int shift = 0;
    while (temp_tail2 != NULL)
    {
        int carry = 0;
        cal *temp_result_head = NULL, *temp_result_tail = NULL;
        cal *temp_tail1 = tail1;
        while (temp_tail1 != NULL)
        {
            int product = temp_tail1->data * temp_tail2->data + carry;
            carry = product / 10000;
            product = product % 10000;
            insert_at_beginning(&temp_result_head, &temp_result_tail, product);
            temp_tail1 = temp_tail1->prev;
        }

        // If there is any remaining carry, add it to the result
        if (carry > 0)
        {
            insert_at_beginning(&temp_result_head, &temp_result_tail, carry);
        }
        for (int i = 0; i < shift; i++)
        {
            insert_at_end(&temp_result_head, &temp_result_tail, 0);
        }
        cal *accumulated_result_head = NULL, *accumulated_result_tail = NULL;
        add(*head_result, *tail_result, temp_result_head, temp_result_tail, &accumulated_result_head, &accumulated_result_tail); // Add the two numbers
        *head_result = accumulated_result_head;
        *tail_result = accumulated_result_tail;
        temp_tail2 = temp_tail2->prev;
        shift++;
    }
}

// Function to insert a value at the end of a doubly linked list
void insert_at_end(cal **head, cal **tail, int value)
{
    cal *new_node = (cal *)malloc(sizeof(cal));
    if (new_node == NULL)
    {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = value;
    new_node->next = NULL;
    new_node->prev = *tail;

    if (*tail != NULL)
    {
        (*tail)->next = new_node;
    }
    *tail = new_node;
    if (*head == NULL)
    {
        *head = new_node;
    }
}
