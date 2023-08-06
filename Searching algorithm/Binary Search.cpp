#include<iostream>
#include<vector>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    int s;
    cout<<"Element you want to find"<<endl;
    cin>>s;
    int low=0;
    int high=n-1;
    bool found=false;
    while(low<=high)
    {
        int mid=low+(high-low)/2;
        if(a[mid]==s)
        {
            cout<<"Element found at index "<<mid<<endl;
            found=true;
            break;
        }
        else if(a[mid]<s)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    if(!found)
    {
        cout<<"Element not found"<<endl;
    }
    return 0;
}
//               BINARY SEARCH
//              TIME COMPLEXITY
//    BEST    |    AVGERAGE        |   WORST
//    O(1)    |     O(log(N))      |  O(log(N))
//            |    with base 2     | with base 2
//____________________________________________
//            |  SPACE COMPLEXITY |
//            |       O(1)        |
// ARRAY SHOULD BE SORTED
