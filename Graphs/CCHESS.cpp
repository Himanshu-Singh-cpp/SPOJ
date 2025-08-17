#include<bits/stdc++.h>
using namespace std;

#define int long long
#define INF 1e9
#define MOD (int)(1e9+7)

vector<int> dx = {2,2,-2,-2,1,1,-1,-1};
vector<int> dy = {1,-1,1,-1,2,-2,2,-2};

void solve(int a, int b,int c,int d){
    priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
    pq.push({0,a,b});

    vector<vector<int>> dist(8,vector<int>(8,INF));
    dist[a][b] = 0;
    while(!pq.empty()){
        int curr_dist = pq.top()[0];
        int x = pq.top()[1];
        int y = pq.top()[2];
        pq.pop();
        if(curr_dist > dist[x][y]) continue;
        for(int i=0;i<8;i++){
            int xdx = x + dx[i];
            int ydy = y + dy[i];
            if(xdx >=0 && xdx < 8 && ydy >=0 && ydy < 8  && dist[xdx][ydy] > dist[x][y] + x*xdx + y*ydy){
                dist[xdx][ydy] = dist[x][y] + x*xdx + y*ydy;
                pq.push({dist[x][y] + x*xdx + y*ydy,xdx,ydy});
            }
        }
    }
    cout<<dist[c][d]<<'\n';

}

signed main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    int t = 1;

    // cin >> t;
    int a, b, c, d;
    while (cin >> a >> b >> c >> d){
        solve(a,b,c,d);
    }
}