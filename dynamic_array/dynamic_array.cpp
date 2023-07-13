#include <bits/stdc++.h>
using namespace std; 

class ArrayList {
		int * arr; 
		int numElements;
		int capacity;

public: 
		void resize(){
			// double the capacity
			// copy the elements
			// delete the old array 
			int * temp = new int[capacity * 2]; 
			capacity *= 2;
			
			for(int i = 0; i < numElements; i++){
				temp[i] = arr[i]; 
			}

			delete [] arr;

			arr = temp;
		}
		void insert(int val){
				if(num_elements < capacity){
					arr[num_elements] = val; 
					num_elements++; 
				}
				else{
					resize(); 
					arr[num_elements] = val; 
					num_elements++; 
				}
		}
		int length(){
			return num_elements; 
		}
		int get(int index){
			if(index < num_elements){
				return arr[index]; 
			}
			else{
				return -1; 
			}
		}
}; 
