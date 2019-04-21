#include <bits/stdc++.h>
using namespace std;

void insertionSort(int * vet, int n)
{
	register int i,j,k;
	for(i = 1; i < n; ++i)
	{
		for(k = vet[i], j = i-1; j >= 0 &&  k < vet[j] ; j--) 
			vet[j+1] = vet[j];
		vet[j+1] = k;
	}
}


void OrdenacaoOscilante(int N, int * vet, int * cont)
{
	bool flag = 1;
	while(++cont[0] && flag)
	{
		flag = 0;
		for(int i = N-1;++cont[1] && i >= 1;++cont[2],i--) // N-2
		{
			if(++cont[3] &&vet[i-1] > vet[i]) // N-3
			{ 
				swap(vet[i-1], vet[i]);	// N-3
				++cont[4];
				flag = 1; // N-1
				++cont[5];
			}
		}
		for(int i = 1;++cont[6] && i < N; ++cont[7] &&i++) // N-2
		{
			if(++cont[8] && vet[i-1] > vet[i]) // N-3
			{ 
				swap(vet[i-1], vet[i]); // N-3
				++cont[9];
				flag = 1;//N-3
				++cont[10];
			}
		}
	}
}

void bubbleSortMelhorado(int * vet, int n)
{
	bool flag = 1;
	for(int i = 0 ; i < n && flag ;  ++i, flag = 0)
	{
		for(int j = n-1 ; j >= i+1 ; j-- )
		{
			if(vet[j] < vet[j-1])
			{ 
				swap(vet[j-1],vet[j]);
				flag = 1;
			}
		}
	}
}

int BinarySearch(int i, int j, int k, int * vet)
{
	register int meio = (i+j)/2;
	if(i == j) return i;
	if( k > vet[meio] ) return BinarySearch(meio+1,j,k,vet);
	return BinarySearch(i,meio,k,vet);
}

int SequencialR(int k, int * vet, int N)
{
	register int i;
	for(i = 0; i < N && vet[i] != k ;i++);
	if(vet[i] == k) return i;
	return -1;
}

int Sequencial(int k, int * vet,int N)
{
	int resp = -1 , i;
	for(i = 0; i < N ;i++) 
		if( vet[i] == k  ) resp = i;
	return resp;
}

void printVet(int * vet, int n)
{
	for(int i = 0; i < n; i++) cout<<vet[i]<<' ';
	cout<<endl;
}

void bubbleSort(int N , int * vet, int * cont)
{ 
	int flag  = 1;
	for(int i = 0 ; ++cont[0] && i < N && flag;  ++i, ++cont[1]) 
	{
		++cont[2],flag= 0;
		for(int j = N-1 ; ++cont[3] && j > i; --j,++cont[4]) 
		{	
			if(++cont[5] && vet[j] < vet[j-1])
			{
				flag = 1;
				swap(vet[j-1],vet[j]);
				++cont[6];
			}
		}
	}
}

int main()
{
	int N = 4;
	int vetA[N] = {4,3,1,2};
	//int vetB[N];
	int count[60];
	
    //for(int i = 0; i <N;++i) vetA[i] = rand()%N * pow(-1,i);
	//for(int i = 0; i <N;++i) vetB[i] = rand();
	
	memset(count,0,sizeof count);
	bubbleSort(N,vetA,count);
	cout<<endl;
	for(int i = 0; i < 7;i++)
	{
		cout<<count[i]<<endl;	
	}
	cout<<endl;
	
	//printVet(vetA,N);
}
