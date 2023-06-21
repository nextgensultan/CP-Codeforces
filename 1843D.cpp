#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;
typedef long long ll;
void GetEdges(vector<vector<ll>> &vt, vector<ll> &dp)
{
    for (ll i = vt.size() - 1; i >= 1; i--)
    {
        if (vt[i].size() == 0)
            dp[i] = 1;
        else
            for (ll j = 0; j < vt[i].size(); j++)
                dp[i] += dp[vt[i][j]];
    }
}
void solve()
{
    ll n;
    cin >> n;
    vector<vector<ll>> vt(n + 1, vector<ll>(0));
    for (ll i = 0; i < n - 1; i++)
    {
        ll v1, v2;
        cin >> v1 >> v2;
        vt[min(v1, v2)].emplace_back(max(v1, v2));
    }
    vector<ll> dp(n + 1, 0);
    GetEdges(vt, dp);
    ll k;
    cin >> k;
    for (ll i = 0; i < k; i++)
    {
        ll v1, v2;
        cin >> v1 >> v2;
        cout << dp[v1] * dp[v2] << endl;
    }
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