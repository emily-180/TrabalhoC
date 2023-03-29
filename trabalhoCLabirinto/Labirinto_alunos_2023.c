#include <stdio.h>
#include "bibliotecaPilhaEncadeada.h"
#include <stdlib.h>
#define MAX 20

void criaLabirinto(char labirinto[MAX][MAX]){
     int i,j,x,y;
     srand(time(NULL));
     for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++){
          if((rand()%5)==1)
             labirinto[i][j]='|';
             else
              labirinto[i][j]='.';
          }
     for(i=0;i<MAX;i++){
           labirinto[0][i]='*';
           labirinto[MAX-1][i]='*';
           labirinto[i][0]='*';
           labirinto[i][MAX-1]='*';
           }// fim for
        x=  (rand() % MAX-2) +1;
        labirinto[x][19]='S';
     }// fim funcao cria
//-------------------------------------------     
void printLabirinto(char labirinto[MAX][MAX]){
    int i,j;
     for ( i = 0; i < MAX; i++){
     	 printf("\n");
        for ( j = 0; j < MAX; j++)
			printf (" %c ",labirinto[i][j] );
    }

} // fim funcao
//-------------------------------------------
     
 int buscaSaida(char lab[MAX][MAX],int i, int j){
        tPilha p1;
        inicializa(&p1);
        tdado atual;
        while(1){
        	lab[i][j]=1; //marcando que já passei nesse ponto
        	atual.x = i;
        	atual.y = j;
        	if(lab[i][j+1] == '.' || lab[i][j+1] == 'S'){
        	    push(&p1, atual);  //guarda na pilha
        		j++;
			}
			else if(lab[i+1][j]  == '.' || lab[i+1][j] == 'S'){
        		push(&p1, atual);  //guarda na pilha
        		i++;
			}
			else if(lab[i][j-1] == '.' || lab[i][j-1] == 'S' ){
        		push(&p1, atual);  //guarda na pilha
        		j--;
			}
			else if(lab[i-1][j] == '.' || lab[i-1][j] == 'S'){
        		push(&p1, atual);  //guarda na pilha
        		i--;
			}
			else if(!isEmpty){
				atual = pop(&p1);
				i= atual.x;
				j=atual.y;
				lab[i][j]=2;		
			}
			
				// else impossivel
			Sleep(500); //pausa
			system("cls"); //limpa
			printLabirinto(lab); //mostra
			printf("%d - %d", i,j);
		}//fim while
        return 1;
 }// fim funcao

//-------------------------------------------
int main(){
    char meuLabirinto[MAX][MAX];
    int x,y;
    criaLabirinto(meuLabirinto);
    printLabirinto(meuLabirinto);
    printf("\nEntre com a posicao inicial do robo:");
    scanf("%d %d",&x,&y);
    buscaSaida(meuLabirinto,x,y);
    getch();
    return 0;
}
