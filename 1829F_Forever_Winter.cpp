#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;
typedef long long ll;
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> edgeCount(n+1,0);
    for (int i = 0; i < m; i++)
    {
        int v1,v2;
        cin>>v1>>v2;
        edgeCount[v2]++;
        edgeCount[v1]++;
    }
    int count=0;
    for(int i=0;i<=n;i++)
        if(edgeCount[i]==1)
            count++;
    cout<<n-count-1<<" "<< (count)/(n-1-count)<<endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}