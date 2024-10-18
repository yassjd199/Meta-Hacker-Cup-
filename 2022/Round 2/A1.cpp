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
// 1-indexed BIT
ll fn[N];
void inc(int x, ll val) {
	for (; x < N; x += x & (-x)) fn[x] += val;
}
ll query(int x) {
	ll res = 0ll;
	for (; x; x -= x & (-x)) res += fn[x];
	return res ;
}
ll query(int l, int r) {
	return l == 0 ?  query(r) : query(r) - query(l - 1) ;
}



int n, q;


void testcase() {

	cin >> n ;
	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		inc(i, x);
	}
	cin >> q;

	auto check = [](int l, int r)->char {
		char ret = 'A';
		int cnt = 0;
		for (int i = 0; i < 26; i++) {
			if (((p[i][r] - p[i][l - 1]) & 1)) {
				cnt++;
				ret = (char)(i + 'a');
				if (cnt > 1) break ;
			}
		}
		if (cnt != 1) ret = 'A';
		return ret;
	};
	auto solve = [check, p](int l, int r)->bool {
		char x = check(l, r);
		if (x == 'A' ) return 0;
		if (((r - l + 1) & 1) == 0) return 0;
		for (int i = 0; i < 26; i++) {
			if (abs(p[i][l  + (r - l + 1) / 2] - p[i][l - 1] -  p[i][r] + p[i][r - (r - l + 1) / 2]) <=  1 ||
			abs(p[i][l - 1 + (r - l + 1) / 2] - p[i][l - 1] - p[i][r] + p[i][r - 1 - (r - l + 1) / 2]) <=  1) continue ;
			return 0;
		}

		return 1;


	};

	int ans = 0;
	while (q--) {
		int l, r; cin >> l >> r;
		ans += solve(l, r);
	}
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
