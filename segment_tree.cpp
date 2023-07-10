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
void update(vi &tree, int index)
{
    index += tree.size() >> 1;
    tree[index] = 1;
    while (index > 1)
    {
        index >>= 1;
        tree[index] = tree[index << 1] + tree[(index << 1) + 1];
    }
}
int GetSum(vi &tree, int l, int r)
{
    int sum = 0;
    int n = tree.size() >> 1;
    l += n;
    r += n;
    while (l <= r)
    {
        if (l & 1)
            sum += tree[l++];
        if (!(r & 1))
            sum += tree[r--];
        l >>= 1;
        r >>= 1;
    }
    return sum;
}
void solve()
{
    int n, m;
    cin >> n >> m;
    set<pair<int, int>> range;
    FOR(i, 0, m)
    {
        int l, r;
        cin >> l >> r;
        range.insert({l - 1, r - 1});
    }
    int q;
    cin >> q;
    vi tree(n << 1, 0);
    int res = -1;
    FOR(i, 0, q)
    {

        int index;
        cin >> index;
        if (res != -1)
            continue;
        update(tree, index - 1);
        trav(p, range)
        {
            if (GetSum(tree, p.F, p.S) > ((p.S - p.F + 1) >> 1))
            {
                res = i + 1;
                break;
            }
        }
    }
    cout << res << endl;
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