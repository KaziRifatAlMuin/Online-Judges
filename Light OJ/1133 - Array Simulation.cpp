/*
    Author : RifatALmuiN
    Problem : Array Simulation
    Source : https://lightoj.com/problem/array-simulation
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
typedef vector <int> vi;
typedef vector <long long int> vl;
typedef pair <int, int> pii;
typedef pair <long long int, long long int> pll;

void solve()
{
    int n, m;
    cin >> n >> m;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin>>v[i];
    }
    while(m--){
        char ch;
        int d, k, y, z;
        cin >> ch;
        if(ch == 'S'){
            cin>>d;
            for(int i = 0; i < n; i++){
                v[i] += d;
            }
        }
        else if(ch == 'M'){
            cin >> d;
            for(int i = 0; i < n; i++){
                v[i] *= d;
            }
        }
        else if(ch == 'D'){
            cin >> k;
            for(int i = 0; i < n; i++){
                v[i] /= k;
            }
        }
        else if(ch == 'P'){
            cin >> y >> z;
            swap(v[y], v[z]);
        }
        else if(ch == 'R'){
            reverse(v.begin(),v.end());
        }
    }
    for(int i = 0; i < n; i++){
        cout << v[i] << (i==n-1 ? "\n" : " ");
    }
}

int main()
{
    FAST_IO;
   #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
   #endif
    int t = 1, case_number = 1;
    cin >> t;
    while(t--)
    {
        cout << "Case " << case_number++ << ":\n";
        solve();
    }
    return 0;
}

