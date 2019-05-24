#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <time.h>

void imprimir_tablero(int tablero[][15], int perder);
void colocar_bombas(int minas[][15], int bum);


int main(){

	//VARIABLES DEL MENU
	float a;
	char r1;

	//VARIABLES: TRES EN RAYA
	int jugador=1,error,empate=0,ganar=0;
	char c1='1',c2='2',c3='3',c4='4',c5='5',c6='6',c7='7',c8='8',c9='9',tirada,marca,respuesta='s';

	// VARIABLES: BUSCAMINAS
	int buscaminas[15][15] = {0}, i, j;
	int nivel, bombas;
	int gameStatus, gameCounter = 0, victoria;
	char salida;
	srand(time(NULL));

	// Ventana 1
	printf ("\n\n   SSSSSSS   AAAAAAA   LL      AAAAAAA          DDDDDD    EEEEEE\n   SSS       AA   AA   LL      AA   AA          DD  DDD   EE   \n   SSSSSSS   AAAAAAA   LL      AAAAAAA          DD  DDD   EEEE\n       SSS   AA   AA   LL      AA   AA          DD  DDD   EE   \n   SSSSSSS   AA   AA   LLLLLL  AA   AA          DDDDDD    EEEEEE\n\n\n     JJJJJJJ   UU   UU   EEEEEE   GGGGGGG   OOOOOOO    SSSSSSS\n          JJ   UU   UU   EE       GG        OO   OO    SSS    \n          JJ   UU   UU   EEEE     GG  GGG   OO   OO    SSSSSSS\n     JJ   JJ   UU   UU   EE       GG   GG   OO   OO        SSS\n     JJJJJJJ   UUUUUUU   EEEEEE   GGGGGGG   OOOOOOO    SSSSSSS\n\n\n   --------------  Presiona ENTER para continuar  --------------\n\n\n");
	system ("pause");

	do{
		do{
		// Ventana 2
		system ("cls");
		printf ("\n   MENU DE SELECCION\n\n   	1) TRES EN RAYA\n\n   	2) BUSCAMINAS\n\n\n   (Pulsa 1 para jugar al TRES EN RAYA)\n\n   (Pulsa 2 para jugar al BUSCAMINAS)\n\n\n   ");
		scanf ("%f", &a);
		fflush (stdin);

		system ("cls");

		// 1º Juego
			if (a == 1){

	    		do{
					error=1;
					system("cls");
					printf("TRES EN RAYA\n");
					printf("\n                        %c | %c | %c\n",c1,c2,c3);
					printf("                       ---|---|---");
					printf("\n                        %c | %c | %c\n",c4,c5,c6);
					printf("                       ---|---|---");
					printf("\n                        %c | %c | %c\n\n",c7,c8,c9);
					
				if(jugador==1){
					marca='X';
				}
				else{
					marca='O';
				}
				printf("Turno del Jugador %d.",jugador);
				printf("\nEscribe la posicion donde colocar la ficha: ");

				fflush(stdin);
				scanf("%c",&tirada);

				if (tirada=='1' && c1=='1') {c1=marca;}
				else if (tirada=='2' && c2=='2') {c2=marca;}
				else if (tirada=='3' && c3=='3') {c3=marca;}
				else if (tirada=='4' && c4=='4') {c4=marca;}
				else if (tirada=='5' && c5=='5') {c5=marca;}
				else if (tirada=='6' && c6=='6') {c6=marca;}
				else if (tirada=='7' && c7=='7') {c7=marca;}
				else if (tirada=='8' && c8=='8') {c8=marca;}
				else if (tirada=='9' && c9=='9') {c9=marca;}
				else {printf("Error! Movimiento no valido\n"); error=2;}

				if(c1=='X'||c1=='O'){
					if(c2==c1&&c3==c1){
						ganar=1;
					}

					if(c4==c1&&c7==c1){
					ganar=1;
					}
				}

				if(c5=='X'||c5=='O'){
					if (c1 == c5 && c9 == c5){
						ganar=1;
					}
					if (c2 == c5 && c8 == c5){
						ganar=1;
					}
					if (c4 == c5 && c6 == c5){
						ganar=1;
					}
					if (c3 == c5 && c7 == c5){
						ganar=1;
					}
		        }

				if(c9=='X'||c9=='O'){
					if (c6 == c9 && c3 == c9){
						ganar=1;
					}
					if (c7 == c9 && c8 == c9){
						ganar=1;
					}
				}

				if ((c1 != '1' && c2 != '2' && c3 != '3' && c4 != '4' && c5 != '5' && c6 != '6' && c7 != '7' && c8 != '8' && c9 != '9') && ganar == 0){
		          empate=1;
				}

				if (ganar==1||empate==1){
					system("cls");
					if (ganar==1){
		              printf("Jugador: %d Gana!\n\n",jugador);
		              printf("\n                         %c | %c | %c\n",c1,c2,c3);
		              printf("                        ---|---|---");
		              printf("\n                         %c | %c | %c\n",c4,c5,c6);
		              printf("                        ---|---|---");
		              printf("\n                         %c | %c | %c\n\n",c7,c8,c9);
		        	}

					if (empate==1){
		              printf("Empate!\n",jugador);
		              printf("\n                         %c | %c | %c\n",c1,c2,c3);
		              printf("                        ---|---|---");
		              printf("\n                         %c | %c | %c\n",c4,c5,c6);
		              printf("                        ---|---|---");
		              printf(" \n                         %c | %c | %c\n\n",c7,c8,c9);
		        	}

			    //CREACION DEL 1º FICHERO
				FILE *f;
				f = fopen("TRES_EN_RAYA.txt","a");
				if(f == NULL){
					printf("Error al abrir el fichero.\n");
				}
				else{
	
	
				fprintf(f, "El ganador es: jugador %i\n", jugador);
				fclose(f);
				}


				printf("Quiere repetir de nuevo? Si (S) y No (pulse cualquier letra) ?\n\n");
				fflush(stdin);
				scanf("%c",&respuesta);
				fflush(stdin);

					if (respuesta=='s'||respuesta=='S' || respuesta=='n'||respuesta=='N' ){
		            	empate=0;
		            	jugador=2;
		           		ganar=0;
		            	c1='1';
		            	c2='2';
		            	c3='3';
		            	c4='4';
	    	        	c5='5';
	            		c6='6';
	            		c7='7';
	            		c8='8';
	            		c9='9';
					}
	      		}
	      		
					if(error==1){
						if (jugador==1){
							jugador=2;
						}
						else{
							jugador=1;
						}
					}

			}while(respuesta =='s'||respuesta =='S');

			}


		// 2º Juego
			if( a == 2){

				do{
                    gameStatus = 0;
				    system("cls");
				    printf("BUSCAMINAS\n\n");
				    printf("Introduce el nivel del juego:\n\n Nivel 1 (10 BOMBAS)\n Nivel 2 (15 BOMBAS)\n Nivel 3 (20 BOMBAS)\n Nivel 4 (25 BOMBAS)\n Nivel 5 (30 BOMBAS)\n Nivel 6 (PRUEBA)\n\n");


					do{

						scanf("%i", &nivel);
				    	fflush(stdin);

				    	switch(nivel){

				        	case 1: bombas = 10;
									break;

				        	case 2: bombas = 15;
				                	break;

				        	case 3: bombas = 20;
				                	break;

				        	case 4: bombas = 25;
				                	break;

				        	case 5: bombas = 30;
				                	break;
				            
				            case 6: bombas = 200;
				            		break;
				            

				        	default: printf("Lo sentimos, por el momento solo disponemos de 6 niveles.\n\n");
				                    break;

				   	    }
					}while(nivel!=1 && nivel!=2 && nivel!=3 && nivel!=4  && nivel!=5 && nivel!=6);


				    colocar_bombas(buscaminas, bombas);
					
					do{

			           system("cls");
			           printf("\nBUSCAMINAS\n\n");

			           imprimir_tablero(buscaminas, gameStatus); // 1º Función 

			           printf("\n  (i es el valor para las filas)\n  (j es el valor para las columnas)\n");
			           
						do{
				           printf("\n  Ingrese la tirada[i, j]: ");
				           scanf("%d%d",&i, &j);
				           fflush(stdin);
				           
				           if((i<0||i>14)||(j<0||j>14)){
	                        printf("tirada no valida , ingresela de nuevo \n");
				           }
						}while((i<0||i>14)||(j<0||j>14));
						
			        	if(buscaminas[i][j] == 3){
			            	gameStatus = -1;
			             
			            	system("cls");
			            	printf("\nBUSCAMINAS\n\n");
			            	imprimir_tablero(buscaminas, gameStatus); // 2º Función
			            	printf("\n\n GAME OVER, el juego ha terminado...");

			            	getch();
			        	}
			        	else
			        	{
			            	buscaminas[i][j] = 1;
			            	gameCounter++;
			           }
			           
			           if(gameCounter == (225 - bombas) ){
			            	victoria = 1;
			            	system("cls");
			            	printf("\nBUSCAMINAS\n\n");
			            	imprimir_tablero(buscaminas, gameStatus);
			            	printf("\n\n Has ganado, felicidades!");

			            	getch();
			        	}

				    }while(gameStatus != -1 || victoria == 1);

				    	gameCounter = 0;

				    //CREACION DEL 2º FICHERO
					FILE *f;
					f = fopen("BUSCAMINAS.txt","a");
					if(f == NULL){
						printf("Error al abrir el fichero.\n");
					}
					else{
		
		
					fprintf(f, "Has jugado en el nivel %i\n", nivel);
					fclose(f);
					}

					printf("\n\n Desea jugar de nuevo(S/N)?: ");
			    	scanf("%c", &salida);
			    	fflush(stdin);
			    	salida = tolower(salida);

				    if(salida == 's'|| salida == 'S'){
				    	for(i = 0; i <= 15 - 1; i++) for(j = 0; j <= 15 - 1; j++) buscaminas[i][j] = 0;
					}

				}while(salida == 's'|| salida == 'S');

				getch();
			}

			if (a != 1 && a != 2){
				printf("\n Lo sentimos, pero por el momento no disponemos de mas juegos.\n\n");
				system("pause");
			}


		}while(a!=1 && a!=2);

		printf("\n\n Desea volver al Menu inicial? si es asi pulse (M)\n\n");
		scanf("%c",&r1);
		fflush(stdin);

	}while (r1 == 'm' || r1 == 'M');

return 0;
}

// Funciones

void colocar_bombas(int minas[][15], int bum){
	
    int i , j , renglon, columna;
    for(i=0;i<15;i++){
        for(j=0;j<15;j++){
            minas[i][j]=0;
        }
    }

    do{
        renglon = 0 + rand() % 14;
        columna = 0 + rand() % 14;
        if(minas[renglon][columna]!=3){
        minas[renglon][columna] = 3;
        bum--;
        }
    }while(bum);
}


void imprimir_tablero(int tablero[][15], int perder){
	
    int i, j;
	for(i = 0; i <= 15 -1; i++){
       printf("%d ", i);
	}
    printf("\n");

    for(i = 0; i <= 15 - 1; i++){
    printf("--");
	}
    
	printf("\n");

    for(i = 0; i <= 15 -1; i++){
        for(j = 0; j <= 15 - 1; j++){

            if(tablero[i][j] == 1)
            	printf("%d ", tablero[i][j]);
            else if((tablero[i][j] == 3) && (perder == -1))
            	printf("%c ", '*');
            else
            	printf("%c ", '#');
           }

        printf("| %d", i);
        printf("\n");

    }
}



