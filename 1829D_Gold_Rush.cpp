#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;
typedef long long ll;
bool rec(int n, int m)
{
    if (n < m)
        return false;
    if (n == m)
        return true;
    if (n % 3 != 0)
        return false;
    if (rec(n / 3, m))
        return true;
    if (rec(2 * n / 3, m))
        return true;
    return false;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    if (rec(n, m))
        cout << "yes\n";
    else
        cout << "no\n";
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