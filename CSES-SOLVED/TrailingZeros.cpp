#include <bits/stdc++.h>

using namespace std; 


int main() 
{   
    long long num; 
    cin >> num; 

    int res = 0; 
    long long t = 5; 

    while(t <= num)
    {
        res += num / t;
        t *= 5;
    }

    cout << res;
}