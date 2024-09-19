/*
    Author : RifatALmuiN
    Problem : Secret Origins
    Source : https://lightoj.com/problem/secret-origins
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

string dec_to_bin(int n)
{
    string str = "";
    while(n){
        char c;
        c = n&1 ? '1' : '0';
        str += c;
        n /= 2;
    }
    while(str.length()<=32) str += '0';
    reverse(str.begin(),str.end());
    return str;
}

int bin_to_dec(string s)
{
    int len = s.length(), res=0;
    for(int i=len-1, j=0; i>=0; i--,j++){
        res += ((s[i]-'0')*pow(2,j));
    }
    return res;
}


void solve()
{
    ll n;
    cin>>n;
    string bin = dec_to_bin(n);
    next_permutation(bin.begin(),bin.end());
    cout<<bin_to_dec(bin)<<endl;
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

