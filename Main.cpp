//// STRUKTURE ATP RED 
/// n petorki ( ai,bi,ci,di,ei ) 
/// ai je vrijeme nakon prethodnog pacijenta 50 - 300 cega nemam pojma ,varijabla a je rand vrijeme
/// bi je vrijeme u ordinaciji  50 - 300 cega ??  varijabla b isto rand         
/// ci je prioritet pacijenta ( 1 hitni, 2 invalidi, 3 trudnice, 4 djeca mlada od 6 god, 5 ostali ) 1- 5 su prioriteti takoder  varijabla c
/// di je vrsta usluge ( 1 pregled, 2 previjanje , 3 recepti, 4 uputnice ) varijabla d 
/// ei je ordinacija poliklinike ( 1 obiteljska medicina , 2 oftalmologija , 3 dermatovenerelogija, 4 ginekologija , 5 urologija ) varijabla e


#include<iostream>
#include<ctime>
#include "polje.h"
//#include "pokazivaci.h"

using namespace std;
struct generiranje{
       int a,b,c,d,e;
       }petorka[1000];

int ehitni,etrudnice;
int n;
int br=0;
void jedan(int n){    
     cout<<endl<<endl;
 for(int i=0; i<n; i++){
     cout<<"------------------ Ispis za pacijenta [ "<<i+1<<" ]--------------"<<endl<<endl;       
     cout<<" Vrijeme nakon prethodnog pacijenta u sec  ";
     petorka[i].a=(rand() %(300-50)) +50; cout<<petorka[i].a<<endl;
     cout<<" Vrijeme  pacijenta u ordinaciji u minutama  ";
     petorka[i].b=(rand() %(300-50)) +50;
     cout<<petorka[i].b<<endl;
     cout<<" Prioritet pacijenta "; 
            petorka[i].c=(rand () %5 );//za prioritet
            switch (petorka[i].c){
                   case 0: cout<<" HITNI "<<endl;br++; break;
                   case 1: cout<<" INVALIDI "<<endl; break;
                   case 2: cout<<" TRUDNICE "<<endl; break;
                   case 3: cout<<" DJECA "<<endl;break;
                   case 4: cout<<" OSTALI "<<endl; break;
                        }
     cout<<" Vrsta usluge za pacijenta ";
      petorka[i].d=(rand () %4 );
      if(petorka[i].c==0) {
               cout<<endl<<" Ako je pacijent HITNI , " ;
               goto lb;
               }
      switch (petorka[i].d){
      lb:    case 0: cout<<" Pregled "; break;
             case 1: cout<<" Previjanje "; break;
             case 2: cout<<" Recepti "; break;
             case 3: cout<<" Uputnice "; break;
             }        
     if(petorka[i].c==0){//hitni
                       petorka[i].e=(rand () %4);  
                       switch(petorka[i].e){
                        case 0: cout<<endl<<" Status HITNO poslati u ordinaciju dermatovenorologije"; break;
                        case 1: cout<<endl<<" Status HITNO poslati u ordinaciju oftamologije "; break;//stavil na 1 prvo mjesto radi ispisa za 25 god
                        case 2: cout<<endl<<" Status HITNO poslati u ordinaciju ginekologije "; break;
                        case 3: cout<<endl<<" Status HITNO poslati u ordinaciju urologije "; break;  
                        }
                        }                         
     if(petorka[i].c==2 ){//trudnice
     petorka[i].e = (rand () %4);
              switch(petorka[i].e){
                        case 0: cout<<endl<<" Status TRUDNICE poslati u ordinaciju obiteljske medicine "; break;  
                        case 1: cout<<endl<<" Status TRUDNICE poslati u ordinaciju oftalmologije "; break;//stavil na 1 prvo mjesto radi ispisa za 25 god
                        case 2: cout<<endl<<" Status TRUDNICE poslati u ordinaciju dermatovenorologije "; break;
                        case 3: cout<<endl<<" Status TRUDNICE poslati u ordinaciju ginekologije "; break;
                        }
                        }                                                
      if((petorka[i].c== 1) || (petorka[i].c==3)||(petorka[i].c==4)){//djeca,invalidi,ostali
      petorka[i].e=(rand () %3);
      switch(petorka[i].e){
                        case 0: cout<<endl<<" Status poslati u ordinaciju obiteljske medicine "; break;  
                        case 1: cout<<endl<<" Status poslati u ordinaciju oftalmologije "; break;////stavil na 1 prvo mjesto radi ispisa za 25 god
                        case 2: cout<<endl<<" Status poslati u ordinaciju dermatovenorologije "; break;
                           }              
                           }  
                            cout<<endl<<endl;  
                            }
                              
}
void dva(red *novi){
     tpacijenti podaci;
     for(int i=0; i<n; i++){
     cout<<" Upis opcih podataka za pacijenta  ["<<i+1 <<"] "<<endl;   
     cout<<" Prioritet pacijenta = ";
     switch(petorka[i].c){
                   case 0: cout<<" HITNI "<<endl;br++; break;
                   case 1: cout<<" INVALIDI "<<endl; break;
                   case 2: cout<<" TRUDNICE "<<endl; break;
                   case 3: cout<<" DJECA "<<endl;break;
                   case 4: cout<<" OSTALI "<<endl; break;
                        }     
     cout<<" Ime pacijenta = ";
     cin.ignore();
     cin.getline(podaci.ime,20);
     cout<< " Prezime pacijenta = ";
     cin.getline(podaci.prezime,20);
     cout<<" Spol pacijenta 0 = zenski , 1 = muski ";
     cin>>podaci.spol;
unos: cout<<" Datum rodenja pacijenta \n Dan = ";
     cin>>podaci.d_rodenja[0];//dan
     if(podaci.d_rodenja[0] >32  || 0.5>podaci.d_rodenja[0])
     goto unos;
unos_1:cout<<" Mjesec = ";
     cin>>podaci.d_rodenja[1];
     if(podaci.d_rodenja[1] >=13  || 0.5>podaci.d_rodenja[1])
     goto unos_1;
unos_2:cout<<" Godina = ";cin>>podaci.d_rodenja[2]; 
     if(podaci.d_rodenja[2] >2014  || 1880>podaci.d_rodenja[2])
     goto unos_2;
     podaci.prioritet=petorka[i].c;
     podaci.vrsta_usluge=petorka[i].d;
     podaci.ordinacija=petorka[i].e;   
     cout<<endl;
     EnQueueQ(podaci, novi);
     }
     }    
          
 void tri( red *novi,red* pomocni){
      tpacijenti podaci;    
       while (!IsEmptyQ(novi)) {     
              podaci=FrontQ(novi);
              DeQueueQ(novi);
        if((podaci.ordinacija==1) && (podaci.d_rodenja[2]<1987) && (podaci.spol==0)){
        cout<<" \n Pacijentice STARIJE OD 25 GODINA, pregled kod oftalmologa"<<endl<<endl;
        cout << " Ime = " << podaci.ime << endl;
        cout << " Prezime = "<<podaci.prezime<<endl;
        cout << " Godina rodenja = " << podaci.d_rodenja[2] << endl;
        cout<<  " Vrsta usluge = ";
        switch(podaci.vrsta_usluge){
             case 0: cout<<" Pregled "; break;
             case 1: cout<<" Previjanje "; break;
             case 2: cout<<" Recepti "; break;
             case 3: cout<<" Uputnice "; break;
                     }       
                     cout<<endl<<endl;     
        }else  EnQueueQ (podaci, pomocni);
                   }
        cout<<" \n Stanje reda poslije ispisivanje pacijentica kod oftalmologa "<<endl<<endl;         
                   while (!IsEmptyQ(pomocni)) {
               podaci=FrontQ(pomocni);
               DeQueueQ(pomocni);
        cout << " Ime pacijenta = " << podaci.ime << endl;
        cout << " Prezime = " << podaci.prezime << endl;
        cout << " Godina rodenja pacijenta = " << podaci.d_rodenja[2] << endl<<endl;
                  EnQueueQ(podaci, novi);  
               }
                   }
 void cetiri (red *novi,red *pomocni ){                   
         tpacijenti podaci;   
   if (IsEmptyQ(novi)) {
      cout<<"Red je prazan.\n";
                       }
   else { 
        while (!IsEmptyQ(novi)) {
              podaci=FrontQ(novi);
              DeQueueQ(novi);     
        if((podaci.prioritet==1) && (podaci.vrsta_usluge==1)&&(podaci.d_rodenja[2]<1963)) {
        cout<<"\n Pacijent (INVALID) izbačen, usluga previjanje "<<endl;
        cout << " Ime   =  " << podaci.ime << endl;
        cout << " Prezime = " << podaci.prezime << endl;
        cout << "Godina rodenja = " << podaci.d_rodenja[2] << endl<<endl;   
                      }
        else  EnQueueQ (podaci, pomocni);
                      }
                      }
        cout<<"\n Stanje reda poslije izbacivanja INVALIDA IZ REDA "<<endl<<endl;
        while (!IsEmptyQ(pomocni)) {
               podaci=FrontQ(pomocni);
               DeQueueQ(pomocni);
        cout << " Ime  =  " << podaci.ime << endl;
        cout << " Prezime  = " << podaci.prezime << endl;
        cout << " Godina rodenja  = " << podaci.d_rodenja[2] << endl<<endl;
                  EnQueueQ(podaci, novi);  
               }
                      }
