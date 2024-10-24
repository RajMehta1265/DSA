#include <iostream>
using namespace std;

class poly
{
public:
    int coefficent;
    int power;

    int add(poly p1[100], poly p2[100], poly p3[100], int t1, int t2)
    {
        int i, j, k;
        int t3;
        i = j = k = 0;
        while (i < t1 && j < t2)
        {
            if (p1[i].power == p2[j].power)
            {
                p3[k].coefficent = p1[i].coefficent + p2[j].coefficent;
                p3[k].power = p1[i].power;
                i++, j++, k++;
            }
            else if (p1[i].power > p2[j].power)
            {
                p3[k].coefficent = p1[i].coefficent;
                p3[k].power = p1[i].power;
                i++, k++;
            }
            else
            {
                p3[k].coefficent = p2[j].coefficent;
                p3[k].power = p2[j].power;
                j++, k++;
            }
        }
        while (i < t1)
        {
            p3[k].coefficent = p1[i].coefficent;
            p3[k].power = p1[i].power;
            i++, k++;
        }
        while (j < t2)
        {
            p3[k].coefficent = p2[j].coefficent;
            p3[k].power = p2[j].power;
            j++, k++;
        }
        t3 = k;
        return t3;
    }
};

int main()
{
    poly p1[100], p2[100], p3[100],p4;
    int t1, t2,t3;

    cout << "Enter the number of terms for polynomial 1: ";
    cin >> t1;
    for (int i = 0; i < t1; ++i)
    {
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> p1[i].coefficent >> p1[i].power;
    }

    cout << "Enter the number of terms for polynomial 2: ";
    cin >> t2;
    for (int i = 0; i < t2; ++i)
    {
        cout << "Enter coefficient and power for term " << i + 1 << ": ";
        cin >> p2[i].coefficent >> p2[i].power;
    }

    t3=p4.add(p1,p2,p3,t1,t2);

    for (int i = 0; i < t3; i++)
    {
        cout << "Term " << i + 1 << ": Coefficient = " << p3[i].coefficent << ", Power = " << p3[i].power << endl;
    }


    return 0;
}
