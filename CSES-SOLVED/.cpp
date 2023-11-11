#include <bits/stdc++.h>
 
using namespace std; 
 
long long repetion(string s);
 
int main() 
{
    string s; 
    cin >> s; 
 
    cout << repetion(s);
}
 
long long repetion(string s) 
{
    long long res = 1; 
    long long left = 0;
 
    for(long long right = 1; right < s.length(); right++) 
    {
        if(s[right] == s[right - 1])
            res = max(res, right - left + 1); 
        else 
            left = right; 
    }
 
    return res;  
}
