#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Car{
protected:
    int power;
    int capacity;
    string name;
public:
    Car(int power=0, int capacity=0, string name=""):power(power),capacity(capacity),name(name){}
    Car(const Car &other):power(other.power),capacity(other.capacity),name(other.name){}
    ~Car()=default;
    virtual void print(){
    cout<<"Puterea masinii este de : "<<this->power<<" cai putere , "<<"Capacitatea rezervorului este : "<<this->capacity<<" , "<<"Marca : "<<this->name<<'\n';
    }
    friend istream& operator>> (istream&, Car&);
    friend ostream& operator<< (ostream&, Car&);
};

istream& operator>>(istream &in, Car &car){
    cout<<"Introduceti puterea , capacitatea rezervorului si marca masinii"<<'\n';
    in>>car.power;
    in>>car.capacity;
    in>>car.name;
    return in;
}

ostream& operator<<(ostream &cout, Car &car)
{
    car.print();
    return cout;
}

class Coupe : public Car{
public:
    Coupe(int power=0,int capacity=0,string name=""):Car(power,capacity,name){}
    Coupe(const Coupe &other):Car(other){}
    ~Coupe()=default;
    void print(){
        cout<<"Masina este Coupe, ";
        cout<<"Puterea masinii este de : "<<this->power<<" cai putere , "<<"Capacitatea rezervorului este : "<<this->capacity<<" , "<<"Marca : "<<this->name<<'\n';
    }
    friend istream& operator>> (istream&, Coupe&);
    friend ostream& operator<< (ostream&, Coupe&);
};

istream& operator>>(istream &in,Coupe &car){
    in>>dynamic_cast<Car&>(car);
    return in;
}

ostream& operator<<(ostream &cout,Coupe &car)
{
    car.print();
    return cout;
}
///

class HotHatch : public Car{
    int engine;
public:
    HotHatch(int power=0,int capacity=0,string name="",int engine=-1):Car(power,capacity,name),engine(engine){}
    HotHatch(const HotHatch &other):Car(other),engine(other.engine){}
    ~HotHatch()=default;
    void print(){
        cout<<"Masina este Coupe , ";
        cout<<"Puterea masinii este de : "<<this->power<<" cai putere , "<<"Capacitatea rezervorului : "<<this->capacity<<" , "<<"Marca : "<<this->name<<" , "<<"Motoeul este : ";
        if (this->engine==0)
            cout<<"Benzina"<<'\n';
        else
            cout<<"Diesel"<<'\n';
    }
    friend istream& operator>> (istream&, HotHatch&);
    friend ostream& operator<< (ostream&, HotHatch&);
};

istream& operator>>(istream &in,HotHatch &car){
    in>>dynamic_cast<Car&>(car);
    cout<<"Adaugati tipul morotului , 0 reprezentand motorul pe benzina iar motorul diesel"<<'\n';
    in>>car.engine;
    return in;
}

ostream& operator<<(ostream &cout,HotHatch &car)
{
    car.print();
    return cout;
}


///
class Cabrio : public Car{
    int rooftype;
public:
    Cabrio(int power=0,int capacity=0,string name="",int rooftype=-1):Car(power,capacity,name),rooftype(rooftype){}
    Cabrio(const Cabrio &other):Car(other),rooftype(rooftype){}
    ~Cabrio()=default;
    void print(){
        cout<<"Masina este Cabrio, ";
        cout<<"Puterea masinii este de : "<<this->power<<" cai putere , "<<"Capacitatea rezervorului : "<<this->capacity<<" , "<<"Marca : "<<this->name<<" , "<<"Plafonul este : ";
        if(this->rooftype==0)
            cout<<"Textil"<<'\n';
        else
            cout<<"Metalic"<<'\n';
    }
    friend istream& operator>> (istream&, Cabrio&);
    friend ostream& operator<< (ostream&, Cabrio&);
};

istream& operator>>(istream &in,Cabrio &car){
    in>>dynamic_cast<Car&>(car);
    cout<<"Adaugati tipul plafonului, 0 reprezentand plafonul textil, iar 1 plafonul metalic"<<'\n';
    in>>car.rooftype;
    return in;
}

ostream& operator<<(ostream &cout,Cabrio &car)
{
    car.print();
    return cout;
}




