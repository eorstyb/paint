/******************************************************************************/
/*                                                                            */
/******************************************************************************/

// importation des librairies
#include <stdio.h>
#include "lib/libgraphique.h"

// constantes
#define H 800
#define L 600
#define MARGE 50

// prototypes des fonctions
void init();
void rectangle_plein();
void triangle();
void rectangle_vide();
void segment();
void polygone();
 
int main(void)
{
	init();
	actualiser();
	while (1)
	{
		Point a = attendre_clic();
		if (a.x <= 40 && a.x >= 10 && a.y <= 60 && a.y >= 40) // si l'utilisateur clique sur le rectangle
		{
				rectangle_vide();
				actualiser();
		}
		
		if (a.x >= 10 && a.x <= 40 && a.y <= 120 && a.y >= 100) // si l'utilisateur clique sur le triangle
		{
			triangle();
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 40 && a.y >= 150 && a.y <= 180)
		{
			segment();
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
	Point p = {MARGE,0};
	Point q = {MARGE,H};
	dessiner_ligne(p,q,blanc);
	//rectangle
	Point rectangle_1 = {10, 40};
	Point rectangle_2 = {10, 60};
	Point rectangle_3 = {40, 40};
	Point rectangle_4 = {40, 60};
	dessiner_ligne(rectangle_1, rectangle_2, blanc);
	dessiner_ligne(rectangle_2, rectangle_4, blanc);
	dessiner_ligne(rectangle_3, rectangle_4, blanc);
	dessiner_ligne(rectangle_3, rectangle_1, blanc);
	
	//triangle
	Point a = {25, 100};
	Point b = {10, 120};
	Point c = {40, 120};
	dessiner_ligne(a,b,blanc);
	dessiner_ligne(b,c,blanc);
	dessiner_ligne(a,c,blanc);
	
	//segment
	Point segment_1 = {10, 150};
	Point segment_2 = {40, 180};
	dessiner_ligne(segment_1,segment_2,blanc);
	 
	
}

void rectangle_plein() // créé un rectangle à partir de deux points
{ 
	Point coin1 = attendre_clic();
	Point coin2 = attendre_clic();
	if (coin1.x <= MARGE || coin2.x <= MARGE) return;
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

void rectangle_vide() //2 ou 3 points ??
{
	Point coin1 = attendre_clic();
	Point coin2 = attendre_clic();
	if (coin1.x <= MARGE || coin2.x <= MARGE) return;
	Point coin3;
	coin3.x = coin2.x;
	coin3.y = coin1.y;
		
	Point coin4;
	coin4.x = coin1.x;
	coin4.y = coin2.y;
	dessiner_ligne(coin1,coin3,blanc);
	dessiner_ligne(coin3,coin2,blanc);
	dessiner_ligne(coin2,coin4,blanc);
	dessiner_ligne(coin4,coin1,blanc);
}

void triangle()
{
	Point a = attendre_clic();
	Point b = attendre_clic();
	Point c = attendre_clic();
	if (a.x <= MARGE || b.x <= MARGE || c.x <= MARGE) return;
	dessiner_ligne(a,b,blanc);
	dessiner_ligne(b,c,blanc);
	dessiner_ligne(a,c,blanc);
}

void segment()
{
	Point segment_1 = attendre_clic();
	Point segment_2 = attendre_clic();
	if(segment_1.x <= MARGE || segment_2.x <= MARGE) return ;
	dessiner_ligne(segment_1,segment_2,blanc);
}

void polygone()
{
	
