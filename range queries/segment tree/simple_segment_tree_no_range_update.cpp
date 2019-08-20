#include <bits/stdc++.h>
#include <random>
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#define _CRT_SECURE_NO_WARNINGS
//-------------------------------------------------------------------------
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define prv(v) for (auto i : v) { cout << i << " ";}
#define prmat(v) for (auto i : v) { prv(i); cout << "\n";}
#define cout(x) cout << fixed << setprecision(x)
#define read(v) for (int i_ = 0; i_ < v.size(); i_++) { cin >> v[i_];}
#define fast_io ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define all(v) (v.begin()), (v.end())
#define rall(v) (v.rbegin()), (v.rend())
#define pii pair<int, int>
//-------------------------------------------------------------------------
class segment_tree {

private:
	int n;
	vector<ll> t;

	void build(int v, int tl, int tr, vector<ll> &arr) {
		if (tl == tr) {
			t[v] = arr[tl];
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm, arr);
		build(v * 2 + 1, tm + 1, tr, arr);
		t[v] = max(t[v * 2], t[v * 2 + 1]);
	}

	ll get(int v, int tl, int tr, int l, int r) {
		if (tl > tr || r < tl || l > tr) {
			return -1e9; // don't forget about neutral element
		}
		if (tl >= l && tr <= r) {
			return t[v];
		}
		ll tm = (tl + tr) / 2;
		return max(get(v * 2, tl, tm, l, r), get(v * 2 + 1, tm + 1, tr, l, r));
	}

	void upd(int v, int tl, int tr, int i, ll x) {

		if (tl == tr) {
			t[v] = x;
			return;
		}

		int tm = (tl + tr) / 2;

		if (i <= tm) {
			upd(v * 2, tl, tm, i, x);
		}
		else {
			upd(v * 2 + 1, tm + 1, tr, i, x);
		}

		t[v] = max(t[v * 2], t[v * 2 + 1]);
	}

public:
	segment_tree(vector<ll> &v) {
		n = v.size();
		t.resize(4 * n);
		build(1, 0, n - 1, v);
	}

	segment_tree(int n) {
		this->n = n;
		t.resize(4 * n);
	}

	segment_tree() {
		segment_tree(0);
	}

	ll get(int l, int r) {
		return get(1, 0, n - 1, l, r);
	}
	void upd(int i, ll x) {
		upd(1, 0, n - 1, i, x);
	}
};