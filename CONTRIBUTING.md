  #include <stdio.h>
#include <stdlib.h>

int main ()
{
        int jugador=1,error,empate=0,ganar=0;
        char c1='1',c2='2',c3='3',c4='4',c5='5',c6='6',c7='7',c8='8',c9='9',tiro,marca,respuesta='y';

        do{

          error=1;

          system("cls");
          
          printf("JUEGO DEL TRES EN RAYA\n");
          printf("\n                        %c | %c | %c\n",c1,c2,c3);
          printf("                       ---|---|---");
          printf("\n                        %c | %c | %c\n",c4,c5,c6);
          printf("                       ---|---|---");
          printf("\n                        %c | %c | %c\n\n",c7,c8,c9);

          if(jugador==1)
          {
           marca='X';
          }

          else
          {
           marca='O';
          }

          printf("Turno del Jugador %d.",jugador);
          printf("\nEscribe la posicion donde colocar la ficha: ");

          fflush(stdin);

          scanf("%c",&tiro);

          if (tiro=='1' && c1=='1') {c1=marca;}
          else if (tiro=='2' && c2=='2') {c2=marca;}
          else if (tiro=='3' && c3=='3') {c3=marca;}
          else if (tiro=='4' && c4=='4') {c4=marca;}
          else if (tiro=='5' && c5=='5') {c5=marca;}
          else if (tiro=='6' && c6=='6') {c6=marca;}
          else if (tiro=='7' && c7=='7') {c7=marca;}
          else if (tiro=='8' && c8=='8') {c8=marca;}
          else if (tiro=='9' && c9=='9') {c9=marca;}
          else {printf("Error! Movimiento No Valido\n"); error=2;}

          if(c1=='X'||c1=='O')

          {

            if(c2==c1&&c3==c1)
             {
              ganar=1;
             }

            if(c4==c1&&c7==c1)
             {
              ganar=1;
             }
          }

          if(c5=='X'||c5=='O')
          {
                   if (c1 == c5 && c9 == c5)
                           {ganar=1;}
                   if (c2 == c5 && c8 == c5)
                           {ganar=1;}
                   if (c4 == c5 && c6 == c5)
                           {ganar=1;}
                   if (c3 == c5 && c7 == c5)
                           {ganar=1;}
            }
 
          if(c9=='X'||c9=='O')
          {
                     if (c6 == c9 && c3 == c9)
                             {ganar=1;}
                     if (c7 == c9 && c8 == c9)
                            {ganar=1;}
          }

          if ((c1 != '1' && c2 != '2' && c3 != '3' &&
              c4 != '4' && c5 != '5' && c6 != '6' &&
              c7 != '7' && c8 != '8' && c9 != '9') &&
              ganar == 0)
          {
              empate=1;
          }

          if (ganar==1||empate==1)
          {
              system("cls");
              if (ganar==1)
              {
                  printf("Jugador: %d Gana!\n\n",jugador);
                  printf("\n                         %c | %c | %c\n",c1,c2,c3);                                
                  printf("                        ---|---|---");
                  printf("\n                         %c | %c | %c\n",c4,c5,c6);
                  printf("                        ---|---|---");
                  printf("\n                         %c | %c | %c\n\n",c7,c8,c9);
              }
             
              if (empate==1)
              {
                  printf("Empate!\n",jugador);
                  printf("\n                         %c | %c | %c\n",c1,c2,c3);
                  printf("                        ---|---|---");
                  printf("\n                         %c | %c | %c\n",c4,c5,c6);
                  printf("                        ---|---|---");
                  printf(" \n                         %c | %c | %c\n\n",c7,c8,c9);   
              }
   
              printf("Jugar de Nuevo: Y/N ?\n");
   
              fflush(stdin);
   
              scanf("%c",&respuesta);
   
              if (respuesta=='y'||respuesta=='Y')
              {
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

          if(error==1)
          {
              if (jugador==1)
              {
               jugador=2;
              }
              else
              {
               jugador=1;
              }
          }

  }while(respuesta=='y'||respuesta=='Y');
 
  system("PAUSE");
  return 0;
}                                              
