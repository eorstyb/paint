/******************************************************************************/
/*                                                                            */
/******************************************************************************/

// importation des librairies
#include <stdio.h>
#include "../lib/libgraphique.h"

// constantes
#define H 800
#define L 600


// prototypes des fonctions
void init();
void rectangle();
 
int main(void)
{
	init();
	actualiser();
	while (1)
	{
		Point a = attendre_clic();
		if (a.x <= 40 && a.x >= 10 && a.y <= 60 && a.y >= 40)
		{
				rectangle();
				actualiser();
		}
	}
	attendre_clic();
	fermer_fenetre();
    return 0;
}

void init() // initialise la fenêtre et la barre du menu
{
	ouvrir_fenetre(H,L);	
	Point p = {50,0};
	Point q = {50,H};
	Point rectangle_1 = {10, 40};
	Point rectangle_2 = {10, 60};
	Point rectangle_3 = {40, 40};
	Point rectangle_4 = {40, 60};
	dessiner_ligne(p,q,blanc);
	dessiner_ligne(rectangle_1, rectangle_2, blanc);
	dessiner_ligne(rectangle_2, rectangle_4, blanc);
	dessiner_ligne(rectangle_3, rectangle_4, blanc);
	dessiner_ligne(rectangle_3, rectangle_1, blanc);
	
}

void rectangle() 
{ 
	Point coin1 = attendre_clic();
	Point coin2 = attendre_clic();
	if (coin1.x <=  coin2.x && coin1.y <= coin2.y)  dessiner_rectangle(coin1, coin2.x - coin1.x, coin2.y - coin1.y, blanc);
	
	else if (coin1.x <= coin2.x && coin1.y >= coin2.y) 
	{
		Point coin3;
		coin3.x = coin1.x;
		coin3.y = coin2.y;
		dessiner_rectangle(coin3, coin2.x - coin3.x, coin1.y - coin3.y, blanc);
	}
	
	else if (coin1.x >= coin2.x && coin1.y >= coin2.y)
	{
		Point coin3 = coin1;
		coin1 = coin2;
		coin2 = coin3;
		dessiner_rectangle(coin1, coin2.x - coin1.x, coin2.y - coin1.y, blanc);
	}
	
	else 
	{
		Point coin4;
		coin4 = coin1;
		coin1 = coin2;
		coin2 = coin4;
		Point coin3;
		coin3.x = coin1.x;
		coin3.y = coin2.y;
		dessiner_rectangle(coin3, coin2.x - coin3.x, coin1.y - coin3.y, blanc);
	}
	
}
