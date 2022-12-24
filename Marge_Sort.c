#include <stdio.h>

void dispaly(int sanjay[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", sanjay[i]);
    }
    printf("\n");
}

void marge(int sanjay[], int low, int mid, int high)
{
    // int size = sizeof(sanjay) / sizeof(int);
    int temp[50];
    int i, j, k, m;
    i = k = m = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (sanjay[i] < sanjay[j])
        {
            temp[k] = sanjay[i];
            i++;
            k++;
        }
        else
        {
            temp[k] = sanjay[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        temp[k] = sanjay[i];
        i++;
        k++;
    }
    while (j <= high)
    {
        temp[k] = sanjay[j];
        j++;
        k++;
    }

    for (m; m <= high; m++)
    {
        sanjay[m] = temp[m];
    }
}

void marge_Sort(int sanjay[], int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        marge_Sort(sanjay, low, mid);
        marge_Sort(sanjay, (mid + 1), high);
        marge(sanjay, low, mid, high);
    }
}
void main()
{
    int size;
    printf("Enter total number of your array : ");
    scanf("%d", &size);

    int arr[size];
    int i;

    for (i = 0; i < size; i++)
    {
        printf("Enter the %d no element of your array : ", (i + 1));
        scanf("%d", &arr[i]);
    }

    dispaly(arr, size);
    marge_Sort(arr, 0, size);
    printf("\n");
    dispaly(arr, size);
}