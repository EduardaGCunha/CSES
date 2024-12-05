#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int arr[n];
    int tot = 0;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tot += arr[i];
    }

    vector<int> dp(tot+1, 0);
    vector<int> ans;
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = tot; j >= arr[i]; j--){
            dp[j] += dp[j-arr[i]];
        }
    }

    for(int i = 1; i <= tot; i++) if(dp[i]) ans.push_back(i);

    cout << ans.size() << endl;
    for(auto u : ans){
        cout << u << " ";
    }
    cout << endl;
}