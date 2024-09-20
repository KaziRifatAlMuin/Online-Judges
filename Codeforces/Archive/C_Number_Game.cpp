#include <bits/stdc++.h>
using namespace std;
#define YN(result) (result)? cout<<"YES\n" : cout<<"NO\n";
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;

void player_1(){
    cout << "Ashishgup" << endl;
}

void player_2(){
    cout << "FastestFinger" << endl;
}

bool check_prime(int n){
    for(int i = 2; i < min(N, n); i++)
        if(n % i == 0)
            return 0;
    return 1;
}

void solve()
{
    int n;
    cin >> n;
    bool lose = (n == 1);
    if(n > 2 && n % 2 == 0){
        int m = n - 1;
        if((n & m) == 0)
            lose = 1;
        else if(n % 4 != 0 && check_prime(n / 2))
            lose = 1;
    }
    if(lose)
        player_2();
    else player_1();
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}