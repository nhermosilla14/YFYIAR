/*
 * YFYIAR - Clon libre del juego flash "You Find Yourself In A Room"
 * 
 * Copyright 2013 Nicolás Hermosilla P. <nhermosilla14@gmail.com>
 * 
 * Idea original por Eli Piilonen
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
/*cntcat despliega en pantalla el contenido de un fichero
 de texto plano, centrando cada linea*/
void cntcat(char archivo[15])
{
  FILE *fr;
  char linea[80];
  fr = fopen(archivo, "rt");
  while (fgets(linea, 80, fr) != NULL)
  {
    int i=1;
    int numofch = strlen(linea);
    while (i<(40-(numofch/2)))
		{
		printf(" ");
		i++;
		}
    printf(linea); 
  }
  fclose(fr);
}
/*Control de respuesta. Entrega un valor comparando una respuesta 
  con dos valores correctos posibles. Si es verdadero, entrega 1, si es falso
  entrega 0*/
int ctrlresp(char resp[25], char correcta1[15], char correcta2[15])
{
if ( (strcmp(resp,correcta1) == 0) || (strcmp(resp, correcta2) == 0))
  {
	return 1;  
 }
 else
 {
	return 0; 
	}	
}
/*cat hace lo mismo que la función estándar cat en sistemas *nix, esto es,
  despliega el contenido de un fichero de texto en pantalla*/
void cat(char archivo[15])
{
  FILE *fr;
  char linea[80];
  fr = fopen(archivo, "rt");
  while (fgets(linea, 80, fr) != NULL)
  {
   printf(linea); 
  }
  fclose(fr);
  puts("\n");
}

void clrscr() /*Borra la pantalla en terminales ANSI. 
Evita dependencias de llamadas a funciones del sistema, lo que vuelve el código portable*/
{
	
	fprintf(stdout, "\033[2J");
	fprintf(stdout, "\033[1;1H"); 
}

