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
    int s;
    cin >> s;
    vector<int> vt(s);
    for (int i = 0; i < s; i++)
        cin>>vt[i];
    sort(vt.begin(),vt.end());
    int sum=0;
    for(int i=0;i<s/2;i++)
        sum+= (vt[s-i-1] - vt[i]);
    cout<<sum<<endl;
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