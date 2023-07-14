#include <iostream>
// #include <algorithm>

using namespace std;

int binary_search(int a[], int left, int right, int x)
{
    if(left > right)
        return -1;
    else if(left == right)
    {
        if(a[left] == x)
            return left;
        else
            return -1;        
    }
    else
    {
        int mid = (left + right) / 2;

        if(a[mid] == x)
            return mid;
        else if(x < a[mid])
            return binary_search(a, left, mid-1, x);
        else
            return binary_search(a, mid+1, right, x);
    }
}

int main()
{
    int n, arr[1000], i, x;

    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the items in sorted order: ";
    for(i = 0; i < n; ++i)
        cin >> arr[i];

    cout << "Enter the item to search: ";
    cin >> x;

    // sort(arr, arr+n);
    int res = binary_search(arr, 0, n-1, x);

    if(res == -1)
        cout << "Item is not in the list.\n";
    else
        cout << "Found the item at position " << (res+1) << '\n';    

    return 0;
}