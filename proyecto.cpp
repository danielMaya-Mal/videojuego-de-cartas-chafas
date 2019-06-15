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
		mimo=enfrentamiento();
		printf("%i ",mimo);
		mimo2=enfrentamiento();
		printf("%i ",mimo2);
		mimic(mimo,mimo2);
		
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
	int peleador1,peleador2,cont2,puntos,aleatorio,mimo,vic1=0,vic2=0;
//	for(cont=0;cont<1;cont=cont+1)
	{
		srand(time(NULL));
		aleatorio=0+rand()%(2+1);printf("%i \n",aleatorio);
	//	v[cont]=aleatorio;
	//	Sleep(1000);
	//	if(cont==0)
		{
			peleador1=v[aleatorio];
		//	p1[0]=aleatorio;
		//	return(aleatorio);
			printf("%i\n",peleador1);
		}
	//	if(cont==1)
		{
	//		peleador2=v[aleatorio];
	//		printf("%i \n",peleador2);
		}
	}
//	for(cont=0;cont<2;cont=cont+1)
	{
		srand(time(NULL));
		aleatorio=3+rand()%(5+1);printf("%i \n",aleatorio);
	//	if(cont==0)
		{
	//		peleador1=v[aleatorio];
	//		printf("%i\n",peleador1);
		}
	//	if(cont==1)
		{
			peleador2=v[aleatorio];
		//	p2[0]=aleatorio;
	//		return(aleatorio);
			printf("%i \n",peleador2);
		}
	}
//	puntos=0;
//	for(cont=0;cont<3;cont=cont+1)
	{
	//	peleador1=v[0];
	//	for(cont2=3;cont2<6;cont2=cont2+1)
		{
			//peleador2=v[3];
			printf("Round 1-destreza: %s contra %s\n",carta[peleador1].nombre,carta[peleador2].nombre);
			puntos=carta[peleador1].destreza-carta[peleador2].destreza;
			Sleep(1000);
			if(puntos>0)
			{
				printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				Sleep(1000);
				vic1=vic1+1;
			}
			else
			{
				puntos=puntos*-1;
				printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				Sleep(1000);
				vic2=vic2+1;
			}
			printf("round 2-vitalidad: %s contra %s\n",carta[peleador1].nombre,carta[peleador2].nombre);
			puntos=carta[peleador1].vitalidad-carta[peleador2].vitalidad;
			Sleep(1000);
			if(puntos>0)
			{
				printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				Sleep(1000);
				vic1=vic1+1;
			}
			else
			{
				puntos=puntos*-1;
				printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				Sleep(1000);
				vic2=vic2+1;
			}
			if((vic1==2)||(vic2==2))
			{
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
			else
			{
				printf("round 3-fuerza: %s contra %s\n",carta[peleador1].nombre,carta[peleador2].nombre);
				puntos=carta[peleador1].fuerza-carta[peleador2].fuerza;
				Sleep(1000);
				if(puntos>0)
				{
					printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				}
				else
				{
					puntos=puntos*-1;
					printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				}
			}
	}
}
}
int mimic(int mimo,int mimo2)
{
	int peleador1,peleador2,cont2,puntos,aleatorio1,vic1=0,vic2=0;
	aleatorio1=0;
	do
	{
		srand(time(NULL));
		aleatorio1=0+rand()%(2+1);printf("%i \n",aleatorio1);
	}
	while(aleatorio1==mimo);
	peleador1=v[aleatorio];
	mimo=v[aleatorio];
	return(mimo);
	aleatorio1=0;
	do
	{
		srand(time(NULL));
		aleatorio1=3+rand()%(5+1);printf("%i \n",aleatorio1);
	}
	while(aleatorio1==mimo2);
	peleador2=v[aleatorio];
	mimo2=v[aleatorio];
	return(mimo2);
	printf("%i \n",peleador2);
	printf("Round 1-destreza: %s contra %s\n",carta[peleador1].nombre,carta[peleador2].nombre);
			puntos=carta[peleador1].destreza-carta[peleador2].destreza;
			Sleep(1000);
			if(puntos>0)
			{
				printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				Sleep(1000);
				vic1=vic1+1;
			}
			else
			{
				puntos=puntos*-1;
				printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				Sleep(1000);
				vic2=vic2+1;
			}
			printf("round 2-vitalidad: %s contra %s\n",carta[peleador1].nombre,carta[peleador2].nombre);
			puntos=carta[peleador1].vitalidad-carta[peleador2].vitalidad;
			Sleep(1000);
			if(puntos>0)
			{
				printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				Sleep(1000);
				vic1=vic1+1;
			}
			else
			{
				puntos=puntos*-1;
				printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				Sleep(1000);
				vic2=vic2+1;
			}
			if((vic1==2)||(vic2==2))
			{
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
			else
			{
				printf("round 3-fuerza: %s contra %s\n",carta[peleador1].nombre,carta[peleador2].nombre);
				puntos=carta[peleador1].fuerza-carta[peleador2].fuerza;
				Sleep(1000);
				if(puntos>0)
				{
					printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
					Sleep(1000);
				}
				else
				{
					puntos=puntos*-1;
					printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
					Sleep(1000);
				}
			}
}
