/*
Arreglos Bidimensionales de calificaciones de alumnos utilizando matrices para su visualizacion
*/

#include "stdio.h"
#include "conio.h"
#include "windows.h"
#include "stdlib.h"

float calificaciones[5][5];
const char *alumnos[5] = { "Pedro", "Manuel", "Marina", "Renata", "Ruben" };
const char *materias[5] = { "Historia", "Calculo", "Sociales", "Biologia","Etica"};
void capturar ();
void mostrar ();
void promalumnos ();
void prommaterias ();
void mejoralumno ();
void mejorprom ();
void promgeneral ();



int main()
{
    char op;
    do{
        do{
        system("cls");
        printf("\n\n\tMen%c Calificaciones <Array Bidimensional>\n\n",163);
        printf("\t[F1] Capturar calificaciones\n\t[F2] Mostrar calificaciones\n\t[F3] Promedio de los Alumnos\n\t[F4] Promedio por Materias");
        printf("\n\t[F5] Mejor Alumno\n\t[F6] Mejor promedio por materia\n\t[F7] Promedio General\n\tESC. Salir\n\n");
        printf("\tSeleccione una opcion: ");
        op = getch();//Al presionar la tecla generara el numero correspondiente al Codigo ASCII
        if(op==0)
		    {
			    op=getch();
				system("cls");
				if((op!=59)&&(op!=60)&&(op!=61)&&(op!=62)&&(op!=63)&&(op!=64)&&(op!=65)&&(op!=27))
				{
				    printf("\n Tecla erronea\n");
					getch();
				 }
			}				
	}while((op!=59)&&(op!=60)&&(op!=61)&&(op!=62)&&(op!=63)&&(op!=64)&&(op!=65)&&(op!=27));//Condicion para Especificar que es incorrecto
        switch(op)
		{
			//Opciones del menu y llamada de funciones
		    case 59:
            capturar (); 
			break;
            case 60: 
            mostrar ();
			break;			
			case 61: 
            promalumnos ();
			break;			
			case 62: 
            prommaterias ();
			break;						
			case 63: 
            mejoralumno ();
			break;						
			case 64: 
            mejorprom ();
			break;						
			case 65: 
            promgeneral ();
			break;
			case 27:
			exit(0);
			break;	
	    }			
    }while(1);
}

void capturar ()//Funcion de capturar
{ 
    system("cls");
	int f, c;
	fflush(stdin);//Limpieza de buffer
	for(f=0; f<5; f++)//Recorrido de filas y alumnos
	{
		//Impresion para calificaciones segun el alumno
		if(f==0)
		printf("Ingresa las calificaciones de %s\n",alumnos[f]);
		if(f==1)
		printf("Ingresa las calificaciones de %s\n",alumnos[f]);
		if(f==2)
		printf("Ingresa las calificaciones de %s\n",alumnos[f]);
		if(f==3)
		printf("Ingresa las calificaciones de %s\n",alumnos[f]);
		if(f==4)
		printf("Ingresa las calificaciones de %s\n",alumnos[f]);
		for(c=0; c<5; c++)//Recorrido de materias y comlumnas
		{
			//Impresion para las calificacion de cada materia
			if(c==0)
			printf("%s ",materias[c]);
			if(c==1)
			printf("%s ",materias[c]);
			if(c==2)
			printf("%s ",materias[c]);
			if(c==3)
			printf("%s ",materias[c]);
			if(c==4)
			printf("%s ",materias[c]);
			scanf("%f",&calificaciones[f][c]);//Almacenamiento de calificaciones 	
		}
	}
	system("pause");
}


void mostrar ()//Funcion para la impresion de pantalla de los resultados
{	
	system("cls"); // limpieza de la pantalla
	int f=0,c;
	printf("CALIFICACIONES\n\n");
	printf("\t\t");
	for(int x=0; x<5; x++)//Recorrido arreglo de materias
	{
		printf("%s \t",materias[x]);
	}printf("\n");
	for(f=0; f<5; f++)//Recorrido de alumnos y calificaciones
	{
		printf("%s\t\t",alumnos[f]);//Impresion nombre de alumnos
		for(c=0; c<5; c++)
		{
			printf("%.0f\t\t",calificaciones[f][c]);//Impresion de calificaciones
		}printf("\n");
	}
	system("pause");
}

