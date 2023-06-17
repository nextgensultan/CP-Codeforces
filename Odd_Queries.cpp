#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;
typedef long long ll;
vector<ll> arr(2*100000 +1), ps(2*100000 +1);
void solve()
{
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < n; i++)
        cin >> arr[i];
    ps[0] = arr[0];
    for (int i = 1; i < n; i++)
        ps[i] = ps[i - 1] + arr[i];
    ll l, r, k;
    while (q--)
    {
        cin >> l >> r >> k;
        ll sum = 0;
        if(l==1)
            sum = ps[r-1] ;
        else
            sum = ps[r-1] - ps[l-2];
        sum = ps[n-1]-sum  + + k * (r-l+1);
        if(sum&1)
            cout<<"YES\n";
        else
            cout <<"NO\n";
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