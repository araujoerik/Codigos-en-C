/*
Programa que guarda un registro con estructuras y funciones, incluye un menu sencillo
*/

#include "stdio.h"
#include "conio.h"
#include "windows.h"
#include "stdlib.h"
#include "string.h"

void capturar_registro();
void mostrar_registro();
int buscar_registro(int x);
void editar_registro();
void eliminar_registro();

int aux;
int registro = 1;

struct domicilio
{
    char calle[50];
    int numero;
    char colonia[50];
};

struct localidad
{
    char ciudad[30];
    char pais[30];
};

struct fecha
{
    char mes[15];
    int anyo;
};

struct suscriptor
{
    int clave;
    char nombre_completo[60];
    struct domicilio dom;
    struct localidad loc;
    int tel;
    char e_mail[50];
    char tipo_revista[30];
    float costo;
    struct fecha fech;
}suscriptores[10];

int main()
{
    char op;
    int aux = 1;
    do{
        do{
            system("cls");
            printf ("\n\t*MENU DE OPCIONES*\n\n");
            printf("\n\t[F1] Alta de registros\n\t[F2] Mostrar registros\n\t[F3] Buscar registros\n\t[F4] Editar registros");
            printf("\n\t[F5] Eliminar registros\n\tESC. Salir\n\n");
            printf("\tSeleccione una opcion: ");
            op = getch();//Al presionar la tecla generara el numero correspondiente al Codigo ASCII
            if(op==0)
		    {
			    op=getch();
				if((op!=59)&&(op!=60)&&(op!=61)&&(op!=62)&&(op!=63)&&(op!=27))//Condicion para Especificar que es incorrecto
				{
				    printf("\n\tTECLA ERRONEA\n");
					getch();
				}
			}				
	    }while((op!=59)&&(op!=60)&&(op!=61)&&(op!=62)&&(op!=63)&&(op!=27));
        switch(op)
		{
			//Opciones del menu y llamada de funciones
		    case 59:
            capturar_registro(); 
			break;
            case 60: 
            mostrar_registro();
			break;			
			case 61: 
            buscar_registro(3);
			break;			
			case 62: 
            editar_registro();
			break;						
			case 63: 
            eliminar_registro();
			break;						
			case 27:
			exit(0);
			break;	
	    }			
    }while(1);
}

void capturar_registro()
{
    system("cls");
    char res;
   
    do{
        system("cls"); 
        printf("\t**CAPTURA DE DATOS**\n\n");
        printf("\tRegistro # %d\n", registro);
        printf("\tClave de suscriptor a 4 digitos: ");
        scanf("%d", &suscriptores[aux].clave);
        printf("\tNombre completo de suscriptor: "); fflush(stdin);
        gets(suscriptores[aux].nombre_completo);
        printf("\tCalle: "); fflush(stdin);
        gets(suscriptores[aux].dom.calle);
        printf("\tNumero de Calle: ");
        scanf("%d", &suscriptores[aux].dom.numero);
        printf("\tColonia: "); fflush(stdin);
        gets(suscriptores[aux].dom.colonia);
        printf("\tCiudad: "); fflush(stdin);
        gets(suscriptores[aux].loc.ciudad);
        printf("\tPais: "); fflush(stdin);
        gets(suscriptores[aux].loc.pais);
        printf("\tTelefono: ");
        scanf("%d", &suscriptores[aux].tel);
        printf("\tE-mail: "); fflush(stdin);
        gets(suscriptores[aux].e_mail);
        printf("\tTipo de revista\n\t(especializada, informativa, divulgacion cientifica, entretenimiento, educativa, tematica, comics): "); fflush(stdin);
        gets(suscriptores[aux].tipo_revista);
        printf("\tCosto de la suscripcion: ");
        scanf("%f", &suscriptores[aux].costo);
        printf("\tMes de suscripcion: "); fflush(stdin);
        gets(suscriptores[aux].fech.mes);
        printf("\tA%co de suscripcion: ",164); 
        scanf("%d", &suscriptores[aux].fech.anyo);
        aux += 1;
        registro += 1;
        printf("\t\n¿Deseas agregar otro registro? (s/n)\n"); fflush(stdin);
        scanf("%c",&res);
    }while(res=='s');
    getch();
}

void mostrar_registro()
{
    system("cls");
    for(int i =  0 ; i < aux; i++)
    {
        printf("\t**MUESTREO DE DATOS**\n\n");
        printf("\tRegistro # %d\n", i + 1);
        printf("\n\tClave de suscriptor a 4 digitos: %d\n",suscriptores[i].clave);
        printf("\tNombre completo de suscriptor: %s\n", suscriptores[i].nombre_completo);
        printf("\tCalle: %s\n", suscriptores[i].dom.calle);
        printf("\tNumero de Calle: %d\n", suscriptores[i].dom.numero);
        printf("\tColonia: %s\n", suscriptores[i].dom.colonia);
        printf("\tCiudad: %s\n", suscriptores[i].loc.ciudad);
        printf("\tPais: %s\n", suscriptores[i].loc.pais);
        printf("\tTelefono: %d\n", suscriptores[i].tel);
        printf("\tE-mail: %s\n", suscriptores[i].e_mail);
        printf("\tTipo de revista: %s\n", suscriptores[i].tipo_revista);
        printf("\tCosto de la suscripcion: $%.2f\n", suscriptores[i].costo);
        printf("\tMes de suscripcion: %s\n", suscriptores[i].fech.mes);
        printf("\tA%co de suscripcion: %d\n\n",164, suscriptores[i].fech.anyo);
    }
    getch();
}

