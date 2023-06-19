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
    ll b;
    cin >>b;
    int s1=1e9,s2=1e9,both=1e9;
    string str;
    while(b--)
    {
        int m;
        cin>>m;
        cin>>str;
        if(str[0]=='1' && str[1]=='1')    
            both = min(both,m);
        else if(str[0]=='1')
            s1= min(s1,m);
        else if(str[1] == '1')
            s2= min(s2,m);
    }
    if((s1==1e9 || s2==1e9 )&& both == 1e9)
        cout<<-1<<endl;
    else
        cout<<min(both,s1+s2)<<endl;
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