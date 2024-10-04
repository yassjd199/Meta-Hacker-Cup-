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



vll v;
int n;
multiset<ll> se;

void testcase() {
	cin >> n;
	v.clear();
	v.resize(2 * n - 1);
	se.clear();
	if (n == 1) {
		ll x; cin >> x;
		cout << 1 << endl;
		return ;
	}
	for (int i = 0; i < 2 * n - 1; i++) {
		cin >> v[i];
		se.insert(v[i]);
	}
	sort(all(v));
	// not the min nor the max
	ll target = v[0] + v.back();
	int cnt = 0;
	bool ok1 = 1;
	ll ans1 ;
	while (!se.empty()) {
		auto x = *se.begin();
		if (2 * x == target) {
			if (se.count(x) >= 2) {
				se.erase(se.find(x));
				se.erase(se.find(x));
			}
			else {
				cnt++;
				ans1 = x;
				se.erase(se.find(x));
			}
			continue ;
		}
		if (se.count(target - x)) {
			se.erase(se.find(x));
			se.erase(se.find(target - x));
		}
		else {
			cnt++;
			se.erase(se.find(x));
			ans1 = target - x;
		}
	}
	ok1 &= (cnt <= 1);

	// min is missing
	target = v[0] + v[2 * n - 3];
	cnt = 0;
	bool ok2 = 1;
	ll ans2 ;
	for (auto x : v) se.insert(x);
	while (!se.empty()) {
		auto x = *se.begin();
		if (2 * x == target) {
			if (se.count(x) >= 2) {
				se.erase(se.find(x));
				se.erase(se.find(x));
			}
			else {
				cnt++;
				ans2 = x;
				se.erase(se.find(x));
			}
			continue ;
		}
		if (se.count(target - x)) {
			se.erase(se.find(x));
			se.erase(se.find(target - x));
		}
		else {
			cnt++;
			se.erase(se.find(x));
			ans2 = target - x;
		}
	}
	ok2 &= (cnt <= 1);

	// max is missing

	target = v[1] + v.back();
	cnt = 0;
	bool ok3 = 1;
	ll ans3 ;
	for (auto x : v) se.insert(x);
	while (!se.empty()) {
		auto x = *se.begin();
		if (2 * x == target) {
			if (se.count(x) >= 2) {
				se.erase(se.find(x));
				se.erase(se.find(x));
			}
			else {
				cnt++;
				ans3 = x;
				se.erase(se.find(x));
			}
			continue ;
		}
		if (se.count(target - x)) {
			se.erase(se.find(x));
			se.erase(se.find(target - x));
		}
		else {
			cnt++;
			se.erase(se.find(x));
			ans3 = target - x;
		}
	}
	ok3 &= (cnt <= 1);
	ll ans = 1e17;
	//dbg(ans1, ans2, ans3);
	if (ok1 && ans1 > 0 ) ans = min(ans, ans1);
	if (ok2 && ans2 > 0) ans = min(ans, ans2);
	if (ok3 && ans3 > 0) ans = min(ans, ans3);
	if (ans == 1e17 || ans <= 0) ans = -1;
	cout << ans << endl;





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
