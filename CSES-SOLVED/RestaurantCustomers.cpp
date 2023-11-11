#include <bits/stdc++.h> 

using namespace std; 

#define pi pair<int, int>
#define ll long long 

int n;

int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(nullptr); 

    cin >> n; 
    vector<pi> p;

    for(int i = 0; i < n; i++)
    {    
        int x, y; 
        cin >> x >> y; 
        p.push_back({x, 1});
        p.push_back({y, -1});     
    }
    
    sort(p.begin(), p.end()); 
    ll ans = 0, c = 0; 

    for(pi s: p)
    {
        c += s.second;
        ans = max(c, ans); 
    }
    

    cout << ans; 
    
}