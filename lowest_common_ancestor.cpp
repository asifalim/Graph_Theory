#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define dbg(a,b,c,d) cerr<<a<<"  "<<b<<"  "<<c<<"  "<<d<<endl;
#define kill(a) {cout<<a<<endl;continue;}
#define KILL(a) {cout<<a<<endl;return 0;}
#define debug cerr<<"Error Found"<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define lcm(a, b) (a/__gcd(a,b))*b
#define w(t) cin>>t;while(t--)
#define pi  2 * acos(0.0)
#define ll long long int
#define endl "\n"
#define INF 1e18
int t,cs=0;
const int mxn=1e5+2,mod=1e9+7;
int lca[1004][mxn],level[1004],par[1004];
vector<int>adj[mxn];
void dfs(int n,int l,int from)
{
    level[n]=l;                   //Time_complexity O(logn) and space_complexity O(nlogn)
    par[n]=from;
    for(auto i:adj[n])
    {
        if(i!=from)dfs(i,l+1,n);
    }
}
void build_table(int n)
{
    for(int i=1; i<=n; i++)lca[i][0]=par[i];
    for(int j=1; 1<<j<=n; j++)
    {
        for(int i=1; i<=n; i++)
        {
            lca[i][j]=lca[lca[i][j-1]][j-1];
        }
    }
}
int dis(int a,int b)
{
    if(level[b]<=level[a])swap(b,a);
    int d=log2(level[b]);
    for(int i=d; i>=0; i--)
    {
        if(level[b]-(1<<i)>=level[a])b=lca[b][i];
    }
    if(a==b)return a;
    for(int i=d; i>=0; i--)
    {
        if(lca[a][i]!=lca[b][i])a=lca[a][i],b=lca[b][i];

    }
    return par[b];
}
signed main()
{

    //fast;
    //w(t)
    // {
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0,1);
    build_table(n);
    int q;
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        cout<<dis(l,r)<<endl;
    }

    //}
}
