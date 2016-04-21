// Kodu nawaliłem to na komentarzach oszczedze...
#include <iostream>
#include <cstdlib>
using namespace std;

int position(int &n);
void showNumerals(int &n);

int main(int argc, char const *argv[]) {

    int n = atoi(argv[1]);
    int k=0, temp, nk;
    bool found=false;
    do
    {
        ++k;
        nk=n*k;



        if (nk>=1000000) {
            cout<<"zbyt wielka liczba";
            break;}
        found=true;
        temp=nk;
        while (temp>1)
        {
            if ((temp % 10) == 0) temp=temp/10;
            else{
                 found=false;
                 break;}
        }
    }while (found==false);
    if (found) showNumerals(k); else "Nie znaleziono ";
}

int position(int &n)
{

    int x=0, tem=n;
      do{
        tem=tem/10;
        ++x;
      }while (tem!=0);
      return x;
}

void showNumerals(int &n)
{
 string numerals[4][10]=
    {{"jeden ", "dwa ", "trzy ", "cztery ", "piec ", "szesc ", "siedem ", "osiem ", "dziewiec "},

    {"dziesiec ","jedenascie ", "dwanascie ", "trzynascie ", "czternascie ", "pietnascie ", "szesnascie ", "siedemnascie ",
        "osiemnascie ", "dziewietnascie "},

    {"dwadziescia ", "trzydziesci ", "czterdziesci ", "piecdziesiat ", "szescdziesiat ", "siedemdziesiat ",
        "osiemdziesiat ", "dziewiecdziesiat "},

    {"sto ", "dwiescie ", "trzysta ", "czterysta ", "piecset ", "szescset ", "siedemset ",
        "osiemset ", "dziewiecset " }};

    int y=n;
    int size=position(n);
    int *number = new int[size];

    for (int i = (size-1); i>(-1); --i){

        number[i]=(y%10);
        y=y/10;}

    int pos=0;
    int temp=size;
    if (n==0) cout<<"zero"<<endl;
        else
    while(pos!=size)
    {
        if (n==0) break;
        if (number[pos]==0) pos++;

        switch(temp){

            case 1:
                    cout<<numerals[0][(number[pos])-1];
                    break;
            case 2:
                   if (n<20){
                      cout<<numerals[1][(number[pos+1])];
                      ++pos;}
                   else if (n<100){
                           cout<<numerals[2][number[pos]-2];
                           n=n-(number[pos]*10);
                           --temp;}
                    break;
            case 3:
                    cout<<numerals[3][number[pos]-1];
                    n=n-(number[pos]*100);
                    --temp;
                    if (n<10){
                    ++pos;
                    --temp;}
                    break;
            case 4:
                    if (n==1000){
                       if ((number[pos-1]>0)&&(number[pos-1]<9)&&(number[pos]==1))
                           cout<<numerals[0][(number[pos])-1]<<"tysiecy ";
                       else
                       cout<<"tysiac ";

                       pos+=3;}
                    else if (n<10000){
                            if ((number[pos-1]>0)&&(number[pos-1]<9)&&(number[pos]==1))
                                cout<<numerals[0][(number[pos])-1]<<"tysiecy ";


                             else if ((number[pos]>1)&&(number[pos]<5))
                                     cout<<numerals[0][(number[pos])-1]<<"tysiace ";
                             else  cout<<numerals[0][(number[pos])-1]<<"tysiecy ";
                    --temp;
                    n=n-(number[pos]*1000);
                    if (n<10){
                        ++pos;
                        temp-=2;}
                    else if (n<100) --temp;}
                    break;
            case 5:
                    if(n<20000) {
                        cout<<numerals[1][(number[pos+1])]<<"tysiecy ";
                        ++pos;
                        n=n-((number[pos]+10)*1000);
                        if (n<10) {
                            temp-=4;
                            pos+=2;}
                        else if (n<100) temp-=3;
                        else if (n<1000) temp-=2;}
                    else if(n<100000){
                        cout<<numerals[2][number[pos]-2];
                        if (number[pos+1]==0)  cout<<"tysiecy ";

                        n=n-(number[pos]*10000);
                        if (n<10) {
                            temp-=4;
                            pos+=2;}
                        else if (n<100){
                            temp-=3;
                            pos+=2;}
                        else if (n<1000) temp-=2;
                        else if (n<10000) temp--; }

                    break;
            case 6:
                    cout<<numerals[3][number[pos]-1];
                    if ((number[pos+1]==0)&&(number[pos+2]>0))
                        cout<<"";
                    else if (number[pos+1]==0)
                        cout<<"tysiecy ";
                    n=n-(number[pos]*100000);
                    --temp;
                   if (n<10) {
                            temp-=4;
                            pos+=3;}
                        else if (n<100){
                            temp-=2;}
                        else if (n<1000){
                            temp-=2;
                            pos+=2;}
                        else if (n<10000) temp--;

                    break;}
        ++ pos;
       }

    delete [] number;
}
