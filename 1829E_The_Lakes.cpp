#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <sstream>
#include <queue>
using namespace std;
typedef long long ll;
int bfs(vector<vector<int>> &arr, vector<vector<bool>> &visit, int i, int j, int n, int m)
{
    queue<pair<int, int>> st;
    st.emplace(make_pair(i, j));
    int count=0;
    while (!st.empty())
    {
        int y = st.front().first;
        int x = st.front().second;
        st.pop();
        if (x < 0 || x == m || y < 0 || y == n)
            continue;;
        if (arr[y][x] && visit[y][x] == false)
        {
            count += arr[y][x];
            visit[y][x] = true;
            st.emplace(make_pair(y, x + 1));
            st.emplace(make_pair(y, x - 1));
            st.emplace(make_pair(y + 1, x));
            st.emplace(make_pair(y - 1, x));
        }
    }
    return count;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<vector<bool>> visit(n, vector<bool>(m));
    int maxCount = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] && visit[i][j] == false)
            {
                maxCount = max(maxCount, bfs(arr, visit, i, j, n, m));
            }
        }
    cout << maxCount << endl;
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