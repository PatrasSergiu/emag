#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;
#define NMAX 100001
int n,s;
ifstream fin("darb.in");
ofstream fout("darb.out");
int dist[NMAX];
queue <int> q;
vector <int> adiacenta[NMAX];

int maxDistance(){
    int i,poz=1;
    for(i=1;i<=n;i++)
        if(dist[i] > dist[poz]){
        poz = i;
    }
return poz;
}
void input(){
    int x,y,i;
    fin>>n;
    while(fin>>x>>y){
        adiacenta[x].push_back(y);
        adiacenta[y].push_back(x);
    }
}

void dfs(int x){
    for (auto i : adiacenta[x])
        if (dist[i] == 0)
        {
            dist[i] = dist[x] + 1;
            dfs(i);
        }
}

int main()
{
    input();
    dist[1] = 1;
    dfs(1);
    int p = maxDistance();
    fill(dist,dist+n,0);
    dist[p] = 1;
    dfs(p);
    p = maxDistance();
    fout<<dist[p];
    fin.close();
    fout.close();
    return 0;
}
