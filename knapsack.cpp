#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 

ll knapsack(vector<pair<ll, ll>>& p_w, ll x, ll n){
    ll m[n][x + 1];
    for(ll i = 0; i < n; i++){
        m[i][0] = 0;
    }
    for(ll i = 0; i < p_w[0].second; i++){
        m[0][i] = 0; 
    }
    for(ll i = p_w[0].second; i <= x; i++){
        m[0][i] = p_w[0].first; 
    }
    for(ll i = 1; i < n; i++){
        for(ll j = 1; j <= x; j++){
            if(j >= p_w[i].second){
                m[i][j] = max(p_w[i].first + m[i - 1][j - p_w[i].second],  m[i - 1][j]); 
            }
            else m[i][j] = m[i - 1][j];
        }
    }
    return m[p_w.size() - 1][x]; 
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    ll n, x; cin >> n >> x; 
    vector<pair<ll, ll>> p_w(n); 
    for(ll i = 0; i < n; i++){
        ll X; cin >> X; 
        p_w[i].first = X; 
    }
    for(ll i = 0; i < n; i++){
        ll X; cin >> X; 
        p_w[i].second = X; 
    }
    sort(p_w.begin(), p_w.end(), [](pair<ll, ll> a, pair<ll, ll> b){
        return double(a.first) / double(a.second) > double(b.first) 
        / double(b.second); 
    }); 
    cout << knapsack(p_w, x, n) << "\n"; 
}