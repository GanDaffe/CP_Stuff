#include <bits/stdc++.h> 

using namespace std; 

int n; 
int dp[1000001];

int find_max(int n) 
{
    int res = -1;
    while(n > 0) 
    {
        int dig = n % 10; 
        n /= 10; 
        res = max(res, dig);
    }

    return res;
}

int main() 
{
    cin >> n; 
    dp[0] = 0;

    for(int i = 1; i <= n; i++) 
    {
        dp[i] = dp[i - find_max(i)] + 1;
    }

    cout << dp[n]; 
}