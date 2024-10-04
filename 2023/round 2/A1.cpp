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
#define llu unsigned
const int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};
const long long mod =1e9+7;
const int N=1e6+1,M=20;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
int gcd (int a,int b) { return b ? gcd (b,a%b):a;}
int lcm (int a,int b){ return a*(b/gcd(a,b));}
int r,c;
char g[20][20];
bool vis[20][20];
int empty_cnt;
bool ok(int x,int y){ return x>=0 && x<r && y>=0 && y<c ;}
void dfs(int a,int b){
    // base case 
    if(!ok(a,b)) return ;
    //cerr<<a<<" "<<b<<endl;
    if(g[a][b]=='.'){
        if(!vis[a][b]) {
            vis[a][b]=1;
            empty_cnt++;
            return ;
        }
        return ;
    }
    if(g[a][b]=='B') return ;
    vis[a][b]=1;
    for(int i=0;i<4;i++){
        int x=a+dx[i],y=b+dy[i];
        if(!vis[x][y]) dfs(x,y);
    }


}

void testcase(){
    memset(vis,0,sizeof(vis));  
    cin>>r>>c;
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
            cin>>g[i][j];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            if(g[i][j]=='W' && !vis[i][j]){
                empty_cnt=0;
                memset(vis,0,sizeof(vis));
                dfs(i,j);
                if(empty_cnt==1){
                    cout<<"YES"<<endl;
                    return ;
                }
            }
        }
    }
    cout<<"NO"<<endl;



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
