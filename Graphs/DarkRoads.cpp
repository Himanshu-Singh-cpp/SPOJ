#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

struct DSU{
    vector<int> par;

    DSU(int n){
        par.resize(n);
        iota(par.begin(),par.end(),0);
    }

    int find(int x){
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unite(int x, int y){
        x = find(x);
        y = find(y);
        if(x == y) return;
        par[x] = y;
    }
};

bool solve(){
    int n,m;
    cin>>n>>m;
    if(m == 0 && n == 0) return false;

    vector<vector<int>> edges;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        edges.push_back({x,y,z});
    }

    sort(edges.begin(),edges.end(), [&](const vector<int>& a,const vector<int>& b){
        return a[2] < b[2];
    });

    int ans = 0;
    DSU dsu = DSU(n);
    for(auto it:edges){
        if(dsu.find(it[0]) != dsu.find(it[1])) {
            dsu.unite(it[0],it[1]);
        } else ans += it[2];
    }
    cout<<ans<<'\n';
    return true;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    bool check = true;
    while (check){
        check = solve();
    }
}