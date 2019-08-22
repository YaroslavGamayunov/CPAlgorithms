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
struct sparse_table {

private:
	int n;
	int K;
	vector<int> log;
	vector<vector<ll>> table;
public:
	sparse_table(int n) {
		this->n = n;
		log.resize(n);

		for (int i = 2; i < n; i++) {
			log[i] = log[i / 2] + 1; // precomute logs to make further usage faster
		}

		this->K = log[n - 1] + 1;

		table.resize(n, vector<ll>(K));
	}

	sparse_table(vector<ll> &v) {
		n = v.size();
		log.resize(n);

		for (int i = 2; i < n; i++) {
			log[i] = log[i / 2] + 1; 
		}

		K = log[n - 1] + 1;

		table.resize(n, vector<ll>(K));

		for (int i = 0; i < n; i++) {
			table[i][0] = v[i];
		}

		for (int p = 1; p < K; p++) {
			for (int i = 0; i + (1 << p) - 1 < n; i++) {
				table[i][p] = min(table[i][p - 1], table[i + (1 << (p - 1))][p - 1]);
			}
		}
	}

	ll get(int l, int r) {
		int len = log[r - l + 1];
		return min(table[l][len], table[r - (1 << len) + 1][len]);
	}
};