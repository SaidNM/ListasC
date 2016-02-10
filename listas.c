#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct agenda{
	char nom[20];
	char tel[12];
	struct agenda *siguiente;
};

struct agenda *primero,*ultimo;



void menu();
void agregar();
void borrar();
void mostrar();


int main(){
primero=NULL;
ultimo=NULL;
int op;
do{
	menu();
	scanf("%d",&op);
	switch(op){
	case 1:
	agregar();
	break;
	case 2:
	borrar();
	break;
	case 3:
	mostrar();
	break;
	case 4:
	printf("\nfin");
	break;
	default:
	printf("\nOpcion Invalida");
	break;
	}
	}while(op!=4);


    getch();
	return 0;
}


void menu(){
	printf("\nMenu\n1.-Agregar elemento\n2.-Borrar elemento\n3.-Mostrar lista\n4.-Salir\n\nElige una opcion:");
	}
void agregar(){
struct agenda *nuevo;
nuevo=(struct agenda*)malloc(sizeof(struct agenda));
if(nuevo==NULL){
printf("\n Memoria agotada");
return;
}
else{
printf("\nNombre: ");
fflush(stdin);
gets(nuevo->nom);
printf("\nTelefono: ");
fflush(stdin);
gets(nuevo->tel);
nuevo->siguiente=NULL;
}
if(primero==NULL){
primero=nuevo;
ultimo=nuevo;
}
else{
	ultimo->siguiente=nuevo;
	ultimo=nuevo;
}
}
void mostrar(){
	struct agenda *aux;
	aux=primero;
	if(aux==NULL){
		printf("\nlista vacia\n");
		return;
	}
	else{
		while(aux != NULL){
			printf("\nNombre: %s\n",aux->nom);
			printf("Telefono; %s\n",aux->tel);
			aux=aux->siguiente;
		}
	}
}

void borrar(){
	 struct agenda *aux =primero;
	 aux=primero;
	 if(primero==NULL){
	 	printf("\nVacia");
	 	return;
	 }
	 if(aux==ultimo){
            free(aux);
            primero=ultimo=NULL;
            }
	 else{
	 	while(aux->siguiente != ultimo){
	 		aux=aux->siguiente;
		 }
		 ultimo=aux;
		 free(aux->siguiente);
		 ultimo->siguiente=NULL;
	 }
}

