/*
    Author : RifatALmuiN
    Problem : 100 - The 3n + 1 problem
    Source : https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=36
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

unordered_map <int,int> len;


ll cycle(ll n)
{
    ll length;
    if(len.count(n))
        return len[n];
    if(n==1)
        length = 1;
    else if(n%2==0){
        length = 1 + cycle(n/2);
    }
    else{
        length = 1 + cycle(3*n + 1);
    }
    return len[n]=length;
}

void solve()
{
    ll i,j,maxi;
    while((scanf("%lld %lld",&i,&j))!=EOF){
        maxi=0;
        cout<<i<<" "<<j<<" ";
        if(i>j) swap(i,j);
        for(int x=i;x<=j;x++){
            maxi = max(maxi,cycle(x));
        }
        cout<<maxi<<"\n";
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
    //cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

