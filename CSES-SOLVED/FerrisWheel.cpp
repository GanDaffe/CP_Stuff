#include <bits/stdc++.h>

using namespace std; 

int n, x; 

int main() 
{
    cin >> n >> x; 
    int p[n]; 
    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        cin >> p[i]; 

    }     
    
    sort(p, p + n);
    int l = 0, r = n - 1; 

    while(l <= r) 
    {
        int sum = p[l] + p[r]; 
        if(sum <= x)
        {
            l++; 
            r--;
        }    
        else 
        {
            r--; 
        }
        ans++; 
    }
    
    cout << ans;
}