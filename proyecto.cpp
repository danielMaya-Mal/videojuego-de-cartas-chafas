#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<windows.h>
int cont,retorno,aleatorio,v[5],jugador=0,oponente=0;
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
void imprimir(int v[5]);
void reglas();
void introduccion();
main()
{
 reglas();
 introduccion();	
	do
	{
		jugador=0;
		oponente=0;
		for(cont=0;cont<6;cont=cont+1)
		{
			v[cont]=azar();
		//	printf("%i \t",v[cont]);
		}
		imprimir(v);
		enfrentamiento();
		printf("si usted quiere dejar de jugar, presione 1\n");
		scanf("%i",&retorno);
	}
	while(retorno!=1);
}
void reglas()
{
printf("presiona cualquier tecla para comenzar el juego \n");
getch();
printf("las reglas de este juego son:\n");
Sleep(2000);
printf("-el ganador del torneo sera el que gane dos de tres de los enfrentamientos entre sus personajes,\ncada enfrentamiento entre personajes tiene tres rounds\n\n ");
Sleep(2000);
printf("-el personaje que gane dos de los tres rounds de habilidades sera el ganador del enfrentamiento dandole a su poseedor un punto\n\n");
Sleep(2000);
printf("-si un personaje ha ganado dos rounds seguidos, este sera el ganador del enfrentamiento\nsiendo el tercer round un desempate en caso de empate de puntos\n\n");
Sleep(2000);
printf("-si en el enfrentamiento las estadisticas de personajes se empatan se le dara a cada personaje medio punto...\nquien tenga un punto y medio sera el ganador del enfrentamiento\n\n");
Sleep(2000);
printf("presione cualquier tecla cuando acepte las reglas\n");
getch();
}
void introduccion()
{
 printf("se decia que solo los mas fuertes sobreviven\n");
 Sleep(2500);
 printf("hasta que un dia eso no fue suficiente\n");
 Sleep(2500);
 printf("los dioses se hartaron del ego de los hombres y desencadenaron ....\n");
 Sleep(2500);
 printf("EL CAOS\n");
 Sleep(3000);
 printf("ahora todo lo decidira el y es muy voluble\n");
 Sleep(2500);
 printf("arrojando la moneda del azar decidira un nuevo rey\n");
 Sleep(2500);
 printf("que comienze el juego.....suerte al rey\n");
}
int azar()
{
	int aleatorio,num,cont1;
	srand(time(NULL));
//	for(cont=0;cont<6;cont=cont+1)
	{
		aleatorio=0+rand()%(19+1);//printf("%i ",aleatorio);
		v[cont]=aleatorio;
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
			printf("rey anfitreon\n tus subditos son:\n\n");
		}		
		if(cont==3)
		{
			printf("\n\n rey de las maquina\n sus subditos:\n\n");
		}
		printf("%s\nvitalidad: %i\nfuerza: %i\ndestreza: %i\n\n",carta[personaje].nombre,carta[personaje].vitalidad,carta[personaje].fuerza,carta[personaje].destreza);
		Sleep(1500);
			
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
		//	printf("%i\n",peleador1);
			peleador2=v[cont2];
		//	printf("%i \n",peleador2);
			printf("\n\nRound 1 por destreza:'%s con %i contra %s con %i\n",carta[peleador1].nombre,carta[peleador1].destreza,carta[peleador2].nombre,carta[peleador2].destreza);
			puntos=carta[peleador1].destreza-carta[peleador2].destreza;
			Sleep(3000);
			if(puntos==0)
			{
				printf("\nduelo con empate, medio punto para cada jugador\n");
				vic1=(float)vic1+0.5;
				vic2=(float)vic2+0.5;
			//	printf("1%f\n2%f",vic1,vic2);
			}
			if(puntos>0)
			{
				printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				Sleep(1000);
				vic1=(float)vic1+1;//	printf("1%f\n2%f",vic1,vic2);
			}
			else if(puntos<0)
			{
				puntos=puntos*-1;
				printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				Sleep(1000);
				vic2=(float)vic2+1;
				//printf("1%f\n2%f",vic1,vic2);
			}
			printf("\nRound 2 por vitalidad:'%s con %i contra %s con %i\n",carta[peleador1].nombre,carta[peleador1].vitalidad,carta[peleador2].nombre,carta[peleador2].vitalidad);
			puntos=carta[peleador1].vitalidad-carta[peleador2].vitalidad;
			Sleep(3000);
			if(puntos==0)
			{
				printf("\nduelo con empate, medio punto para cada jugador\n");
				vic1=(float)vic1+0.5;
				vic2=(float)vic2+0.5;
			//	printf("1%f\n2%f",vic1,vic2);
			}
			if(puntos>0)
			{
				printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
				Sleep(1000);
				vic1=(float)vic1+1;
			//	printf("1%f\n2%f",vic1,vic2);
			}
			else if(puntos<0)
			{
				puntos=puntos*-1;
				printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
				Sleep(1000);
				vic2=(float)vic2+1;
			//	printf("1%f\n2%f",vic1,vic2);
			}
			/*condicion para determinar el ganador con dos rounds ganados o un round y un empate...*/
			if(((vic1==2)||(vic2==2))||((vic1==1.5)||(vic2==1.5))) 
			{
				if((vic1==2)||(vic1==1.5))
				{
				printf("ganador de partida: %s",carta[peleador1].nombre);
				jugador=jugador+1; //contador para determinar las partidas ganadas
			//	printf("\n %i ",jugador);
				Sleep(1000);
				}
				if((vic2==2)||(vic2==1.5))
				{
				printf("ganador de partida: %s",carta[peleador2].nombre);
				oponente=oponente+1; //contador para determinar las partidas ganadas
			//	printf("\n %i ",oponente);
				Sleep(1000);
				}
			}
			////////////////////////////////////////////////////////////////////////////////////////////////////////
			/*condiciones para empates  */
			if((vic1==1.00)&&(vic2==1.00))
			{
				printf("\nRound 3 por fuerza:'%s con %i contra %s con %i\n",carta[peleador1].nombre,carta[peleador1].fuerza,carta[peleador2].nombre,carta[peleador2].fuerza);
				puntos=carta[peleador1].fuerza-carta[peleador2].fuerza;
				Sleep(3000);
				if(puntos==0)
				{
					printf("\nduelo con empate, sin ganador\n");
					vic1=(float)vic1+0.5;
					vic2=(float)vic2+0.5;//printf("1%f\n2%f",vic1,vic2);
				}
				if(puntos>0)
				{
					printf("\nganador: %s\n con %i puntos\n",carta[peleador1].nombre,puntos);
					vic1=(float)vic1+1;//printf("1%f\n2%f",vic1,vic2);
				}
				else
				{
					puntos=(float)puntos*-1;
					printf("\nganador: %s\n con %i puntos\n",carta[peleador2].nombre,puntos);
					vic2=(float)vic2+1;//printf("1%f\n2%f",vic1,vic2);
				}
				if(vic1==2)
				{
				printf("ganador de partida: %s",carta[peleador1].nombre);
				jugador=jugador+1; //contador para determinar las partidas ganadas
			//	printf("\n %i",jugador);
				Sleep(1000);
				}
				if(vic2==2)
				{
				printf("ganador de partida: %s",carta[peleador2].nombre);
				oponente=oponente+1; //contador para determinar las partidas ganadas
				//printf("\n %i",oponente);
				Sleep(1000);
				}
			}
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////
			printf("\n.............................................................................................................\n");
	}
	/*determina quien ha ganado el juego...*/
			if((jugador==2)||(jugador==3))
				{
					printf("\n\n el rey del trono es...\n");
					Sleep(3000);
					printf("el rey anfitreon...la moneda del azar cayo a tu favor \n");
					Sleep(2000);
					printf("que viva el rey y su reinado del caos\n");
				}
				else if((oponente==2)||(oponente==3))
				{
					printf("\n\n el rey del trono es...\n");
					Sleep(3000);
					printf("el rey de las maquinas...el azar no te ha favorecido\n");
					Sleep(2000);
					printf("que viva el rey y su reinado del caos\n");
				}
}
