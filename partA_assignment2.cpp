#include <iostream>
#include <cstdlib> //srand,rand
#include <ctime> //time
#include <array>
#include <vector>

using namespace std;
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
						static_cast<double>(rand()%10 +1);
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
		vector<double> neighbors(Graph G,int x){
			vector<double> neighbors;
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

void siftDown(vector<double> pq,int i){
	int size = pq.size();
	int minindex = i;
	int l = 2*i+1;
	if(l<=size-1 && pq[l]<pq[minindex]) minindex = l;
	int r = 2*i +2;
	if(r<=size-1 && pq[r]<pq[minindex]) minindex = r;
	if(i!=minindex){
		swap(pq[i],pq[minindex]);
		siftDown(pq,minindex);
	}
}

void siftUp(vector<double> pq,int i){
	while(i>0 && pq[(i-1)/2]<pq[i]){
		swap(pq[(i-1)/2],pq[i]);
		i = (i-1)/2;
	}
}

class PriorityQueue{
	private:
		vector<double> pq;
		int size=0;
	public:
		PriorityQueue(double a[]){
			size = a.size();
			for(int i=0;i<size;++i)
				this.insert(a[i]);
		}
		void chgPriority(int i,double priority){
			pq[i]=priority;
		}
		double minPriority(){
			double result;
			result = pq[0];
			pq[0] = pq[size-1];
			pq.pop_back();
			size -=1;
			siftDown(pq,0);
			return result;
		}
		bool contains(double elt){
			for(int i=0;i<size;++i){
				if(elt<pq[i]) return false;break;
				else if(elt==pq[i]) return true;
				else return false;
			}
		}
		void insert(double elt){
			pq.push_back(elt);
			size +=1;
			siftUp(pq,size-1);
		}
		double top(){return pq[0];}
		int size(){return size;}


};

class ShortestPath{
	
};

int main(){


	return 0;
}
