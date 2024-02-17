#include <bits/stdc++.h>

using namespace std;

int main()
{

    int low = 1, high = 100000;
    // Taking the value of n as input and setting it as high as it will be the maximum value
    cin >> high;


    // To keep track of the number of tries
    int count = 0;

    // Binary search
    while (low <= high)
    {
        // Finding the mid value
        int mid = (low + high) >> 1;
        // Printing the guess
        cout << "guess " << mid << endl;


        // Taking the response as input
        string response;
        cin >> response;

        // Checking the response
        if (response == "correct")
            return 0;
        else if (response == "high")
            high = mid - 1;
        else if (response == "low")
            low = mid + 1;

        // Increasing the count
        count++;

        // If the count is greater than 30 then printing too many tries and returning
        if (count >= 30)
        {
            cout << "too many tries" << endl;
            return 0;
        }
    }

    return 0;
}