#include <iostream>

using namespace std;

void merge(int a[], int low, int mid, int high)
{
    int b[1000], k = low, i = low, j = mid+1, p;

    while(i <= mid && j <= high)
    {
        if(a[i] <= a[j])
        {
            b[k++] = a[i];
            i++;
        }
        else
        {
            b[k++] = a[j];
            j++;
        }
    }

    // filling the rests
    if(i > mid)
    {
        for(p = j; p <= high; ++p)
            b[k++] = a[p];
    }
    else
    {
        for(p = i; p <= mid; ++p)
            b[k++] = a[p];
    }

    // copying
    for(p = low; p <= high; ++p)
        a[p] = b[p];
}

void merge_sort(int a[], int low, int high)
{
    if(low < high)
    {
        int mid = (low+high) / 2;

        merge_sort(a, low, mid);
        merge_sort(a, mid+1, high);
        merge(a, low, mid, high);
    }
}

int main()
{
    int n, arr[1000], i;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the items: ";
    for(i = 0; i < n; ++i)
        cin >> arr[i];

    merge_sort(arr, 0, n-1);

    cout << "The sorted items are: ";
    for(i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}