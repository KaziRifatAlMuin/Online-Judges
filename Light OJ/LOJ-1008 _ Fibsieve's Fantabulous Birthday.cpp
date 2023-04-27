/*
    Author : RifatALmuiN
    Problem : Fibsieve's Fantabulous Birthday
    Source : https://lightoj.com/problem/fibsieves-fantabulous-birthday
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    ll n,sq,root,d,mid,x,y,change,shift,num;
    cin>>n;
    root = sqrt(n);
    if(n!=(root*root)) root++;
    d= pow(root,2)-pow(root-1,2);
    sq = root*root;
    mid= d/2;
    change = sq-n;
    num = sq-mid;
    x=root;
    y=root;
    shift = abs(n-num);
    if(sq&1){
        if(change>mid){
            y-=shift;
        }
        else{
            x-=shift;
        }
    }
    else{
        if(change>mid){
            x-=shift;
        }
        else{
            y-=shift;
        }       
    }
    cout<<x<<" "<<y<<"\n";
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

