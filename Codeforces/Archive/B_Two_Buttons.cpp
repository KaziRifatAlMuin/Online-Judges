#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

bool vis[N];
int level[N];
vector <int> graph[N];

void bfs(int n){
    queue <int> q;
    q.push(n);
    while(!q.empty()){
        int cur_v = q.front();
        vis[cur_v] = true;
        q.pop();
        for(auto child : graph[cur_v]){
            if(!vis[child]){
                q.push(child);
                level[child] = level[cur_v] + 1;
            }
        }
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    int mMax = (m - 1) * 2;
    for(int i = 1; i < N; i++){
        if(i > 1) graph[i].push_back(i - 1);
        if(i * 2 <= mMax) graph[i].push_back(i * 2);
    }
    bfs(n);
    cout << level[m] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}