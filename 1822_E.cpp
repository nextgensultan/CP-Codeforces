#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <sstream>
#include <cmath>
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
void solve()
{
    int n;
    cin >> n;
    string str;
    cin >> str;
    if (n & 1)
    {
        cout << -1 << endl;
        return;
    }
    vi occ(26, 0);
    vi match(26, 0);
    trav(ch, str)
        occ[ch - 'a']++;
    FOR(i, 0, n / 2)
    match[str[i] - 'a'] += (str[i] == str[n - 1 - i]);
    ll sum = 0;
    trav(i, match)
        sum += ll(i);
    FOR(i, 0, 26)
    {
        int temp = n / 2 - match[i] - (occ[i] - 2 * match[i]);
        if (temp < match[i])
        {
            cout << -1 << endl;
            return;
        }
    }
    sort(rall(match));
    cout << max(ll(match[0]), (sum + 1) / 2) << endl;
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