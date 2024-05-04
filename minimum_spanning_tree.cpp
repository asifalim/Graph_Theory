#include<bits/stdc++.h>
using namespace std;
const int mxn = 2e6 + 3;
int par[mxn];
void refresh(int n)
{
    for(int i = 1; i <= n; i++)par[i] = i;
}
int find(int n)
{
    return par[n] == n ? n: par[n] = find(par[n]);
}
int main()
{
    int n, m;
    cin>>n>>m;
    refresh(n);
    array<int, 3>ar[m];
    for(int i = 0; i < m; i++)cin>> ar[i][1] >> ar[i][2] >> ar[i][0];
    sort(ar, ar + m);
    int64_t cost = 0;
    int cmp = 0;
    for(int i = 0; i < m; i++)
    {
        int a = find(ar[i][1]);
        int b = find(ar[i][2]);
        if(a != b)cost += ar[i][0], merge(a,b), cmp++;
    }
    if(cn < n - 1)cout << "IMPOSSIBLE" << endl;
    else cout << cost << endl;
    return 0;
}
