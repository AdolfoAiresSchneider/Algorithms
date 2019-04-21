#include <bits/stdc++.h>
using namespace std;


int partition(int * A ,int p, int r)
{
	int x = A[r];
	int i = p-1;
	for(int j = p ; j < r; j++){
		if(A[j] <= x){
			swap(A[++i],A[j]);	
		}
	}
	swap(A[i+1], A[r]);
	return i++;
}


void quick_sort(int * A, int p, int r)
{
	if(p <r) 
	{
		int q = partition(A,p,r);
		quick_sort(A,p,q-1);
		quick_sort(A,q+1,r);
	}
}

	
int main()
{
	int a[7] = {51,9,7,4,5,6,-1};	
	quick_sort(a,0,6);
	for(int i = 0; i < 7 ;i++) cout<<a[i]<<' ';
	cout<<endl;
}
