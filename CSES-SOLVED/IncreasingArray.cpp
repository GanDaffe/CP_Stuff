#include <bits/stdc++.h>

using namespace std;

long long increasing_array(long long n, vector<long long> v);

int main()
{
    long long n; 
    cin >> n; 
    vector<long long> v;
    for(int i = 0; i < n; i++) 
    {
        long long val; 
        cin >> val;
        v.push_back(val);
    }

    cout << increasing_array(n, v);
}

long long increasing_array(long long n, vector<long long> v) 
{
    long long res = 0;

    for(long long i = 1; i < n; i++) 
    {
        if(v.at(i) < v.at(i - 1)) 
        {
            long long dis = v.at(i - 1) - v.at(i);
            v.at(i) += dis;
            res += dis;
        }
    }

    return res;
}