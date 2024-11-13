#include <bits/stdc++.h>
using namespace std;


int main(){
    int n; cin >> n;
    vector<int> v1, v2; 
    for(int i = 1; i <= n; i++) v1.push_back(i);

    while(v1.size() > 0){
        for(int i = 0; i < v1.size(); i+=2){
            cout << v1[i] << " ";
            v2.push_back(i);
        }
    }
}