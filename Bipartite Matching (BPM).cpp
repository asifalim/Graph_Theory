#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cerr<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e12
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0;
const int mxn=1e3+3,mod=1e9+7;
vector<int>adj[mxn];
int match[mxn];
bool vis[mxn];
bool dfs(int n)
{
    for(auto i:adj[n])
    {
        if(vis[i])continue;
        vis[i]=true;
        if(match[i]==-1 or dfs(match[i]))
        {
            match[i]=n;
            match[n]=i;
            return 1;
        }
    }
    return 0;
}
signed main()
{

    //fast;
    w(t)
    {
        int n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
        string s,ss,sr,sa;
        bool f=false,ff=false;
        cin>>n>>m;mem(match,-1);
        for(i=0; i<m; i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
        for(i=1; i<=n; i++)
        {
            mem(vis,false);
            if(~match[i] or !dfs(i))cn++;
        }
        for(i=1; i<=n; i++)adj[i].clear();

        cout<<"Case "<<++tot<<": "<<cn<<endl;
    }
}
