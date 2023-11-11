#include <bits/stdc++.h>

using namespace std; 

const int mod = 1e9 + 7; 
int n, x; 

int solve(int c[]) 
{
    int dp[x + 1];
    dp[0] = 1;

    for(int i = 1; i <= x; i++) 
        dp[i] = 0;

    for(int k = 0; k < n; k++) 
    {
        for(int i = 0; i <= x; i++) 
        {
            if(i >= c[k])
                dp[i] += dp[i - c[k]];

            dp[i] %= mod; 
        }
    }

    return dp[x];
}

int main()
{
    cin >> n >> x; 
    int c[n]; 
    
    for(int i = 0; i < n; i++)
        cin >> c[i]; 
    
    cout << solve(c);
}