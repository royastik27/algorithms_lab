#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if(n == 0)
        return 0;
    else if(n == 1)
        return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);    
}

int main()
{
    int n, i;

    cout << "Enter the number of fibonacci numbers to generate: ";
    cin >> n;

    cout << "\nFibonacci numbers:\n";
    for(i = 0; i < n; ++i)
        cout << fibonacci(i) << ' ';
    cout << '\n';

    return 0;
}