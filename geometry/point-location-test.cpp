#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};
 
 
//cross product (calcula a area)
ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}
 
bool col(pt p, pt q, pt r) { // se p, q e r sao colin.
	return sarea2(p, q, r) == 0;
}
 
bool ccw(pt p, pt q, pt r) {
	return sarea2(p, q, r) > 0;
}
 
int main(){
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        pt a, b, c; 
        cin >> a >> b >> c;
        if(col(a, b, c)) cout << "TOUCH\n";
        else if(ccw(a, b, c)) cout << "LEFT\n";
        else cout << "RIGHT\n";
    }
}