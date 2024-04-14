#include <iostream>
using namespace std;

int distanceTraveled(int mainTank, int additionalTank)
{
    int dist = 0;
    while (mainTank != 0)
    {
        if (mainTank < 5)
        {
            dist += mainTank * 10;
            mainTank = 0;
        }
        else if (mainTank >= 5)
        {
            dist += 50;
            if (additionalTank != 0)
            {
                mainTank = mainTank - 4;
                additionalTank--;
            }
            else
            {
                mainTank = mainTank - 5;
            }
        }
    }
    return dist;
}

int main()
{
    int n, m;
    cout << "Main Tank: ";
    cin >> n;
    cout << "Additional Tank: ";
    cin >> m;

    cout<<endl;
    cout << "Total Distance Traveled: " << distanceTraveled(n, m) << endl;
    
    return 0;
}