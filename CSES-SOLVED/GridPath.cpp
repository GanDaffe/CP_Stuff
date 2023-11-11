#include <bits/stdc++.h>
 
using namespace std; 
 
int n; 
int maze[1001][1001];
const int mod = 1e9 + 7;
 
int main() 
{
    cin >> n; 
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            char c; 
            cin >> c; 
            if(c == '*')
                maze[i][j] = 0; 
            else 
                maze[i][j] = 1;
        }
    }
 
    int dp[n][n]; 
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
 
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            if(maze[i][j]) 
            {
                if(i > 0 && j > 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                else if(i > 0) 
                    dp[i][j] += dp[i - 1][j]; 
                else if(j > 0)
                    dp[i][j] += dp[i][j - 1]; 
                dp[i][j] %= mod;
            }
            else 
                dp[i][j] = 0;
        }
    }
    cout << dp[n - 1][n - 1];
}
