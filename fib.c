#include <stdio.h>

unsigned long long fibonacci(unsigned int n)
{
    unsigned long long a = 0, b = 1;

    for (unsigned int i = 0; i < n; i++)
    {

        b = a + b;
        a = b - a;
    }

    return a;
}

int main()
{
    unsigned int number;
    printf("Enter number: ");
    fflush(stdout);
    scanf("%u", &number);

    printf("The %u fibonacci number is %llu \nFibCalc \nGrzegorz Rożek \n91045", number, fibonacci(number));
    return 0;
}