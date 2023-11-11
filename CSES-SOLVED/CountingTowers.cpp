#include <bits/stdc++.h> 

using namespace std; 

int t, n; 
const int mod = 1e9 + 7;
const int MAX = 1000001;
long long dp[MAX][3];

void solve() 
{
    dp[1][1] = 1; 
    dp[1][2] = 1; 
    for(long long i = 2; i < MAX; i++) 
    {
        dp[i][1] = (dp[i - 1][1] * 4 % mod + dp[i - 1][2]) % mod; 
        dp[i][2] = (dp[i - 1][1]  + dp[i - 1][2] * 2 % mod) % mod; 
    }
}

int main() 
{
    cin >> t; 
    solve();
    while(t--) 
    {
        cin >> n; 
        cout << (dp[n][1] + dp[n][2]) % mod << '\n';
    }
    
}