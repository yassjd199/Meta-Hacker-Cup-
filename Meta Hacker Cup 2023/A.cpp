// author : yassjd199
#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vii;
typedef vector<long long> vll;
double eps = 1e-12;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define endl '\n'
#define ll long long int    
#define llu unsigned long long int 
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
const long long mod =1e9+7;
const int N=1e6+1,M=20;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
int gcd (int a,int b) { return b ? gcd (b,a%b):a;}
int lcm (int a,int b){ return a*(b/gcd(a,b));}



double a[N];
void testcase(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	if(n==5){
		double ans1=(((a[n-1]-a[n-3])/2)+a[n-3])-((a[1]-a[0])/2+a[0]);
		double ans2=((a[n-1]-a[n-2])/2+a[n-2])-((a[2]-a[0])/2+a[0]);
		double ans=max(ans1,ans2);
		cout<<fixed<<setprecision(6)<<ans<<endl;

	}
	else{
		double ans=(((a[n-2]-a[n-1])/2)+a[n-1])-(((a[1]-a[0])/2)+a[0]);
		cout<<fixed<<setprecision(6)<<ans<<endl;
	}





	



}

int main(){
    fast;
/* #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
 #endif*/
    //clock_t z=clock();
    int t=1;
    int tt=1;
    cin>>t;
    while(t--) {
        cout<<"Case #"<<tt++<<": ";
        testcase();
    }
    //cerr <<endl<<"Run Time: " <<((double)(clock() -z) / CLOCKS_PER_SEC)<<endl;
    return 0;
}
