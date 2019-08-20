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
struct fenwik_tree {

	int n;
	vector<ll> t;

	void inc(int i, ll x) {
		for (; i < n; i = i | (i + 1)) {
			t[i] += x;
		}
	}

	ll get(int r) {
		ll res = 0;
		for (; r >= 0; r = (r & (r + 1)) - 1) {
			res += t[r];
		}
		return res;
	}

	ll get(ll l, ll r) {
		return get(r) - get(l - 1);
	} 

	fenwik_tree(int n) {
		this->n = n;
		t.resize(n);
	}

	fenwik_tree(vector<ll> &a) {
		this->n = a.size();

		t.resize(n);

		for (int i = 0; i < a.size(); i++) {
			inc(i, a[i]);
		}
	}
};