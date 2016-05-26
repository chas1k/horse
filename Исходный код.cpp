#include <iostream>
#include <vector>

using namespace std;

struct pt{
	int x, y;
	pt(){}
	pt(int a, int b):x(a), y(b){}
};

istream &operator >>(istream &is, pt &p){
	is >> p.x >> p.y;
	return is;
}

int n, m;
pt b;
vector<pt> old;

bool found(const pt &a, const vector<pt> &v){
	for (auto i = v.begin(); i != v.end(); ++i)
		if (i->x == a.x && i->y == a.y)
			return true;
	return false;
}

bool chk(pt a, vector<pt> &v){
	if (found(a, old)) return false;
	bool fl = false;
	for (int u = -1; u <= 1; u += 2)
		for (int w = -2; w <= 2; w += 4){
 			pt q(a.x + u, a.y + w), e(a.x + w, a.y + u);
			if (q.x >=0 && q.x < n && q.y >= 0 && q.y < m){
				v.push_back(q);
				fl = true;
			}
			if (e.x >=0 && e.x < n && e.y >= 0 && e.y < m){
				v.push_back(e);
				fl = true;
			}
		}
	old.push_back(a);
	return fl;
}

int func(vector<pt> gen, int numgen){
	vector<pt> nextgen;
	bool final = true;
	for (auto i = gen.begin(); i != gen.end(); ++i)
		if (chk(*i, nextgen)) final = false;
	if (found(b, nextgen)) return numgen + 1;
	else if (final) return -1;
	else return func(nextgen, numgen + 1);
}

int main(){
	vector<pt> a(1);
	cin >> n >> m >> a[0] >> b;
	cout << func(a, 0);
}