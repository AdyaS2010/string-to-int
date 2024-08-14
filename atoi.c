#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    // Base case: empty string -> return 0
    if (strlen(input) == 0)
    {
        return 0;
    }
    // Get index of last char in string
    int last_index = strlen(input) - 1; // index starts from 0... hence, -1 from string length
    // Convert last char into its numeric value
    int last_digit = input[last_index] - '0';
    // Remove last char from string -> move null terminator 1 position left
    input[last_index] = '\0';
    // Return resulting value + 10 * int value of the new, shortened string.
    return last_digit + (10 * convert(input)); 
}
