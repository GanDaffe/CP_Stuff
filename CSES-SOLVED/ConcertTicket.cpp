#include <bits/stdc++.h>
 
using namespace std; 
 
int n, m, p;
 
int main() 
{
    cin >> n >> m;
    multiset<int> h; 
 
    while(n--)
    {
        cin >> p; 
        h.insert(p);
    }
 
    int curr;
    while(m--) 
    { 
        cin >> curr; 
        auto ctr = h.upper_bound(curr); 
        
        if(ctr == h.begin()) 
        {
            cout << -1 << '\n'; 
        }
        else 
        {
            ctr--;
            cout << *ctr << '\n';
            h.erase(ctr); 
        }
    }
 
}
