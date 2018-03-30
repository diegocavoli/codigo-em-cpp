
#include <iostream>
#include <locale.h> // Biblioteca para poder utilizar setlocale()
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;
#define MAX 10
// Estrutura da pilha 
typedef struct lista{
       int vet[MAX];
       int topo;       
}lista;
    
// Cria  pilha 
lista ele_lista;
lista ele_lista1;
//Prototipação das funçoes 
void listar_IN(lista* p, int eleme,int esc);
void listar_QL(lista* p, int eleme,int selec,int esc);
void listar_FI(lista* p, int eleme,int esc);
void remove_IN(lista* p,int esc);
void remove_QL(lista* p, int eleme,int esc);
void remove_FI(lista* p,int esc);
void constru_lista(lista* p);
void imprimir_TDlista();
int imprimir_lista(lista* p,int esc);
void menu();
void remove_lista(lista *p,int esc);
int localizar_elemento(int el,int esc);
int lista_cheia(int CH);
int lista_vazia(int VA);


int main(){
	
setlocale(LC_ALL,"PORTUGUESE"); //aceitar caracteres especiais

int veri_menu=0;
struct lista p;
int num,adc;       
constru_lista(&p);
menu();
    
}

// Função para  listar o dados no inicio do lista.
void listar_IN(lista* p, int eleme,int esc){   
	 
	 	if(p->topo<0){
     		p->topo=0;
    	 }
    	if(esc==1){
    		for(int i=ele_lista.topo-1;i>=0;i--){
				ele_lista.vet[i+1]=ele_lista.vet[i];
     		}
     		ele_lista.vet[0]= eleme;
			p->topo++; 	
		}else{
			for(int i=ele_lista1.topo-1;i>=0;i--){
				ele_lista1.vet[i+1]=ele_lista1.vet[i];
     		}
     		ele_lista1.vet[0]= eleme;
			p->topo++;	
		}
     	
}

// Função para listar o dados em alguma posição desejada.
void listar_QL(lista* p, int eleme,int selec,int esc){    
     if(!lista_cheia(1)){
     	if(esc==1){
     		p->topo++; 
     		for(int i=ele_lista.topo-1;i>=selec;i--){
				ele_lista.vet[i+1]=ele_lista.vet[i];
     			ele_lista.vet[i]= eleme;
			}
		}else if(esc==2){
		 	p->topo++; 
     		for(int i=ele_lista1.topo-1;i>=selec;i--){
				ele_lista1.vet[i+1]=ele_lista1.vet[i];
     			ele_lista1.vet[i]= eleme;	
		 	}
		}
    }
}

// Função para  listar o dados no fim da lista.
void listar_FI(lista* p, int eleme){  
  	if(p->topo<0){
     	p->topo=0;
    }
    if(p->topo>=MAX ){
    	cout<<"\nA lista esta cheia \n ";
		 }else{	 	
			p->vet[p->topo]= eleme;
		 	p->topo++;
		 }
	}
// Função para remover os dados no inicio da lista.
void remove_IN(lista* p){      
	cout<<"\n Removido da Lista: "<<ele_lista.vet[0];
	for(int i=0;i<ele_lista.topo;i++){
		ele_lista.vet[i]=ele_lista.vet[i+1];
	}
	p->topo--;
}

// Função para remover os dados de alguma posição desejada.
void remove_QL(lista* p,int eleme){      
    if(p->topo==MAX ){
        cout<<"\nA lista esta cheia \n ";
     }else{
	 	if(p->topo<0){
     	p->topo=0;
    	 }
    	 cout<<"\n Removido da Lista: "<<ele_lista.vet[eleme];
     	for(int i=eleme;i<=ele_lista.topo-1;i++){
		ele_lista.vet[i]=ele_lista.vet[i+1];
			p->topo--; 
     	}
     	
	 }
}

// Função para  remover dados no fim da lista.
void remove_FI(lista* p){
	cout<<"\n Removido da Lista: "<<ele_lista.vet[p->topo-1];      
    p->topo--;	
}
// Função para inicializar os topos  da lista com valor -1. 
void constru_lista(lista* p){
     ele_lista.topo-1;
     ele_lista1.topo-1;
}

void remove_lista(lista *p){
		for(int i=0;i<MAX;i++){
			p->topo--;	
		}
		if(p->topo<=0){
			lista_vazia(1);
		}
	}

 
