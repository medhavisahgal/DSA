#include <bits/stdc++.h>
using namespace std;
int main()
{
    // select the minimum then swap the content basically selecting and swapping
    int n = 5;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++)
        {
            if (a[mini] > a[j])
            {
                mini = j;
            }
        }
        int temp = a[mini];
        a[mini] = a[i];
        a[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    //-----------Time Complexity----------------
    //               O(n^2)
    //-----------Space Complexity----------------
    //               O(1)
}
