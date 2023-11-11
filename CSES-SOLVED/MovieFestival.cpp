#include <bits/stdc++.h> 
 
using namespace std; 
 
int n; 
 
bool cmp(pair<int, int> p1, pair<int, int> p2) 
{
    return p1.second < p2.second; 
}
 
int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(nullptr); 
    
    cin >> n; 
    pair<int, int> p[n];
    for(int i = 0; i < n; i++) 
        cin >> p[i].first >> p[i].second;
    sort(p, p + n, cmp); 
    
    long long res = 1;
    int t = p[0].second;
 
    for(int i = 1; i < n; i++) 
    {
        if(t <= p[i].first)   
        {
            res++; 
            t = p[i].second;
        }
    }
 
    cout << res; 
 
    return 0; 
}
