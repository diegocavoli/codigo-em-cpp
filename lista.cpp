
#include <iostream>
#include <locale.h> // Biblioteca para poder utilizar setlocale()
#include <math.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <limits>

using namespace std;
#define MAX 5
// Estrutura da Lista 
typedef struct lista{
       int vet[MAX];
       int topo;       
}lista;
    
// Cria  Lista 
lista ele_lista;
lista ele_lista2;

//Prototipação das funçoes 
void listar_IN(lista* p, int eleme);
void listar_QL(lista* p, int eleme,int selec);
void listar_FI(lista* p, int eleme);
void remove_IN(lista* p);
void remove_QL(lista* p, int eleme);
void remove_FI(lista* p);
void constru_lista(lista* p);
void imprimir_TDlista();
void imprimir_lista();
void menu();
void menu_lista();
void remove_lista(lista *p);
int localizar_elemento(lista *p,int el);
int lista_cheia(int CH);
int lista_vazia(int VA);
int opcao(int verificador);

//para que o codigo enchergue qual lista que armazenar.
int selec_lista=0;
int main(){
	
setlocale(LC_ALL,"PORTUGUESE"); //aceitar caracteres especiais

int veri_menu=0;
struct lista p;
int num,adc;       
constru_lista(&p);
menu();
    
}

// Função para  listar o dados no inicio do lista.
void listar_IN(lista* p, int eleme){   
	 	if(p->topo<0){
     		p->topo=0;
    	 }	
		 if(selec_lista==1){
    	 for(int i=ele_lista.topo-1;i>=0;i--){
				ele_lista.vet[i+1]=ele_lista.vet[i];
     		}
     		ele_lista.vet[0]= eleme;
			p->topo++; 			
		 }
		 
		 if(selec_lista==2){
    	 for(int i=ele_lista2.topo-1;i>=0;i--){
				ele_lista2.vet[i+1]=ele_lista2.vet[i];
     		}
     		ele_lista2.vet[0]= eleme;
			p->topo++; 			
		 }
}

// Função para listar o dados em alguma posição desejada.
void listar_QL(lista* p, int eleme,int selec){    
     if(!lista_cheia(1)){
     		if(selec_lista==1){
			 	p->topo++; 
     			for(int i=ele_lista.topo-1;i>=selec;i--){
					ele_lista.vet[i+1]=ele_lista.vet[i];
     				ele_lista.vet[i]= eleme;
				}
			 }else if(selec_lista==2){
			 	p->topo++; 
     			for(int i=ele_lista2.topo-1;i>=selec;i--){
					ele_lista2.vet[i+1]=ele_lista2.vet[i];
     				ele_lista2.vet[i]= eleme;
				}
			 }
		}
    }


// Função para  listar o dados no fim da lista.
void listar_FI(lista* p, int eleme){  
  	if(p->topo<0){
     	p->topo=0;
    }
    	if(selec_lista==1){
			 if(p->topo<MAX ){
    		 	p->vet[p->topo]= eleme;
    		 	p->topo++;	
			 }
		}else if(selec_lista==2){
			if(p->topo<MAX ){
    		 	p->vet[p->topo]= eleme;
    			p->topo++;	
		 	}
		}
    
	}
	
// Função para remover os dados no inicio da lista.
void remove_IN(lista* p){

		if(selec_lista==1){
			cout<<"\n Removido da Lista: "<<ele_lista.vet[0];
			for(int i=0;i<ele_lista.topo;i++){
				ele_lista.vet[i]=ele_lista.vet[i+1];
			}
			p->topo--;	
			
		}else if(selec_lista==2){
			cout<<"\n Removido da Lista: "<<ele_lista2.vet[0];
				for(int i=0;i<ele_lista.topo;i++){
				ele_lista2.vet[i]=ele_lista2.vet[i+1];
		}
			p->topo--;		 	
		}
	}	

