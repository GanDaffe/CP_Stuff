#include <bits/stdc++.h> 
 
using namespace std; 
 
int n, x;
int dp[1002][100002];
 
int main() 
{
    ios ::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> x; 
    int book[n]; 
    int pages[n]; 
 
    for(int i = 0; i < n; i++)  
        cin >> book[i]; 
 
    for(int i = 0; i < n; i++)  
        cin >> pages[i]; 
 
    for(int i = 0; i < n; i++) 
    {
        for(int j = 0; j <= x; j++) 
        {
            dp[i + 1][j] = dp[i][j];
            if(j >= book[i]) 
                dp[i + 1][j] = max(dp[i][j], dp[i][j - book[i]] + pages[i]);
        }
    }
 
    cout << dp[n][x];
}
