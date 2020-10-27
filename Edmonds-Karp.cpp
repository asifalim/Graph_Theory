#include<bits/stdc++.h>
#define ll long long int
using namespace std;
const int mxN=1e4+2;
ll INF=1e61;              //O(V*E^2)
vector<ll>adj[mxN];
ll cc[mxN][mxN];
ll bfs(ll s,ll t,vector<ll>&parent)
{
    fill(parent.begin(),parent.end(),-1);
    parent[s]=-2;
    queue<pair<ll,ll>>q;
    q.push({s,INF});
    while(!q.empty())
    {
        ll cur=q.front().first,flow=q.front().second;
        q.pop();
        for(auto next:adj[cur])
        {
            if(parent[next]==-1 and cc[cur][next])
            {
                parent[next]=cur;
                ll new_flow=min(flow,cc[cur][next]);
                if(next==t)return new_flow;
                q.push({next,new_flow});
            }
        }
    }
    return 0;
}
ll max_flow(ll s,ll t)
{
    vector<ll>parent(mxN);
    ll flow=0,new_flow;
    while(new_flow=bfs(s,t,parent))
    {
        flow+=new_flow;
        ll cur=t;
        while(cur!=s)
        {
            ll prev=parent[cur];
            cc[prev][cur]-=new_flow;
            //cc[cur][prev]+=new_flow;
            cur=prev;
        }
    }
    return flow;
}
int main()
{
    ll n,m,i,j,a,b,c;
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>a>>b>>c;
        adj[a].push_back(b);
        //adj[b].push_back(a);
        cc[a][b]+=c;
        //cc[b][a]+=c;     /*For undirected
    }
    cout<<max_flow(1,n)<<endl;    //Source 1 and sink n
    return 0;
}

