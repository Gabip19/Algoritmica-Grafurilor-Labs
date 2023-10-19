#include <fstream>
#include <algorithm>
#define MOD 1000000007
using namespace std;

struct elem
{
    int x, y, c;
};

elem v[200001], sol[200001];

int n, m, dim[200001], tata[200001];

inline bool cmp(const elem& a, const elem& b)
{
    return a.c < b.c;
}

int tata_multime(int x)
{
    if (x != tata[x])
        x = tata_multime(tata[x]);
    return tata[x];
}

void unire(int x, int y)
{
    x = tata_multime(x);
    y = tata_multime(y);
    if (dim[y] > dim[x])
    {
        tata[x] = y;
        dim[y] += dim[x];
    }
    else
    {
        tata[y] = x;
        dim[x] += dim[y];
    }
}

int main(int argc, char* argv[])
{
    ifstream f(argv[1]);
    ofstream g(argv[2]);

    int i, rez = 0, k = 0;
    f >> n >> m;
    for (i = 1; i <= m; i++)
        f >> v[i].x >> v[i].y >> v[i].c;
    sort(v + 1, v + m + 1, cmp);
    for (i = 1; i <= n; i++)
    {
        dim[i] = 1;
        tata[i] = i;
    }
    for (i = 1; i <= m && k < n; i++)
    {
        if (tata_multime(v[i].x) != tata_multime(v[i].y))
        {
            unire(v[i].x, v[i].y);
            rez += v[i].c;
            sol[++k] = v[i];
        }
    }
    g << rez << '\n' << k << '\n';
    for (i = 1; i <= k; i++) g << sol[i].x << ' ' << sol[i].y << '\n';

    f.close();
    g.close();
    return 0;
}