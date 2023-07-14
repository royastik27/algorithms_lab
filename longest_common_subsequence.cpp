#include <iostream>

using namespace std;

int main()
{
    int sz1, sz2, c[100][100], i, j;
    string str1, str2;

    cout << "Enter the first string: ";
    cin >> str1;

    cout << "Enter the second string: ";
    cin >> str2;

    sz1 = str1.length();
    sz2 = str2.length();

    for(i = 0; i <= sz1; ++i)
        c[0][i] = 0;

    for(i = 0; i <= sz2; ++i)
        c[i][0] = 0;

    for(i = 1; i <= sz1; ++i)
    {
        for(j = 1; j <= sz2; ++j)
        {
            if(str1[i-1] == str2[j-1])  // working with 0-based index
                c[i][j] = 1 + c[i-1][j-1];
            else
                c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    }

    cout << "Length of the longest common subsequence: " << c[sz1][sz2] << '\n';

    return 0;
}