// Função para remover os dados de alguma posição desejada.
void remove_QL(lista* p,int eleme){      
    if(!lista_vazia(1)){
    	
    		if(selec_lista==1){
			 	cout<<"\n Removido da Lista: "<<ele_lista.vet[eleme];
     				for(int i=eleme;i<=ele_lista.topo-1;i++){
					ele_lista.vet[i]=ele_lista.vet[i+1];
					p->topo--;
				}
			 }else if(selec_lista==2){
			 	cout<<"\n Removido da Lista: "<<ele_lista2.vet[eleme];
     				for(int i=eleme;i<=ele_lista2.topo-1;i++){
					ele_lista2.vet[i]=ele_lista2.vet[i+1];
					p->topo--;
				}
			 }
		}
    }

// Função para  remover dados no fim da lista.
void remove_FI(lista* p){
		
			if(selec_lista==1){
			 	cout<<"\n Removido da Lista: "<<ele_lista.vet[p->topo-1];      
    			p->topo--;
			 }else if(selec_lista==2){
			 	cout<<"\n Removido da Lista: "<<ele_lista2.vet[p->topo-1];      
    			p->topo--;	
			 }	
}

// Função para inicializar os topos  da lista com valor -1. 
void constru_lista(lista* p){
     ele_lista.topo-1;
     ele_lista2.topo-1;
}

void remove_lista(lista *p){
		for(int i=0;i<MAX;i++){
			p->topo--;	
		}
	}

 
