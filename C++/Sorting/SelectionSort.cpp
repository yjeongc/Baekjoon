#include <iostream>

void SelSort(int arr[], int n)
{
    int i, j;
    int maxIdx;
    int temp;

    for (i=0; i<n-1;i++)
    {
        maxIdx = i;

        for (j=i+1; j<n; j++)
        {
            if(arr[j] < arr[maxIdx])
            maxIdx = j;
        }

        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;

    }
}

int main()
{
    int arr[4] = {3,4,2,1};
    int i;

    SelSort(arr, sizeof(arr)/sizeof(int));

    for(i=0; i<4; i++)
        std::cout << arr[i] << " ";

    std::cout << std::endl;
    
    return 0;
}

