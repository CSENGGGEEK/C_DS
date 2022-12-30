#include<stdio.h>

void is_array_sorted(int array[],int n);

void main(){
    int array[] = {1,2,3,8,5};
    is_array_sorted(array,5);
}

void is_array_sorted(int array[],int n){
    if (n==1)
    {
        printf("The array is sorted !!");
    }else{
        if (array[n-1]>array[n-2])
        {
            is_array_sorted(array,n-1);
        }else
        {
            printf("Array is not in sorted order!!");
        }        
    }
}