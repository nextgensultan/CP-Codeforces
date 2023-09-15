#include <iostream>
#include <vector>
#include <cassert>
#include <map>
#include <set>
#include <queue>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>

using namespace std;

int getParent(vector<int> &parent, int u)
{
    if(parent[parent[u]]!=parent[u])
    {
        parent[u]=getParent(parent, parent[u]);
    }return parent[u];
}

void dfs(vector<vector<array<int, 2>>> &al, vector<int> &up, vector<int> &variables, int u)
{
    for(auto &t: al[u])
    {
        int &v=t[0], &w=t[1];
        if(up[u]==v)continue;
        up[v]=u;
        if(w==-1)
        {
            w=variables[v]^variables[u]; // gives value of that particular edge (xor of child with parent)
        }
        dfs(al, up, variables, v);
    }
}

void merge(vector<int> &parent, vector<int> &sz, int u, int v)
{
    int pu=getParent(parent, u), pv=getParent(parent, v);
    if(pu==pv)return;
    if(sz[pu]>sz[pv])
    {
        swap(u, v);
        swap(pu, pv);
    }
    parent[pu]=pv;
    sz[pu]+=sz[pv];
    sz[pv]=0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);

    int tttt=1;
    cin>>tttt;
    while(tttt--)
    {
        int n, m;
        cin>>n>>m;
        vector<vector<array<int, 2>>> al(n);
        vector<array<int, 3>> rels;
        for(int i=0;i<n-1;i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            u--, v--;
            al[u].push_back({v, w});
            al[v].push_back({u, w});
            if(w!=-1)rels.push_back({u, v, w%2});
        }
        for(int i=0;i<m;i++)
        {
            int a, b, dist;
            cin>>a>>b>>dist;
            a--, b--;
            if(dist!=-1)rels.push_back({a, b, dist});
        }
        vector<int> sz(n*2,1);
        vector<int> parent(n*2);
        iota(parent.begin(),parent.end(),0);
        for(auto rel: rels)
        {
            int u=rel[0], v=rel[1], parity=rel[2];
            if(parity)
            {
                merge(parent, sz, u, v+n);
                merge(parent, sz, u+n, v);
            }
            else
            {
                merge(parent, sz, u, v);
                merge(parent, sz, u+n, v+n);
            }
        }

        bool ok = true;
        vector<set<int>> same(2*n);
        for(int i=0;i<n&&ok;i++)
        {
            int pi = getParent(parent, i), pin = getParent(parent, i+n);
            if(pi == pin)
            {
                ok=false;
            }
            same[pi].insert(i);
            same[pin].insert(i+n);
        }
        if(!ok)
        {
            cout << "NO" << '\n';
            continue;
        }

        vector<int> variables(2*n, -1);
        for(int i=0;i<2*n;i++)
        {
            if(variables[i]!=-1)continue;
            int st = getParent(parent, i);
            variables[st] = 0;
            vector<int> stk = {st};
            while(!stk.empty())
            {
                int u = stk.back();
                stk.pop_back();
                if(u==getParent(parent, u)) // if variable is parent of a set then it will push all unvisited children 
                {
                    for(auto child: same[u])
                    {
                        if(variables[child]!=-1)continue;
                        variables[child]=variables[u];
                        stk.push_back(child);
                    }
                }
                int opp = getParent(parent, u>=n?u-n:u+n); // get the parent of the set which includes opposite of the variable in question
                if(variables[opp]!=-1)continue;
                variables[opp] = variables[u]^1;
                stk.push_back(opp);
            }
        }
        
        vector<int> up(n, -1);
        dfs(al, up, variables, 0);
        cout << "YES" << '\n';
        for(int u=0;u<n;u++)
        {
            for(auto pr: al[u])
            {
                int v=pr[0], w=pr[1];
                if(up[u]==v)continue;
                cout << u+1 << ' ' << v+1 << ' ' << w << '\n';
            }
        }
    }
    return 0;
}