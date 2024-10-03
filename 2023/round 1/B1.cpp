//  author : yassjd199
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


void testcase(){
	ll p;cin>>p;
	ll copy=p;
	vll v;
	ll sum=0;
	for(int i=2;i*i<=p;i++){
		while(p%i==0){
			v.pb(i);
			p/=i;
			sum+=i;
			if(i>41){
				cout<<-1<<endl;
				return ;
			}
		}

	}
	if(p>1){
		sum+=p;
		v.pb(p);
	}
	sort(all(v));
	//debug(v);
	if(sum==41){
		cout<<v.size()<<" ";
		for(auto i : v) cout<<i<<" ";
		cout<<endl;
		return ;
	}
	if(sum<41 && v.size()+(41-sum)<=100){
		cout<<v.size()+(41-sum)<<" ";
		//debug(41-sum);
		for(int i=0;i<41-sum;i++) cout<<1<<" ";
		for(auto i : v){
			cout<<i<<" ";
		}
		cout<<endl;
		return ;
	}
	ll x=v.back();
	int len=v.size();
	int i=0;
	while(sum!=41 && i<v.size()){
		sum-=x;
		sum-=v[i];
		x*=v[i];
		sum+=x;
		len--;
		if(sum<41){
			ll y=sum;
			int len1=len;
			while(len1<=100 && sum<41){
				sum++;
				len1++;

			}
			cout<<len1<<" ";
			for(int i=0;i<len1-len;i++) cout<<1<<" ";
			for(int j=i;i<v.size()-1;i++) cout<<v[i]<<" ";
			cout<<x<<endl;
			return ;
		}
		i++;
	}
	if(sum==41){
		for(int j=i;i<v.size()-1;i++) cout<<v[i]<<" ";
		cout<<x<<endl;
	}
	else cout<<-1<<endl;







	



}

int main(){
    fast;
/* #ifndef ONLINE_JUDGE
     freopen("input.txt","r",stdin);
     freopen("output.txt","w",stdout);
 #endif
    clock_t z=clock();*/
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
