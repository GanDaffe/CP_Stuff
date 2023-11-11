
#include <bits/stdc++.h>
 
using namespace std; 
 
long long dice_simulation(long long n);
 
const long long m=1e9+7;
 
int main() 
{
    long long n; 
    cin >> n;
    cout << dice_simulation(n);
}
 
long long dice_simulation(long long n) 
{
    if(n == 1)
        return 1; 
 
    long long dp[n + 1];
    
    for(int i = 0; i < n + 1; i++)
        dp[i] = 0;
 
    dp[0] = 1;
 
    for(long long i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= 6; j++) 
        {
            if(i - j >= 0)
                dp[i] = (dp[i] + dp[i - j]) % (m);
        }
    }
    return dp[n];
}
