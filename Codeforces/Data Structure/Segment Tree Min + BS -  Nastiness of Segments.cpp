#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

template<typename T>
struct SegmentTree {
    #define lc (C << 1)
    #define rc (C << 1 | 1)
    #define M ((L+R)>>1)
    struct data {
        T mini;
        data() : mini(INT_MAX) {}
    };
    vector<data> st;
    int N;
    SegmentTree(int _N) : N(_N) {
        st.resize(4 * N + 5);
    }
    void combine(data& cur, data& l, data& r) {
        cur.mini = min(l.mini, r.mini);
    }
    void build(int C, int L, int R, vector<T>& v) {
        if (L == R) {
            st[C].mini = v[L];
            return;
        }
        build(lc, L, M, v);
        build(rc, M + 1, R, v);
        combine(st[C], st[lc], st[rc]);
    }
    data Query(int i, int j, int C, int L, int R) {
        if (j < L || i > R) return data();
        if (i <= L && R <= j) return st[C];

        data ret;
        data d1 = Query(i, j, lc, L, M);
        data d2 = Query(i, j, rc, M + 1, R);
        combine(ret, d1, d2);
        return ret;
    }
    void Update(int pos, T val, int C, int L, int R) {
        if (L == R) {
            st[C].mini = val;
            return;
        }
        if (pos <= M) Update(pos, val, lc, L, M);
        else Update(pos, val, rc, M + 1, R);
        combine(st[C], st[lc], st[rc]);
    }
    void Update(int pos, T val) {
        Update(pos, val, 1, 1, N);
    }
    T Query(int i, int j) {
        return Query(i, j, 1, 1, N).mini;
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<int> v(n + 1);
    for(int i = 1; i <= n; i++) cin >> v[i];
    SegmentTree<int> seg(n);
    seg.build(1,1,n,v);
    while(m--){
        int type; 
        cin >> type;
        if(type == 1){
            int pos, val;
            cin >> pos >> val;
            seg.Update(pos,val);
        }
        else{
            int l, r;
            cin >> l >> r;
            int low = l, high = r, ans = 0;
            while(low <= high){
                int mid = (low + high) / 2;
                int res = seg.Query(l,mid);
                if(res == mid - l){
                    ans = 1;
                    break;
                }
                else if(res < mid - l){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            cout << ans << "\n";
        }
    }
} 

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t = 1, st = clock();
    cin >> t;
    while(t--){
        solve();
    }
    // cerr << "[Time : " << 1000 * (clock() - st) / CLOCKS_PER_SEC << " ms]\n";
    return 0;
}
// https://codeforces.com/problemset/problem/2184/G