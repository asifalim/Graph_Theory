#include<bits/stdc++.h>
using namespace std;
struct edge
{
    int a;int b;int c;
};
edge ar[100002];
int parent[1003];
bool cmp(edge a,edge b)
{
    return a.c<b.c;
}
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
    for(i=0;i<m;i++)cin>>ar[i].a>>ar[i].b>>ar[i].c;
    for(i=1;i<=n;i++)parent[i]=-1;
    sort(ar,ar+m,cmp);
    for(i=0;i<m;i++)
    {
        c=find(ar[i].a);
        d=find(ar[i].b);
        if(c!=d)sm+=ar[i].c,merge(c,d);
    }

    cout<<sm<<endl;
}