int buscar_registro(int x)
{
    system("cls");
    int registro, b=0, pos;
	if(x==4) 
    printf("\nDame el numero de registro a ELIMINAR: ");
	else if(x==5) 
    printf("\nDame el numero de registro a MODIFICAR: ");
	else 
    printf("\nDame el numero de registro a BUSCAR: ");
	scanf("%d",&registro); 
    if(aux==0)
	printf("\nNO EXISTE EL REGISTRO\n");
	else
	for(int i=0; i<aux; i++)
    if(registro==registro)
    {
        if(x != 5)
        {
            printf("\tRegistro # %d\n", registro);
            printf("\n\tClave de suscriptor a 4 digitos: %d\n",suscriptores[i].clave);
            printf("\tNombre completo de suscriptor: %s\n", suscriptores[i].nombre_completo);
            printf("\tCalle: %s\n", suscriptores[i].dom.calle);
            printf("\tNumero de Calle: %d\n", suscriptores[i].dom.numero);
            printf("\tColonia: %s\n", suscriptores[i].dom.colonia);
            printf("\tCiudad: %s\n", suscriptores[i].loc.ciudad);
            printf("\tPais: %s\n", suscriptores[i].loc.pais);
            printf("\tTelefono: %d\n", suscriptores[i].tel);
            printf("\tE-mail: %s\n", suscriptores[i].e_mail);
            printf("\tTipo de revista: %s\n", suscriptores[i].tipo_revista);
            printf("\tCosto de la suscripcion: $%.2f\n", suscriptores[i].costo);
            printf("\tMes de suscripcion: %s\n", suscriptores[i].fech.mes);
            printf("\tA%co de suscripcion: %d\n\n",164, suscriptores[i].fech.anyo);
        }
        b=1; 
        pos = i; 
        break;
    }
    if(b==0)
    {
        printf("NO EXISTE REGISTRO\n"); 
        pos=-1;
    }
    if(x==3)
    {
        printf("\nOPRIME ENTER PARA CONTINUAR\n");
        getch();
    }
    return pos;
}

void editar_registro()
{
    system("cls");
    int op, i , p;
    p=buscar_registro(5);
    if(p != -1)
    do{
        printf("\tRegistro # %d\n", p);
        printf("\n\t1) Clave de suscriptor a 4 digitos: %d\n",suscriptores[p].clave);
        printf("\t2) Nombre completo de suscriptor: %s\n", suscriptores[p].nombre_completo);
        printf("\t3) Calle: %s\n", suscriptores[p].dom.calle);
        printf("\t4) Numero de Calle: %d\n", suscriptores[p].dom.numero);
        printf("\t5) Colonia: %s\n", suscriptores[p].dom.colonia);
        printf("\t6) Ciudad: %s\n", suscriptores[p].loc.ciudad);
        printf("\t7) Pais: %s\n", suscriptores[p].loc.pais);
        printf("\t8) Telefono: %d\n", suscriptores[p].tel);
        printf("\t9) E-mail: %s\n", suscriptores[p].e_mail);
        printf("\t10) Tipo de revista: %s\n", suscriptores[p].tipo_revista);
        printf("\t11) Costo de la suscripcion: $%.2f\n", suscriptores[p].costo);
        printf("\t12) Mes de suscripcion: %s\n", suscriptores[p].fech.mes);
        printf("\t13) A%co de suscripcion: %d\n\n",164, suscriptores[p].fech.anyo);
        printf("\t14) SALIR\n");
        printf("¿Que deseas modificar?\n");
        scanf("%d", &op);
        switch(op)
        {
            case 1:
            printf("\tClave de suscriptor a 4 digitos: ");
            scanf("%d", &suscriptores[p].clave);
            break;
            case 2:
            printf("\tNombre completo de suscriptor: "); fflush(stdin);
            gets(suscriptores[p].nombre_completo);
            break;
            case 3:
            printf("\tCalle: "); fflush(stdin);
            gets(suscriptores[p].dom.calle);
            break;
            case 4:
            printf("\tNumero de Calle: ");
            scanf("%d", &suscriptores[p].dom.numero);
            break;
            case 5:
            printf("\tColonia: "); fflush(stdin);
            gets(suscriptores[p].dom.colonia);
            break;
            case 6:
            printf("\tCiudad: "); fflush(stdin);
            gets(suscriptores[p].loc.ciudad);
            break;
            case 7:
            printf("\tPais: "); fflush(stdin);
            gets(suscriptores[p].loc.pais);
            break;
            case 8:
            printf("\tTelefono: ");
            scanf("%d", &suscriptores[p].tel);
            break;
            case 9:
            printf("\tE-mail: "); fflush(stdin);
            gets(suscriptores[p].e_mail);
            break;
            case 10:
            printf("\tTipo de revista\n\t(especializada, informativa, divulgacion cientifica, entretenimiento, educativa, tematica, comics): "); fflush(stdin);
            gets(suscriptores[p].tipo_revista);
            break;
            case 11:
            printf("\tCosto de la suscripcion: ");
            scanf("%f", &suscriptores[p].costo);
            break;
            case 12:
            printf("\tMes de suscripcion: "); fflush(stdin);
            gets(suscriptores[p].fech.mes);
            break;
            case 13:
            printf("\tA%co de suscripcion: ",164); 
            scanf("%d", &suscriptores[p].fech.anyo);
            break;
            case 14:
            exit(0);
            break;
        }
    }while(op != 14);
    getch();
}

void eliminar_registro()
{
    system("cls");
    int p, i;
    char r;
    p=buscar_registro(4);
    if(p!=-1)
    {
        printf("\n¿Lo deseas eliminar?(S/N) ");
        scanf("%c", &r);
        if(r=='s'||r=='n');
        {
            for(i = p; i <= aux; i++)
            suscriptores[i] = suscriptores[i+1];
            aux = aux-1;
        }
    }
    getch();
}