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
    int n;
    cin >>n;
    char str[101];
    cin >>str;
    string out;
    int i=0;
    while(i<n)
    {
        out.push_back(str[i]);
        char ch= str[i];
        i++;
        while(str[i]!=ch)
            i++;
        i++;
    }
    cout <<out <<endl;
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