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
#define INF (1LL<<61)
int t,cs=0;
const int mxn=1e5+5,mod=1e9+7;
set<int>adj[mxn];
int sub[mxn];
int par[mxn];
int sz;                              //This algo makes n height tree into logn height
void dfs1(int n,int p)
{
    sub[n]=1;
    sz++;
    for(auto i:adj[n])
    {
        if(i^p)
        {
            dfs1(i,n);
            sub[n]+=sub[i];
        }
    }
}
int dfs2(int n,int p)
{
    for(auto i:adj[n])
    {
        if(i^p)
        {
            if(sub[i]>sz/2)return dfs2(i,n);
        }
    }
    return n;
}
int root;
void decompose(int n,int p)
{
   sz=0;
   dfs1(n,n);
   int center=dfs2(n,n);
   if(p==-1)p=center,root=center;
   par[center]=p;
   for(auto i:adj[center])
   {
       adj[i].erase(center);
       decompose(i,center);
   }
   adj[center].clear();
}
int32_t main()
{
   fast;
   int n;
   cin>>n;
   for(int i=1,a,b;i<n;i++)cin>>a>>b,adj[a].insert(b),adj[b].insert(a);
   decompose(1,-1);
   for(int i=1;i<=n;i++)adj[i].insert(par[i]),adj[par[i]].insert(i);
}

