#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define nmax 50005
#define mmax 250005
#define inf 0x3f3f3f

using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

struct str {
    int nod;
    int cost;
};

vector <str> birdy[mmax];
queue <str> q;
int n,m,dist[nmax],in_q[nmax],nr_q[nmax];
bool ciclu = false;

void input(){
    int a,b,c;
    fin>>n>>m;
    while(fin>>a>>b>>c){
        birdy[a].push_back({b,c});
    }
}

void bellmanford(int source){
    int nod,cost;
    dist[source] = 0;
    in_q[source] = 1;
    nr_q[source] = 1;
    q.push({source,0});
    while(!q.empty() && !ciclu){
        nod = q.front().nod;
        cost = q.front().cost;
        q.pop();
        in_q[nod] = 0;
        for(auto i : birdy[nod]){
            if(dist[i.nod] > dist[nod] + i.cost){
                dist[i.nod] = dist[nod] + i.cost;
                if(!in_q[i.nod]){
                    in_q[i.nod] = 1;
                    nr_q[i.nod]++;
                    if(nr_q[i.nod] == n)
                        ciclu = true;
                    q.push({i.nod,dist[i.nod]});
                }
            }
        }
    }
}

int main()
{
    input();
    fill(dist + 0, dist+n+1, inf);
    bellmanford(1);
    if(ciclu)
        fout<<"Ciclu negativ!";
    else {
        for(int i=2;i<=n;i++)
            fout<<dist[i]<<" ";
    }
    return 0;
}
