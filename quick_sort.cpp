#include <iostream>
#include <climits>

using namespace std;

#define INF INT_MAX;

void interchange(int a[], int i, int j)
{
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;

    return;
}

int partition(int a[], int beg, int end)
{
    int temp = a[end];
    a[end] = INF;

    int pivot = a[beg], i = beg+1, j = end;

    while(i < j)
    {
        while(a[i] < pivot)
            ++i;

        while(a[j] > pivot)
            --j;

        if(i < j)
            interchange(a, i, j);
    }
    
    // now a[j] is less than or equal to pivot
    a[beg] = a[j];
    a[j] = pivot;
    
    a[end] = temp;

    return j;
}

void quick_sort(int a[], int beg, int end)
{
    if(beg < end)
    {
        int j = partition(a, beg, end+1);

        quick_sort(a, beg, j-1);
        quick_sort(a, j+1, end);
    }

    return;
}

int main()
{
    int n, arr[1000], i;

    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the items: ";
    for(i = 0; i < n; ++i)
        cin >> arr[i];

    quick_sort(arr, 0, n-1);

    cout << "The sorted items are: ";
    for(i = 0; i < n; ++i)
        cout << arr[i] << ' ';
    cout << '\n';

    return 0;
}