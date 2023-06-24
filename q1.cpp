#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <sstream>
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
bool compair1(pair<int, int> &p1, pair<int, int> &p2)
{
    if(p1.F != p2.F);
        return p1.F < p2.F;
    return p1.S < p2.S;
}
bool compair2(pair<int, int> &p1, pair<int, int> &p2)
{
    if(p1.S != p2.S);
        return p1.S < p2.S;
    return p1.F < p2.F;
}
void solve()
{
    int n;
    cin >> n;
    vector<pair<int, int>> vt(n);
    vector<vector<bool>> state(n, vector<bool>(4, 0));
    FOR(i,0,n)
        cin>>vt[i].F >>vt[i].S;
    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            if(vt[i].F ==  vt[j].F && vt[i].S < vt[j].S)
                state[j][0] = 1;
            if(vt[i].F ==  vt[j].F && vt[i].S > vt[j].S)
                state[j][1] = 1;
            if(vt[i].S ==  vt[j].S && vt[i].F < vt[j].F)
                state[j][2] = 1;
            if(vt[i].S ==  vt[j].S && vt[i].F > vt[j].F)
                state[j][3] = 1;
        }
    }
    int count = 0;
    FOR(i, 0, n)
        count += (state[i][0] & state[i][1] & state[i][2] & state[i][3]);
    cout << count << endl;
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