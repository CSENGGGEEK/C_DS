#include<stdio.h>

void main(){
    int a[10],min_num,min_index,temp;

    // Taking user input
    for (int i = 0; i < 10; i++)
    {
        printf("A[%d] = ",i);
        scanf("%d",&a[i]);
    }

    // Iterating over the array
    for (int i = 0; i < 10; i++)
    {

        min_num = 5464;
        min_index = 52;
        // Calculating the minimum element in the remaining subarray
        for (int j = i; j < 10; j++)
        {
            if (a[j]<min_num)
            {
                min_num = a[j];
                min_index = j;
            }
        }
        // Swapping the current element and element at minimum index
        temp = a[i];
        a[i] = min_num;
        a[min_index] = temp;
    }

    // Printing the whole array
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }
    

}