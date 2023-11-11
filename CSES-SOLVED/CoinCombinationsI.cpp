#include <bits/stdc++.h>

using namespace std; 

long long n, x; 
const int mod = 1e9 + 7;

long long solve(long long c[]) 
{
    long long dp[x + 1];
    for(long long i = 1; i <= x; i++)
        dp[i] = 0;

    dp[0] = 1; 
    for(long long i = 1; i <= x; i++) 
    {
        for(long long k = 0; k < n; k++) 
        {
            if(i >= c[k])
                dp[i] += dp[i - c[k]];
        }
        dp[i] %= mod;
    }
    return dp[x]; 
}

int main() 
{
    cin >> n >> x; 
    long long c[n]; 
    for(long long i = 0; i < n; i++) 
        cin >> c[i]; 

    cout << solve(c);
}