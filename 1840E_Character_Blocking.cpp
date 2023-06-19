#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
void solve()
{
    string str[2];
    cin >> str[0] >> str[1];

    ll t, q;
    cin >> t >> q;
    ll p1, p2;
    int s1, s2;
    ll count=0;
    vector<bool> NE(str[0].size());
    vector<bool> NE(str[0].size());
    for (ll i = 0; i < str[0].size(); i++)
        {
            count ++;
        }
    queue<pair<ll,ll>> wait; 

    for(ll k=0;k<q;k++)
    {
        int qu;

        cin >> qu;
        if (qu == 1)
        {
            cin >> p1;
            p1--;
            count--;
            wait.emplace(make_pair(p1,t+k));
        }
        if (qu == 2)
        {
            cin >> s1 >> p1 >> s2 >> p2;
            s1--, p1--, s2--, p2--;
            swap(str[s1][p1],str[s2][p1]);

            
            
        }
        if (qu == 3)
        {
            bool flag = 1;
            for (int i = 0; i < str[0].size(); i++)
            {
                // if (NE[i] && (wait.find(i) == wait.end() || wait[i] <= 0))
                // {
                //     flag = false;
                //     break;
                // }
            }
            if (flag)
                cout << "YES\n";
            else
                cout << "NO\n";
        }
    }
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