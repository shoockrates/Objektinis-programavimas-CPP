#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Banko_saskaita
{
    string savininko_vardas;
    string numeris;
    long long balansas;

public:
    Banko_saskaita()
    {
        savininko_vardas = "Petras";
        numeris = "123456789101112131";
        balansas = 123;
        cout<<"Saskaita sukurta."<<endl;
    }

    ~Banko_saskaita()
    {
        cout<<"Saskaita sunaikinta."<<endl;
    }

    void set_savininko_vardas(string vardas)
    {
        if((vardas.length() != 0) && (vardas != ""))
        {
            savininko_vardas = vardas;
        }
    }

    void set_numeris(string num)
    {
        if((num.length() == 18) && (num != ""))
        {
            numeris = num;
        }
    }

    void set_balansas(long long l)
    {
            balansas = l;
    }

    string get_savininko_vardas()
    {
        return savininko_vardas;
    }

    string get_numeris()
    {
        return numeris;
    }

    long long get_balansas()
    {
        return balansas;
    }

    string to_string()
    {
        stringstream ss;

        ss<<savininko_vardas<<" LT"<<numeris<<", "<<balansas<<" eur." ;

        return ss.str();
    }
};

int main()
{
    Banko_saskaita banko_saskaita_1;

    cout<<banko_saskaita_1.to_string()<<endl;


    banko_saskaita_1.set_savininko_vardas("TEST TEST");

    banko_saskaita_1.set_numeris("101010101010101010");

    banko_saskaita_1.set_balansas(2022);

    cout<<banko_saskaita_1.to_string()<<endl;


    banko_saskaita_1.set_savininko_vardas("Kestutis");

    banko_saskaita_1.set_balansas(-2020);

    cout<<banko_saskaita_1.to_string()<<endl;

    return 0;
}
