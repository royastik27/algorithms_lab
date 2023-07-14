#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int weight;
    int profit;
}Item;

bool cmp(Item a, Item b)
{
    return double(a.profit) / a.weight > double(b.profit) / b.weight;
}

int main()
{
    int n, capacity, i, total_weight;
    double x, profit;
    Item item[1000];

    cout << "Enter the number of items: ";
    cin >> n;
    
    cout << "Enter the details of each item (weight, profit):\n";
    for(i = 0; i < n; ++i)
    {
        cout << "Item " << (i+1) << ": ";
        cin >> item[i].weight >> item[i].profit;
    }
    
    cout << "Enter the capacity of the knapsack: ";
    cin >> capacity;

    sort(item, item+n, cmp);
    
    total_weight = profit = 0;
    for(i = 0; i < n && total_weight < capacity; ++i)
    {
        if(total_weight + item[i].weight <= capacity)
        {
            x = 1;
            total_weight += item[i].weight;
        }
        else
        {
            x = double(capacity - total_weight) / item[i].weight;
            total_weight = capacity;
        }

        profit += x * item[i].profit;
    }

    cout << "Maximum profit: " << profit << '\n';

    return 0;
}