#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int cont,retorno,estructura,fila,cartas,c1,c2,c3,c4,c5,c6,aleatorio,v[5],p1[3],p2[3],mimo,mimo2;
struct personajes {
	char nombre[20];
	int fuerza;
	int vitalidad;
	int destreza;
};
struct personajes carta[] = {
	"caballero",12,15,10,
	"piromantico",8,9,10,
	"oscar de astora",8,13,9,
	"clerigo",10,9,5,
	"ladron",8,9,12,
	"hechicero",5,8,9,
	"marginado",15,10,5,
	"vagabundo",10,12,15,
	"guerrero",15,10,12,
	"caballero negro",18,20,13,
	"demonio aries",12,10,9,
	"demonio tauro",16,15,9,
	"loutrec",13,12,15,
	"power bazinga",18,12,9,
	"rusin",5,5,5,
	"sigmayer",15,12,13,
	"guardiana",2,8,12,
	"paches",12,10,8,
	"solere",17,15,10,
	"invasor",20,5,20
};
int azar();
int enfrentamiento();
int mimic(int mimo,int mimo2);
void imprimir(int v[5]);
main()
{
	do
	{
		printf("presiona cualquier tecla para comenzar el juego \n");
		getch();
		for(cont=0;cont<6;cont=cont+1)
		{
			v[cont]=azar();
			printf("%i \t",v[cont]);
		}
		imprimir(v);
		enfrentamiento();
		printf("si usted quiere dejar de jugar, presione 1\n");
		scanf("%i",&retorno);
	}
	while(retorno!=1);
}

int azar()
{
	int aleatorio,num,cont1;
	srand(time(NULL));
//	for(cont1=0;cont1<6;cont1=cont1+1)
	{
		aleatorio=0+rand()%(19+1);//printf("%i ",aleatorio);
		v[cont1]=aleatorio;
		Sleep(1000);
		return(aleatorio);
	}
	//return(aleatorio);
}
void imprimir(int v[5])
{
	int personaje;
	for(cont=0;cont<6;cont=cont+1)
	{
		personaje=v[cont];	
		if(cont==0)
		{
			printf("tu equipo:\n\n");
		}		
		if(cont==3)
		{
			printf("tu oponente:\n\n");
		}
		printf("%s\nvitalidad: %i\nfuerza: %i\ndestreza: %i\n\n",carta[personaje].nombre,carta[personaje].vitalidad,carta[personaje].fuerza,carta[personaje].destreza);
		Sleep(1000);
			
	}
}
int enfrentamiento()
{
	int peleador1,peleador2,cont2,puntos,aleatorio,mimo;
	float vic1=0,vic2=0;
	for(cont=0,cont2=3;cont<3;cont=cont+1,cont2=cont2+1)
	{
			vic1=0;
			vic2=0;
			peleador1=v[cont];
			printf("%i\n",peleador1);
			peleador2=v[cont2];
			printf("%i \n",peleador2);
			printf("Round 1-destreza:'%s con %i contra %s con %i\n",carta[peleador1].nombre,carta[peleador1].destreza,carta[peleador2].nombre,carta[peleador2].destreza);
			puntos=carta[peleador1].destreza-carta[peleador2].destreza;
			Sleep(1000);
			if(puntos==0)
			{
				printf("duelo empate, punto medio para cada jugador\n");
				vic1=(float)vic1+0.5;
				vic2=(float)vic2+0.5;
				printf("1%f\n2%f",vic1,vic2);
			}
			if(puntos>0)
			{
				printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				Sleep(1000);
				vic1=(float)vic1+1;	printf("1%f\n2%f",vic1,vic2);
			}
			else if(puntos<0)
			{
				puntos=puntos*-1;
				printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				Sleep(1000);
				vic2=(float)vic2+1;
				printf("1%f\n2%f",vic1,vic2);
			}
			printf("Round 2-vitalidad:'%s con %i contra %s con %i\n",carta[peleador1].nombre,carta[peleador1].vitalidad,carta[peleador2].nombre,carta[peleador2].vitalidad);
			puntos=carta[peleador1].vitalidad-carta[peleador2].vitalidad;
			Sleep(1000);
			if(puntos==0)
			{
				printf("duelo empate, punto medio para cada jugador\n");
				vic1=(float)vic1+0.5;
				vic2=(float)vic2+0.5;
				printf("1%f\n2%f",vic1,vic2);
			}
			if(puntos>0)
			{
				printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				Sleep(1000);
				vic1=(float)vic1+1;
				printf("1%f\n2%f",vic1,vic2);
			}
			else if(puntos<0)
			{
				puntos=puntos*-1;
				printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				Sleep(1000);
				vic2=(float)vic2+1;
				printf("1%f\n2%f",vic1,vic2);
			}
			/*condicion para determinar el ganador con dos rounds ganados o un round y un empate...*/
			if(((vic1==2)||(vic2==2))||((vic1==1.5)||(vic2==1.5))) 
			{
				if((vic1==2)||(vic1==1.5))
				{
				printf("ganador de partida: %s",carta[peleador1].nombre);
				Sleep(1000);
				}
				if((vic2==2)||(vic2==1.5))
				{
				printf("ganador de partida: %s",carta[peleador2].nombre);
				Sleep(1000);
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////
			/*condiciones para empates  */
			if((vic1==1.00)&&(vic2==1.00))
			{
				printf("Round 3-fuerza:'%s con %i contra %s con %i\n",carta[peleador1].nombre,carta[peleador1].fuerza,carta[peleador2].nombre,carta[peleador2].fuerza);
				puntos=carta[peleador1].fuerza-carta[peleador2].fuerza;
				Sleep(1000);
				if(puntos==0)
				{
					printf("duelo empate, sin ganador\n");
					vic1=(float)vic1+0.5;
					vic2=(float)vic2+0.5;printf("1%f\n2%f",vic1,vic2);
				}
				if(puntos>0)
				{
					printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
					vic1=(float)vic1+1;printf("1%f\n2%f",vic1,vic2);
				}
				else
				{
					puntos=(float)puntos*-1;
					printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
					vic2=(float)vic2+1;printf("1%f\n2%f",vic1,vic2);
				}
				if(vic1==2)
				{
				printf("ganador de partida: %s",carta[peleador1].nombre);
				Sleep(1000);
				}
				if(vic2==2)
				{
				printf("ganador de partida: %s",carta[peleador2].nombre);
				Sleep(1000);
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	}
}

