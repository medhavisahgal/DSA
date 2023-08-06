#include <iostream>
#include <vector>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int s;
    cout << "Element you want to find" << endl;
    cin >> s;
    bool found = false;
    for(int i=0; i<n; i++){
        if(a[i] == s){
            cout << "found at index " << i << endl;
            found = true;
        }
    }
    if(!found){
        cout << "NOT FOUND" << endl;
    }
    return 0;
}
//               LINEAR SEARCH
//              TIME COMPLEXITY
//    BEST    |    AVGERAGE        |  WORST
//    O(1)    |     O(N)           |   O(N) 
//____________________________________________
//            |  SPACE COMPLEXITY |
//            |       O(1)        |
