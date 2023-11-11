#include <bits/stdc++.h> 

using namespace std; 

#define ll long long

const int MAX = 2e5; 
int n; 
int arr[MAX + 5];

int main() 
{
    ios::sync_with_stdio(0); 
    cin.tie(nullptr); 

    cin >> n; 

    for(int i = 0; i < n; i++)   
        cin >> arr[i];

    sort(arr, arr + n);
    int mid = arr[n / 2]; 
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans += abs(mid - arr[i]);

    cout << ans;
}   