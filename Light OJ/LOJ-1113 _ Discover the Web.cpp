/*
    Author : RifatALmuiN
    Problem : Discover the Web
    Source : https://lightoj.com/problem/discover-the-web
*/

#include <bits/stdc++.h>
using namespace std;
#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(NULL)
typedef long long int ll;

int main()
{
    #ifndef ONLINE_JUDGE
       freopen("input.txt", "r", stdin);
       freopen("output.txt", "w", stdout);
   #endif
    
    int t; //number of test cases
    cin>>t;

    //getchar() is used to read the new line character after the test case.
    getchar(); 

    for(int k=1;k<=t;k++)
    {
        cout<<"Case "<<k<<":\n";

        stack<string> FORWARD,BACK;
        string str,url;

        //to initialize the FORWARD stack according to the problems condition.
        FORWARD.push("http://www.lightoj.com/");

        // While(1) loop is used to ensure we keep taking input till we get the "QUIT" input.
        while(1)
        {
            cin>>str;

            string temp;

            if(str=="VISIT")
            {
                cin>>url;

                if(FORWARD.empty())
                    cout<<"Ignored"<<'\n';
                else
                    {

                       //for moving the top element of the "FORWARD" stack to the "BACK" stack
                       temp=FORWARD.top();
                       FORWARD.pop();
                       BACK.push(temp);

                       //for emptying the entire stack.
                       while(!FORWARD.empty())
                       {
                           FORWARD.pop();
                       }
                       FORWARD.push(url);
                    }

                cout<<FORWARD.top()<<'\n';

            }
            else if(str=="BACK")
            {

                if(BACK.empty())
                    cout<<"Ignored"<<'\n';
                else
                {
                    //For moving the top element of the "BACK" stack to the "FORWARD" stack.
                    temp=BACK.top();
                    BACK.pop();
                    FORWARD.push(temp);

                    cout<<FORWARD.top()<<'\n';
                }

            }
            else if(str=="FORWARD")
            {
                if(FORWARD.size()<2)
                    cout<<"Ignored"<<'\n';
                else
                {
                    temp=FORWARD.top();
                    FORWARD.pop();
                    BACK.push(temp);
                    cout<<FORWARD.top()<<'\n';
                }
            }
            else if(str=="QUIT")  //The query to stop taking inputs and end the program.
                break;

        }
    }
    return 0;
}