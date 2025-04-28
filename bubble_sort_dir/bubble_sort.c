#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void bubble_sort(int array[], int *pN);
void swap(int *Pa, int *Pb);

void swap(int *Pa, int *Pb)
{
    int temp = *Pa;
    *Pa = *Pb;
    *Pb = temp;
}


void bubble_sort(int *Parray, int *pN)
{
    // walkthrough on each element in the array, starting from 0
    for (uint32_t i = 0; i < *pN - 1; i++)
    {
        uint32_t swap_counter = 0;
        // limit the sorted portion, so each pass sorted element will "bubble" right
        for (uint32_t p = 0; p < *pN - 1 - i; p++)
        {
            // compare each element with the next, if larger -> do swap
            if (Parray[p] > Parray[p + 1])
            {
                swap(&Parray[p], &Parray[p + 1]);
                swap_counter += 1;
            }
            /*debug*/
            printf("%u swap of array[%i] el: ", swap_counter, i);
            for (uint32_t test = 0; test < *pN; test++)
            {
                printf("%i ", Parray[test]);
            }
            printf("\n");
            /*end debug*/
        }
        // when swapping is finished -> the last element will be sorted
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Please provide any array input: ex: ./bubble_sort 2\n");
        return 1;
    }

    // allocate memory to an array
    int N = argc - 1;
    int *array = (int *)malloc(sizeof(int) * N);
    if (array == NULL)
    {
        printf("Can't allocate memory to the new array. Not enough memory.\n");
        return 1;
    }

    //memory successfully allocated, iterate through argc to store values inside array

    for (uint32_t i = 0; i < N; i++)
    {
        *(array + i) = strtol(*(argv + i + 1), NULL, 10);
        printf("%i ", *(array + i));
    }
    printf("\nArray created successfully. N = %i, bytes = %lu\n", N, sizeof(*(array)) * N);

    // bubble sort
    bubble_sort(array, &N);
    
    for (uint32_t i = 0; i < N; i++)
    {
        printf("%i ", *(array + i));
    }
    printf("\nSorted with bubble sort. \n");

    free(array);
    return 0;
}