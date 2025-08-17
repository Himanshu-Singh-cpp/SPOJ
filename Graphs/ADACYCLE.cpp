#include<bits/stdc++.h>
using namespace std;

// #define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin>>mat[i][j];
    }

    vector<vector<int>> adj(n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 1) adj[i].push_back(j);
        }
    }

    for(int i=0;i<n;i++){
        int ans = -1;
        queue<pair<int,int>> qu;
        qu.push({i,0});
        vector<int> vis(n,0);
        vis[i] = 1;
        while(!qu.empty()){
            int top = qu.front().first;
            int dist = qu.front().second;
            qu.pop();
            for(int it: adj[top]){
                if(it == i) {
                    ans = dist + 1; 
                    break;
                }
                if(vis[it] == 0){
                    qu.push({it, dist+1});
                    vis[it] = 1;
                }
            }
            if(ans != -1) break;
        }
        if(ans == -1){
            cout<<"NO WAY\n";
        } else {
            cout<<ans<<'\n';
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while (t--){
        solve();
    }
}