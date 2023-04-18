
#include "fibonacci.h"
#include <iostream>

void fillInFibonacciNumbers(int *result, int length)
{
    result[0] = 0;
    if (length == 1)
    {
        return;
    }
    result[1] = 1;
    for (int i = 2; i < length; i++)
    {
        result[i] = result[i - 1] + result[i - 2];
    }
}

void printArray(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        std::cout << arr[i] << std::endl;
    }
}

void createFibonacci()
{
    int lengthFib = 0;
    std::cout << "How many numbers do you want to generate of the Fibonacci sequence? " << std::endl;
    std::cin >> lengthFib;
    int *result = new int[lengthFib];
    fillInFibonacciNumbers(result, lengthFib);
    printArray(result, lengthFib);
    delete[] result;
    result = nullptr;
}