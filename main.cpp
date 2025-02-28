#include <stdexcept>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cassert>
#include <string>
#include <vector>
#include <memory>

// Kipras Vytautas Spirgys
// snake_case, klases pavadinimai is didziosios raides, o kintamuju ir funkciju is mazosios

using namespace std;

static int object_id = 0;
static int object_count = 0;

class Banko_saskaita{
private:
    string owner_name;
    string number;
    long long balance;
    int id;

    void set_owner_name(string owner_name){
        if((owner_name.length() != 0)){
            this->owner_name = owner_name;}
        }
    void ModifyCount(bool inc){
        if (inc){
            ++object_id;
            ++object_count;
        }
        else{
            --object_count;}
        }

public:
    Banko_saskaita(string owner_name, string number,long long balance){
        set_owner_name(owner_name);
        Set_Number(number);
        set_balance(balance);
        id = object_id;
        ModifyCount(true);
    }

    Banko_saskaita(string owner_name, string number){
        set_owner_name(owner_name);
        Set_Number(number);
        set_balance(0);
        id = object_id;
        ModifyCount(true);
    }

    ~Banko_saskaita(){
        ModifyCount(false);
    };


    void Set_Number(string number){

        if((number.length() == 18)){
            this->number = number;
        }
    }

    void set_balance(long long balance){

        if (balance < 0){
            throw invalid_argument("Balance can not be negative\n");
        }

        this->balance = balance;
    }

    string get_owner_name(){
        return owner_name;
    }

    string get_number(){
        return number;
    }

    int get_id(){return id;}

    long long get_balance(){
        return balance;
    }

    string my_to_string(){
        return to_string(get_id()) + " " + get_owner_name() + " " + "LT" + get_number() + " " + to_string(get_balance());
    }
};

int main(){
    {
        vector<unique_ptr<Banko_saskaita>> banko_saskaitos;
        banko_saskaitos.push_back(make_unique<Banko_saskaita>("Petras", "010120200120312030", 123));
        banko_saskaitos.push_back(make_unique<Banko_saskaita>("Tomas", "482736159048273916", 15));
        banko_saskaitos.push_back(make_unique<Banko_saskaita>("Domas", "759384216507839124"));

        assert(object_count == 3);
        assert(banko_saskaitos[0]->get_owner_name() == "Petras");
        assert(banko_saskaitos[0]->get_number() == "010120200120312030");
        assert(banko_saskaitos[0]->get_balance() == 123);
        assert(banko_saskaitos[0]->get_id() == 0);
        cout << banko_saskaitos[0]->my_to_string() << endl;

        banko_saskaitos[1]->Set_Number("258384636507839124");
        banko_saskaitos[1]->set_balance(13);
        assert(banko_saskaitos[1]->get_number() == "258384636507839124");
        assert(banko_saskaitos[1]->get_owner_name() == "Tomas");
        assert(banko_saskaitos[1]->get_balance() == 13);
        assert(banko_saskaitos[1]->get_id() == 1);
        cout << banko_saskaitos[1]->my_to_string() << endl;

        assert(banko_saskaitos[2]->get_balance() == 0);
        banko_saskaitos[2]->set_balance(66);
        assert(banko_saskaitos[2]->get_owner_name() == "Domas");
        assert(banko_saskaitos[2]->get_number() == "759384216507839124");
        assert(banko_saskaitos[2]->get_balance() == 66);
        cout << banko_saskaitos[2]->my_to_string() << endl;
    }
    assert(object_count == 0);

    return 0;
}
