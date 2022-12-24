#include <stdio.h>

void display(int sanjay[], int limit)
{
    int i = 0;
    for (; i < limit; i++)
    {
        printf("%d\t", sanjay[i]);
    }
    printf("\n");
}

int partition(int sanjay[], int low, int high)
{
    int i, j;
    i = low + 1;
    // int pivot = sanjay[low];
    j = high;
    int temp;
    do
    {

        while (sanjay[i] <= sanjay[low] || sanjay[j] > sanjay[low])
        {
            if (sanjay[i] <= sanjay[low])
            {

                i++;
            }
            if (sanjay[j] > sanjay[low])
            {
                j--;
            }
        }
        // while (sanjay[j] > sanjay[low])
        // {
        //     j--;
        // }
        if (i < j)
        {
            temp = sanjay[j];
            sanjay[j] = sanjay[i];
            sanjay[i] = temp;
        }
    } while (i < j);

    temp = sanjay[j];
    sanjay[j] = sanjay[low];
    sanjay[low] = temp;
    return j;
}

void Quick_Sort(int sanjay[], int low, int high)
{
    int indexpartition;
    if (low < high)
    {
        indexpartition = partition(sanjay, low, high);
        Quick_Sort(sanjay, low, indexpartition - 1);
        Quick_Sort(sanjay, indexpartition + 1, high);
    }
}

void main()
{
    int size;
    printf("Enter total number of array element : ");
    scanf("%d", &size);
    int arr[size];
    int i;
    for (i = 0; i < size; i++)
    {
        printf("Enter %d no element of your array : ", (i + 1));
        scanf("%d", &arr[i]);
    }
    printf("\n");
    display(arr, size);
    Quick_Sort(arr, 0, size - 1);
    display(arr, size);
}