/*
    Author : RifatALmuiN
    Problem : Interactive Search
    Source : https://lightoj.com/problem/interactive-search
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


void solve()
{
    int n;
    cin >> n;
    int high = n, low = 1, mid;

    while (1) {
        mid = (high+low)/2;
        cout << "guess " << mid << endl;
        fflush(stdin);
        string resp;
        getline(cin, resp);


        if (resp == "correct" || resp == "too many tries") {
            break;
        }

        else if (resp == "low") {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
}

int main()
{
//    FAST_IO;
//   #ifndef ONLINE_JUDGE
//       freopen("input.txt", "r", stdin);
//       freopen("output.txt", "w", stdout);
//   #endif
    int t = 1, case_number = 1;
    //cin >> t;
    while(t--)
    {
        //cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

