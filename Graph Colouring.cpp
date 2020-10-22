#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int mxN=1e4+3;
vector<int>adj[mxN],vis;
bool f=true;
void bfs(int a)
{
    queue<int>q;
    q.push(a);
    while(!q.empty())
    {
        int n=q.front();
        q.pop();
        for(auto i:adj[n])
        {
            if(vis[i]==-1)vis[i]=vis[n]^1,q.push(i);
            else if(vis[i]==vis[n])
            {
                f=false;
                break;
            }
        }
    }
}
int main()
{
    int t,n,m,i,j,a,b,c,d,e;
    while(cin>>t)
    {
        cin>>n;
        f=true;
        memset(adj,0,sizeof(adj));
        vis.assign(n+1,-1);
        for(i=0; i<n; i++)cin>>a>>b,adj[a].push_back(b),adj[b].push_back(a);
        bfs(0);
        if(!f)cout<<"NOT BICOLORABLE."<<endl;
        else cout<<"BICOLORABLE."<<endl;
    }
    return 0;
}
