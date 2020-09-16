#include<bits/stdc++.h>
#define ll long long int
#define INF (1LL<<61)
using namespace std;
int main()
{
    ll n,m,i,j,t,k,a,b,c,d,e;
    cin>>n>>m>>t;
    vector<vector<ll>>adj(n+1,vector<ll>(n+1,INF));
    for(i=1; i<=n; i++)adj[i][i]=0;
    while(m--)
    {
        cin>>a>>b>>c;
        adj[a][b]=min(c,adj[a][b]);
        adj[b][a]=min(c,adj[b][a]);
    }
    for(k=1; k<=n; k++)
    {
        for(i=1; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(adj[i][k]<INF and adj[k][j]<INF)adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    while(t--)
    {
        cin>>d>>e;
        if(adj[d][e]==INF)cout<<-1<<'\n';
        else cout<<adj[d][e]<<'\n';
    }
    return 0;
}
