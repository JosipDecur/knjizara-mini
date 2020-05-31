#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>

using namespace std;

bool manjiod(double cijena)
{
    if(cijena<500)
        return true;
    else
        return false;
}

int main()
{
    int izbor, brojac=0;
    int brKnjige=0;
    unsigned long long int *barkod = new unsigned long long int[2000];
    string *naziv = new string[2000];
    double *cijena = new double[2000];
    while(1)
    {
        cout << "1. Unos nove knjige: " << endl;
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
        else if(izbor==2)
        {
            for(int i=0; i<brKnjige; i++)
                 cout<<barkod[i]<<", "<<naziv[i]<<", "<<cijena[i]<<endl;
        }
        else if(izbor==3)
        {
             cout<<"Podatci za inventuru: "<<endl;
             cout<<"Suma svih cijena knjiga: "<< accumulate(cijena, cijena+brKnjige, 0.0) <<endl;
             int min_index=min_element(cijena,cijena+brKnjige)-cijena;
             double mincij=cijena[min_index];
             cout<<"Knjiga s najmanjom cijenom: "<< naziv[min_index] <<endl;
             for(int i=0; i<brKnjige; i++)
             {
                  if(cijena[i]==mincij)
                      brojac++;
             }
             cout<<"Broj knjige s najmanjom cijenom: "<<brojac<<endl;
             cout<<"Broj knjige s cijenom manjom od 500 kn: "<<count_if(cijena, cijena+brKnjige, manjiod)<<endl;
         }
        else if(izbor==4)
                {
                    string pretraga;
                    cout<<"Unesite naziv knjige koji pretrazujete."<<endl;
                    cin.ignore();
                    getline(cin, pretraga);
                    for(int i=0; i<brojac; i++)
                    {
                        if(naziv[i]==pretraga)
                        {
                            cout<<"Knjiga koju trazite ima barkod."<<barkod[i]<<" i cijenu "<<cijena[i]<<endl;
                            brojac++;
                        }
                    }
                    if(brojac==0)
                    {
                        cout<<"Takva knjiga ne postoji."<<endl;
                    }
                }
        else if(izbor==7)
        {
            cout<<"Izlaz iz programa."<<endl;
            break;
        }
        else
        {
            cout<<"Krivi unos."<<endl;
        }
        cout<<endl;
        system("pause");
    }
    return 0;
}
