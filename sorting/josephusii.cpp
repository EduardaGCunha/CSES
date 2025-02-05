#include <bits/stdc++.h>
using namespace std;


#define int long long
signed main(){
    int n, k; cin >> n >> k;

    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);

    k++;
    int cnt = 1;
    while(!q.empty()){
        auto u = q.front(); q.pop();
        if(!cnt){
            cout << u << " ";
        }else q.push(u);
        cnt = (cnt+1)%k;
    }
    cout << endl;

}