#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    vector<int> v1, v2;
    for(int i = 2; i <= n; i+=2) v1.push_back(i);
    for(int i = 1; i <= n; i+= 2) v2.push_back(i);
    for(int i = 0; i < v2.size(); i+= 2){
        v1.push_back(v2[i]);
    }
    for(int i = 1; i < v2.size(); i+= 2){
        v1.push_back(v2[i]);
    }
    for(auto u : v1) cout << u << " ";
    cout << endl;
}