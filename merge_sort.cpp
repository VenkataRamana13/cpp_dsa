#include <bits/stdc++.h>
using namespace std; 

using ll = long long; 

void mergeSort(ll *a, ll l, ll r){//include l, not r
    if(r - l == 1) return; 
    mergeSort(a, l, l + (r - l) / 2); 
    mergeSort(a, l + (r - l)/ 2, r); 
    vector<ll> b;
    ll p = l, q = l + (r - l) / 2; 
    while(true){
        if(p < l + (r - l) / 2 and q < r){
            if(a[p] <= a[q]){
                b.push_back(a[p]); 
                p++; 
            }
            else{
                b.push_back(a[q]); 
                q++; 
            }
        }
        else if(p >= l + (r - l) / 2 and q < r){
            b.push_back(a[q]); q++;  
        }
        else if(p < l + (r - l) / 2 and q >= r){
            b.push_back(a[p]); p++; 
        }
        else break; 
    }
    for(ll i = 0; i < b.size(); i++){
        a[l + i] = b[i]; 
    }
}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); 
    ll n; cin >> n; 
    ll a[n]; 
    for(auto &i : a){
        cin >> i; 
    }
    mergeSort(a, 0, n);
    for(ll i = 0; i < n; i++){
        cout << a[i] << " "; 
    }
    cout << "\n"; 
}