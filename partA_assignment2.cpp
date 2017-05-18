#include <iostream>
#include <cstdlib> //srand,rand
#include <ctime> //time
#include <array>
#include <vector>


const int size = 50;

double prob(){
	return (static_cast<double>(rand())/RAND_MAX);
}

class Graph{
	public:
		Graph(int size,double density){
			edges = new bool*[size];
			costs = new double*[size];
			for(int i=0;i<size;++i){
				edges[i]=new bool[size];
				costs[i]=new double[size];
			}
			for(int i=0;i<size;++i){
				for(int j=i;j<size;++j){
					if(i==j) edges[i][j]=false;
					else edges[i][j]=edges[j][i]=
						(prob()<density);
				}
			}
			for(int i=0;i<size;++i){
				for(int j=i;j<size;++j){
					if(deges[i][j]) costs[i][j]=costs[j][i]=
						rand()%10 +1;
				}
			}
		}
		int V(Graph G) {return G.edges[0].size();}
		int E(Graph G) {
			int count;
			for(int i=0;i<size;++i){
				for(int j=i;j<size;++j){
					if(G.edges[i][j]) count++;
				}
			}
			return count;
		}
		bool adjacent(Graph G,int x, int y){return G.edges[x][y];}
		vector<int> neighbors(Graph G,int x){
			vector<int> neighbors;
			int size = G.edges[x].size();
			for(int i=0;i<size;++i){
				if(G.edges[x][i]) neighbors.push_back(i);
			}
			return neighbors;
		}


	private:
		bool** edges;
		double** costs;
};


void GenerateGraph(bool** graph,int size,double density){
	srand(time(0)); //seed rand()
	//heap created 2D array of Bool
	graph = new bool*[size];
	for(int i=0;i<size;++i)
		graph[i] = new bool[size];

	for(int i=0;i<size;++i){
		for(int j=i;j<size;++j){
			if(i==j) graph[i][j]=false;
			else graph[i][j]=graph[j][i] = (prob()<density);
		}
	}

}

int main(){


	return 0;
}
