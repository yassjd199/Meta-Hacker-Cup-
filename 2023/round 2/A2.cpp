// author : yassjd199
// for this problem the stack size should be increased ,check this link : https://nor-blog.codeberg.page/posts/2023-09-25-increase-stack-size/
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


int R, C;
char g[3009][3009];
bool vis[3009][3009];
bool ok(int r, int c) { return r >= 0 && r < R && c >= 0 && c < C ;}
set<pii> se;
int compSz;
void dfs(int r, int c) {
	if (vis[r][c]) return ;
	vis[r][c] = 1;
	compSz++;
	for (int i = 0; i < 4; i++) {
		int x = r + dx[i], y = c + dy[i];
		if (ok(x, y)) {
			if (g[x][y] == 'W') dfs(x, y);
			else if (g[x][y] == '.') {

				if (se.size() < 2) se.insert({x, y});
			}
		}
	}
}

void testcase() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> g[i][j];
			vis[i][j] = 0;
		}
	}
	map<pii, int> cnt;
	int ans = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!vis[i][j] && g[i][j] == 'W') {
				se.clear();
				compSz = 0;
				dfs(i, j);
				if (se.size() == 1) {
					cnt[*se.begin()] += compSz;
					ans = max(ans, cnt[*se.begin()]);
				}

			}
		}
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
