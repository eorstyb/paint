/******************************************************************************/
/*                                                                            */
/******************************************************************************/

// importation des librairies
#include <stdio.h>
#include "lib/libgraphique.h"
#include <math.h>
#include <string.h>

// constantes
#define H 1500
#define L 1000
#define MARGE 230

// prototypes des fonctions
void init();
void rectangle_plein(Couleur couleur);
void triangle(Couleur couleur);
void rectangle_vide(Couleur couleur);
void segment(Couleur);
void charger_image();
void cercle_plein(Couleur couleur);
int power(int a);
void texte();
void main_levee(Couleur couleur);
void gomme();
void remplissage();
void reinit();
void clear();
void animation();
Couleur couleur(Point a);

int main(void)
{
	init();
	actualiser();
	//texte();
	actualiser();
	Couleur prochaine_couleur = rouge;
	Point a;
	polygone();
	while (1)
	{	
		/*while (1)
		{
			a = attendre_clic();
			printf("a.x = %d; a.y = %d\n", a.x, a.y);
			actualiser();
		}*/
		a = attendre_clic();
		if (a.x <= 40 && a.x >= 10 && a.y <= 60 && a.y >= 40) // si l'utilisateur clique sur le rectangle
		{
			reinit();
			rectangle_vide(prochaine_couleur);
			actualiser();
		}
	
		if (a.x >= 10 && a.x <= 40 && a.y <= 120 && a.y >= 100) // si l'utilisateur clique sur le triangle
		{
			reinit();
			triangle(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 40 && a.y >= 150 && a.y <= 180) // si l'utilisateur clique sur le segment
		{
			reinit();
			segment(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 40 && a.y>= 210 && a.y <= 240) // si l'utilisateur clique sur le rectangle plein
		{
			reinit();
			rectangle_plein(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 40 && a.y >= 265 && a.y <= 295) // si l'utilisateur clique sur le cercle plein
		{
			reinit();
			cercle_plein(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 40 && a.y >= 320 && a.y <= 350) // si l'utilisateur clique sur l'image
		{
			reinit();
			charger_image();
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 40 && a.y >= 370 && a.y <= 400) // si l'utilisateur clique sur la gomme
		{		
			reinit();
			gomme();
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 60 && a.y >= 430 && a.y <= 490) // si l'utilisateur clique sur le stylo
		{
				reinit();
				main_levee(prochaine_couleur);
				actualiser();
		}
		
		if (a.x >= H - 30 && a.x <= H-10 && a.y >= 5 && a.y <= 25) // si l'utilisateur clique sur le bouton rouge
		{
			break;
		}
		
		
		if(a.x >= 27 && a.x <= 194 && a.y >= 723 && a.y <= 865) // si l'utilisateur clique sur une couleur
		{
			prochaine_couleur = couleur(a);
		} 
		
		if (a.x >= H - 60 && a.x <= H-40 && a.y >= 10 && a.y <= 30)
		{
			clear();
			actualiser();
		}
	}
	fermer_fenetre();
    return 0;
}

void init() // initialise la fenêtre et la barre du menu
{
	ouvrir_fenetre(H,L);
	Point coin = {0,0};
	dessiner_rectangle(coin,H,L,blanc);
	Point logo = {650,400};
	afficher_image("images/logo.bmp", logo);
	animation();
	dessiner_rectangle(coin,H,L,darkgray);
	dessiner_rectangle(coin,MARGE,L,violet);
	Point p = {MARGE,0};
	Point q = {MARGE,H};
	dessiner_ligne(p,q,blanc);
	Point palette_rectangle = {0,L-200};
	dessiner_rectangle(palette_rectangle,MARGE,200,noir);
	
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
	
	//rectangle_plein
	Point rectangle_plein1 = {10,210};
	dessiner_rectangle(rectangle_plein1,30,30,blanc);
	
	//cercle plein
	Point centre = {25, 280};
	dessiner_disque(centre, 15, blanc);
	 
	//image
	Point image1 = {10,320};
	Point image2 = { 14,324};
	dessiner_rectangle(image1,30,30,blanc);
	dessiner_rectangle(image2,22,22,bleu);
	
	//gomme
	Point gomme = {10, 370};
	afficher_image("images/gomme.bmp",gomme);
	
	//bouton arrêt
	Point arret = {H-30,5};
	afficher_image("images/button-red.bmp", arret);
	
	//bouton clear
	Point clear = {H - 60,5};
	afficher_image("images/bouton-bleu.bmp", clear);
	
	//palette
	Point palette = {10,L-200};
	afficher_image("images/palette.bmp", palette);
	
	
	//main levée
	Point stylo = {10, 430};
	afficher_image("images/stylo.bmp", stylo);
	
	//polygone
	Point polygone = {10, 480};
	afficher_image("images/polygone.bmp", polygone);
}

void reinit() //reinitialise les formes du menu pour les remettre à leur couleur d'origine
{
	Point coin = {0,0};
	dessiner_rectangle(coin,MARGE,L,violet);
	Point p = {MARGE,0};
	Point q = {MARGE,H};
	dessiner_ligne(p,q,blanc);
	Point palette_rectangle = {0,L-200};
	dessiner_rectangle(palette_rectangle,MARGE,200,noir);
	
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
	
	//rectangle_plein
	Point rectangle_plein1 = {10,210};
	dessiner_rectangle(rectangle_plein1,30,30,blanc);
	
	//cercle plein
	Point centre = {25, 280};
	dessiner_disque(centre, 15, blanc);
	 
	//image
	Point image1 = {10,320};
	Point image2 = { 14,324};
	dessiner_rectangle(image1,30,30,blanc);
	dessiner_rectangle(image2,22,22,bleu);
	
	//gomme
	Point gomme = {10, 370};
	afficher_image("images/gomme.bmp",gomme);
	
	//bouton arrêt
	Point arret = {H - 30, 5};
	afficher_image("images/button-red.bmp", arret);
	
	//bouton clear
	Point clear = {H - 60,5};
	afficher_image("images/bouton-bleu.bmp", clear);
	
	//palette
	Point palette = {10,L-200};
	afficher_image("images/palette.bmp", palette);
	
	
	//main levée
	Point stylo = {10, 430};
	afficher_image("images/stylo.bmp", stylo);
	
	actualiser();
}

void rectangle_plein(Couleur couleur) // créé un rectangle à partir de deux points
{ 
	// colorie le rectangle plein du menu en rouge
	Point rectangle_plein1 = {10,210};
	dessiner_rectangle(rectangle_plein1,30,30,couleur);
	actualiser();	
	
	Point coin1 = attendre_clic();
	Point coin2 = attendre_clic();
	if (coin1.x <=  coin2.x && coin1.y <= coin2.y)  dessiner_rectangle(coin1, coin2.x - coin1.x, coin2.y - coin1.y, couleur);
	
	else if (coin1.x <= coin2.x && coin1.y >= coin2.y) 
	{
		Point coin3;
		coin3.x = coin1.x;
		coin3.y = coin2.y;
		dessiner_rectangle(coin3, coin2.x - coin3.x, coin1.y - coin3.y, couleur);
	}
	
	else if (coin1.x >= coin2.x && coin1.y >= coin2.y)
	{
		Point coin3 = coin1;
		coin1 = coin2;
		coin2 = coin3;
		dessiner_rectangle(coin1, coin2.x - coin1.x, coin2.y - coin1.y, couleur);
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
		dessiner_rectangle(coin3, coin2.x - coin3.x, coin1.y - coin3.y, couleur);
	}
	reinit();	
}

void rectangle_vide(Couleur couleur) 
{
	//le rectangle du menu devient rouge
	Point rectangle_1 = {10, 40};
	Point rectangle_2 = {10, 60};
	Point rectangle_3 = {40, 40};
	Point rectangle_4 = {40, 60};
	dessiner_ligne(rectangle_1, rectangle_2, couleur);

	dessiner_ligne(rectangle_2, rectangle_4, couleur);
	dessiner_ligne(rectangle_3, rectangle_4, couleur);
	dessiner_ligne(rectangle_3, rectangle_1, couleur);
	actualiser();
	
	Point coin1 = attendre_clic();
	Point coin2 = attendre_clic();
	Point coin3;
	coin3.x = coin2.x;
	coin3.y = coin1.y;
		
	Point coin4;
	coin4.x = coin1.x;
	coin4.y = coin2.y;
	dessiner_ligne(coin1,coin3,couleur);
	dessiner_ligne(coin3,coin2,couleur);
	dessiner_ligne(coin2,coin4,couleur);
	dessiner_ligne(coin4,coin1,couleur);
	reinit();
}

void triangle(Couleur couleur)
{
	//colorie le triangle du menu en rouge
	Point triangle_a = {25, 100};
	Point triangle_b = {10, 120};
	Point triangle_c = {40, 120};
	dessiner_ligne(triangle_a,triangle_b,couleur);
	dessiner_ligne(triangle_b,triangle_c,couleur);
	dessiner_ligne(triangle_a,triangle_c,couleur);
	actualiser();
	
	Point a = attendre_clic();
	Point b = attendre_clic();
	dessiner_ligne(a,b,couleur);
	actualiser();
	Point c = attendre_clic();
	dessiner_ligne(b,c,couleur);
	dessiner_ligne(a,c,couleur);
	actualiser();
	dessiner_ligne(a,b,couleur);
	dessiner_ligne(b,c,couleur);
	dessiner_ligne(a,c,couleur);
	reinit();
}

void segment(Couleur couleur)
{
	//colorie le segment du menu en rouge
	Point a = {10, 150};
	Point b = {40, 180};
	dessiner_ligne(a,b,couleur);
	actualiser();

	Point segment_1 = attendre_clic();
	//if(segment_1.x <= MARGE)
	{	
		reinit();
		return ;
	}
	
	Point segment_2 = attendre_clic();
	
	if(segment_2.x <= MARGE) 
	{	
		reinit();
		return ;
	}
	dessiner_ligne(segment_1,segment_2,couleur);
	reinit();
}

void charger_image()
{

	Point coin_image = attendre_clic();
	//if(coin_image.x <= MARGE) return ;
	afficher_image("images/uhahah.bpm",coin_image);
}

int power(int a)
{
	return a*a;
}

void cercle_plein(Couleur couleur)
{
	// colorie le cercle plein du menu en rouge
	Point center = {25, 280};
	dessiner_disque(center, 15, couleur);
	actualiser();
	
	Point centre = attendre_clic();
	Point point = attendre_clic();
	int rayon = sqrt(power(centre.x - point.x) + power(centre.y - point.y));
	//if (point.x > MARGE + 5 && centre.x > MARGE + 5 && centre.x - rayon > MARGE) 
	//{
		dessiner_disque(centre, rayon, couleur);
		reinit();
	//}
	//else 
	//{
		//reinit();
		//return;
	//}
}

void texte()
{	
	int taille;
	char str[100];
	char phrase[100];
	printf("Que voulez vous afficher ?\n");
	scanf("%[/n]s", str);
	sscanf(str, "%s",phrase);
	printf("De quelle taille est votre texte ?\n");
	scanf("%d", &taille);
	printf("Veuillez cliquer svp");
	Point coin = attendre_clic();
	afficher_texte(phrase, taille, coin, blanc);
}

void main_levee(Couleur couleur)
{
	Point a = attendre_clic();
	Point b;
	while (touche_a_ete_pressee(SDLK_SPACE) == 0)
	{
		while (touche_a_ete_pressee(SDL_BUTTON_RIGHT) == 0)
		{
			reinitialiser_evenements();
			traiter_evenements();
			b = deplacement_souris_a_eu_lieu();
			if (b.x > MARGE + 5)
			{
				dessiner_ligne(a,b,couleur);
				actualiser();
						a = b;
			}
			else 
			{
				reinitialiser_evenements();
				reinit();
				return;
			}
		}
		a = attendre_clic();
	}	
}

void gomme()
{
	// colorie le cadre de la gomme
	Point trait1 = {10,370};
	Point trait2 = {38,370};

	Point trait3 = {10,408};
	Point trait4 = {38,408};
	dessiner_ligne(trait1,trait2,couleur);

	dessiner_ligne(trait1,trait3,couleur);
	dessiner_ligne(trait2,trait4,couleur);
	dessiner_ligne(trait3,trait4,couleur);
	actualiser();
	
	Point b;
	while (touche_a_ete_pressee(SDLK_SPACE) == 0)
	{
		reinitialiser_evenements();
		traiter_evenements();
		b = deplacement_souris_a_eu_lieu();
		if (b.x > MARGE + 20)
		{
			dessiner_disque(b,20,darkgray);
			actualiser();
		}
	}	
	reinitialiser_evenements();
	reinit();
}

void polygone()
{
	Point a = attendre_clic();
	Point b;
	Point c = a;
	int i = 1;
		
	while (i == 1)
	{	
			b = attendre_clic_gauche_droite();
			if (b.x > 0)
			{
				dessiner_ligne(a,b,blanc);
				actualiser();
				a = b;
			}
			
			else 
			{
				i = 0;
			}
	}
	reinitialiser_evenements();
	dessiner_ligne(a,c,blanc);
	reinit();
}

Couleur couleur(Point a)
{
	if (a.x >= 162 && a.x <= 194 && a.y >= 754 && a.y <= 765) {return blanc;}
    if (a.x >= 124 && a.x <= 156 && a.y >= 748 && a.y <= 769) {return noir;}
    if (a.x >= 84 && a.x <= 117 && a.y >= 759 && a.y <= 778) {return marron;}
    if (a.x >= 46 && a.x <= 78 && a.y >= 759 && a.y <= 769) {return bleu;}
    if (a.x >= 27  && a.x <= 61 && a.y >= 800 && a.y <= 814) {return vert;}
    if (a.x >= 63 && a.x <= 90 && a.y >= 823 && a.y <= 842) {return jaune;}
    if (a.x >= 104 && a.x <= 133 && a.y >= 822 && a.y <= 852) {return orange;}
    if (a.x >= 146 && a.x <= 178 && a.y >= 817 && a.y <= 843) {return rouge;}
	return blanc;
}

void clear()
{
		Point a = {MARGE+1, 0};
		dessiner_rectangle(a, H - a.x, L, darkgray);
		reinit();
}

void animation()
{
	//Point rectangle = {0,0};
	//dessiner_rectangle(rectangle, H, L, blanc);
	Point coin = {690, 600};
	int compteur = 0;
	while(compteur < 3)
	{
		afficher_image("images/Chargement/1.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/2.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/3.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/4.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/5.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/6.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/7.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/8.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/9.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/10.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/11.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/12.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/13.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/14.bmp",coin);
		attente(70);
		actualiser();
		afficher_image("images/Chargement/15.bmp",coin);
		attente(70);
		actualiser();
		compteur += 1;
	}
}
