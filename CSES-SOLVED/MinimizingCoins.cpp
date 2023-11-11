#include <bits/stdc++.h> 

using namespace std; 

int n, x;

int solve(int c[]) 
{
    int dp[x + 1]; 
    for(int i = 0; i <= x; i++)
        dp[i] = x + 1;
    
    dp[0] = 0;
    for(int i = 1; i <= x; i++) 
    {
        for(int k = 0; k < n; k++) 
        {
            if(c[k] <= i) 
            {
                dp[i] = min(dp[i - c[k]] + 1, dp[i]);
            } 
        }
    }
    
    if(dp[x] != x + 1)
        return dp[x];

    return -1;

}

int main() 
{
    cin >> n >> x; 
    int coins[n]; 

    for(int i = 0; i < n; i++) 
        cin >> coins[i];

    cout << solve(coins); 
}
