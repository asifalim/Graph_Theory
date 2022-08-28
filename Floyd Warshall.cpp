#include<bits/stdc++.h>
#define ll long long int
#define INF (1LL<<61)
using namespace std;
int main()
{
    ll n,m,a,b,c;
    cin>>n>>m;
    ll adj[n+1][n+1];
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)if(i==j)adj[i][i]=0;else adj[i][j]=INF;
    for(int i=1; i<=m; i++)
    {
        cin>>a>>b>>c;
        adj[a][b]=min(c,adj[a][b]);
        adj[b][a]=min(c,adj[b][a]);
    }
    for(int k=1; k<=n; k++)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]);
            }
        }
    }
    /*for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)cout<<adj[i][j]<<" ";cout<<endl;
    }*/
    return 0;
}
