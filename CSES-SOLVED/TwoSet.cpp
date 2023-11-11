#include <bits/stdc++.h>

using namespace std; 

int n; 
const int MAX = 1e6;
int a[MAX + 1]; 

int main() 
{
    ios::sync_with_stdio(0);
    cout.tie(nullptr);

    cin >> n; 
    long long sum = 0;

    for(int i = 1; i <= n; i++)
        sum += i; 

    if(sum % 2 != 0) 
        cout << "NO"; 
    else 
    {
        cout << "YES" << '\n';
        long long mid = sum / 2; 
        long long ra = 0, cnt = 0, l = 1, r = n;

        while(ra != mid) 
        {
            if(ra + r <= mid) 
            {    
                ra += r;
                cnt++;
                a[r--] = 1; 
            }

            if(ra + l <= mid) 
            {
                ra += l;
                cnt++;
                a[l++] = 1;
            }
        }
        
        cout << cnt << '\n'; 
        for(int i = 1; i <= n; i++)  
            if(a[i]) cout << i << ' ';
        cout << '\n'; 

        cout << n - cnt << '\n'; 
        for(int i = 1; i <= n; i++)  
            if(!a[i]) cout << i << ' ';
       

    } 
    
}