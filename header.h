#ifndef HEADER_H
#define HEADER_H


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
// Enum for function success or failure status
typedef enum
{
    failure,
    success,
} Status;

// Linked list node definition
typedef struct cal
{
    int data;         // Data of the node (integer value)
    struct cal *prev; // Pointer to the previous node
    struct cal *next; // Pointer to the next node
} cal;

// Functions related to linked list operations
void insert_at_beginning(cal **head, cal **tail, int data); // Insert at the beginning of the list
void insert_at_end(cal **head, cal **tail, int data);       // Insert at the end of the list
void free_linked_list(cal *head);                           // Free the entire linked list
void reverse_list(cal **head, cal **tail);                  // Reverse the linked list
void print(cal *head);                                      // Print the entire list
void print_list(cal *head, int is_negative);                // Print the list with handling for negative numbers
void print_result_addition(cal *head);                      // Print the result of addition
int compare_linked_lists(cal *head1, cal *head2);

// Functions for large number arithmetic
void add(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result);      // Addition
void sub(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result);      // Subtraction
void multiply(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result); // Multiplication
void division(cal *head1, cal *tail1, cal *head2, cal *tail2, cal **head_result, cal **tail_result); // Division

// Utility and validation functions
Status read_and_validation(int argc, char *argv[]);                                                // Read and validate input
void create_linked_list_from_string(cal **head, cal **tail, const char *number, int *is_negative); // Create linked list from string

// Global variable for result sign (used in some functions)
extern int is_result_negative;

#endif // HEADER_H
