#include <fstream>
#include <algorithm>
#include <iomanip>
#include <vector>
#define nmax 10005
using namespace std;

ifstream fin("desen.in");
ofstream fout("desen.out");
int p[nmax],n;
double rez;

struct xoy{
    int x;
    int y;
}points[nmax];

struct str {
    int x,y;
    double d;

    bool operator < (const str &other) const {
            return d < other.d;
    }
};

vector <str> v,v2;

double power(double a){
        return a*a;
}

double atob (xoy a, xoy b){
     return sqrt(power(a.x - b.x) + power(a.y - b.y));
}

int findParent(int nod)
{
    if (p[nod] == nod)return nod;
    return p[nod] = findParent(p[nod]);
}

void unite(int x, int y)
{
    p[findParent(x)] = findParent(y);
}

void getDistance(int act){
    p[act] = act;
    rez = 0;
    for(int i = 1; i < act; i++){
        p[i] = i;
        v.push_back({i,act,atob(points[i],points[act])});
    }
    sort(v.begin(),v.end());
    for (auto i : v){
        if(findParent(i.x) != findParent(i.y)){
            rez += i.d;
            unite(i.x,i.y);
            v2.push_back(i);
        }
    }
    v=v2;
    fout<<fixed<<setprecision(5)<<rez<<'\n';
}

int main()
{
    fin>>n;
    int a,b;
    for(int  i = 1; i<=n;i++){
            fin>>a>>b;
            points[i].x = a;
            points[i].y = b;
            getDistance(i);
    }
    fin.close();
    fout.close();
    return 0;
}