//funcão para imprimir uma das listas.
int imprimir_lista(lista* p,int esc){
	if(esc==1){
		for(int i=0;i<ele_lista.topo;i++){
				cout<<"\n Elemento "<<ele_lista.vet[i]<<" esta na posição "<<i<<". \n";	
		}
	}else{
		for(int i=0;i<ele_lista1.topo;i++){
			
				cout<<"\n Elemento "<<ele_lista1.vet[i]<<" esta na posição "<<i<<". \n";	
		}			 	
	}	
}

void imprimir_TDlista(){
	
	
	if(ele_lista.topo<=0){
		cout<<"\n Primeira Lista Vazia \n";
	}else{
		cout<<"\n Lista 1 \n";
		for(int i=0;i<ele_lista.topo;i++){
			cout<<"\n Elemento "<<ele_lista.vet[i]<<" esta na posição "<<i<<". \n";	
		}
	}
	
	if(ele_lista1.topo<=0){
		cout<<"\n Segunda Lista vazia \n";
	}else{
		cout<<"\n Lista 2 \n";	
		for(int i=0;i<ele_lista1.topo;i++){
			cout<<"\n Elemento "<<ele_lista1.vet[i]<<" esta na posição "<<i<<". \n";	
		}
	}
}	
	

//função para identificar se a lista esta cheia ou não.
int lista_cheia(int CH){
	if(ele_lista.topo==MAX ){
        cout<<"\nPrimeira lista esta cheia \n ";
        if(ele_lista1.topo==MAX ){
        	cout<<"\nSegunda lista esta cheia \n ";
        }
    }
        if(ele_lista.topo==MAX && ele_lista1.topo==MAX){
        	return 1;
     }else{
     	return 0;
     }
}

//função para identificar se a lista esta vazia ou não.
int lista_vazia(int VA){
	if(ele_lista.topo<=0){
			cout<<"\n Primeira Lista Vazia \n";	
	}
    if(ele_lista1.topo<=0){
		cout<<"\n Segunda Lista Vazia \n";
    }
    if( ele_lista.topo<=0 && ele_lista1.topo<=0){
		return 1;
     }else{
     	return 0;
     }
}

//funcão para localizar um elemento espesífico.                          
localizar_elemento(int el){
	if(!lista_vazia(1)){
			bool verif=false;
	for(int i=0;i<=MAX;i++){	
		if(el==ele_lista.vet[i]){
	 		cout<<"\n Elemento "<<ele_lista.vet[i]<<" esta na posição "<<i<<". \n"; 	
	 		verif=true;
		}
	}
	if(verif==false){
		cout<<"\n Não possui esse elemento na lista \n";
	}		
		}
	}

                          
