#include <bits/stdc++.h> 

using namespace std; 

int n; 

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n;
    int a[n]; 

    for(int i = 0; i < n; i++) cin >> a[i]; 
    sort(a, a + n);

    long long curr = 0; 

    for(int i = 0; i < n; i++)
    {
        if(curr + 1 < a[i])
            break; 

        curr += a[i];
    }

    cout << curr + 1;
}
