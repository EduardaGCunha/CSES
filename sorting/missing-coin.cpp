#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
const int MAXN = 2*(1e5)+7;
int arr[MAXN];
int n; 


signed main(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    
    int ans = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] > ans){
            cout << ans << endl;
            return 0;
        }
        ans += arr[i];
    }

    cout << ans << endl;
}