// Função para Exibir o menu de acessos 
void menu(){
	struct lista p;
    int adc,veri_menu,veri_op,selec,el,esc;
	do{
	system("CLS");
	cout<<"\n-----------MENU-LISTA----------";
    cout<<"\n-------------------------------";
	cout<<"\n|1-Adicionar a lista          |";
    cout<<"\n|2-Remover da lista           |";
    cout<<"\n|3-Localizar Elemento         |";
    cout<<"\n|4-Topo Da Lista              |";
    cout<<"\n|5-Imprimir Lista             |";
    cout<<"\n|6-Imprimir Todas As Listas   |";
    cout<<"\n|7-Limpar Lista               |";
    cout<<"\n|8-Sair                       |";
    cout<<"\n-------------------------------";
    		do{
				cout<<"\n Escolha sua opção: ";
            	cin>>veri_menu;
            	if(veri_menu!=1 && veri_menu!=2 && veri_menu!=3 && veri_menu!=4 && veri_menu!=5 && veri_menu!=6 && veri_menu!=7){
			 		cout<<"\n Opção Invalida , Tente Novamente:";
				 }
			 }while(veri_menu!=1 && veri_menu!=2 && veri_menu!=3 && veri_menu!=4 && veri_menu!=5 && veri_menu!=6 && veri_menu!=7);
    cout<<"\n";
    system("CLS");
     if(veri_menu==1){
     	if(!lista_cheia(1)){
     		cout<<"\n--------MENU-ADICAO-LISTA-------";
     		cout<<"\n--------------------------------";
     		cout<<"\n| 1-Adicionar Inicio           |";
     		cout<<"\n| 2-Adicionar em Alguma Posição|";
     		cout<<"\n| 3-Adicionar no Fim           |";
     		cout<<"\n--------------------------------";
			do{
				cout<<"\n Escolha sua opção: ";
            	cin>>veri_op;
            	if(veri_op!=1 && veri_op!=2 && veri_op!=3){
			 		cout<<"\n Opção Invalida , Tente Novamente:";
				 }
			 }while(veri_op!=1 && veri_op!=2 && veri_op!=3); 
			 	
			if(veri_op==1){
				cout<<"\n Digite o Elemento para Adicão a lista: ";
				cin>>adc;
				
				cout<<"\n Adição lista 1 ou 2: ";
				cin>>esc;
					if(ele_lista.topo<MAX && esc==1){
					listar_IN(&ele_lista,adc,esc);		
				}	
				}
				
					if(ele_lista1.topo<MAX && esc==2){
					listar_IN(&ele_lista1,adc,esc);	
					
				}
		}
	}
				
			if(veri_op==2){
				bool verific=false;
				
				if(ele_lista.topo<=1){
					cout<<"\n E necessario inserir a lista pelomenos 2 elementos.\n";
				}else{
					while(verific==false){
					
						cout<<"\n Digite Uma Posição da lista que Deseja Adicionar ,Disponivel de 0 a "<<ele_lista.topo<<": ";
						cin>>selec;
						if(selec>ele_lista.topo){
							cout<<"\n Você so podera adicionar da posição 0 ate "<<ele_lista.topo<<". \n";
							verific=false;
						}else{
							cout<<"\n Digite o Elemento para Adicão a lista: ";
							cin>>adc;
							verific=true;
							cout<<"\n Adição lista 1 ou 2: ";
							cin>>esc;
							if(ele_lista.topo<MAX && esc==1){
								listar_QL(&ele_lista,adc,selec,esc);		
							}	
							if(ele_lista1.topo<MAX && esc==2){
								listar_QL(&ele_lista1,adc,selec,esc);	
							}
						}
					}
				}
			}
		
			
			if(veri_op==3){
				cout<<"\n Digite o Elemento para Adicão a lista: ";
				cin>>adc;
            	listar_FI(&ele_lista,adc);		
			}  
		
	 	
	 
	 
	 if(veri_menu==2){
	 	if(!lista_vazia(1)){
	 		cout<<"\n------MENU-REMOVE-LISTA------";
     		cout<<"\n-----------------------------";
     		cout<<"\n| 1-REMOVE Inicio           |";
     		cout<<"\n| 2-REMOVE em Alguma Posição|";
     		cout<<"\n| 3-REMOVE no Fim           |";
     		cout<<"\n-----------------------------";
     		do{
				cout<<"\n Escolha sua opção: ";
            	cin>>veri_op;
            	if(veri_op!=1 && veri_op!=2 && veri_op!=3){
			 		cout<<"\n Opção Invalida , Tente Novamente:";
				 }
			 }while(veri_op!=1 && veri_op!=2 && veri_op!=3); 
            if(veri_op==1){
           			remove_IN(&ele_lista);
				
			}
			if(veri_op==2){
            		cout<<"\n Digite Uma Posição da lista que Deseja Remover: ";
					cin>>selec;
					remove_QL(&ele_lista , selec);	
			}
			
			if(veri_op==3){
            	remove_FI(&ele_lista);
			}
	 	}
	}

	 if(veri_menu==3){
	 		if(!lista_vazia(1)){ 
	 		cout<<"\n Digite o elemento que deseja localizar: ";
	 		cin>>el;
			localizar_elemento(el);
			}
		}		   	
		if(veri_menu==4){
			if(!lista_vazia(1)){
				cout<<"\n Topo da Lista: "<<ele_lista.vet[0]<<"\n";	
			}	
		}
	  if(veri_menu==5){
	  		if(!lista_vazia(1)){
	  			cout<<"\n Imprimir lista 1 ou 2: ";
				cin>>esc;
				if(esc==1){
					imprimir_lista(&ele_lista,esc);
				}else 
					if(esc==2){
				imprimir_lista(&ele_lista1,esc);
				}
				}
		}
		if(veri_menu==6){
			imprimir_TDlista();	
		}
	  if(veri_menu==7){
	  		if(!lista_vazia(1)){
	  			remove_lista(&ele_lista);
			}	
		}
		 cout<<"\n";
		 system("pause");
}while(veri_menu !=8);
}
