#include <iostream>
#include <cstdlib>
using namespace std;

void showNumerals(int &n);

int main(int argc, char const *argv[]) {

    int n = atoi(argv[1]);
    int k=0, temp, nk;
    bool found=false;
    do
    {
        found=true;
        ++k;
        nk=n*k;
        temp=nk;
        while (temp>1)
        {
            if ((temp % 10) == 0) temp=temp/10;
            else{
                 found=false;
                 break;}
        }
    }while (found==false);
    cout<<k;
}