//funcão para imprimir uma das listas.
void imprimir_lista(){

	if(selec_lista==1){
		for(int i=0;i<ele_lista.topo;i++){
			cout<<"\n Elemento "<<ele_lista.vet[i]<<" esta na posição "<<i<<". \n";
		}
	}
	
	
	else if(selec_lista==2){
		for(int i=0;i<ele_lista2.topo;i++){
				cout<<"\n Elemento "<<ele_lista2.vet[i]<<" esta na posição "<<i<<". \n";	
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
	
	if(ele_lista2.topo<=0){
		cout<<"\n Segunda Lista vazia \n";
	}else{
		cout<<"\n Lista 2 \n";	
		for(int i=0;i<ele_lista2.topo;i++){
			cout<<"\n Elemento "<<ele_lista2.vet[i]<<" esta na posição "<<i<<". \n";	
		}
	}
}	
	
//função para identificar se a lista esta cheia ou não.
int lista_cheia(int CH){
	if(selec_lista==1){
		if(ele_lista.topo==MAX){
			cout<<"\n Lista cheia \n";
			return 1;	
	}
		return 0;	
  
	}else if(selec_lista==2){
		if(ele_lista2.topo==MAX){
			cout<<"\n Lista cheia \n";
			return 1;	
	}
		
		return 0;
	}
	
}

//função para identificar se a lista esta vazia ou não.
int lista_vazia(int VA){
	
	if(selec_lista==1){
		if(ele_lista.topo<=0){
			cout<<"\n Lista Vazia \n";	
			return 1;
	}
     	return 0;
     
	}else if(selec_lista==2){
		if(ele_lista2.topo<=0){
			cout<<"\n Lista Vazia \n";
			return 1;	
	}
     	return 0; 	
	}
	
}

//funçao para verificar se esta sendo digitado somente numero.
int opcao(int verificador){
	cout<<"\n Escolha sua opção: ";
    cin>>verificador;
	while(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "\nDigite Apenas Números!\nEscolha sua opção: ";
        cin >>verificador;
    }
    return verificador;
}

//funcão para localizar um elemento espesífico.                          
localizar_elemento(lista* p,int el){
	bool verif=false;
	if(!lista_vazia(1)){
		if(selec_lista==1){
			for(int i=0;i<ele_lista.topo;i++){	
				if(el==ele_lista.vet[i]){
	 				cout<<"\n Elemento "<<ele_lista.vet[i]<<" esta na posição "<<i<<". \n"; 	
	 				verif=true;
				}
			}
	 	 if(verif==false){
	  		cout<<"\n Não possui esse elemento na lista \n";
	 	  }	
	   }else if(selec_lista==2){
			for(int i=0;i<ele_lista.topo;i++){	
			 if(el==ele_lista2.vet[i]){
	 			cout<<"\n Elemento "<<ele_lista2.vet[i]<<" esta na posição "<<i<<". \n"; 	
	 			verif=true;
			  } 
		   }
	 	 if(verif==false){
	      cout<<"\n Não possui esse elemento na lista \n";
	     }	
	    	
    }		
	 }
}

                          
// Função para Exibir o menu de acessos 
void menu(){
	struct lista p;
    int adc=0,veri_lista=0,veri_op=0,selec=0,el=0;
    bool sup;
    
	do{
		system("CLS");
		cout<<"\n  ------------MENU-LISTAS-----------";
    	cout<<"\n  ----------------------------------";
		cout<<"\n  |1-Lista 1          		   |";
		cout<<"\n  |2-Lista 2          		   |";
    	cout<<"\n  |3-Imprimir as Listas            |";
    	cout<<"\n  |4-Limpar as Listas              |";
    	cout<<"\n  |5-Sair                          |";
    	cout<<"\n  ----------------------------------";
		
            do{
            veri_lista=opcao(verificador);
			if(veri_lista!=1 && veri_lista!=2 && veri_lista!=3 && veri_lista!=4 && veri_lista!=5){
			 		cout<<"\n Opção Invalida , Tente Novamente:";
				 }
			 }while(veri_lista!=1 && veri_lista!=2 && veri_lista!=3 && veri_lista!=4 && veri_lista!=5);	
			if(veri_lista==1){
				selec_lista=1;
				menu_lista();									
			}
			if(veri_lista==2){
				selec_lista=2;
				menu_lista();
			}
			if(veri_lista==3){
				imprimir_TDlista();
			}
			
			if(veri_lista==4){
				remove_lista(&ele_lista);
	  			remove_lista(&ele_lista2);
				 if(ele_lista.topo<=0){
				 	lista_vazia(1);		
			}
			}
		cout<<"\n";
		system("pause");
     

}while(veri_lista!=5);
if(veri_lista==5){
	exit(1);	
}

}

void menu_lista(){
	struct lista p;
    int adc,veri_menu,veri_op,selec,el,verificador=0;
	do{
	system("CLS");
	cout<<"\n  --------SUB-MENU-LISTA---------";
    cout<<"\n  -------------------------------";
	cout<<"\n  |1-Adicionar a lista          |";
    cout<<"\n  |2-Remover da lista           |";
    cout<<"\n  |3-Localizar Elemento         |";
    cout<<"\n  |4-Topo Da Lista              |";
    cout<<"\n  |5-Imprimir Lista             |";
    cout<<"\n  |6-Limpar Lista               |";
    cout<<"\n  |7-Sair                       |";
    cout<<"\n  -------------------------------";
    		do{
				veri_menu=opcao(verificador);
            	if(veri_menu!=1 && veri_menu!=2 && veri_menu!=3 && veri_menu!=4 && veri_menu!=5 && veri_menu!=6 && veri_menu!=7){
			 		cout<<"\n Opção Invalida , Tente Novamente:";
				 }
			 }while(veri_menu!=1 && veri_menu!=2 && veri_menu!=3 && veri_menu!=4 && veri_menu!=5 && veri_menu!=6 && veri_menu!=7);
    		cout<<"\n";
    		system("CLS");
     if(veri_menu==1){
     	if(!lista_cheia(1)){
     		cout<<"\n  --------MENU-ADICÃO-LISTA-------";
     		cout<<"\n  --------------------------------";
     		cout<<"\n  | 1-Adicionar Inicio           |";
     		cout<<"\n  | 2-Adicionar em Alguma Posição|";
     		cout<<"\n  | 3-Adicionar no Fim           |";
     		cout<<"\n  --------------------------------";
			do{
				veri_op=opcao(verificador);
            	if(veri_op!=1 && veri_op!=2 && veri_op!=3){
			 		cout<<"\n Opção Invalida , Tente Novamente:";
				 }
			 }while(veri_op!=1 && veri_op!=2 && veri_op!=3); 
			 	
			if(veri_op==1){
				cout<<"\n Digite o Elemento para Adicão a lista: ";
				cin>>adc;
				if(selec_lista==1){
					listar_IN(&ele_lista,adc);	
				}else if(selec_lista==2){
					listar_IN(&ele_lista2,adc);	
				}
						
			}
		}

 
			if(veri_op==2){
				
				if(selec_lista==1){
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
							listar_QL(&ele_lista,adc,selec);		
						}
					}
				}	
				}else if(selec_lista==2){
					bool verific=false;
				if(ele_lista2.topo<=1){
					cout<<"\n E necessario inserir a lista pelomenos 2 elementos.\n";
				}else{
					while(verific==false){
					
						cout<<"\n Digite Uma Posição da lista que Deseja Adicionar ,Disponivel de 0 a "<<ele_lista2.topo<<": ";
						cin>>selec;
						if(selec>ele_lista2.topo){
							cout<<"\n Você so podera adicionar da posição 0 ate "<<ele_lista2.topo<<". \n";
							verific=false;
						}else{
							cout<<"\n Digite o Elemento para Adicão a lista: ";
							cin>>adc;
							verific=true;
							listar_QL(&ele_lista2,adc,selec);		
						}
					}
				}	
				}
			
}
		
			if(veri_op==3){
				cout<<"\n Digite o Elemento para Adicão a lista: ";
				cin>>adc;
				if(selec_lista==1){
					listar_FI(&ele_lista,adc);	
				}else if(selec_lista==2){
					listar_FI(&ele_lista2,adc);
				}
					
		}
	veri_op=0;		
}
		
	 if(veri_menu==2){
	 	if(!lista_vazia(1)){
	 		cout<<"\n  ------MENU-REMOVE-LISTA------";
     		cout<<"\n  -----------------------------";
     		cout<<"\n  | 1-REMOVE no Inicio        |";
     		cout<<"\n  | 2-REMOVE em Alguma Posição|";
     		cout<<"\n  | 3-REMOVE no Fim           |";
     		cout<<"\n  -----------------------------";
     		do{
				veri_op=opcao(verificador);
            	if(veri_op!=1 && veri_op!=2 && veri_op!=3){
			 		cout<<"\n Opção Invalida , Tente Novamente:";
				 }
			 }while(veri_op!=1 && veri_op!=2 && veri_op!=3); 
            if(veri_op==1){
            	if(selec_lista==1){
            		remove_IN(&ele_lista);
				}else if(selec_lista==2){
					remove_IN(&ele_lista2);
				}	

			}
			if(veri_op==2){
            		cout<<"\n Digite Uma Posição da lista que Deseja Remover: ";
					cin>>selec;
				if(selec_lista==1){
					remove_QL(&ele_lista , selec);	
				}else if(selec_lista==2){
					remove_QL(&ele_lista2 , selec);	
				}				
			}
			
			if(veri_op==3){
				if(selec_lista==1){
					remove_FI(&ele_lista);	
				}else if(selec_lista==2){
					remove_FI(&ele_lista2);
				}	
			}
		}
	veri_op=0;			
	}

	 if(veri_menu==3){
	 		if(!lista_vazia(1)){ 
	 			cout<<"\n Digite o elemento que deseja localizar: ";
	 			cin>>el;
	 			if(selec_lista==1){
	 				localizar_elemento(&ele_lista,el);
				 }else if(selec_lista==2){
				 	localizar_elemento(&ele_lista2,el);
				 }
				
			}
		}
				   	
		if(veri_menu==4){
			if(!lista_vazia(1)){
				if(selec_lista==1){
			 		if(ele_lista.topo>0){
					cout<<"\n Topo da Lista: "<<ele_lista.vet[0]<<"\n";
			 		}
					}else if(selec_lista==2){
			 			if(ele_lista2.topo>0){
						cout<<"\n Topo da Lista: "<<ele_lista2.vet[0]<<"\n";
			 			}	
				}
			}
		}
		
	  if(veri_menu==5){
	  		if(!lista_vazia(1)){
			  	imprimir_lista();	
			}
		}
		
		if(veri_menu==6){
			if(!lista_vazia(1)){
					if(selec_lista==1){
					   remove_lista(&ele_lista);	
					 }else if(selec_lista==2){
						remove_lista(&ele_lista2);	
					 }
					 if(ele_lista.topo<=0){
				 		lista_vazia(1);		
					 }
			}	
		}
		 cout<<"\n";
		 system("pause");
}while(veri_menu !=7);

	if(veri_menu==7){
		menu();
	}
}

