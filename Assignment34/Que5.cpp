#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main()
{
    ifstream fin;
    fin.open("c:/File/new.txt",ios::in);
    ofstream fout;
    fout.open("c:/File/a.txt",ios::app);
    string line;
    if(fout&&fin)
    {
        while(getline(fin,line))
            fout<<line<<"\n";
    }
    else
        cout<<"Error opening the file\n";
    fin.close();
    fout.close();
    return 0;
}