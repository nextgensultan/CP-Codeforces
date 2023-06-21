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
    ll n,s=0;
    cin>>n;
    while(n>=1)
    {
        s+=n;
        n/=2;
    }
    cout<<s<<endl;
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