
#include <iostream>
#include <locale.h> // Biblioteca para poder utilizar setlocale()
#include <math.h>
#include <stdio.h>
#include <conio.h>

using namespace std;
#define MAX 3
// Estrutura da fila 
typedef struct fila{
       int vet[MAX];
       int fim_fila;       
}fila;
    
// Cria  fila 
fila ele_fila;

//Prototipação das funçoes 
void enfileirar(fila * p,int i);
int desenfileirar(fila* p);
void menu();
int imprimir_elemento(int exib);
void constru_fila(fila* p);
int localizar_ele(int exib);

int main(){
setlocale(LC_ALL,"PORTUGUESE"); //aceitar caracteres especiais

struct fila p;
constru_fila(&p);
menu();
}

//Função para enfileirar os elementos.
void enfileirar(fila * p,int i){
	if(p->fim_fila==MAX ){
        cout<<"\nA pilha esta cheia \n ";
     }
     if(p->fim_fila<0){
     	p->fim_fila=0;
	 }
	if(p->fim_fila<MAX ){
        p->vet[p->fim_fila]= i;
     	p->fim_fila++;
     } 
}

// Função para  enfileirar os dados.
int desenfileirar(fila* p){ 
	int aux,i;     
    p->fim_fila--;
    p->vet[p->fim_fila];
    if(p->fim_fila >=0){
	for(int i=0;i<=ele_fila.fim_fila;i++){
	aux=ele_fila.vet[i];
	ele_fila.vet[i-1]=aux;
	ele_fila.vet[i]=-1;
}
    return  p->vet[p->fim_fila];
}
}
// Função para inicializar os topos  da fila com valor -1. 
void constru_fila(fila* p){
     ele_fila.fim_fila=-1;
}
// Função para imprimir os dados da fila. 
int imprimir_elemento(int exib){  
	int i,imp;
	imp=ele_fila.fim_fila;
	for(i=0;i<imp;i++){
		if(imp>0){
			cout<<" \n Elemento "<<ele_fila.vet[i]<<" esta na posição "<<i<<". \n";	
		}		
	}
}
//Função para localizar elemento na fila.
int localizar_ele(int exib){
		int i;
	bool verif=false;
	for(i=0;i<=MAX;i++){	
		if(exib==ele_fila.vet[i]){
	 		cout<<"\n Elemento "<<ele_fila.vet[i]<<" esta na posição "<<i<<". \n"; 	
	 		verif=true;
		}
	}
	if(verif==false){
		cout<<"\n Não possui esse elemento na fila \n";
	}
}
// Função para Exibir o menu de acessos 
void menu(){
	struct fila p;
    int num,adc,veri_menu;
    int cont,exib;
	do{
		system("CLS");
	cout<<"\n-----------MENU---------";
    cout<<"\n------------------------";
	cout<<"\n|1-Enfileirar          |";
    cout<<"\n|2-Desenfileirar       |";
    cout<<"\n|3-Localizar Elemento  |";
    cout<<"\n|4-Inicio Da Fila      |";
    cout<<"\n|5-Imprimir Fila       |";
    cout<<"\n|6-Limpar Fila         |";
    cout<<"\n|7-Sair                |";
    cout<<"\n------------------------";
    cout<<"\n Escolha sua opção: ";
    cin>>veri_menu;
    cout<<"\n";
    	system("CLS");
     if(veri_menu==1){
     	cout<<"\nDigite um valor para enfileirar: ";
        cin>>adc; 
		enfileirar(&ele_fila,adc);  
		cont++;                           
	 	}
	 	
	 if(veri_menu==2){
	 		if(ele_fila.fim_fila<=0){
	 			cout<<"\n fila esta vazia \n";
			 }else{
			 	if(ele_fila.fim_fila>0){
			 	cout<<"\nElemento saiu da fila: "<<ele_fila.vet[0]<<"\n";
			 	}
				 desenfileirar(&ele_fila);
			 }
	 	}
		 	
	 if(veri_menu==3){
	 	if(ele_fila.fim_fila<=0){
	 		cout<<"\n fila esta vazia \n";
		 }else{
		 	cout<<" \n Digite o elemento que deseja localizar na fila: ";
			cin>>exib;
		 	localizar_ele(exib);
		 }
		}
		
		if(veri_menu==4){
			if(ele_fila.fim_fila<=0){
				cout<<"\n Fila esta vazia \n";
			}else{
				cout<<"Inicio da Fila: "<<ele_fila.vet[0]<<"\n";
			}
			
		}
		
	if(veri_menu==5){
			if(ele_fila.fim_fila<=0){
				cout<<" \n Não há elementos nesta fila \n";
			}else{
				imprimir_elemento(exib);
			}
	}
	
	  if(veri_menu==6){
	  	for(int i=0;i<MAX;i++){
	  		desenfileirar(&ele_fila);
		  }
		  if(ele_fila.fim_fila<=0){
		  	cout<<"\n Fila esta vazia \n";
		  }
		 }
		 cout<<"\n";
		 system("pause");
}while(veri_menu !=7);
}

