#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <list>
#include <queue>
#include <sstream>
#include <bitset>
#include <numeric>
#include <functional>
using namespace std;
typedef long long ll;
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const ll INF = 1e18;
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);
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
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define pii pair<int, int>
#define vvi vector<vi>
#define vvd vector<vd>
#define vvl vector<vl>
#define bitat(x, i) (((x) >> (i)) & 1)
#define bitcount(a) (int)__builtin_popcount(a)
#define bitcountll(a) (int)__builtin_popcountll(a)
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
void YES(bool t = 1) { cout << (t ? "YES\n" : "NO\n"); }
void Yes(bool t = 1) { cout << (t ? "Yes\n" : "No\n"); }
void yes(bool t = 1) { cout << (t ? "yes\n" : "no\n"); }
void NO(bool t = 1) { YES(!t); }
void No(bool t = 1) { Yes(!t); }
void no(bool t = 1) { yes(!t); }
void solve()
{
    int r, c;
    cin >> r >> c;
    vvi mat(r, vi(c)), a1(r, vi(c)), a2(r, vi(c)), a3(r, vi(c)), a4(r, vi(c));
    FOR(i, 0, r)
    {
        FOR(j, 0, c)
        {
            cin >> mat[i][j];
            a1[i][j] = a2[i][j] = a3[i][j] = a4[i][j] = mat[i][j];
        }
    }

    FOR(i, 0, r)
    FOR(j, 0, c)
    a1[i][j] += (i && j ? a1[i - 1][j - 1] : 0);
    FOR(i, 0, r)
    ROF(j, c - 1, 0)
    a2[i][j] += (i && j < c - 1 ? a2[i - 1][j + 1] : 0);
    ROF(i, r - 1, 0)
    ROF(j, c - 1, 0)
    a3[i][j] += (i < r - 1 && j < c - 1 ? a3[i + 1][j + 1] : 0);
    ROF(i, r - 1, 0)
    FOR(j, 0, c)
    a4[i][j] += (i < r - 1 && j ? a4[i + 1][j - 1] : 0);
    ll ans = 0;
    FOR(i, 0, r)
    FOR(j, 0, c)
    ans = max(ans, ll(0) + a1[i][j] + a2[i][j] + a3[i][j] + a4[i][j] - 3 * mat[i][j]);
    cout << ans << endl;
}
signed main()
{
    cin.tie(0)->sync_with_stdio(0);
    int t = 1;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        solve();
    }
}