class SuperSport : public Car{
    int price;
    static int nrSS;
public:
    SuperSport(int power=0,int capacity=0,string name="",int price=-1):Car(power,capacity,name),price(price){nrSS++;}
    SuperSport(const SuperSport &other):Car(other),price(price){nrSS++;}
    ~SuperSport(){nrSS--;}
    void set_price(int price){
        this->price=price;
    }
    void print(){
        cout<<"Masina este SuperSport , ";
        cout<<"Puterea masinii este de : "<<this->power<<" cai putere , "<<"Capacitate rezervor : "<<this->capacity<<" , "<<"Marca : "<<this->name<<" , "<<"Pret : "<<this->price<<'\n';
    }
    friend istream& operator>> (istream&, SuperSport&);
    friend ostream& operator<< (ostream&, SuperSport&);
    static void get_nrSS(){
        cout<<nrSS;
    }
};
int SuperSport::nrSS=0;

istream& operator>>(istream &in,SuperSport &car){
    in>>dynamic_cast<Car&>(car);
    cout<<"Adaugati pretul masinii"<<'\n';
    in>>car.price;
    return in;
}

ostream& operator<<(ostream &cout,SuperSport &car)
{
    car.print();
    return cout;
}

class ShowRoom{
    static int nr_exp_cars;
    vector<Car*> exp_cars;
    vector<SuperSport*> SS_exp;
    vector<SuperSport*> SS_sold;
public:
    ShowRoom(){}
    ~ShowRoom(){
        for(int i=0;i<exp_cars.size();i++)
            delete exp_cars[i];
    }
    void set_cars(int opt1){
        if(opt1==1){
                Coupe* m1=new Coupe;
                cin>>*m1;
                exp_cars.push_back(m1);
                nr_exp_cars++;
            }
            if(opt1==2){
                HotHatch* m2=new HotHatch;
                cin>>*m2;
                exp_cars.push_back(m2);
                nr_exp_cars++;
            }
            if(opt1==3){
                Cabrio* m3=new Cabrio;
                cin>>*m3;
                exp_cars.push_back(m3);
                nr_exp_cars++;
            }
            if(opt1==4){
                SuperSport* m4=new SuperSport;
                cin>>*m4;
                exp_cars.push_back(m4);
                SS_exp.push_back(m4);
                nr_exp_cars++;
            }
    }
    void get_cars(){
        for(int i=0;i<exp_cars.size();i++)
            (*exp_cars[i]).print();
    }
    void get_nr_exp(){
        cout<<nr_exp_cars<<" ";
    }
    void get_SS_exp(){
        for(int i=0;i<SS_exp.size();i++)
            (*SS_exp[i]).print();
    }
};
int ShowRoom::nr_exp_cars=0;
void MENU(){
    cout<<"MENIU"<<'\n';
    cout<<"1. Introduceti o noua masina in ShowRoom !"<<'\n';
    cout<<"2. Afisati numarul mesinilor existente in ShowRoom !"<<'\n';
    cout<<"3. Afisati masinile existente in ShowRoom!"<<'\n';
    cout<<"4. Afisati numarul de masini  SuperSport existente si care sunt acestea!"<<'\n';
    cout<<"5. Exit"<<'\n'<<'\n';
}

int opt,opt1;
int main()
{
    ShowRoom Show;
    do{
        MENU();
        cin>>opt;
        if(opt==1){
            cout<<"Ce tip de masina doriti sa introduceti?"<<'\n'<<'\n';
            cout<<"1.Coupe"<<endl;
            cout<<"2.HotHatch"<<endl;
            cout<<"3.Cabrio"<<endl;
            cout<<"4.Supersport"<<endl<<endl;
            cin>>opt1;
            Show.set_cars(opt1);
        }
        else if(opt==2){
            cout<<"In cadrul expozitiei sunt ";
            Show.get_nr_exp();
            cout<<"masini expuse."<<'\n';
        }
        else if(opt==3){
            Show.get_cars();
        }
        else if(opt==4){
            cout<<"Numarul de masini de tip SuperSport din cadrul expozitiei este de ";
            SuperSport::get_nrSS();
            cout<<" masini.\n";
            cout<<"Acestea sunt : "<<'\n';
            Show.get_SS_exp();
        }
        else if(opt==5)
            break;
        else
            cout<<"Introduceti o optiune valida!\n\n";
    }while(true);

    return 0;
}




