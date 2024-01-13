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
int t, cs = 0;
const int mxn = 1e5 + 5, mod = 1e9 + 7;
bool vis[mxn], color[mxn];
vector<int>adj[mxn];
bool bfs(int root)
{
    queue<int>q;
    q.push(root);
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        if(vis[node])continue;
        vis[node] = true;
        for(auto i:adj[node])
        {
           if(vis[i])
           {
               if(color[i] == color[node])return false;
               continue;
           }
           color[i] = (!color[node]);
           q.push(i);
        }
    }
    return true;
}
int32_t main()
{
    int n, m;
    cin >> n >> m;
    for(int i = 0, a, b; i < m; i++)cin >> a >> b, adj[a].push_back(b), adj[b].push_back(a);
    bool f = true;
    for(int i = 1; i <= n and f; i++)if(!vis[i])if(!bfs(i))f = false;
    if(!f)KILL("IMPOSSIBLE");
    for(int i = 1; i <= n; i++)cout << color[i] + 1 <<" ";cout << endl;
}
