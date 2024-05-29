#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int convert(string input);
int recursive_atoi(string input, int size);

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
    printf("%i\n", recursive_atoi(input, strlen(input)));
}

// Iterative implementation of atoi function
int convert(string input)
{
    int size = strlen(input);
    int result = 0;

    for (int i = 0; i < size; i++)
        result += (input[size - i - 1] - '0') * pow(10, i);
    return (result);
}

// Recursive implementation of atoi function
int recursive_atoi(string input, int size)
{
    if (size == 0)
        return (0);
    // Maybe this is not necessary...
    // if (size == 1)
    //     return (*input - '0');
    return (10 * recursive_atoi(input, size - 1) + input[size - 1] - '0');
}
