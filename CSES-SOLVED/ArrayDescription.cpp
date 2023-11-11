#include <bits/stdc++.h> 

using namespace std; 

long long n, m;
const int mod = 1e9 + 7; 
long long dp[100001][101]; 

long long solve(long long a[])  
{
    if(a[0] != 0)
    {
        dp[0][a[0]] = 1;
    }      
    else
    {
        for(long long i = 0; i <= m; i++) 
        { 
            dp[0][i] = 1; 
        }
    }

    for(long long i = 1; i < n; i++) 
    {
        if(a[i] == 0) 
        {   
            for(long long j = 1; j <= m; j++) 
            {
                dp[i][j] += dp[i - 1][j]; 
                if(j - 1 > 0)
                
                    dp[i][j] += dp[i - 1][j - 1];
                if(j + 1 <= m)
                    dp[i][j] +=  dp[i - 1][j + 1];
                
                dp[i][j] %= mod;
            }
        }
        else 
        {
            dp[i][a[i]] += dp[i - 1][a[i]];
            if(a[i] - 1 > 0) 
                dp[i][a[i]] += dp[i - 1][a[i] - 1];
            if(a[i] + 1 <= m)
                dp[i][a[i]] += dp[i - 1][a[i] + 1];
            
            dp[i][a[i]] %= mod; 
        }
    }

    long long res = 0; 
    for(int i = 1; i <= m; i++) 
        res += dp[n - 1][i];
    
    return res % mod;
}


int main() 
{
    cin >> n >> m; 
    long long arr[n]; 

    for(long long i = 0; i < n; i++)
        cin >> arr[i]; 
    
    cout << solve(arr);
}