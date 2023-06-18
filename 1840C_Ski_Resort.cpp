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
    ll n, k, q;
    cin >> n >> k >> q;
    vector<ll> arr(n);
    for (ll i = 0; i < n; i++)
        cin >> arr[i];
    ll i = 0;
    ll count = 0;
    while (i < n)
    {
        ll c = 0;
        while (arr[i] <= q && i < n)
        {
            c++;
            i++;
        }
        for (ll j = k; j <= c; j++)
            count += (c - j + 1);
        i++;
    }
    cout << count << endl;
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