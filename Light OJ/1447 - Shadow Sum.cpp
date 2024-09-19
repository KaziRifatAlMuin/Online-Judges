#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

void solve()
{
    int n, num, pos, sign, i;
    cin>>n;
    ll sum = 0;
    set <int> s;
    map <int,int> mp;
    for(i=0; i<n; i++){
        cin>>num;
        pos = abs(num);
        sign = num<0 ? -1 : 1;
        mp[pos] = sign;
        s.insert(pos);
    }
    for(auto x : s){
        sum += (x*mp[x]);
    }
    cout<<sum<<endl;
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
        cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

