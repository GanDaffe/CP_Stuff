#include <bits/stdc++.h>

using namespace std; 

void weird_algorithm(long long n);

int main()
{
    long long n; 
    cin >> n;
    weird_algorithm(n);
}

void weird_algorithm(long long n) 
{
    while(n != 1)
    {
        cout << n << " ";

        if(n & 2 != 0)
            n = n * 3 + 1;
        else 
            n /= 2;
    }
    cout << n;

}