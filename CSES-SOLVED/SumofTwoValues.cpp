#include <bits/stdc++.h>

using namespace std; 

const int MAX = 2e5;
int x, n; 
int arr[MAX + 5];

int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(nullptr);
    
    cin >> n >> x; 
    for(int i = 1; i <= n; i++)
        cin >> arr[i]; 

    map<int, int> m; 

    for(int i = 1; i <= n; i++) 
    {
        if(m.find(x - arr[i]) != m.end())
        {
            cout << m[x - arr[i]] << ' ' << i; 
            return 0; 
        }

        if(m.find(arr[i]) == m.end()) 
            m.insert({arr[i], i}); 

    }

    cout << "IMPOSSIBLE"; 

}