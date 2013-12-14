void EnQueueQ(tpacijenti x,red *jedan){
     
    red *novi=new red;
    novi->polje=x;
    novi->slijedeci=NULL;
    jedan->zadnji->slijedeci=novi;
    jedan->zadnji=novi;
     
     }
     

void DeQueueQ(red *jedan){

red *brisani=new red;
  if(jedan->zadnji!=jedan->prvi){
  brisani=jedan->prvi;
  jedan->prvi=brisani->slijedeci;
  delete brisani;
 
  }else{
        cout<<"Red je prazan!";
        exit(0);
        }
     
     }
     
     
void InitQ(red *jedan){
     
     red*novi=new red;
     jedan->zadnji=novi;
     jedan->prvi=novi;
     novi->slijedeci=NULL;
     
     }
     
bool IsEmptyQ(red *jedan) {
    return (jedan->prvi == jedan->zadnji);
}
     
