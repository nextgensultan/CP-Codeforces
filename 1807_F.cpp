#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;
typedef long long ll;
int dx[4] = {1, -1, 1, -1};
int dy[4] = {1, 1, -1, -1};
map<string, int> dir = {{"DR", 0}, {"DL", 1}, {"UR", 2}, {"UL", 3}};
int solve()
{
    int m, n, i1, j1, i2, j2;
    cin >> n >> m >> i1 >> j1 >> i2 >> j2;
    string str;
    cin >> str;
    int dindex = dir[str];
    vector<vector<vector<bool>>> state(n, vector<vector<bool>>(m, vector<bool>(4, false)));
    int count = 0;
    while (!(i1 == i2 && j1 == j2))
    {
        int tx, ty;
        ty = i1 + dy[dindex];
        tx = j1 + dx[dindex];
        bool flag = false;
        if (tx < 1)
        {
            dindex--;
            flag = true;
        }
        if (tx > m)
        {
            dindex++;
            flag = true;
        }
        if (ty < 1)
        {
            dindex -= 2;
            flag = true;
        }
        if (ty > n)
        {
            dindex += 2;
            flag = true;
        }
        if (flag)
        {
            count++;
            continue;
        }
        i1 = ty, j1 = tx;
        if (state[i1 - 1][j1 - 1][dindex])
            return -1;
        state[i1 - 1][j1 - 1][dindex] = true;
    }
    return count;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        cout << solve() << endl;
    }
}