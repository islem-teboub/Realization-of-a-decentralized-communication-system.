
#include <Noeud.h>
#include <string.h>
#include <omnetpp.h>
#include <Segment_m.h>



Define_Module(Noeud);


int horlogeG[100];//100= nbr max de noeuds
cQueue queue[100];//la mettre en global


void Noeud::initialize()

{

    int nbr_noeud = getParentModule() -> par("x");

    //initialisation horloge

    int nbr_msg = 3;
    for (int j = 0; j < nbr_noeud; j++){
    horlogeG[j]=0;
    }

    if (getIndex()==0){
         for (int j = 1; j <= nbr_msg; j++){
             horlogeG[getIndex()]++;
             Segment *msg = new Segment();
             msg->num_seq = j;
             msg->horloge=horlogeG[getIndex()];
         for (int i = 0; i < nbr_noeud; i++)
        {//diffusion à tout les noeud
             Segment *copy = msg->dup();
             send(copy, "outport", i);
         }


         }
}
}

void Noeud::handleMessage(cMessage *msg)
{
    Segment *m = check_and_cast<Segment *>(msg);
    if(m->horloge>horlogeG[getIndex()]){
        horlogeG[getIndex()] = m->horloge;
    }else {
        horlogeG[getIndex()]++;
    }
    queue[getIndex()].insert(m);

}

void Noeud::finish()
{
   int nbr_noeud = getParentModule() -> par("x");
   Segment vect[50][50];
for(int affiche=1;affiche<nbr_noeud;affiche++){
if(getIndex()==affiche){
////////////////////////////////////
    EV <<" Noeud " <<  getIndex() << "> Mon horloge locale est = " <<  horlogeG[getIndex()] <<"\n";
   // queue[getIndex()].length()
  int i=0;
  while(!queue[getIndex()].isEmpty()){
      Segment *m = (Segment *)queue[getIndex()].pop();
      vect[getIndex()][i]= *m; i++;
  }

  int j=0;//bouclé sur l'horloge du msg
  i=1;//bouclé sur les num de seq ayant la meme horloge
  int k=0;//bouclé sur la taille du buffer
  while(j<=horlogeG[getIndex()]){
  while(i<=3){
  while(k<50){
        if((vect[getIndex()][k].horloge==j)&&(vect[getIndex()][k].num_seq==i)){EV <<" Noeud " <<  getIndex() <<" > Le message recu à la suite de la diffusion n° " << vect[getIndex()][k].horloge<< ",et ayant un numero de séquence de :"<<  vect[getIndex()][k].num_seq <<", est consommé \n";i++;k=0;}else{k++;}
  }
  k=0;i++;
  }
  j++;i=1;k=0;
  }

////////////////////////////////////////////////////////////////
}}}

