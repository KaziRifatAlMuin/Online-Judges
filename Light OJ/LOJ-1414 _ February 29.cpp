/*
    Author : RifatALmuiN
    Problem : February 29
    Source : https://lightoj.com/problem/february-29
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;


int div(int a, int b, int d)
{
    return b/d - a/d + (a%d==0);
}

void solve()
{
    string m1,m2;
    int d1,d2,y1,y2,y;
    cin>>m1;
    scanf("%d, %d",&d1,&y1);
    cin>>m2;
    scanf("%d, %d",&d2,&y2);
    if(m1=="January" || m1=="February")
        y1=y1;
    else
        y1++;
    if(m2=="January" || (m2=="February" && d2<29))
        y2--;
    else
        y2=y2;
    int m4 = div(y1,y2,4);
    int m400 = div(y1,y2,400);
    int m100 = div(y1,y2,100);
    y = m4 + m400 - m100;
    cout<<y<<endl;
}

int main()
{
    //FAST_IO;
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

