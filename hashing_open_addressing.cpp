//204251 Naveen Kumar Tyagi
#include <iostream>
using namespace std;

int HTableLP[11]; // for linear probing
int HTableQP[11]; // for quadratic probing
int HTableDP[11]; // for double hashing

int HTsize = 11;

int HashF(int key)
{
    return key % HTsize;
}
int HashF2(int key)
{
    return 7 - (key % 7);
}

int reHashLP(int hI) // Linear probing
{
    for (int i = hI + 1; i < HTsize; i++)
    {
        if (HTableLP[i] == -1)
        {
            return i;
        }
    }
    for (int i = 0; i < hI; i++)
    {
        if (HTableLP[i] == -1)
        {
            return i;
        }
    }
    return -1;
}
int reHashQP(int hI) //Quadratic Probing
{
    int in;
    for (int i = 1; true; i++)
    {
        in = (hI + i * i) % HTsize;
        if (HTableQP[in] == -1)
        {
            break;
        }
    }
    return in;
}
int reHashDP(int h1, int h2) //Double Hashing
{
    int in;
    for (int i = 2; true; i++)
    {
        in = (h1 + i * h2) % HTsize;
        if (HTableDP[in] == -1)
        {
            break;
        }
    }
    return in;
}
void insert(int key)
{
    int hI = HashF(key);

    //Linear Probing
    if (HTableLP[hI] == -1)
    {
        HTableLP[hI] = key;
    }
    else
    {
        int in = reHashLP(hI);
        if (in == -1)
        {
            cout << "Insertion is not possible.\n";
        }
        else
        {
            HTableLP[in] = key;
        }
    }
    /*-------------------------------------------*/

    //Quadratic Probing
    if (HTableQP[hI] == -1)
    {
        HTableQP[hI] = key;
    }
    else
    {
        int in = reHashQP(hI);
        HTableQP[in] = key;
    }
    /*------------------------------------------*/

    //Double Hashing
    hI = (HashF(key) + HashF2(key)) % HTsize;
    if (HTableDP[hI] == -1)
    {
        HTableDP[hI] = key;
    }
    else
    {
        int in = reHashDP(HashF(key), HashF2(key));
        HTableDP[in] = key;
    }
}

int searchLP(int key) // Linear probing
{
    int hI = HashF(key);
    if (HTableLP[hI] == key)
    {
        return hI;
    }
    else
    {
        for (int i = hI + 1; i < HTsize; i++)
        {
            if (HTableLP[i] == key)
            {
                return i;
            }
        }
        for (int i = 0; i < hI; i++)
        {
            if (HTableLP[i] == key)
            {
                return i;
            }
        }
    }
    return -1;
}
int searchQP(int key) //Quadratic Probing
{
    int hI = HashF(key);
    int in;

    for (int i = 0; true; i++)
    {
        in = (hI + i * i) % HTsize;
        if (HTableQP[in] == key)
        {
            break;
        }
    }

    return in;
}
int searchDP(int key) //Double Hashing
{
    int h1 = HashF(key);
    int h2 = HashF2(key);
    int in;
    for (int i = 1; true; i++)
    {
        in = (h1 + i * h2) % HTsize;
        if (HTableDP[in] == key)
        {
            break;
        }
    }
    return in;
}
void deleteVal(int key)
{
    int i = searchLP(key);
    HTableLP[i] = -1;

    i = searchQP(key);
    HTableQP[i] = -1;

    i = searchDP(key);
    HTableDP[i] = -1;
}
void displayT()
{
    cout << "\n   Linear Probing\tQuadratic Probing\tDouble Hashing\n";
    for (int i = 0; i < HTsize; i++)
    {
        cout << i << "  " << HTableLP[i] << "\t\t\t\t" << HTableQP[i] << "\t\t\t" << HTableDP[i] << endl;
    }
}
int main()
{
    fill_n(HTableLP, 11, -1); //Linear Probing
    fill_n(HTableQP, 11, -1); //Quadratic Probing
    fill_n(HTableDP, 11, -1); //Double Hashing

    cout << "\n\n-1 is used for vacant place.\n";
    insert(12);
    insert(56);
    insert(23);
    insert(77);
    insert(6);
    insert(6);
    insert(6);

    displayT();
    cout << "\nRemoving 23 and 77\n";
    deleteVal(23);
    deleteVal(77);
    displayT();

    return 0;
}