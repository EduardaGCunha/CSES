#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;

    queue<int> q;
    for(int i = 1; i <= n; i++) q.push(i);

    int flag = 0;
    while(!q.empty()){
        auto u = q.front(); q.pop();
        if(flag){
            cout << u << " ";
        }else q.push(u);
        flag = !flag;
    }
    cout << endl;

}