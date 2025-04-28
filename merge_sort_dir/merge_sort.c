#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>


// merge sort prototype
void mergesort_recursive(int *Parray, uint16_t SIZE);

int main(int argc, char **argv)
{
    if (argc < 1)
    {
        printf("Usage: ./merge_sort array");
        return 1;
    }

    // allocate memory for an array
    uint32_t SIZE = (uint32_t) (argc - 1);
    int32_t *array = (int32_t*) malloc(sizeof(int32_t) * SIZE);

    if (array == NULL)
    {
        printf("Can't allocate memory for an array. Not enough memory.\n");
        return 1;
    }

    // successfully allocated N arguments

    // populate array with user input
    for (int32_t i = 0; i < (int32_t) SIZE; i++)
    {
        array[i] = (int32_t) (strtol(*(argv + 1 + i), NULL, 10));
        printf("%i ", array[i]);
    }
    printf("\n");
    
    mergesort_recursive(array, SIZE); // sorting using merge sort, override existing array
    printf("Sorted!\n");
    for (int32_t i = 0; i < (int32_t) SIZE; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

    return 0;
}


void mergesort_recursive(int *Parray, uint16_t SIZE)
{

    // base 
    if (SIZE == 1)
    {
        return;
    }

    // recursive calls until size becomes 1
    else
    {
        // find middle with division, cast it to the nearest uint
        uint32_t middle = (uint32_t) (SIZE / 2);

        // sort left_half of the array
        
        
        // make left_half array with garbage values
        int left_half[middle];

        // populate left_half array
        for (uint32_t i = 0; i < middle; i++)
        {
            left_half[i] = Parray[i];
        }

        // sort left_half
        mergesort_recursive(&left_half[0], middle);

        // after that sort right_half of the array
        
        
        // make right_half array with garbage values
        int right_half[SIZE - middle];

        // populate right_half array
        for (uint32_t z = 0; z < SIZE - middle; z++)
        {
            right_half[z] = Parray[z + middle];
        }

        // sort right_half
        mergesort_recursive(&right_half[0], SIZE - middle);

        // sort into Parray
        //int merged_array[SIZE];

        // merge 2 halfs

        for (uint32_t l = 0, r = 0, i = 0; (l < middle) && (r < SIZE - middle) && (i < SIZE);)
        {
            // compare each other till one exceeds
            if (left_half[l] < right_half[r])
            {
                Parray[i++] = left_half[l++];
            }
            else
            {
                // right half < left_half or ==
                Parray[i++] = right_half[r++];
            }
            
            // if one of halves exceed - copy the rest
            if (l == middle) // if left
            {
                Parray[i] = right_half[r++];
            }
            else if (r == SIZE - middle) // if right
            {
                Parray[i] = left_half[l++];
            }
            // copy the rest
            /* 
            if (middle != SIZE - middle) // if size of left half != right half
            {
                // then left_half is smaller than right half. Notice: left_half must be less than right_half so the algorithm could work
                if (l < middle)
                {
                    if (left_half[l] < right_half[r])
                    {
                        Parray[i] = left_half[l]; 
                        l++, i++;
                    }
                    else
                    {
                        Parray[i] = right_half[r];
                        r++, i++;
                    }
                }
                else
                {
                    // assuming array gets exhausted
                    // copy the rest
                    Parray[i] = right_half[r];
                    r++, i++;
                }
            }
            // if size of left half and right half are equal
            else
            {
                if (left_half[l] < right_half[r])
                {
                    Parray[i] = left_half[l];
                    l++, i++;
                }
                else
                {
                    Parray[i] = right_half[r];
                    r++, i++;
                }
            }
            */
        }
    }
}