red *brzi;  
//int brojac++;
void pet( red *novi) {
tpacijenti podaci;   
while (!IsEmptyQ(novi)) {
              int i=0;         
              podaci=FrontQ(novi);      
              bool kraj_reda;
if(!kraj_reda == 0){
              if(petorka[i].d==2 || petorka[i].d==3){
               InitQ(brzi);
               EnQueueQ(podaci,brzi); 
               cout<<" Brzi red "<<endl;
               cout<<podaci.prezime<< " , "<<podaci.ime<<endl;             
                }else 
               return EnQueueQ(podaci,novi);
               i++;
               }         
} 
}                        
int main(){
    cout<<"Unesite N ";
    cin>>n;
    srand(time(NULL));
       rand();
    red *novi_red=new red, *pomocni_red=new red;
   InitQ (novi_red);
   InitQ (pomocni_red);
    int odabir;
    cout<<endl;
    do{
    cout<<"  1  ==  Ispis o pacijentima, bez opcih podataka , imena, prezimena itd. "<<endl<<endl;
    cout<<"  2  ==  Dodavanje zapisa o pacijentima poliklinike"<<endl<<endl;
    cout<<"  3 ==   Ispis  pacijentica starijih od 25 godina, pregled kod oftalmologa"<<endl<<endl;
    cout<<"  4  ==  Brisanje iz glavnoga reda invalide starije od 50 godina koji idu na previjanje i prikaz reda poslije brisanja"<<endl<<endl;
    cout<<"  5  ==  Stvaranje brzoga reda , 30%"<<endl<<endl;
    cout<<"  7  ==  Izlaz iz programa"<<endl<<endl;       
        cout<<endl;       
        cout<<"Unesite svoj odabir = ";
        cin>>odabir;
        switch(odabir){
                       case 1: jedan(n); cout<<endl<< " Hitnih pacijenata = "<<br<<endl<<endl;  break;
                       case 2: dva(novi_red);   break;
                       case 3: tri(novi_red,pomocni_red);  break;
                       case 4: cetiri(novi_red,pomocni_red);   break;
                       case 5:  pet(novi_red); break;
                       default: cout<<" Izabrali ste izlazak iz programa "<<endl;  
                                }
    }while(odabir<7);
    
    
                                
    system("pause");
    return 0;
    
}
