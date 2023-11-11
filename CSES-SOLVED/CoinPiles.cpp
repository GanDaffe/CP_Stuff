#include <bits/stdc++.h>

using namespace std; 

bool solve(int a, int b) 
{ 
    return (a + b) % 3 == 0 && (min(a, b) * 2 >= max(a, b));   
}


int main() 
{
    int t, a, b; 
    cin >> t; 

    vector<pair<int, int>> v; 
    for(int i = 0; i < t; i++) 
    {
        cin >> a >> b; 
        v.push_back(make_pair(a, b));
    }


    for(int i = 0; i < t; i++) 
    {
        int first = v[i].first; 
        int second = v[i].second; 

        if(solve(first, second))
            cout << "YES" << endl; 
        else 
        {
            cout << "NO" << endl;
        }

    }


}