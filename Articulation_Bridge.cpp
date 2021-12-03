#include<bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define dbg(a,b,c) cerr<<a<<"  "<<b<<"  "<<c<<endl;
#define mem(a,b) memset(a,b,sizeof(a))
#define endl "\n"
#define INF 1e18
#define w(t) cin>>t;while(t--)
#define kill(a) {cout<<a<<endl;continue;}
#define pi  2 * acos(0.0)
int t,ans=0,tot=0,kk=0;
const ll mxn=2e5+4,mod=1e9+7;
vector<int>adj[mxn];
vector<pair<int,int>>bridge;
int in[mxn],out[mxn];
void dfs(int n,int par=-1)
{
    in[n]=out[n]=++tot;
    for(auto i:adj[n])
    {
        if(i==par)continue;
        if(out[i])
        {
            in[n]=min(in[n],out[i]);
            continue;
        }
        dfs(i,n);
        in[n]=min(in[n],in[i]);
        if(in[i]>out[n])bridge.push_back({n,i});
    }
}
signed main()
{

    //fast;
    //w(t)
    // {
    ll n,m,a,b,c,d,e,i,j,k,sm=0,sm1=0,cn=0,cn1=0,mx=-1e9,mn=1e9;
    //string s,ss,sr,sa;
    bool f=true;
    cin>>n>>m;
    for(i=0; i<m; i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
    dfs(1);
    for(auto i:bridge)cout<<i.first<<" "<<i.second<<endl;
    // }
}
