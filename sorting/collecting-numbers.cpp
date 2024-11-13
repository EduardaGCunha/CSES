#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    map<int, int> mp;
    for(int i = 0; i < n; i++){
        int x; cin >> x;
        mp[x] = i;
    }

    //preciso guardar em qual eu estou atual e o idx
    int cnt = 0, val = 0;
    while(val < n){
        if(mp[val+1] < mp[val]) cnt++;
        val++;
    }
    cout << cnt+1 << endl;
}