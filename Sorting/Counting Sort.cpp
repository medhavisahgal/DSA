#include <bits/stdc++.h>
using namespace std;
void countingSort(vector<int> &a)
{
    // must given info
    // 1)input size
    // 2)range is k
    int maxele = *max_element(a.begin(), a.end());
    vector<int> freq(maxele, 0);
    for (auto x : a)
    {
        freq[x]++;
    }
    int cnt = 0;
    int minele = *min_element(a.begin(), a.end());
    for (int i = minele; i <= maxele; i++)
    {
        fill(a.begin() + cnt, a.begin() + cnt + freq[i], i);
        cnt += freq[i];
    }
}
int main()
{
    vector<int> arr = {9, 4, 7, 6, 3, 1, 5};
    int n = 7;

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    countingSort(arr);
    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
//-----------Time Complexity----------------
//               O(n^2)
//-----------Space Complexity---------------
//               O(1)
