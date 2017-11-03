#include <fstream>
#include <queue>
#include <vector>
#define nmax 805
#define mmax 6005
#define inf 0x3f3f3f3f

using namespace std;

struct str {
    int nod;
    int cost;
    bool operator < (const str &other) const {
            return cost > other.cost;
    }
};

struct ins {
    int nod;
    int tip;
};

ifstream fin("dragoni.in");
ofstream fout("dragoni.out");

int dist[nmax][nmax],n,m,p,drakeDistance[nmax],result,currentDrake;
vector <str> quinn[mmax];
queue <str> q;
queue <ins> qq;

void input(){
    fin>>p;
    fin>>n>>m;
    int i,a,b,d;
    for(i=1;i<=n;i++)
        fin>>drakeDistance[i];
    for(i=1;i<=m;i++){
        fin>>a>>b>>d;
        quinn[a].push_back({b,d});
        quinn[b].push_back({a,d});
    }
}

void solve(int start){
    dist[start][start] = 0;
    qq.push({start,start});
    int nod,tip,tipCurent;
    while(!qq.empty()){
        nod = qq.front().nod;
        tip = qq.front().tip;
        tipCurent = nod;
        qq.pop();
        for(auto i:quinn[nod]){
            if(drakeDistance[tip]>=i.cost && dist[nod][tip]+i.cost<dist[i.nod][tip])
            {
                dist[i.nod][tip]=dist[nod][tip]+i.cost;
                qq.push({i.nod,tip});
            }
            if(drakeDistance[tipCurent]>=i.cost&&dist[nod][tip]+i.cost<dist[i.nod][tipCurent])
            {
                dist[i.nod][tipCurent]=dist[nod][tip]+i.cost;
                qq.push({i.nod,tipCurent});
            }
        }
    }
}

int main()
{
    input();
    if(p==1){
        bool viz[nmax]={false};
        q.push({1,0});
        currentDrake = drakeDistance[1];
        result = drakeDistance[1];
        viz[1] = true;
        int nod,cost;
        while(!q.empty()){
            nod = q.front().nod;
            q.pop();
            for(auto i : quinn[nod]){
                if(!viz[i.nod] && currentDrake >= i.cost){
                    result = max(result,drakeDistance[i.nod]);
                    viz[i.nod] = true;
                    q.push({i.nod,drakeDistance[i.nod]});
                }
            }
        }
    fout<<result;
    }
    else {
        fill(dist[0],dist[0] + nmax * nmax, inf);
        solve(1);
        result = inf;
        for(int i=1;i<=n;i++)
            result = min(result,dist[n][i]);
        fout<<result;
    }
    return 0;
}
