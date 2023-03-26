#include <stdio.h>
#include <math.h>
void mergesort(int A[], int p, int r);
void merge(int A[], int p, int q, int r);

void main()
{

    int a[10];

    for (int i = 0; i < 10; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    mergesort(a, 0, 9);

    printf("Sorted subarray is : ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
}

void mergesort(int A[], int p, int r)
{
    if (p < r)
    {
        // Calculating the mid point
        int q = floor((r + p) / 2);

        // Calling the same function for left subarray 
        mergesort(A, p, q);

        // Calling the same function for right subarray
        mergesort(A, q + 1, r);

        // Merging those subarray after sorting
        merge(A, p, q, r);
    }
}

void merge(int A[], int p, int q, int r)
{
    // Calculating the number of elements in the left and right subarray 
    int n1 = q - p + 1;
    int n2 = r - q;

    // Declaring some variables for interating
    int k, l, m;

    // Declaring left and right subarray with their size we have calculated above 
    int L[n1], R[n2];

    // Populating the left subarray
    for (int i = 0; i < n1; i++)
    {
        // Assigning the elements into the Left subarray with the elements at (p+i)th position in original array
        L[i] = A[p + i];
    }

    // Populating the right subarray 
    for (int j = 0; j < n2; j++)
    {
        // Assigning the elements into the Left subarray with the elements at (p+i)th position in original array
        R[j] = A[q + j + 1];
    }

    // Starting with the initial index of both subarrays as 0
    l = 0;
    m = 0;

    // Starting with lower bound
    k = p;

    // While one or both the arrays are finished
    while ( l < n1 && m < n2)
    {
        // Compare the lth element in left subarray with mth element in right subarray 
        if (L[l] <= R[m])
        {
            // Assign the kth element in original arary with lth element of left subarray
            A[k] = L[l];

            // Increment the index for left subarray
            l++;
        }
        else
        {
            // Assign the mth element in right subarray to kth element in original array
            A[k] = R[m];

            // Increment the index for right subarray
            m++;
        }
        k++;
    }

    // Copy the remaining elements of left subarray if there are any
    while (l < n1) {
        A[k] = L[l];
        l++;
        k++;
    }

    // Copy the remaining elements of right subarray if there are any
    while (m < n2)
    {
        A[k] = R[m];
        m++;
        k++;
    }
}