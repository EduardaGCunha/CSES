#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) cin >> arr[i];

    int i = 0, j = 0;
    set<int> s;
    int ans = 0;
    while(i < n && j < n){
        while(s.count(arr[j])){
            s.erase(arr[i]);
            i++;
        }
        s.insert(arr[j]);
        ans = max(ans, j - i+1);
        j++;
    }

    cout << ans << endl;
}