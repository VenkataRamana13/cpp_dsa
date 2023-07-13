#include <bits/stdc++.h>
using namespace std; 

datatype ** arr = new datatype * [rowSize]; 
for (int i = 0; i < rowSize; i++) 
    arr[i] = new datatype [colSize];

// freeing memory 
for (int i = 0; i < rowSize; i++) 
    delete [] arr[i];
delete [] arr;
