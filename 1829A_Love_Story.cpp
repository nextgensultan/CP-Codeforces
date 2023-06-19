#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <sstream>
using namespace std;
typedef long long ll;
void solve()
{
    string str;
    string cf = "codeforces";
    cin >> str;
    int count =0;
    for(int i=0;i< str.size();i++)
        count+=(str[i]!=cf[i]);
    cout <<count<<endl;
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