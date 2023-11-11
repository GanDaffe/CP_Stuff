#include <bits/stdc++.h>

using namespace std;

void spiral_number(vector<pair<long long, long long>> v, long long n);
long long helper(long long tmp);

int main() 
{
    long long n; 
    cin >> n; 

    vector<pair<long long, long long>> v; 

    for(int i = 0; i < n; i++)  
    {
        long long v1, v2; 
        cin >> v1 >> v2;
        v.push_back(make_pair(v1, v2));
    }

    spiral_number(v, n);
}

void spiral_number(vector<pair<long long, long long>> v, long long n) 
{
    for(long long i = 0; i < n; i++) 
    {
        long long center;
        if(v[i].first > v[i].second) 
        {
            center = helper(v[i].first - 1);
            if(v[i].first % 2 == 0)
                cout << center + (v[i].first - v[i].second);
            else 
                cout << center - (v[i].first - v[i].second);

            cout << '\n';
        }
        else 
        {
            center = helper(v[i].second - 1);  
            if(v[i].second % 2 == 0) 
                cout << center - (v[i].second - v[i].first); 
            else 
                cout << center + (v[i].second - v[i].first);

            cout << '\n';
        }
    }
}

long long helper(long long tmp) 
{
    long long res;
    res = (tmp * (tmp + 1)) + 1;
    return res;
}