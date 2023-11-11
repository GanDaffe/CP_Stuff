#include <bits/stdc++.h> 

using namespace std; 

long long missing_number(long long a[], long long n);

int main() 
{
    long long n; 
    cin >> n; 
    long long a[n - 1]; 

    for(int i = 0; i < n - 1; i++)
        cin >> a[i];
    
    cout << missing_number(a, n);

}

long long missing_number(long long a[], long long n) 
{
    long long vals = (n * (n + 1)) / 2;
    long long sum = 0;

    for(int i = 0; i < n - 1; i++) 
        sum += a[i];

    return vals - sum;
}