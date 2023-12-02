#include <fstream>
#define PMAX 350
using namespace std;
int S, np, min1, min2;
int xmin[PMAX], p[PMAX];
void citire();
void generareProduse();
void afisare();
bool cautareBinara(
    int x,
    int v[],
    int st,
    int dr,
    int & poz);
int main()
{
    citire();
    generareProduse();
    for (int i = 0; i < np; i++)
    {
        int produs = S/2 - p[i];
        int poz;
        if (cautareBinara(produs, p, i+1, np-1, poz))
        {
            min1 = xmin[i];
            min2 = xmin[poz];
            break;
        }
    }
    afisare();
    return 0;
}
bool cautareBinara(
    int x,
    int v[],
    int st,
    int dr,
    int & poz)
{
    poz = -1;
    st--, dr++;
    while (dr-st > 1)
    {
        int mij = st + (dr-st)/2;
        if (v[mij] == x)
        {
            poz = mij;
            return 1;
        }
        if (v[mij] < x) st = mij;
        else dr = mij;
    }
    return 0;
}
void afisare()
{
    ofstream g("dartz.out");
    g << min1 << ' ' << min2 << ' ';
    g << min1 << ' ' << min2;
    g.close();
}
void generareProduse()
{
    int x = 0, produs = 0;
    while (produs < S/2)
    {
        xmin[np] = x;
        p[np++] = produs;
        x++;
        produs = x * (x+1) * (x+2);
    }
}
void citire()
{
    ifstream f("dartz.in");
    f >> S;
    f.close();
}
