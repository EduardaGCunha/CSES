#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
 
struct pt { // ponto
	ll x, y;
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
 
 
ll sarea2(pt p, pt q, pt r) {
	return (q-p)^(r-q);
}
 
bool col(pt p, pt q, pt r) { 
	return sarea2(p, q, r) == 0;
}
 
bool ccw(pt p, pt q, pt r) {
	return sarea2(p, q, r) > 0;
}

vector<pt> convex_hull(vector<pt> v) { // convex hull - O(n log(n))
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	if (v.size() <= 1) return v;
	vector<pt> l, u;
	for (int i = 0; i < v.size(); i++) {
		while (l.size() > 1 and !ccw(l.end()[-2], l.end()[-1], v[i]))
			l.pop_back();
		l.push_back(v[i]);
	}
	for (int i = v.size() - 1; i >= 0; i--) {
		while (u.size() > 1 and !ccw(u.end()[-2], u.end()[-1], v[i]))
			u.pop_back();
		u.push_back(v[i]);
	}
	l.pop_back(); u.pop_back();
	for (pt i : u) l.push_back(i);
	return l;
}
 
int main(){
    int n; cin >> n;
    vector<pt> v;
    for(int i = 0; i < n; i++){
        pt a; cin >> a;
        v.push_back(a);
    }

    vector<pt> ans = convex_hull(v);
    cout << ans.size() << endl;
    for(auto u : ans){
        cout << u.x << " " << u.y << endl;
    }
}