int main()
{	
	char respuesta[25];
	char respuesta0[25]={0};
	clrscr();
	cat("base/es/bienvenida");
	getchar();
	clrscr(); 
	cntcat("base/es/bienvenida1");
	getchar();
	clrscr();
	cntcat("base/es/bienvenida2");
	getchar();
	clrscr();
	cntcat("base/es/R1/status");
	printf("\n");
	printf(">");
	int avance = 0; /*Evita trampas*/
	/*Primera habitación*/
	while (1){
		//strcpy(respuesta, NULL);
	    fgets(respuesta,25,stdin);
	    if ( ctrlresp(respuesta, "ayuda\n", "AYUDA\n") == 1 )
	{
		cntcat("base/es/ayuda");
		printf("\n");
		printf(">");
		continue;
		}
	if ( ((ctrlresp(respuesta, "mirar\n", "MIRAR\n")) == 1) || ((ctrlresp(respuesta,"mirar alrededor\n","MIRAR ALREDEDOR\n")) == 1) )
	{
		if ( avance >= 0 )
		{
		cntcat("base/es/R1/mirar");
		printf("\n");
		printf(">");
		if (avance < 1) avance++;
		continue;
		}	
	 }
	    
	
	if ((ctrlresp(respuesta,"mirar cama\n","MIRAR CAMA\n")) == 1)
	{
		if ( avance >= 1 )
		{
		cntcat("base/es/R1/mirar_cama");
		printf("\n");
		printf(">");
		if (avance < 2) avance++;
		continue;
		}	
	}
	if ((ctrlresp(respuesta,"mirar caja\n","MIRAR CAJA\n")) == 1)
	{
		if ( avance >= 1 )
		{
		cntcat("base/es/R1/mirar_caja");
		printf("\n");
		printf(">");
		continue;
		}	
	}
	if ((ctrlresp(respuesta,"tomar llave\n", "TOMAR LLAVE\n")) == 1)
	{
		if ( avance >= 2 )
		{
		cntcat("base/es/R1/tomar_llave");
		printf("\n");
		printf(">");
		if (avance < 3) avance++;
		continue;
		}	
	}
	
	if (((ctrlresp(respuesta,"inventario\n","INVENTARIO\n")) == 1) || ((ctrlresp(respuesta,"inv\n","INV\n")) == 1) || ((ctrlresp(respuesta,"i\n","I\n")) == 1))
	{
		if ( avance >= 3 )
		{
		cntcat("base/es/R1/inv");
		printf("\n");
		printf(">");
		continue;
		}	
	}
	
	 if ( (ctrlresp(respuesta, "ABRIR CANDADO\n", "abrir candado\n")) == 1 ){
		if ( avance >= 3 )
		{
		cntcat("base/es/R1/abrir_candado");
		printf("\n");
		printf(">");
		if (avance < 4) avance++;
		continue;
		}	
		}
	 if ( (ctrlresp(respuesta, "ENTRAR CAJA\n", "entrar caja\n")) == 1 )
	 {
		 if (avance >= 4)
		 {
			avance++;
			break;
		 }
	 }
	 /*Esto debe ir al final, para evitar que salga del juego*/
		{
		
		int rnd=rand() % 3;
		if (rnd == 0) cntcat("base/es/error0");
		if (rnd == 1) cntcat("base/es/error1");
		if (rnd == 2) cntcat("base/es/error2");
		printf("\n");
		printf(">");	
		
		}
		/*Hasta acá llega el else final*/
	}
	/*Segunda habitación*/ 
	cntcat("base/es/R2/status");
	printf("\n");
	printf(">");
	int a=0;
	int b=0;
	int c=0;
	char control[10];
	while (1)
	{
	fgets(respuesta,25,stdin);
	a=sscanf(respuesta,"%s%d", control, &b);
	if (a==1) sscanf(control,"%d",&c);
	if ( ctrlresp(respuesta, "ayuda\n", "AYUDA\n") == 1 )
	{
		cntcat("base/es/ayuda");
		printf("\n");
		printf(">");
		continue;
		}
	if ( ((ctrlresp(respuesta, "mirar\n", "MIRAR\n")) == 1) || ((ctrlresp(respuesta,"mirar alrededor\n","MIRAR ALREDEDOR\n")) == 1) )
	{
		if ( avance >= 5 )
		{
		cntcat("base/es/R2/mirar");
		printf("\n");
		printf(">");
		if (avance < 6) avance++;
		continue;
		}	
	 }	
	
	if ( ((ctrlresp(respuesta, "mirar teclado\n", "MIRAR TECLADO\n")) == 1) )
	{
		if ( avance >= 6 )
		{
		cntcat("base/es/R2/mirar_teclado");
		printf("\n");
		printf(">");
		if (avance < 7) avance++;
		continue;
		}	
	 }
	if ( (a>1) && (b>0) && (avance>=7) )
	{
		cntcat("base/es/R2/ingresar");
		printf("\n");
		printf(">");
		continue;
	}
	if ( (a==1) && (c>0) && (avance>=7) )
	{
		if (c == 1907)
		{
		break;
		}
		else
		{
		cntcat("base/es/R2/ingreso_fallido");
		printf("\n");
		printf(">");
		continue;	
		}
	}
	 if ( ((ctrlresp(respuesta, "leer nota\n", "LEER NOTA\n")) == 1) )
	{
		if ( avance >= 6 )
		{
		cntcat("base/es/R2/leer_nota");
		printf("\n");
		printf(">");
		continue;
		}	
	 }		
	 
	 {
		
		int rnd=rand() % 3;
		if (rnd == 0) cntcat("base/es/error0");
		if (rnd == 1) cntcat("base/es/error1");
		if (rnd == 2) cntcat("base/es/error2");
		printf("\n");
		printf(">");	
		
		}
		
	}
	/*Tercera habitación*/
	cntcat("base/es/R3/status");
	printf("\n");
	printf(">");
	while (1)
	{
		fgets(respuesta,25,stdin);
		if ( ctrlresp(respuesta, "ayuda\n", "AYUDA\n") == 1 )
		{
		cntcat("base/es/ayuda");
		printf("\n");
		printf(">");
		continue;
		}
		if ( ((ctrlresp(respuesta, "mirar\n", "MIRAR\n")) == 1) || ((ctrlresp(respuesta,"mirar alrededor\n","MIRAR ALREDEDOR\n")) == 1) )
	{
		if ( avance >= 7 )
		{
			cntcat("base/es/R3/mirar");
			printf("\n");
			printf(">");
			if (avance < 8) avance++;
			continue;
		}	
	 }
	 if ( ((ctrlresp(respuesta, "mirar piezas\n", "MIRAR PIEZAS\n")) == 1) )
	{
		if ( avance >= 8 )
		{
			cntcat("base/es/R3/mirar_partes");
			printf("\n");
			printf(">");
			continue;
		}	
	 }
	  if ( ((ctrlresp(respuesta, "tomar cpu\n", "TOMAR CPU\n")) == 1) || ((ctrlresp(respuesta, "tomar disco duro\n", "TOMAR DISCO DURO\n")) == 1) || ((ctrlresp(respuesta, "TOMAR TARJETA MADRE\n", "tomar tarjeta madre\n")) == 1) || ((ctrlresp(respuesta, "TOMAR CABLES\n", "tomar cables\n")) == 1) )
	{
		if ( avance >= 8 )
		{
			cntcat("base/es/R3/partes");
			printf("\n");
			printf(">");
			continue;
		}	
	 }
	  if ( ((ctrlresp(respuesta, "tomar piezas\n", "TOMAR PIEZAS\n")) == 1) )
	{
		if ( avance >= 8 )
		{
			cntcat("base/es/R3/tomar_partes");
			printf("\n");
			printf(">");
			if (avance < 9) avance++;
			continue;
		}	
	 }
	 if (((ctrlresp(respuesta,"inventario\n","INVENTARIO\n")) == 1) || ((ctrlresp(respuesta,"inv\n","INV\n")) == 1) || ((ctrlresp(respuesta,"i\n","I\n")) == 1))
	{
		if ( avance >= 9 )
		{
			cntcat("base/es/R3/inv");
			printf("\n");
			printf(">");
			continue;
		}	
	 }
	  if ( ((ctrlresp(respuesta, "armar computador\n", "ARMAR COMPUTADOR\n")) == 1) || ((ctrlresp(respuesta, "armar pc\n", "ARMAR PC\n")) == 1) )
	{
		if ( avance >= 9 )
		{
			cntcat("base/es/R3/armar_pc0");
			printf("\n");
			printf(">");
			if (avance < 10) avance++;
			continue;	
		}
		else
		{
			if (avance >=8)
			{
			cntcat("base/es/R3/armar_pc");
			printf("\n");
			printf(">");
			continue;	
			}
		}	
	 }	
	 if ( ((ctrlresp(respuesta, "encender\n", "ENCENDER\n")) == 1) )
	{
		if ( avance >= 10 )
		{	avance++;
			break;
		}	
	 }
	 {
		
		int rnd=rand() % 3;
		if (rnd == 0) cntcat("base/es/error0");
		if (rnd == 1) cntcat("base/es/error1");
		if (rnd == 2) cntcat("base/es/error2");
		printf("\n");
		printf(">");	
		
		}		
	}
	/*Cuarta habitación*/
	cntcat("base/es/R4/status");
	printf("\n");
	printf(">");
	b=0;
	c=0;
	while (1)
	{
		fgets(respuesta,25,stdin);
		sscanf(respuesta, "%d", &c);
		if ( ctrlresp(respuesta, "ayuda\n", "AYUDA\n") == 1 )
		{
		cntcat("base/es/ayuda");
		printf("\n");
		printf(">");
		continue;
		}
		if ( ((ctrlresp(respuesta, "mirar\n", "MIRAR\n")) == 1) || ((ctrlresp(respuesta,"mirar alrededor\n","MIRAR ALREDEDOR\n")) == 1) )
	{
		if ( avance >= 11 )
		{
			cntcat("base/es/R4/mirar");
			printf("\n");
			printf(">");
			if (avance < 12) avance++;
			continue;
		}	
	 }
	 if ( ((ctrlresp(respuesta, "mirar teclado\n", "MIRAR TECLADO\n")) == 1) )
	{
		if ( avance >= 12 )
		{
		cntcat("base/es/R4/mirar_teclado");
		printf("\n");
		printf(">");
		if (avance < 13) avance++;
		continue;
		}	
	 }
	 if ( (avance>=13) && (strcmp(respuesta, "\n") != 0 ) && (strcmp(respuesta,respuesta0) != 0) && (c > 0) )
	{
		if (avance==13) cntcat("base/es/R4/intento0");
		if (avance==14) cntcat("base/es/R4/intento1");
		if (avance==15) cntcat("base/es/R4/intento2");
		if (avance==16) cntcat("base/es/R4/intento3");
		if (avance==17) break;
		avance++;
		c=0;
		strcpy(respuesta0, respuesta);
		printf("\n");
		printf(">");
		continue;
	}
	
	if ( (avance>=13) && (strcmp(respuesta, "\n") != 0 ) && (strcmp(respuesta,respuesta0) == 0) )
	{
		if (b==0) cntcat("base/es/R4/repetido0");
		if (b>=1) cntcat("base/es/R4/repetido1");
		strcpy(respuesta0, respuesta);
		b++;
		printf("\n");
		printf(">");
		continue;
	}
		
		{
		
		int rnd=rand() % 3;
		if (rnd == 0) cntcat("base/es/error0");
		if (rnd == 1) cntcat("base/es/error1");
		if (rnd == 2) cntcat("base/es/error2");
		printf("\n");
		printf(">");	
		
		}	
	}
	/*Quinta habitación*/
	cntcat("base/es/R5/status");
	printf("\n");
	printf(">");
	while (1)
	{
	fgets(respuesta,25,stdin);
	if ( ctrlresp(respuesta, "ayuda\n", "AYUDA\n") == 1 )
		{
		cntcat("base/es/ayuda");
		printf("\n");
		printf(">");
		continue;
		}
		
	if ( ((ctrlresp(respuesta, "mirar\n", "MIRAR\n")) == 1) || ((ctrlresp(respuesta,"mirar alrededor\n","MIRAR ALREDEDOR\n")) == 1) )
	{
		if ( avance >= 17 )
		{
			cntcat("base/es/R5/mirar");
			printf("\n");
			printf(">");
			if (avance < 18) avance++;
			continue;
		}	
	 }	
	 if ((strcmp(respuesta,"\n")) != 0)
	 if (( avance >=18 ) || ( avance <=27))
	 {
		{
		    if (avance == 18) cntcat("base/es/R5/intento0");
		    if (avance == 19) cntcat("base/es/R5/intento1");
		    if (avance == 20) cntcat("base/es/R5/intento2");
		    if (avance == 21) cntcat("base/es/R5/intento3");
		    if (avance == 22) cntcat("base/es/R5/intento4");
		    if (avance == 23) cntcat("base/es/R5/intento5");
		    if (avance == 24) cntcat("base/es/R5/intento6");
		    if (avance == 25) cntcat("base/es/R5/intento7");
		    if (avance == 26) cntcat("base/es/R5/intento8");
		    if (avance == 27) 
		    {
				cntcat("base/es/R5/intento9");
				printf("\n");
				printf(">");
				break;
			}			
			printf("\n");
			printf(">");
			avance++;
			continue;
		}
	 }	
	}
	/*Número entre 1 y 100000*/
	srand(time(NULL));
	a=(rand()%100000)+1;
	b=0;
	c=0;
	while (1)
	{	
		fgets(respuesta,25,stdin);
		b=sscanf(respuesta, "%d", &c);
		if ( (b!=1) || (c==0) )
		{
		    cntcat("base/es/R5/sintax_error");
		    printf("\n");
		    printf(">");
		    continue;
		}
		if ( (b==1) && ((c>100000) || (c<1)) )
		{
		    cntcat("base/es/R5/num_error");
		    printf("\n");
		    printf(">");
		    continue;
		}
		if ( (b==1) && (c>a) )
		{
		    cntcat("base/es/R5/num_grande");
		    printf("\n");
		    printf(">");
		    continue;
		}
		if ( (b==1) && (c<a) )
		{
		    cntcat("base/es/R5/num_chico");
		    printf("\n");
		    printf(">");
		    continue;
		}
		if ( (b==1) && (c==a) ) break;
	}
	/*Sexta Habitación*/
	cntcat("base/es/R6/status");
	printf("\n");
	printf(">");
	while (1){
		fgets(respuesta,25,stdin);
		if ( ctrlresp(respuesta, "ayuda\n", "AYUDA\n") == 1 )
			{
			cntcat("base/es/ayuda");
			printf("\n");
			printf(">");
			continue;
			}
		if ( ((ctrlresp(respuesta, "mirar\n", "MIRAR\n")) == 1) || ((ctrlresp(respuesta,"mirar alrededor\n","MIRAR ALREDEDOR\n")) == 1) )
		{
			if ( avance == 27 )
			{
				cntcat("base/es/R6/mirar");
				printf("\n");
				printf(">");
				if (avance < 28) avance++;
				continue;
			}
			if ( avance >= 28 ){
				cntcat("base/es/R6/mirar0");
				printf("\n");
				printf(">");
				if (avance < 29) avance++;
				continue;
			}			
		}
		if ((ctrlresp(respuesta, "mirar sangre\n", "MIRAR SANGRE\n")) == 1) {
			if (avance >= 29){
				cntcat("base/es/R6/mirar_sangre");
				printf("\n");
				printf(">");
				if (avance < 30) avance++;
				continue;
			}
		}
		if ( ((ctrlresp(respuesta, "felicidad\n", "FELICIDAD\n")) == 1) || ((ctrlresp(respuesta,"miedo\n","MIEDO\n")) == 1)  || ((ctrlresp(respuesta,"tristeza\n","TRISTEZA\n")) == 1) || ((ctrlresp(respuesta,"compasión\n","COMPASIÓN\n")) == 1) || ((ctrlresp(respuesta,"alegría\n","ALEGRÍA\n")) == 1) || ((ctrlresp(respuesta,"fe\n","FE\n")) == 1))
		{
			if ( avance == 30 ){
				cntcat("base/es/R6/trivial");
				printf("\n");
				printf(">");
				continue;
			}
		}
		if ((ctrlresp(respuesta, "odio\n", "ODIO\n")) == 1) {
			if (avance == 30){
				cntcat("base/es/R6/odio");
				printf("\n");
				printf(">");
				if (avance < 31) avance++;
				continue;
			}
		}
		if (avance == 31) {
			cntcat("base/es/R6/ultimo");
			printf("\n");
			printf(">");
			if (avance < 32) avance++;
			continue;
		}
		if ((ctrlresp(respuesta, "salir\n", "SALIR\n")) == 1) {
			if (avance == 32){
				cntcat("base/es/R6/fin");
				printf("\n");
				printf(">");
				getchar();
				cntcat("base/es/R6/creditos");
				getchar();
				break;
			}
		}
		int rnd=rand() % 3;
		if (rnd == 0) cntcat("base/es/error0");
		if (rnd == 1) cntcat("base/es/error1");
		if (rnd == 2) cntcat("base/es/error2");
		printf("\n");
		printf(">");	
	}
	return 0;
}

