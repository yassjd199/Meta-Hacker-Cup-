// author : yassjd199
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = 1e-12;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define ll unsigned long long int    
#define llu unsigned
long long mod =1e9+7;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
int gcd (int a,int b) { return b ? gcd (b,a%b):a;}
int lcm (int a,int b){ return a*(b/gcd(a,b));}
const int N=1e6+1,M=20;
void testcase(){
	ll r,c;cin>>r>>c;
	ll a,b;cin>>a>>b;
	cout<<(r>c ? "YES":"NO")<<endl;

}


int main(){
	fast;
/* #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
 #endif*/
	int t=1;
	int tt=1;
	cin>>t;
	while(t--) {
		cout<<"Case #"<<tt++<<": ";
		testcase();
	}
	return 0;
}
