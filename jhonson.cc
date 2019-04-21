#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;

#define MAXN 1000
#define INF 0x3f3f3f3f

vector<ii> Grafo[MAXN]; // lista de adjacencia
int dist[MAXN][MAXN];   // matriz do caminho minimo de todo mundo para todo mundo
int H[MAXN];            // vetor distancia do bellmanFord

bool jhonson(int N)
{
	// Limpando os vetores
	memset(dist,INF,sizeof dist);
	memset(H,INF,sizeof H);
	 
	// Adicionando o vertice S
	for(int i = 1 ; i <= N ; i++)
		Grafo[0].push_back(ii(i,0));
	
	
	// Belmanford
	H[0] = 0;
	for(int i = 0 ; i <= N-1;i++)
		for(int u = 0; u <= N;u++)
			for(size_t j = 0; j < Grafo[u].size();j++){
				ii v = Grafo[u][j];
				H[v.first] = min( H[v.first] , H[u] + v.second);
			}
			
	Grafo[0].clear();
	
	// Verificar se existe ciclo negativo
	for(int u = 1; u <= N; u++)
		for(size_t i = 0 ; i < Grafo[u].size() ; i++){
			ii v = Grafo[u][i];
			if(H[v.first] > H[u] + v.second)
				return false; // ciclo negativo
		}
	 
	// Recalculando o peso das arestas
	for(int u = 1; u <= N; u++)
		for(size_t i = 0 ; i < Grafo[u].size();i++){
			int novoPeso = Grafo[u][i].second + (H[u] - H[Grafo[u][i].first]);
			Grafo[u][i].second = novoPeso;
		}
	
	// Rodando o dikjstra N vezes
	priority_queue< ii, vector<ii>, greater<ii> > pq;
	for(int k = 1 ; k <= N; k++)
	{
		dist[k][k] = 0;
		pq.push( ii( 0 , k ) );
		
		while(! pq.empty() )
		{
			ii atual = pq.top(); pq.pop();
			int d = atual.first;
			int u = atual.second;
			if(d > dist[k][u]) continue;
			
			for(size_t i = 0; i < Grafo[u].size() ; i++)
			{
				ii v = Grafo[u][i];
				if(dist[k][u] + v.second < dist[k][v.first])
				{
					dist[k][v.first] = dist[k][u] + v.second;
					pq.push(ii(dist[k][v.first],v.first));
				}
			}			
		}
	}
	
	//~ // Concertando os pesos dos caminhos
	for(int i = 1; i <= N;i++)
		for(int j = 1; j <= N;j++)
			dist[i][j] += H[j] - H[i];
			
	return true; // deu bom
}

int main()
{
	freopen("in","r",stdin);
	int N,E,a,b,c;
	while(cin>>N>>E && N)
	{
		// limpando o grafo
		for(int i = 0; i <= N;i++)
			Grafo[i].clear();
		
		// montando o grafo
		while(E--)
		{
			cin>>a>>b>>c;
			Grafo[a].push_back(ii(b,c)); 
		}
		
		if(!jhonson(N))
		{
			cout<<"GRAFO INVALIDO!!! (EXISTENCIA DE CICLO NEGATIVO)"<<endl;
			continue;	
		}
		
		for(int i = 1; i <= N;i++)
		{
			for(int j = 1; j <= N;j++)
			{
				if(dist[i][j] >= INF) cout<<"inf\t";
				else cout<<dist[i][j]<<'\t';
			}
			cout<<endl;
		}
	}		
}

