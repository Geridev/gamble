#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
    srand(time(0));
    int a = rand() % 2; 
	if (a==0)
	{
		cout << "Milan" << endl;
	}
	else
	{
		cout << "Pepe" << endl;
	}
}

