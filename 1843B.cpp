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
    ll s;
    cin>>s;
    vector<ll> vt(s);
    ll sum = 0;
    for (ll i = 0; i < s; i++)
    {
        cin >> vt[i];
        sum += abs(vt[i]);
    }
    ll count = 0;
    for (ll i = 0; i < s; i++)
    {
        if(vt[i]<0)
            count++;
        if(vt[i]==0)
            continue;
        while (vt[i] <= 0 && i<s)
            i++;
        
    }
    cout << sum << " " << count << endl;
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