#include <bits/stdc++.h> 

using namespace std; 

int n; 

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n; 

    long long res = INT_MIN, tmp = 0; 
    for(int i = 0; i < n; i++) 
    {
        int x; 
        cin >> x;
        tmp += x;
        res = max(res, tmp);  

        if(tmp < 0) 
            tmp = 0; 
    }
    cout << res;    
}