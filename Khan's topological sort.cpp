#include<bits/stdc++.h>
using namespace std;
const int mxN=2e5+4;
vector<int>adj[mxN],in,v;
bool khan(int n)
{
    queue<int>q;
    for(int i=1; i<=n; i++)if(in[i]==0)q.push(i);
    while(!q.empty())
    {
        int x=q.front();
        v.push_back(x);
        q.pop();
        for(auto i:adj[x])
        {
            in[i]--;
            if(in[i]==0)q.push(i);
        }
    }
    return v.size()==n;
}
int main()
{
    int n,m,i,j,c,d;
    cin>>n>>m;
    in.assign(n+1,0);
    while(m--)
    {
        cin>>c>>d;
        adj[c].push_back(d);
        in[d]++;
    }
    if(khan(n))
    {
        for(auto i:v)cout<<i<<" ";
        cout<<endl;
    }
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
