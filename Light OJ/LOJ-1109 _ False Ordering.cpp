/*
    Author : RifatALmuiN
    Problem : False Ordering
    Source : https://lightoj.com/problem/false-ordering
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;
const int MX = 1e3; //1000

pair<int, int> d[MX];

bool order_cond (pair<int, int> x, pair<int, int> y) {
  if (x.second != y.second)
    return x.second < y.second; 
    //If Number of divisors of x is less than number of divisors of y.
  return x.first > y.first;
  //If Number of divisors of x is equal to number of divisors of y and x > y.
}

void pre_compute() {
  for (int i = 1; i <= MX; i++) {
    d[i - 1].first = i;
    for (int j = i; j <= MX; j += i) {
      d[j - 1].second++;
    }
  }
  sort(d, d + MX, order_cond); //custom comparison
}



void solve()
{
    int n;
    cin>>n;
    cout<<d[n-1].first<<endl;
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
    pre_compute();
    while(t--)
    {
        cout << "Case " << case_number++ << ": ";
        solve();
    }
    return 0;
}

