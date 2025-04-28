#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// function prototype
int number binary_search(int *sorted_array, int number);

// can't use binary_search unless the array is sorted!
int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: ./binary_search sorted_elements(any size)\n");
        return 1;
    }
    
    // create array
    uint32_t N = argc - 1; // number of elements in the array

    int *unsorted_array = malloc(sizeof(int) * (argc - 1)); // calculate how many bytes will be used. For ex: 4 ints => 4 * 4bytes => 16 bytes
    if (unsorted_array == NULL)
    {
        printf("Not enough memory. Closing the program\n");
        return 1;
    }

    printf("Allocated unsorted_array size in bytes: %lu\nN = %u\n", sizeof(*unsorted_array) * N, N); // debug to see the malloc size
    // array successfully created
    for (int i = 0; i < N; i++) // iterate through char *argv
    {
        // initialize array
        unsorted_array[i] = strtoul(*(argv + i + 1), NULL, 10); // syntactic sugar: argv[i + 1] = *(argv + i + 1), *(argv + i + 2) - NUL Terminator // 
    }

    // determine the size of the array:
    for (int i = 0; i < N; i++)
    {
        printf("unsorted_array[%i] = %i\n", i, unsorted_array[i]);
    }

    free(unsorted_array);
    return 0;
}

int *element_position binary_search(int *sorted_array, int number)
{
    // find middle
    uint16_t middle = sorted_array[N / 2]; 
    if (number == middle)
    {
        return middle;
    }
    else if (number < middle)
    {
        return binary_search(sorted_array[middle / 2], number)
    }
    else if (number > middle)
    {
        return binary_search(sorted_array[middle / 2], number)    
    }
    else
    {
        return -1;
    }
}