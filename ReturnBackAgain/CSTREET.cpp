/*CSTREER.cpp*/
#include <iostream>
#include <bits/stdc++.h>
#define ll long long int 
#define MOD 1e9 + 7 
# define INF 0x3f3f3f3f
using namespace std ;

vector< pair<int, int> > g[100005];
priority_queue< pair<int, int>, vector< pair<int, int> >, greater<pair<int, int>> > pq;
vector<int> key(100000, INF);
vector<int> parent(100000, -1);
vector<bool> mst(100000, false);

void solve(int n, int m, int price) {
        int total = 0;
        int src = 0;
        pq.push(make_pair(0, src));
        key[src]  = 0;
        while(!pq.empty()) {
                int u   = pq.top().second;
                int w = pq.top().first;
                pq.pop();
                if(mst[u] != true) {
                       total += w; 
                }
                mst[u] = true;
                cout <<" u is " << u << " with weight " << w << " " << " total " << total << endl;
                for(auto p: g[u]) {
                        int v = p.second;
                        int weight = p.first;
                        if(key[v] > weight && mst[v] == false) {
                                key[v] = weight;
                                parent[v] = u;
                                pq.push(make_pair(key[v], v));
                        }
                }
        }
        cout << total * price << endl;
}

int main() {
        int t;
        cin >> t;
        for(int i = 0; i < t; i++) {
                int p, n, m;
                cin >> p >> n >> m;
                for(int i = 0; i < m; i++) {
                        int a, b, c;
                        cin >> a >> b >> c;
                        g[a-1].push_back(make_pair(c, b-1));
                        g[b-1].push_back(make_pair(c, a-1));
                }
                solve(n, m, p);
        }
}
