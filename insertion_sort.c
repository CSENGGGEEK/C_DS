#include<stdio.h>

int main(){
    int a[10],key,j;

    // Taking User input
    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = ",i);
        scanf("%d",&a[i]);
    }

    // Interating an array with starting from index 1
    for (int i = 1; i < 10; i++)
    {
        // Storing the element to compare
        key = a[i];

        // Interating the left subarray fron index i-1 to 0
        for (j = i-1; j >= 0; j--)
        {
            // Comparing the key from each element in the left subarray
            // If it occurs shifting that element rightwards 
            if (a[j]>key)
            {
                // Incrementing the position or index 
                a[j+1] = a[j];
            }
        }
        // Storing the value into the required position
        a[j+1] = key;
    }
    
    // Printing the array 
    for (int i = 0; i < 10; i++)
    {
        printf("%d  ",a[i]);
    }

    return 0;
}

/*
    a[0] = 9
    a[1] = 8
    a[2] = 7
    a[3] = 6
    a[4] = 5
    a[5] = 4
    a[6] = 3
    a[7] = 2
    a[8] = 1
    a[9] = 0

    0  1  2  3  4  5  6  7  8  9 
*/