#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define nmax 36005
#define mmax 2*nmax
#define inf 0x3f3f3f3

using namespace std;

struct str {
    int nod;
    int cost;
    bool operator < (const str &other) const{
            return cost > other.cost;
    }
};

ifstream fin("catun.in");
ofstream fout("catun.out");

vector <str> birdy[mmax];
priority_queue <str> q;

int n,m,x,dist[nmax],fort[nmax],pr[nmax];

void input(){
    int a,b,c;
    fin>>n>>m>>x;
     fill(dist+0,dist + n + 1,inf);
    fill(pr+0,pr+n+1,inf);
    for(int i=1;i<=x;i++){
        fin>>a;
        fort[a] = 1;
        pr[a] = a;
        q.push({a,0});
    }
    while(m){
        fin>>a>>b>>c;
        birdy[a].push_back({b,c});
        birdy[b].push_back({a,c});
        m--;
    }

}

void dijkstra(){
    int nod,cost;
    while(!q.empty()){
        nod = q.top().nod;
        cost = q.top().cost;
        q.pop();
        for(auto i : birdy[nod]){
            if(!fort[i.nod] && (dist[i.nod] > cost + i.cost)){
                dist[i.nod] = cost + i.cost;
                q.push({i.nod,dist[i.nod]});
                pr[i.nod] = pr[nod];
            }
            else if(!fort[i.nod] && (dist[i.nod] == cost + i.cost))
                        pr[i.nod] = min(pr[i.nod],pr[nod]);
        }
    }
}

void printResult(){
      for(int i=1;i<=n;i++){
        if(fort[i])
            fout<<0<<" ";
        else if(dist[i] == inf)
                fout<<0<<" ";
            else fout<<pr[i]<<" ";
    }
}

int main()
{
    input();
    dijkstra();
    printResult();
    fin.close();
    fout.close();
    return 0;
}
