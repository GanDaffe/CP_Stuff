#include <bits/stdc++.h>
 
using namespace std; 
 
int n, m, k; 
 
 
int solve(int a[], int b[]) 
{
    int j = 0, i = 0, res = 0; 
    while(i < n && j < m) 
    {
        if(abs(a[i] - b[j]) <= k) 
        {
            res++; 
            i++; 
            j++; 
        }
        else 
        {
            if(a[i] - b[j] > k) 
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    return res; 
}
 
int main() 
{
    cin >> n >> m >> k; 
    int a[n];
    int b[m]; 
 
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
 
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
 
    sort(a, a + n); 
    sort(b, b + m); 
 
    cout << solve(a, b);
}
