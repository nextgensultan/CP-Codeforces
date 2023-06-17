#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<sstream>
using namespace std;
typedef long long ll;
void solve()
{
    ll n,k;
    cin>>n>>k;
    if(k>30)
        k=30; // as 1<<K excees 10^9 if k > 30
    cout << min(ll(1)<<k,n+1) << endl;
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