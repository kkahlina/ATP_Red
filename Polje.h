#include<iostream>
using namespace std;

struct tpacijenti{ 
       char ime[20],prezime[20];
       int d_rodenja[3];
       int spol;
       int prioritet,vrsta_usluge,ordinacija;
            };
struct red{
       tpacijenti polje[1000];
       int prvi,zadnji;
       };
       
int AddOne(int i){
    return ((i+1)%1000);
    }   
    
tpacijenti FrontQ (red *jedan){
           if(AddOne(jedan->zadnji)== (jedan->prvi))  {
                                      cout<<"Red je prazan"<<endl;
                                      exit(0); 
                                      }else {
                                            return jedan->polje[jedan->prvi];
                                            }
                                            }
void EnQueueQ(tpacijenti x  ,red *jedan){
      if(AddOne(AddOne(jedan->zadnji))==jedan->prvi){
     cout<<"Red je pun!";
     exit(0);
     }else{
           jedan->zadnji=AddOne(jedan->zadnji);
           jedan->polje[jedan->zadnji]=x;
                                         }
                                         }  
void DeQueueQ(red *jedan){
     
     if(AddOne(jedan->zadnji)==jedan->prvi){
     cout<<"Red je prazan!";
           exit(0);
     }
     
     else{
          jedan->prvi=AddOne(jedan->prvi); 
           
           }
}    
void InitQ(red *jedan){
     jedan->prvi=0;
     jedan->zadnji=999;
                        }

bool IsEmptyQ(red *jedan) {
    return jedan->prvi == AddOne(jedan->zadnji);
}

