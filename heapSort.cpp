#include <bits/stdc++.h>
using namespace std;


void max_heapify(int * vet, int i, int size) // concerta a extrutura da maxHeap
{
	int l = 2*i;
	int r = 2*i+1;
	int bigger = i;
	
	if(l < size && vet[l] > vet[bigger]) bigger = l ;
	if(r < size && vet[r] > vet[bigger]) bigger = r ;
	
	if(i != bigger) // apenas coloca o maior como pai, faz isso para todos errados consecutivamente
	{ 
		swap(vet[i],vet[bigger]);
		max_heapify(vet,bigger,size);
	}
}

void build_heap(int * vet, int size)
{
	for(int i = size/2 -1 ; i >= 0 ; i--) // roots estao sempre antes de size/2, depois sao folhas
			max_heapify(vet,i,size);
}


void heapSort(int * vet,int size)
{
	build_heap(vet ,size);
	for(int i = size - 1 ; i > 0 ; i--)
	{
		swap(vet[0] , vet[i]);
		size--;
		max_heapify(vet,0,size); // vou colocando sempre na ultima folha, entao removo a folha,
		// sempre coloca o maior no topo
	}		
}

int main()
{
	int vet[11] = {-1,9,1,3,4,5,7,8,9,1,-9};
	
	heapSort(vet,11);
	for(int i = 0; i < 11;i++)
		cout<<vet[i]<<' ';
	cout<<endl;
}
