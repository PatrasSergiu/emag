#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>
#define nmax 200002

using namespace std;

ifstream fin("apm.in");
ofstream fout("apm.out");

struct str {
    int nod;
    int target;
    int cost;

    bool operator < (const str &other) const {
        return cost < other.cost;
    }
};

vector <str> v;
vector <pair<int,int> > nods;

int n,m,p[nmax];

int findParent(int nod){
    if(p[nod] == nod)
        return nod;
    else return p[nod] = findParent(p[nod]);
}

void unite(int a, int b){
    p[findParent(b)] = findParent(a);
}


void input(){
    fin>>n>>m;
    int a,b,c,i;
    for(a=1;a<=n;a++)
        p[a] = a;
    for(i=1;i<=m;i++){
        fin>>a>>b>>c;
        v.push_back({a,b,c});
    }
}

int main()
{
    input();
    int nr = 0,i,a,b,c,res=0;
    sort(v.begin(),v.end());
   // for(auto i : v)
     //   fout<<i.nod<<" "<<i.target<<" "<<i.cost<<'\n';
    for(i=0;i<v.size() && nr < (m-1);i++){
        a = v[i].nod;
        b = v[i].target;
        c = v[i].cost;
        if(findParent(a) != findParent(b)){
            res+=c;
            unite(a,b);
            nr++;
            nods.push_back({a,b});
        }
    }

    fout<<res<<'\n';
    fout<<nr<<'\n';
    for(auto i : nods)
        fout<<i.first<<" "<<i.second<<'\n';

    return 0;
}
