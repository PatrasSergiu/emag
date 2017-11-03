#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define nmax 50005
#define inf 0x3f3f3f
ifstream fin("dijkstra.in");
ofstream fout("dijkstra.out");
struct str {
    int nod;
    int cost;
    bool operator < (const str &other) const{
        return cost > other.cost;
    }
};
vector <str> adiacenta[nmax];
priority_queue <str> q;
int n,m,dist[nmax];

void input(){
    fin>>n>>m;
    int a,b,c;
    while(fin>>a>>b>>c){
        adiacenta[a].push_back({b,c});
    }
}

void dijkstra(int source){
    int nod,cost;
    dist[source] = 0;
    q.push({source,0});
    while(!q.empty()){
        nod = q.top().nod;
        cost = q.top().cost;
        q.pop();
        if(cost!=dist[nod]) continue;
        for(auto i : adiacenta[nod]){
            if(dist[i.nod] > cost + i.cost){
                dist[i.nod] = cost + i.cost;
                q.push({i.nod,dist[i.nod]});
            }
        }
    }
}

void printResult(){
    for(int i=2;i<=n;i++)
        if(dist[i] != inf)
            fout<<dist[i]<<" ";
        else fout<<0<<" ";
}

int main()
{
    input();
    dijkstra(1);
    printResult();
fin.close();
fout.close();
    return 0;
}
