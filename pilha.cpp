
#include <iostream>
#include <locale.h> // Biblioteca para poder utilizar setlocale()
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define MAX 3
// Estrutura da pilha 
typedef struct Pilha{
       int vet[MAX];
       int topo;       
}Pilha;
    
// Cria  pilha 
Pilha ele_pilha;

//Prototipação das funçoes 
void empilhar(Pilha* p, int i);
int desempilhar(Pilha* p);
void constru_pilha(Pilha* p);
int select_desempilhar(Pilha* p, int num);
int exibir_elemento(int exib);
int imprimir_elemento(int exib);
void menu();
void topo();

/*Para as funçoes enchegar o valor desempilhado*/
int aux2;
int main(){
	
setlocale(LC_ALL,"PORTUGUESE"); //aceitar caracteres especiais

int veri_menu=0;
struct Pilha p;
int num,adc;       
constru_pilha(&p);
menu();
    
}
// Função para  exibir o topo.
void topo(){
	int i,imp,aux=0;
	imp=ele_pilha.topo;
	for(i=0;i<imp;i++){
		if(imp>=ele_pilha.topo){
			aux=ele_pilha.vet[i];
		}		
	}
	if(ele_pilha.topo<=0){
		cout<<"\n Não há elementos na pilha \n";
	}else{
		cout<<" \n Topo da Pilha: "<<aux;
		cout<<"\n";
	}
		
}

// Função para  empilhar o dados.
void empilhar(Pilha* p, int i){    
     if(p->topo==MAX ){
        cout<<"\nA pilha esta cheia \n ";
     }
     if(p->topo<0){
     	p->topo=0;
	 }
     if(p->topo<MAX ){
        p->vet[p->topo]= i;
     	p->topo++;
     } 
}     
// Função para  desempilhar os dados.
int desempilhar(Pilha* p){      
    p->topo--;
    p->vet[p->topo];
    if(p->topo >=0){	
    return  p->vet[p->topo];
}
}
// Função para inicializar os topos  da pilha com valor 0. 
void constru_pilha(Pilha* p){
     ele_pilha.topo=-1;
}
// Função que chama a função desempilhar os dados.                     
int select_desempilhar(Pilha* p, int num){
       aux2 = desempilhar(&ele_pilha);
         
}
// Função para Localizar os dados da pilha. 
int exibir_elemento(int exib){  
	int i;
	bool verif=false;
	for(i=0;i<=MAX;i++){	
		if(exib==ele_pilha.vet[i]){
	 		cout<<"\n Elemento "<<ele_pilha.vet[i]<<" esta na posição "<<i<<". \n"; 	
	 		verif=true;
		}
	}
	if(verif==false){
		cout<<"\n Não possui esse elemento na pilha \n";
	}
}
// Função para imprimir os dados da pilha. 
int imprimir_elemento(int exib){  
	int i,imp;
	imp=ele_pilha.topo;
	for(i=0;i<imp;i++){
		if(imp>0){
			cout<<" \n Elemento "<<ele_pilha.vet[i]<<" esta na posição "<<i<<". \n";	
		}		
	}
}                                                          
// Função para Exibir o menu de acessos 
void menu(){
	struct Pilha p;
    int num,adc,veri_menu;
    int exib;
	do{
	cout<<"\n---------MENU---------";
    cout<<"\n----------------------";
	cout<<"\n|1-Empilhar          |";
    cout<<"\n|2-Desempilhar       |";
    cout<<"\n|3-Localizar Elemento|";
    cout<<"\n|4-Topo Da Pilha     |";
    cout<<"\n|5-Imprimir Pilha    |";
    cout<<"\n|6-Limpar Pilha      |";
    cout<<"\n|7-Sair              |";
    cout<<"\n----------------------";
    cout<<"\n Escolha sua opção: ";
    cin>>veri_menu;
    cout<<"\n";
    system("CLS");
     if(veri_menu==1){
     	cout<<"\nDigite um valor para empilhar: ";
        cin>>adc; 
		empilhar(&ele_pilha,adc);                             
	 	}
	 if(veri_menu==2){
     	 select_desempilhar(&p,num);      
		  	if(aux2>=0){
				cout<<"\nValor desempilhado: \n"<<aux2;
				cout<<"\n"; 
			}
			if(aux2 < 0){
				cout<<"\n Pilha esta vazia \n";
			}  
	 	}	
	 if(veri_menu==3){
		int exib=-1;
		
		if(ele_pilha.topo<0){	
			cout<<"\n Voce ainda não inseriu valores na pilha \n";	
		}else{
			cout<<" \nEscolha qual elemento deseja Localizar \n";
			cin>>exib;
			exibir_elemento(exib);
		}
		}		   	
		if(veri_menu==4){
			topo();
		}
	  if(veri_menu==5){
		imprimir_elemento(exib);
			if(ele_pilha.topo<=0){
				cout<<" \n Não há elementos para imprimir \n";
			}
		}
	  if(veri_menu==6){
	  
	  	for(int i=0;i<=MAX;i++){
		   		select_desempilhar(&p,num);
			}
		   	if(aux2 < 0){
				cout<<"\n Pilha esta vazia \n";
			}			
		 }
	  	 
	  	 
		 cout<<"\n";
		 system("pause");
		 system("CLS");	
}while(veri_menu !=7);
}
