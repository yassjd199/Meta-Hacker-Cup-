// author : yassjd199

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = std::numeric_limits<double>::epsilon();
#define f first
#define s second
#define pb push_back
#define endl '\n'
#define ll  long long int
#define ull unsigned long long int
const int dx[4] = {0, 0, -1, 1}, dy[4] = { -1, 1, 0, 0};
//const int dx[8] = {0, 0, -1, 1, -1, -1, 1, 1} , dy[8] = {-1, 1, 0, 0, -1, 1, -1, 1};
const long long mod = 1e9 + 7;
const int N = 1e6 + 1, M = 20;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
template<typename T> using Set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename K, typename V> using Map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

void dbg_out() {
	cerr << endl;
}
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
	cerr << ' ' << H;
	dbg_out(T...);
}
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

ll P;
vector<vll> all;
void gen(ll sm, ll s, vll v) {
	//dbg(sm);
	if (sm == 41) {
		all.emplace_back(v);
		return ;
	}
	for (int i = s; i <= 41; i++) {
		if (sm > 41 || v.size() > 41) return;
		v.emplace_back(i);
		gen(sm + i, i, v);
		v.pop_back();
	}

}

void testcase() {
	cin >> P;
	vll v;
	all.clear();
	gen(0ll, 1, v);

	ll mn = 1e9;
	vll ans;
	for (auto vec : all) {
		ll p = 1;
		for (auto x : vec) {
			p *= x;
		}
		if ((ll)vec.size() < mn && p == P) mn = (ll) vec.size(), ans = vec;
	}
	if (!ans.empty()) {
		cout << ans.size() << " ";
		for (auto x : ans) {
			cout << x << " ";
		}
		cout << endl;
	}
	else cout << -1 << endl;

}

int main() {
	ios::sync_with_stdio (0);
	cin.tie (0);
	cout.tie (0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int _ = 1;
	int __ = 1;
	clock_t z = clock();
	cin >> _;

	while (_--) {
		cout << "Case #" << __++ << ": ";
		testcase();
	}

	cerr << endl << "Run Time: " << (( double ) ( clock() - z ) / CLOCKS_PER_SEC ) << endl;
	return 0;
}
