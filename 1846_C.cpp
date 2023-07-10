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
bool comp(pair<ll, ll> &p1, pair<ll, ll> &p2)
{
    if (p1.F != p2.F)
        return p1.F > p2.F;
    return p1.S < p2.S;
}
void solve()
{
    ll n, m, h;
    cin >> n >> m >> h;
    vector<pair<ll, ll>> vt(n, {0, 0});
    FOR(j, 0, n)
    {
        vi ti(m);
        trav(i, ti)
        {
            cin >> i;
        }
        sort(all(ti));
        FOR(i, 1, m)
        ti[i] += ti[i - 1];
        auto it = upper_bound(all(ti), h);
        // cout<<ti<<endl;
        int index = it - ti.begin();
        ll sum = 0;
        FOR(i, 0, index)
        sum += ti[i];

        vt[j].F = index, vt[j].S = sum;
    }
    pair<ll, ll> ans = vt[0];

    sort(all(vt), comp);

    FOR(i, 0, n)
    if (ans == vt[i])
    {
        cout << i + 1 << endl;
        return;
    }
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