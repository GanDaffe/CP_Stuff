#include <bits/stdc++.h>

using namespace std; 

void solve(int disks, int start, int mid, int goal) 
{
    if(disks == 1)
    {
        cout << start << ' ' << goal << '\n';
        return;
    }    

    solve(disks - 1, start, goal, mid); 
    solve(1, start, mid, goal); 
    solve(disks - 1, mid, start, goal);
    
}

int main() 
{
    int n; 
    cin >> n; 

    cout << (1 << n) - 1 << '\n';
    solve(n, 1, 2, 3);
}