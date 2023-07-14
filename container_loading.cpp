#include <iostream>
#include <algorithm>

using namespace std;

typedef struct
{
    int id;
    int weight;
}Item;

bool cmp(Item a, Item b)
{
    return a.weight < b.weight;
}

int main()
{
    int n, capacity, i, total_weight;
    Item item[1000];
    bool taken[1000] = {};

    cout << "Enter the capacity of the container: ";
    cin >> capacity;

    cout << "Enter the number of items to load: ";
    cin >> n;

    cout << "Enter the weights of the items:\n";
    for(i = 0; i < n; ++i)
    {
        cout << "w" << (i+1) << ": ";
        cin >> item[i].weight;

        item[i].id = i;
    }

    sort(item, item+n, cmp);

    total_weight = 0;
    for(i = 0; i < n; ++i)
    {
        if(total_weight + item[i].weight <= capacity)
        {
            total_weight += item[i].weight;
            taken[item[i].id] = true;
        }
        else
            break;
    }

    cout << "Solution: ";
    for(i = 0; i < n; ++i)
    {
        if(taken[i])
            cout << "w" << (i+1) << ' ';
    }
    cout << '\n';

    return 0;
}