#include <fstream>
#include <queue>
#include <vector>
using namespace std;
#define nmax 7505
#define mmax 14005
queue <int> q;
vector <int> adiacenta[mmax];
vector <int> rez;
ifstream fin("graf.in");
ofstream fout("graf.out");

int n,m,x,y;
int dist1[nmax],dist2[nmax],fr[nmax],sol[nmax];

void input(){
    fin>>n>>m>>x>>y;
    int a,b;
    while(fin>>a>>b){
        adiacenta[a].push_back(b);
        adiacenta[b].push_back(a);
    }
fill(dist1+0,dist1+nmax,0x3f3f3f3);
fill(dist2+0,dist2+nmax,0x3f3f3f3);
}

void bfs(int dist[]){
    while(!q.empty()){
        int nod = q.front();
        q.pop();
        for(auto i : adiacenta[nod]){
            if(dist[i] > dist[nod] + 1){
                dist[i] = dist[nod] + 1;
                q.push(i);
            }
        }
    }
}

bool ok(int d,int i){
    for(int j=1;j<=n;j++)
        if(dist1[j] == d || dist2[j] == d)
            if(i != j && dist1[i] != dist2[j])
                return false;
    return true;
}

int main()
{
    input();
    int nr = 0;
    dist1[x] = 0;
    dist2[y] = 0;
    ///bfs din x
    q.push(x);
    bfs(dist1);
    ///bfs din y
    q.push(y);
    bfs(dist2);
    int s = dist1[x] + dist2[x];
    int c1,c2,i;
    for(i=1;i<=n;i++){
        c1 = dist1[i] + dist2[i];
        if(s == c1){
            if(ok(dist1[i],i)){
                nr++;
                rez.push_back(i);
            }
    }
}
    fout<<nr<<'\n';
    for(auto i : rez)
        fout<<i<<" ";

    return 0;
}
