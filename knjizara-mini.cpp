#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>

using namespace std;

int main()
{
    int izbor;
    int brKnjige=0;
    unsigned long long int *barkod = new unsigned long long int[2000];
    string *naziv = new string[2000];
    double *cijena = new double[2000];
    while(1)
    {
        cout << "1. Unos novog knjige: " << endl;
        cout << "2. Ispis svih podataka: " << endl;
        cout << "3. Inventura: " << endl;
        cout << "4. Pretraga prema nazivu knjige: " << endl;
        cout << "5. Brisanje knjige: " << endl;
        cout << "6. Izmjena podataka knjige: " << endl;
        cout << "7. Izlaz iz programa: " << endl;
        cout << "Odaberite: ";
        cin >> izbor;
        if(izbor==1)
        {
            unsigned long long unos;
            while(1)
            {
                try
                {
                    cout << "Unesite barkod: ";
                    cin >> unos;
                    if(unos<100000 || unos>999999)
                        throw "Barkod mora imati 6 znamenki.";
                    break;
                }
                catch (const char* msg)
                {
                    cout << msg << endl;
                }
            }
            barkod[brKnjige]=unos;
            cout << "Unesite naziv knjige: " << endl;
            cin.ignore();
            getline(cin, naziv[brKnjige]);
            cout << "Unesite cijenu knjige: " << endl;
            cin >> cijena[brKnjige];
            brKnjige++;
        }
    }
    return 0;
}
