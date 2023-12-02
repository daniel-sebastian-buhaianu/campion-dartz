#include <fstream>
using namespace std;
bool esteProdusDeTreiNumereConsecutive(int p, int & x);
int main()
{
    ifstream f("dartz.in");
    ofstream g("dartz.out");
    int S;
    f >> S;
    f.close();
    int p1, p2;
    for (p1 = 0, p2 = S/2; p1 <= p2; p1 += 2, p2 -= 2)
    {
        int x, y;
        if (esteProdusDeTreiNumereConsecutive(p1, x)
            && esteProdusDeTreiNumereConsecutive(p2, y))
        {
            g << x << ' ' << y << ' ';
            g << x << ' ' << y;
            break;
        }
    }
    g.close();
    return 0;
}
bool esteProdusDeTreiNumereConsecutive(int p, int & x)
{
    x = 0;
    int pp = 0;
    while (pp < p)
    {
        x++;
        pp = x * (x+1) * (x+2);
    }
    return pp == p;
}
