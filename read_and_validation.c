// Command-Line Argument Validation  
#include "header.h"
/*  
 * Validates the number format and operator in user input.  
 *  
 * Input: Command-line arguments (operand1, operator, operand2)  
 * Output: Returns success if valid, failure otherwise  
 */

// Function to validate the command-line arguments for the operation
Status read_and_validation(int argc, char *argv[])
{
    // Check if the number of arguments is less than 4
    if (argc < 4)
    {
        printf("Error: Invalid argument count. Usage: <operand1> <operator> <operand2>\n");
        return failure; // Return failure if there are not enough arguments
    }

    // Extract the operator (second argument) from the input
    char *operator= argv[2];
    // Check if the operator is valid (+, -, x, or /)
    if (strcmp(operator, "+") != 0 && strcmp(operator, "-") != 0 && strcmp(operator, "x") != 0 && strcmp(operator, "/") != 0)
    {
        printf("Error: Invalid operator. Valid operators are +, -, x, /\n");
        return failure; // Return failure if the operator is not valid
    }

    // Extract the first operand (first argument) from the input
    char *operand_1 = argv[1];
    int i = 0;

    // Check if the first operand starts with a '+' or '-' (indicating a sign)
    if (operand_1[i] == '+' || operand_1[i] == '-')
    {
        i++; // Skip the sign character
    }

    // Check if all remaining characters in operand_1 are digits
    for (; operand_1[i] != '\0'; i++)
    {
        if (!isdigit(operand_1[i])) // If a non-digit character is found
        {
            printf("Error: Operand 1 contains invalid characters. Only digits are allowed.\n");
            return failure; // Return failure if any non-digit character is found
        }
    }

    // Extract the second operand (third argument) from the input
    char *operand_2 = argv[3];
    i = 0;

    // Check if the second operand starts with a '+' or '-' (indicating a sign)
    if (operand_2[i] == '+' || operand_2[i] == '-')
    {
        i++; // Skip the sign character
    }

    // Check if all remaining characters in operand_2 are digits
    for (; operand_2[i] != '\0'; i++)
    {
        if (!isdigit(operand_2[i])) // If a non-digit character is found
        {
            printf("Error: Operand 2 contains invalid characters. Only digits are allowed.\n");
            return failure; // Return failure if any non-digit character is found
        }
    }

    // If all validations pass, return success
    return success;
}
