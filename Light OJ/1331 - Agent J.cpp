#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
long long int const MOD = 1e9 + 7;
int const N = 2e5 + 7;
#define PI acos(-1.0)

double area(double r , double angle){
    return 0.5*r*r*angle ;
}

double angle(double A, double B, double C){
    return acos(((B*B)+(C*C)-(A*A)) / (2*B*C));
}

void solve()
{
    double a,b,c ;
    cin >> a >> b >> c ;
    double s = (a+a+b+b+c+c)/2.0;
    double Total =  sqrt(s*(s-a-b)*(s-b-c)*(s-c-a));
    double Circular = area(a,angle(b+c,c+a,a+b)) + area(b,angle(c+a,a+b,b+c)) + area(c,angle(a+b,b+c,c+a));
    cout << fixed << setprecision(10) << Total - Circular << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int t = 1, cs = 1;
    cin >> t;
    while(t--){
        cout << "Case " << cs++ << ": ";
        solve();
    }
    return 0;
}