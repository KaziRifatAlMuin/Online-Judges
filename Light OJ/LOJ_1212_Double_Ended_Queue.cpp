#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL);
typedef long long int ll;
long long int const MOD = 1e9 + 7;

void solve()
{
    deque <int> dq;
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        string s;
        int x;
        cin >> s;
        if(s == "pushLeft"){
            cin >> x;
            if(dq.size() == n){
                cout << "The queue is full" << endl;
            }
            else{
                dq.push_front(x);
                cout << "Pushed in left: " << x << endl;
            }
        }
        else if(s == "pushRight"){
            cin >> x;
            if(dq.size() == n){
                cout << "The queue is full" << endl;
            }
            else{
                dq.push_back(x);
                cout << "Pushed in right: " << x << endl;
            }
        }
        else if(s == "popLeft"){
            if(dq.size() == 0){
                cout << "The queue is empty" << endl;
            }
            else{
                cout << "Popped from left: " << *dq.begin() << endl;
                dq.pop_front();
            }
        }
        else if(s == "popRight"){
            if(dq.size() == 0){
                cout << "The queue is empty" << endl;
            }
            else{
                cout << "Popped from right: " << *(--dq.end()) << endl;
                dq.pop_back();
            }
        }
    }
}

int main()
{
    FAST_IO

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

/*


Coded by RifatALmuiN

Input
_______________________________

_______________________________


Output
_______________________________

_______________________________


*/
    