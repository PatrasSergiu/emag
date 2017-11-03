#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#define nmax 55
#define inf 0x3f3f3f3f

using namespace std;

struct base {
    int nod;
    int time;
    int w;
};

vector <base> birdy[nmax];
queue <pair<int,int> > q;
ifstream fin("lanterna.in");
ofstream fout("lanterna.out");

bool friends[nmax];
int dist[nmax][1002],n,m,k,tmin = inf;

void input(){
    fin>>n>>k;
    int i,a,b,t,w;
    for(i=1;i<=n;i++)
        fin>>friends[i];
    fin>>m;
    for(i=1;i<=m;i++){
        fin>>a>>b>>t>>w;
        birdy[a].push_back({b,t,w});
        birdy[b].push_back({a,t,w});
    }
}

int possiblePath(int lant){
    fill(dist[0],dist[0] + nmax * 1002, inf);
    dist[1][lant] = 0;
    q.push({1,lant});
    int nod,left,time,w,z;
    while(!q.empty()){
        nod = q.front().first;
        left = q.front().second;
        q.pop();
        int currentLeft=dist[nod][left];
        if(friends[nod])
            left = lant;
        for(auto i : birdy[nod]){
            time = i.time;
            w = i.w;
            if(left >= w && (dist[i.nod][left-w] > currentLeft + time)){
                dist[i.nod][left-w] = currentLeft + time;
                q.push({i.nod,left-w});
            }
        }
    }
    for(z=1;z<=n;z++)
        if(dist[n][z] != inf)
            return 1;
    return 0;
}

int binarySearch(){
    bool sol = false;
    int st = 0, dr = k + 1;
    while(st < dr){
        int mij = (st+dr+1)/2;
        if(possiblePath(mij)){
            dr = mij;
            for(int i=1;i<=n;i++)
            tmin = min(tmin,dist[n][i]);
        }
        else
            st = mij + 1;
    }
return st;
}

int main()
{
    input();
    int r = binarySearch();
    fout<<tmin<<" "<<r;

    return 0;
}
