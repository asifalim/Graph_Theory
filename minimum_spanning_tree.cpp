#include<bits/stdc++.h>
using namespace std;
vector<int>parent;
int find(int a)
{
    if(parent[a]==-1)return a;
    return parent[a]=find(parent[a]);
}
void merge(int a,int b)
{
    parent[a]=b;
}
int main()
{
    int n,m,i,sm=0,c,d,k;
    cin>>n>>m;
    array<ll,3>ar[m];
    for(i=0;i<m;i++)cin>>ar[i][1]>>ar[i][2]>>ar[i][0];
    sort(ar,ar+m);parent.assign(n+1,-1);
    for(i=0;i<m;i++)
    {
        a=find(ar[i][1]);
        b=find(ar[i][2]);
        if(a!=b)sm+=ar[i][0],merge(a,b),cn++;
    }
    if(cn<n-1)cout<<"IMPOSSIBLE"<<endl;
    else
    cout<<sm<<endl;
    return 0;
}
