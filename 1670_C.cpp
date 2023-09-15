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
ll gcd(ll a, ll b)
{
    return b ? gcd(b, a % b) : a;
}
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n);
    cin>>a>>b>>c;
    set<int> pre;
    trav(i,c) if(i)pre.insert(i);
    vi link(n+1);
    iota(all(link),0);
    vi siz(n+1,1);
    function<int(int)>  get = [&](int x)
    {
    	while(link[x]!=x)
    		x=link[x];
    	return x;
    };
    FOR(i,0,n)
    {
        
    	if(pre.find(a[i])!=pre.end() || pre.find(b[i])!=pre.end())
    		{link[a[i]]=link[b[i]] = 0;continue;}
    	int NA = get(a[i]);
    	int NB = get(b[i]);
        if(NA==0 || NB==0)
            {link[NA] = link[NB] = 0;continue;}
    	if(NA==NB ) continue;
    	if(siz[NA] < siz[NB])
    		swap(NA,NB);
    	siz[NA]+=siz[NB];
    	link[NB]=NA;
    }
    set<int> ans;
    for(int i=1;i<=n;i++)
    {
    	if(pre.find(i) != pre.end() || siz[i] == 1 || get(i)==0)	continue;
    	ans.insert(get(i));
    }
    ans.erase(0);
    ll A=1;
    FOR(i,0,ans.size())
        A<<=1,A%=ll(MOD);
    cout<<A<<"\n";

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