void promalumnos ()
{
	int f, c; // variables para el control de las filas y comlumnas 
    
    {   
		system("cls");
        float suma=0,proma; // la variable suma guarda el total de las sumas de las calificaciones  y proma calcula el promedio
        printf ("\n PROMEDIO PARA CADA UNO DE LOS ALUMNOS");
	    printf ("\n Promedio de pedro: ");
		f=0; // se empieza en la fila 0 de la matriz
		for(c=0; c<5; c++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf (" %.2f",proma); // impresion del promedio
	}
	{
	    float suma=0,proma;
	    printf ("\n Promedio de Manuel: ");
		f=1; // se empieza en la fila 1 de la matriz
		for(c=0; c<5; c++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf (" %.2f",proma); // impresion del promedio
    }
	{
        float suma=0,proma;
	    printf ("\n Promedio de Marina: ");
		f=2; // se empieza en la fila 2 de la matriz
		for(c=0; c<5; c++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf ("%.2f",proma); // impresion del promedio
    }
	{
       	float suma=0,proma;
	    printf ("\n Promedio de Renata: ");
		f=3; // se empieza en la fila 3 de la matriz
		for(c=0; c<5; c++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf ("%.2f",proma); // impresion del promedio

    }
	{
		float suma=0,proma;
	    printf ("\n Promedio de Ruben: ");
		f=4; // se empieza en la fila 4 de la matriz
		for(c=0; c<5; c++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf ("%.2f",proma); // impresion del promedio
	}
	system("pause");
}

void prommaterias ()
{
	system("cls"); // limpieza de la pantalla
    int f, c; // variables para el control de las filas y comlumnas 
    {   
		system("cls");
        float suma=0,proma; // la variable suma guarda el total de las sumas de las calificaciones  y proma calcula el promedio
	    printf ("\n PROMEDIO PARA CADA UNA DE LAS MATERIAS");
	    printf ("\n Historia");
		c=0; // se empieza por la columna 0 de la matriz
		for(f=0; f<5; f++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf (" %.2f",proma); // impresion del promedio
	}
	{
	    float suma=0,proma;
	    printf ("\n Calculo: ");
		c=1;  // se empieza por la columna 1 de la matriz
		for(f=0; f<5; f++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf (" %.2f",proma); // impresion del promedio

    }
	{
        float suma=0,proma;
	    printf ("\n Sociales: ");
		c=2;  // se empieza por la columna 2 de la matriz
		for(f=0;  f<5; f++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf ("%.2f",proma); // impresion del promedio

    }  
	{
       	float suma=0,proma;
	    printf ("\n Biologia: ");
		c=3;  // se empieza por la columna 3 de la matriz
		for(f=0; f<5; f++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf ("%.2f",proma); // impresion del promedio
    }  
	{
		float suma=0,proma;
	    printf ("\n Etica: ");
		c=4;  // se empieza por la columna 4 de la matriz
		for(f=0; f<5; f++)
		{
			suma += calificaciones[f][c];
	    }
		proma=suma/5;
		printf ("%.2f",proma); // impresion del promedio
	}printf("\n");
	system("pause");	
}

void mejoralumno ()
{
	
}

void mejorprom ()
{
	
}

void promgeneral ()
{
	system("cls"); // limpieza de la pantalla
    int f, c;
	float suma=0, prom;
	printf ("\n PROMEDIO GENERAL");
	for(f=0; f<5; f++)
	{
		for(c=0; c<5; c++)
		{
			suma += calificaciones[f][c];
		}
	}
	prom=suma/25;
    printf("\n EL promedio general es: %.2f\n",prom);
	system("pause");
}