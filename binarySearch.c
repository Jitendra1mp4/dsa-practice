#include <stdio.h>

int search(int *arr, int n, int key){
	int start = 0 , end = n ,  mid ;
	while (start <= end){
		mid = (start + end)/2  ;
		int currentValue = arr[mid] ;
		if(currentValue == key) return  mid ; 
		else if (currentValue < key ) start = mid + 1 ;
		else end = mid - 1 ;
	}
	return -1 ;
}

int searchRecursivly(int *arr, int key, int start , int end){
	if (start >= end) return -1 ;
	int mid = ( start + end ) / 2 ;
	
	int currVlu = arr[mid] ;
	if (currVlu == key) return mid ;
	else if(currVlu < key )return searchRecursivly(arr,key,start+1,end) ;
	else return searchRecursivly(arr,key,start,end-1) ;
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9} ;
	int key = 6 ;
	int res = searchRecursivly(arr,key,0,9) ;
	printf("%d ", res) ;
}