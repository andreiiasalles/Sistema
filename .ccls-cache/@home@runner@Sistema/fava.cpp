#include <iostream>
using namespace std;

struct no*PtLista;
struct no*Pont;
struct no*Ant;

struct no{
  int Chv;
  struct no*Prox;
};

void buscar(int x){
  Ant = PtLista;
  Pont = NULL;
  no*Aux = PtLista->Prox;

  while(Aux != NULL){
    if(Aux->Chv < x){
      Ant = Aux;
      Aux = Aux->Prox; 
    } 
    else {     
      if(Aux->Chv == x){
        Pont = Aux;
        //return 1;
      }
      Aux = NULL;
    }
  } 
  //return 0;
}
void inserir(int x){
  buscar(x);
  if(Pont != NULL){
    cout << ("Chave duplicada! Escolha outro numero.") << endl; 
  }
  else{
    no*Aux = new no;
    Aux->Prox = Ant->Prox;
    Ant->Prox = Aux;
    Aux->Chv = x;
    cout << ("Numero adcionado.") << endl;
  }
}

void remover(int x){ 
  
   if (PtLista->Prox != NULL){
        buscar(x);
      if(Pont != NULL){
        Ant->Prox = Pont->Prox;
			  Pont->Prox = NULL;
      }
      cout <<("Numero apagado." ) << endl;
    }  
      else{
        cout <<("Numero não encontrado." ) << endl;
      } 
  
}
void alterar(int x, int y){
    buscar(x);
    if ( Pont != NULL){ 
      Pont->Chv = y;
    }  
      else{
        cout <<("Numero não encontrado." ) << endl;
      }
  
}

void listar(){
  no*Aux = PtLista->Prox;
  
  while(Aux != NULL){
    cout <<  (Aux->Chv) << endl;
    Aux = Aux->Prox;
    
  }
}

int main() {

  PtLista = new no;
	PtLista->Prox = NULL;
  
  for(int i = 1; i > 0; i++){
    int opcao;
    cout <<("Menu da lista:" ) << endl;
    cout <<("Escolha o numero da opção desejada:" ) << endl;
    cout <<("1 - Inserir ") << endl;
    cout <<("2 - Alterar") << endl;
    cout <<("3 - Buscar") << endl;
    cout <<("4 -  Remover") << endl;
    cout <<("5 - Listar") << endl;
    cout <<("6 - Sair") << endl;

    cin >>(opcao);
    
    switch (opcao){
      
     case 1:
        int x;
        cout << ("Informe o numero que deseja adcionar.") << endl;
        cin >> (x);
        inserir(x);
     break;
      
     case 2:
         int y;
         cout << ("Informe o numero que deseja alterar.") << endl; 
         cin >> (x);
         cout << ("Informe o numero que deseja colocar no lugar") << endl; 
         cin >> (y);
         
         alterar(x,y);
     break;
        
     case 3:
         cout << ("Informe o numero que deseja buscar.") << endl; 
         cin >> (x);
         buscar (x);
         if (Pont == NULL){ 
           cout <<("Numero não encontrado." ) << endl;
         }  
           else{
             cout <<("Numero encontrado." ) << endl;
          }
     break;

     case 4:
        cout << ("Informe o numero que deseja deletar.") << endl; 
        cin >> (x);
        remover(x);
        
     break;
      
     case 5:
        cout << ("Os numeros armazenados são:") << endl; 
        listar();
     break;
      
     case 6:
        i = -1;
       cout << (" O sistema foi encerrado.") << endl;
     break;

     default:
        cout << ("Escolha uma opção válida. As opções são de 1 à 6.") << endl;
   }
  }
}
  