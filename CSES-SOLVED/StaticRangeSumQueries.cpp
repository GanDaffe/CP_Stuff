#include <bits/stdc++.h>

#define ull unsigned long long
#define ll long long
#define FORL(i, a, b) for(int i = a; i <= b; i++)
#define FORG(i, a, b) for(int i = a; i >= b; i--)

using namespace std; 

int n, q, a, b;
ull pref[200001]; 
ull arr[200001];

int main() 
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    cin >> n >> q;  
    
    FORL(i, 0, n - 1) cin >> arr[i]; 
    FORL(i, 1, n) pref[i] = pref[i - 1] + arr[i - 1];

    while(q--) 
    {
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << '\n';
    }

    return 0; 
}