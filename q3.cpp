#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <sstream>
#include <cstdint>
using namespace std;
typedef long long ll;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define pq priority_queue
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define FORE(i, a, b) for (int i = (a); i <= (b); ++i)
#define ROF(i, a, b) for (int i = (a); i >= (b); --i)
#define trav(a, x) for (auto &a : x)
#define sz(x) (int)x.size()
#define make_unique(v) \
    sort(all(v));      \
    v.erase(unique(all(v)), v.end())
template <class T>
using minpq = pq<T, vector<T>, greater<T>>;
template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template <int D, typename T>
struct vt : public vector<vt<D - 1, T>>
{
    template <typename... Args>
    vt(int n = 0, Args... args) : vector<vt<D - 1, T>>(n, vt<D - 1, T>(args...)) {}
};
template <typename T>
struct vt<1, T> : public vector<T>
{
    vt(int n = 0, const T &val = T()) : vector<T>(n, val) {}
};
template <typename T>
istream &operator>>(istream &in, vector<T> &a)
{
    for (auto &x : a)
        in >> x;
    return in;
};
template <typename T>
ostream &operator<<(ostream &out, vector<T> &a)
{
    for (auto &x : a)
        out << x << ' ';
    return out;
};
int dp(vector<vector<int>> &vt1, vector<vector<int>> &vt2, char ch, vector<int> &f, vector<int> &n, int s, int size, int i, int j)
{

    if (s > size)
        return -1;
    if (s == size)
        return 0;
    if (ch == '!' && vt1[s][size - 1] != INT16_MAX)
        return vt1[s][size - 1];
    if (ch == '+' && vt2[s][size - 1] != INT16_MAX)
        return vt2[s][size - 1];
    FOR(k, s + i - 1, s + j)
    {
        int nt = n[k] - (s == 0 ? 0 : n[s - 1]);
        int fl = f[k] - (s == 0 ? 0 : f[s - 1]);
        if (ch == '!')
        {
            int a1 = dp(vt1, vt2, '+', f, n, k + 1, size, i, j);
            if (a1 == -1)
                continue;
            vt1[s][size - 1] = min(vt1[s][size - 1], nt + a1);
        }
        else
        {
            int a2 = dp(vt1, vt2, '!', f, n, k + 1, size, i, j);
            if (a2 == -1)
                continue;
            vt2[s][size - 1] = min(vt2[s][size - 1], fl + a2);
        }
    }
    if (ch == '!')
        return vt1[s][size - 1];
    return vt2[s][size - 1];
}
void solve()
{
    int r, c, i, j;
    cin >> r >> c >> i >> j;
    vector<vector<int>> vt(c, vector<int>(c, INT16_MAX));
    vector<vector<int>> vt1(c, vector<int>(c, INT16_MAX));

    vector<int> f(c, 0), n(c, 0);
    for (int i = 0; i < r; i++)
    {
        string str;
        cin >> str;
        FOR(j, 0, c)
        {
            char ch = str[j];
            if (ch == '!')
                f[j]++;
            else
                n[j]++;
        }
    }
    FOR(i, 1, c)
    {
        f[i] += f[i - 1];
        n[i] += n[i - 1];
    }
    int a1 = dp(vt, vt1, '!', f, n, 0, c, i, j);
    int a2 = dp(vt, vt1, '+', f, n, 0, c, i, j);
    cout << min(a1, a2) << endl;
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    // cin >> t;
    for (int test = 1; test <= t; test++)
    {
        solve();
    }
}