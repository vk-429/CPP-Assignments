#include<iostream>
using namespace std;
class dollar;
class Rupee
{
    private:
        float x;
    public:
        Rupee()
        {
            cout<<"DC Called for Rupee\n";
        }
        /*Rupee(dollar D)
        {
            cout<<"Rupee(Dollar) Called"<<endl;
            x=D.getD()*100;
        }*/
        Rupee(const Rupee &R)
        {
            cout<<"Copy Costructor(Rupee) Called\n";
            x=R.x;
        }
        Rupee(float n)
        {
            cout<<"PC Called for Rupee\n";
            x=n;
        }
        float getX()
        {
            return x;
        }
        void operator=(Rupee R)
        {
            cout<<"Operator = called for rupee\n";
            x=R.x;
        }
        
        void display()
        {
            cout<<"Display of Rupee\n";
            cout<<"Rupee is "<<x<<endl;
        }
        operator float()
        {
            cout<<"TC float() Called for Rupee\n";
            return x;
        }
        /*operator dollar() // Can't define it here, should be defined below the dollar class to access the dollar object
        {
            cout<<"Dollar() called for Rupee\n";
            return x/100.0;
        }*/
        //operator dollar();
        //Rupee(dollar&);
        void operator=(dollar d);
};
class dollar
{
    private:
        float d;
    public:
        dollar()
        {
            cout<<"DC Called for Dollar"<<endl;
        }
        dollar(float n)
        {
            cout<<"PC called for Dallor"<<endl;
            d=n;
        }
        dollar(const dollar &D)
        {
            cout<<"Copy Costructor(Dollar) Called\n";
            d=D.d;
        }
        // dollar(Rupee R)
        // {
        //     cout<<"PC Dollar(Rupee)(user defined to user defined) Called"<<endl;
        //     d=R.getX()/100;
        // }
        void operator=(Rupee R)
        {
            cout<<"AO D1=R1 Called\n";
            d=R.getX()/100.0;
        }
        void operator=(dollar D)
        {
            cout<<"Operator = called for dollar\n";
            d=D.d;
        }
        
        float getD()
        {
            return d;
        }
        void display()
        {
            cout<<"Display of dollar\n";
            cout<<"Dollar is "<<d<<endl;
        }
        operator float()
        {
            cout<<"TC float() Called for Dollar\n";
            return d;
        }
        // operator Rupee()//Doller to Rupee
        // {
        //     cout<<"TC Rupee() called for daller\nRupee is above Doller\nWe can do it\n";
        //     return d*100;
        // }
};
// Rupee::operator dollar()
// {
//     cout<<"Dollar() called for Rupee\n";
//     return x/100.0;
// }

// Rupee::Rupee(dollar &D)
// {
//     cout<<"PC Rupee(dallar)(user defined to user defined) Called"<<endl;
//     x=D.getD()*100;
// }

void Rupee::operator=(dollar d)
{
    cout<<"AO for R1=D1 Called\n";
    x=d.getD()*100;
}
int main()
{
    float x=10;
    float y=20;
    Rupee R1=(Rupee)x;//PM for Rupee Called
    R1.display();//Display for Rupee
    //x=(float)R1;//typecast float() for Rupee
    cout<<x<<"\n";

    dollar D1=(dollar)y;//PM for Dollar
    D1.display();//Display for Dollar
    x=(float)D1;//typecast float() for Dollar
    cout<<x<<"\n";

    R1=D1;
    
    // Case 1. When we 
    // Case 2. When we want to convert with the help of PC this happens
    //yha pe rupee ka ak reference bna hai jisne rupee ke
    //PC ko call kiya hai, uske bad dollar ke PC ke argument me D=D1 ke liye dollar ka CC chla
    // agr hm PC ke argument me dollar ka reference recieve kre to fir D=D1 nhi hoga or CC call nhi hoga
    //uske bad PC called line chle OR iss reference object ke x me d*100 assign ho gya
    //uske bad AO of rupee chla jisme ye reference object pass hua isliye yha pe CC nhi chla
    //or AO ne R1 ke x me reference wale x ko assign krdiya and work finished

    // Case 3. With the help of typecast operator
    // Similar as case 2 except in statrting it will call TCO
    R1.display();

    D1=R1;//D1=(dollar)R1;
    D1.display();
    return 0;
}