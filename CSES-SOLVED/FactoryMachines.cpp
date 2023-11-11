#include <bits/stdc++.h>

using namespace std; 

long long n, t; 


long long SP(long long mid, long long arr[]) 
{
    long long int res = 0; 
    for(long long i = 0; i < n; i++) 
    {
        res += mid / arr[i];
        if(res >= t)
            return res;
    }
    return res; 
}
long long solve(long long arr[], long long max) 
{
    long long right = max * t + 1, left = 0; 
    long long int ans = 0;

    while(left <= right) 
    {
        long long mid = left + (right - left) / 2;
        long long sp = SP(mid, arr); 

        
        if(sp >= t) 
        {
            ans = mid;
            right = mid - 1;
        }
        else 
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main() 
{
    cin >> n >> t; 
    long long arr[n]; 
    long long m = 0;

    for(int i = 0; i < n; i++) 
    {
        cin >> arr[i]; 
        m = max(arr[i], m);
    }

    cout << solve(arr, m); 
}