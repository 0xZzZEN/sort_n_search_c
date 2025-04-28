#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


void selection_sort(long int *Parray, uint32_t *PN);
void swap(long int *pA, long int *pB);

// ex: ./selection_sort 3 2 1

int main(int argc, char **argv)
{
    uint32_t N = argc - 1;
    long int *array = (long int*)malloc(sizeof(long int)* N);
    if ((array == NULL) || (argc <= 3))
    {
        return 1;
    }

    // allocation succeed and num of argc >= 3

    // make an array from argv
    for (uint32_t i = 0; i < N; i++)
    {
        *(array + i) = strtol(*(argv + 1 + i), NULL, 10);
        printf("%li ", array[i]);
    }
    printf("\n");
    printf("Succesfully made an array of %u (N) size (%lu in bytes)\n", N, sizeof(array) * N);
    
    selection_sort(&array[0], &N);
    // print sorted_array
    printf("Sorted array: ");
    for (uint32_t i = 0; i < N; i++)
    {
        printf("%li ", array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}

void selection_sort(long int *Parray, uint32_t *PN)
{
    for (uint32_t m = 0; m < *PN; m++)
    {
        long int min = Parray[m]; // let element (first is array[0]) be the smallest so we can compare (TIP: randomness selection here could benefit?)
        uint32_t min_index = m; 
        // find min
        for (uint32_t i = m + 1; i < *PN; i++) // m is offset so we only should find min in the subset which isn't sorted yet
        {
            if (Parray[i] < min)
            {
                min = Parray[i];
                min_index = i;
            }
        }
        // smallest element found, so we can sort it via swapping by swapping with first unsorted element
        swap(&Parray[m], &Parray[min_index]);
        
        /*debug*/
        printf("%u swap: ", m);
        for (uint32_t test = 0; test < *PN; test++)
        {
            printf("%li ", Parray[test]);
        }
        printf("\n");
        /*end debug*/
    }
    // sorting done, return
    return;
}
void swap(long int *pA, long int *pB)
{
    int temp = *pA;
    *pA = *pB;
    *pB = temp;
}