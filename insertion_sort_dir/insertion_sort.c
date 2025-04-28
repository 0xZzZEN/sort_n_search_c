#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void insertion_sort(int64_t *Parray, uint64_t *PN);
void print_array(int64_t *Parray, uint64_t *PN);

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage: ./insertion_sort num1 (...) \n");
        return 1;
    }
    
    // num of elements (2^16 max)
    uint64_t N = argc - 1; // int64_t - signed long int
    
    // create an empty array of N size

    // allocate memory for an array
    int64_t *array = (int64_t *) malloc(sizeof(int64_t) * N);
    if (array == NULL)
    {
        printf("Can't allocate memory for an array. Not enough memory.\n");
        return 1;
    }
    
    // memory successfully allocated, so now array has garbage values inside

    // convert string literals to long integer and populate the array

    // make nptr to store possible number from current argv
    char *nptr;

    // make endptr to store invalid values of provided string
    char *endptr;
    
    for (uint64_t i = 0; i < N; i++)
    {
        nptr = *(argv + 1 + i);
        long int val = strtol(nptr, &endptr, 10);
        if (*nptr == *endptr)
        {
            printf("No digits were found in argv[%li]. Use only base 10.\n", i);
            return 2;
        }
        if (*endptr != '\0')
        {
            printf("argv[%li]: \"%s\". Further characters after number are discarded: \"%s\"\n", i, nptr, endptr);
        }
        *(array + i) = val;
        printf("array[%li]: %li\n", i, val);
    }
    // array has been created

    insertion_sort(array, &N); // sort array

    printf("Sorted!\n");
    print_array(array, &N);

    free(array);
    return 0;
}

void print_array(int64_t *Parray, uint64_t *PN)
{
    for (uint64_t i = 0; i < *PN; i++)
    {
        printf("array[%li]: %li\n", i, Parray[i]);
    }
}

void insertion_sort(int64_t *Parray, uint64_t *PN)
{
    for (uint64_t i = 1; i < *PN; i++) // first element is already sorted in the subarray, so we start from 1
    {
        int64_t key = Parray[i];

        int64_t j = i - 1; // to make comparison between key and sorted to find correct position for the key
        
        /* potential issue: overflow if uint64_t > int64_t, since 2^64-1 is max for int64_t, but who would make such insane comparison with insertion_sort?*/
        
        // find the position and insert key into sorted subarray (size Parray[0: i - 1])
        for (; ((j >= 0) && (Parray[j] > key)); j--) // walkthrough last element (i - 1) of sorted array to the first and compare each with key to find position
        {
            Parray[j + 1] = Parray[j];
        }
        Parray[j + 1] = key;
        printf("Shifting..\n");
        print_array(Parray, PN);
    }
}

/*
Loop invariant: At the beginning of each iteration of the outer loop (for i from 1 to *PN - 1), the subarray Parray[0...i-1] is sorted in non-decreasing order.
    Initialization: prior to the first iteration of the outer loop, subarray Parray[j] is already sorted, because we start from the i = 1 there j = i - 1 
                    and Parray[0..j-1] = Parray[0], therefore loop invariant holds.
    Maintenance: prior to the (i = k) outer loop (where i <= k < *PN) step, (there j starts with = k - 1), inner loop finishes with j < 0 || Parray[j] <= key:
        if it has finished with j < 0:
            the loop went through all the elements and shifted them to the right Parray[j+1] = Parray[j]
        if it finishes with Parray[j] <= key:
            there all the elements of the sorted subarray Parray[k-1] are on the right place, i.e. they are already sorted
        after that the key went to Parray[j+1] = key 
        Parray[j] is less than or equal to key. This means the correct position for key is immediately after Parray[j].
        therefore, subarray Parray[k] became sorted.
    therefore loop invariant holds. Parray[0..k-1] and subarray Parray[k]
    
    Termination: outer loop finishes with i = *PN, such thing lead to sorted array Parray[0..*PN], the loop invraiant remains true
    Therefore, the algorithm is correct.
*/

/*
Вот сравнение максимальных значений для int64_t и uint64_t:

int64_t (знаковое 64-битное целое число):

Минимальное значение: −9,223,372,036,854,775,808 (−(2 
63
 ))
Максимальное значение: +9,223,372,036,854,775,807 (2 
63
 −1)
uint64_t (беззнаковое 64-битное целое число):

Минимальное значение: 0
Максимальное значение: +18,446,744,073,709,551,615 (2 
64
 −1)

*/