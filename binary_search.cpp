ll binary_search(ll n, ll *a, ll x){
  ll left = 0, right = n - 1; 
  while(left <= right){
    ll mid = left + (right - left) / 2; 
    if(a[mid] == x){
      return mid; 
    else if (a[mid] < x){
      left = mid + 1; 
    else right = mid - 1; 
  return -1; 
