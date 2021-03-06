#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <string>
#include <utility>
#include <fstream>
using namespace std;

bool manjiod(double cijena)
{
    if(cijena<500)
        return true;
    else
        return false;
}
bool pretrazivanje(string naziv[],unsigned long long int barkod[], double cijena[], string potraga,int brBarkodova)
{

    int br=0;
    for(int i=0;i<brBarkodova;i++)
    {
        if(naziv[i]==potraga)
        {
            br++;
            cout<<"Naziv knjige je: "<<naziv[i]<<", barkod knjige je: "<<barkod[i]<<", cijena knjige je: "<<cijena[i]<<endl;
        }
        if(br==0)
            return false;
        else
            return true;
    }
}


int main()
{
    int izbor;
    int brKnjige=0;
    unsigned long long int br;
    unsigned long long int *barkod = new unsigned long long int[2000];
    string *naziv = new string[2000];
    double *cijena = new double[2000];
    ofstream datoteka;
    datoteka.open("pravila.txt");
    datoteka << "Dobrodosli u model knjizare! Pravila koristenja ove knjizare su sljedeca: 1. Zabranjeni su neprimjereni nazivi knjiga. 2. Brisanje knjiga je funkcija implementirana samo za situacije u kojima se dogodi pogreska i ne smije ju se iskoristavati! 3. Kako bi uspjesno pretrazivali knjige morate dobro znati njihova imena, jer inace funkcija nece raditi! Hvala sto koristite nasu knjizaru!" << endl;
    datoteka.close();

    while(1)
    {
        cout << "1. Unos nove knjige: " << endl;
        cout << "2. Ispis svih podataka: " << endl;
        cout << "3. Inventura: " << endl;
        cout << "4. Pretraga prema nazivu knjige: " << endl;
        cout << "5. Brisanje knjige: " << endl;
        cout << "6. Pravila knjizare: " << endl;
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
                cout<<"Barkod knjige je: "<<barkod[i]<<", naziv knjige je: "<<naziv[i]<<", cijena knjige je: "<<cijena[i]<<endl;
        }
        else if(izbor==3)
        {
            cout<<"Zbroj svih cijena knjiga: "<<accumulate(cijena,cijena+brKnjige,0.0)<<endl;
            int min_index=min_element(cijena,cijena+brKnjige)-cijena;
            double najmanji=cijena[min_index];
            cout<<"Naziv knjige koja ima najmanju cijenu: "<<naziv[min_index]<<endl;
            cout<<"broj knjiga koje imaju cijenu manju od 500 kn: "<<count_if(cijena,cijena+brKnjige, manjiod)<<endl;
        }
        else if(izbor==4)
        {
            string pretraga;
            cout<<"Unesite naziv knjige koji pretrazujete:"<<endl;
            cin.ignore();
            getline(cin, pretraga);
            if(pretrazivanje(naziv,barkod,cijena,pretraga,brKnjige)==false)
            {
                cout<<"Knjige nema";
            }
        }
        else if (izbor==5)
        {

            cout<<"Unesite barkod knjige koji želite izbrisati: ";
            cin>>br;
            int h=0;
            for(int i=0;i<brKnjige;i++)
            {
                if(br==barkod[i])
                {
                    h++;
                    for(int j=i+1;j<brKnjige;j++)
                    {
                        barkod[j-1]=barkod[j];
                        naziv[j-1]=naziv[j];
                        cijena[j-1]=cijena[j];
                    }
                    brKnjige--;
                    break;
                }
            }
            if(h==0)
            {
                cout<<"Ta knjiga ne postoji!"<<endl;
            }
        }
        else if(izbor==6)
        {
            ifstream datoteka;
            string redak;
            datoteka.open("pravila.txt");
            getline(datoteka,redak);
            cout << redak << endl;
            datoteka.close();
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
