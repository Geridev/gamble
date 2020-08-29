#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    int ossz = 50000;
    int bet;
    cout << "tedd fel az oszeget" << endl;
    cin >> bet;
    cout<< "osszeged: " <<ossz-bet<<endl;
    int a;
    cout << "adj meg egy szamot" << endl;
    cin >> a;
    srand(time(0));
    int b = rand() % 1; 
    cout << b << endl;
    if (a==b)
    {
        cout << "Gratulalok nyertel" << 2 * bet + ossz << endl;
    }
    else
    {
        cout << "sajna vesztetel" << endl;
    }
    cout << ossz << endl;
}
