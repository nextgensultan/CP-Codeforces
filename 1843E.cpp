#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;
typedef long long ll;

bool valid(vector<int> chg,vector<pair<int,int>> ind, int m,int n)
{
    vector<int> ones(n+1,0);
    for(int i=0;i<m;i++)
        ones[chg[i]]=1;
    for(int i=1;i<=n;i++)
        ones[i]+=ones[i-1];
    for(auto &i: ind)
        if((ones[i.second] - ones[i.first-1]) > i.second-i.first - (ones[i.second] - ones[i.first-1]) +1)
            return true;
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> indi;
    for (int i = 0; i < m; i++)
    {
        int x1, y1;
        cin >> x1 >> y1;
        indi.emplace_back(make_pair(x1, y1));
    }
    int k = 0;
    cin >> k;
    bool flag = false;
    vector<int> chg(k);
    for (int i=0; i < k; i++)
        cin >> chg[i];
    int l=0,r=k+1;
    while(r-l>1)
    {
        if(valid(chg,indi,(l+r)>>1,n))
            r=(l+r)>>1;
        else
            l=(l+r)>>1;
    }
    cout<<(r==k+1?-1:r)<<endl;
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