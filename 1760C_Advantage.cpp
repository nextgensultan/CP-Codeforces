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
    cin >> s;
    int maxi = -1;
    int secondMax = -1;
    vector<int> vt(s);
    for (int i = 0; i < s; i++)
    {
        cin >> vt[i];
        if (vt[i] > maxi)
        {
            secondMax = maxi;
            maxi = vt[i];
        }
        else if (vt[i] > secondMax)
            secondMax = vt[i];
    }
    for (auto &i : vt)
        if (i == maxi)
            cout << (i - secondMax) << " ";
        else
            cout << i - maxi << " ";
    cout << endl;
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