#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
int main(){
    vector<int > prev(26,-1);
    int t;
    char ch;
    cin>>t;
    while(t--)
    {
        int s;
        cin>>s;
        bool flag = true;
        fill(prev.begin(),prev.end(),-1);
        string str;
        cin>>str;
        for(int i=0;i<s;i++)
        {

            if(prev[str[i]-'a'] ==-1)
                prev[str[i]-'a']=i&1;
            else if(prev[str[i]-'a'] !=(i&1))
                {
                    flag=false;
                    break;
                }
        }
        if(flag)
            cout<<"YES\n";
        else
             cout<<"NO\n";
    }
}