/*  
 * Large Number Calculator  
 *  
 * Performs arithmetic operations (+, -, x, /) on large numbers using linked lists.  
 *  
 * Input: Two large numbers (as strings) and an operator  
 * Output: Computed result as a linked list  
 */

#include "header.h"
int is_result_negative = 0; 
void set_result_negative(int *is_negative)
{
    *is_negative = 1;
}

int main(int argc, char *argv[])
{
    // Validate input arguments
    if (read_and_validation(argc, argv) == failure)
    {
        return failure; // Exit if validation fails
    }

    // Initialize linked list pointers for operands and result
    cal *head1 = NULL, *tail1 = NULL;
    cal *head2 = NULL, *tail2 = NULL;
    cal *head_result = NULL, *tail_result = NULL;

    char ch = argv[2][0];                   // Extract the operator from the second argument
    int is_negative1 = (argv[1][0] == '-'); // Check if the first number is negative
    int is_negative2 = (argv[3][0] == '-'); // Check if the second number is negative

    // Create linked lists from the input numbers
    create_linked_list_from_string(&head1, &tail1, argv[1], &is_negative1);
    create_linked_list_from_string(&head2, &tail2, argv[3], &is_negative2);

    // Print the input linked lists for debugging
    print(head1);
    print(head2);

    // Handle addition operation
    if (ch == '+')
    {
        if (is_negative1 == is_negative2)
        {
            // If both numbers have the same sign, perform simple addition
            add(head1, tail1, head2, tail2, &head_result, &tail_result);
            if (is_negative1)
            {
                set_result_negative(&is_result_negative); // Set result as negative if both inputs are negative
            }
        }
        else
        {
            // If numbers have different signs, perform subtraction
            if (compare_linked_lists(head1, head2) >= 0)
            {
                sub(head1, tail1, head2, tail2, &head_result, &tail_result);
                if (is_negative1)
                {
                    set_result_negative(&is_result_negative); // Result is negative if the larger number is negative
                }
            }
            else
            {
                sub(head2, tail2, head1, tail1, &head_result, &tail_result);
                if (is_negative2)
                {
                    set_result_negative(&is_result_negative);
                }
            }
        }
    }
    // Handle subtraction operation
    else if (ch == '-')
    {
        if (is_negative1 == is_negative2)
        {
            // If both numbers have the same sign, perform subtraction
            if (compare_linked_lists(head1, head2) >= 0)
            {
                sub(head1, tail1, head2, tail2, &head_result, &tail_result);
                if (is_negative1)
                {
                    set_result_negative(&is_result_negative);
                }
            }
            else
            {
                sub(head2, tail2, head1, tail1, &head_result, &tail_result);
                if (!is_negative1)
                {
                    set_result_negative(&is_result_negative);
                }
            }
        }
        else
        {
            // If numbers have different signs, perform addition
            add(head1, tail1, head2, tail2, &head_result, &tail_result);
            if (is_negative1)
            {
                set_result_negative(&is_result_negative);
            }
        }
    }
    // Handle multiplication operation
    else if (ch == 'x')
    {
        multiply(head1, tail1, head2, tail2, &head_result, &tail_result);
        if (is_negative1 != is_negative2)
        {
            set_result_negative(&is_result_negative); // Result is negative if inputs have opposite signs
        }
    }
    // Handle division operation
    else if (ch == '/')
    {
        division(head1, tail1, head2, tail2, &head_result, &tail_result);
        if (is_negative1 != is_negative2)
        {
            set_result_negative(&is_result_negative); // Result is negative if inputs have opposite signs
        }
    }
    else
    {
        // Unsupported operator
        printf("Error: Unsupported operator '%c'.\n", ch);
        free_linked_list(head1); // Free allocated memory
        free_linked_list(head2);
        return failure;
    }

    // Handle edge case: if the result is zero, reset negative flag
    if (head_result == NULL || (head_result->data == 0 && head_result->next == NULL))
    {
        is_result_negative = 0;
    }

    // Print the result
    print_list(head_result, is_result_negative);

    // Free allocated memory for linked lists
    free_linked_list(head1);
    free_linked_list(head2);
    free_linked_list(head_result);

    return 0; // Exit successfully
}
