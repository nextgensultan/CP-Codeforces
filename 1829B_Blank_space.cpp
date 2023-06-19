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
    ll size = 0;
    cin >> size;
    ll count = 0;
    ll maxsize = 0;
    int num;
    for (int i = 0; i < size; i++)
    {
        cin >> num;
        if (num)
        {
            maxsize = max(maxsize, count);
            count = 0;
        }
        else
            count++;
    }
    cout << max(count,maxsize) << endl;
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