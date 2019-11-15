/******************************************************************************/
/*                                                                            */
/******************************************************************************/

// importation des librairies
#include <stdio.h>
#include "lib/libgraphique.h"
#include <math.h>
#include <string.h>

// constantes
#define H 1800	
#define L 900
#define MARGE 230

// prototypes des fonctions
void init();
void rectangle_plein(Couleur couleur);
void triangle(Couleur couleur);
void rectangle_vide(Couleur couleur);
void segment(Couleur);
void charger_image(Couleur couleur);
void cercle_plein(Couleur couleur);
void cercle_vide(Couleur couleur);
int power(int a);
void texte(Couleur couleur);
int epaisseur(Point a);
void main_levee(Couleur couleur);
void gomme(Couleur couleur);
void polygone(Couleur couleur);
void reinit();
void clear();
void animation();
void cube(Couleur couleur);
void remplissage(Point a, Couleur couleur);
Couleur couleur(Point a);

int main(void)
{
	init();
	actualiser();
	Couleur prochaine_couleur = rouge;
	Point a;
	texte(prochaine_couleur);
	while (1)
	{			
		/*while (1)
		{
			a = attendre_clic();
			printf("a.x = %d; a.y = %d\n", a.x, a.y);
			actualiser();
		}*/
		a = attendre_clic();
		
		if (a.x <= 80 && a.x >= 10 && a.y <= 60 && a.y >= 20) // si l'utilisateur clique sur le rectangle
		{
			reinit();
			rectangle_vide(prochaine_couleur);
			actualiser();
		}
	
		if (a.x >= 10 && a.x <= 80 && a.y <= 120 && a.y >= 80) // si l'utilisateur clique sur le triangle
		{
			reinit();
			triangle(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 80 && a.y >= 140 && a.y <= 180) // si l'utilisateur clique sur le segment
		{
			reinit();
			segment(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 80 && a.y>= 200 && a.y <= 240) // si l'utilisateur clique sur le rectangle plein
		{
			reinit();
			rectangle_plein(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 80 && a.y >= 260 && a.y <= 300) // si l'utilisateur clique sur le cercle plein
		{
			reinit();
			cercle_plein(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 80 && a.y >= 320 && a.y <= 360) // si l'utilisateur clique sur le cercle vide
		{
			reinit();
			cercle_vide(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 80 && a.y >= 380 && a.y <= 430) // si l'utilisateur clique sur le polygone
		{
			reinit();
			polygone(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 10 && a.x <= 80 && a.y >= 450 && a.y <= 490) // si l'utilisateur clique sur le polygone
		{
			reinit();
			cube(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 120 && a.x <= 230 && a.y >= 20 && a.y <= 35) // si l'utilisateur clique sur l'image
		{
			reinit();
			charger_image(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 120 && a.x <= 230 && a.y >= 65 && a.y <= 75) // si l'utilisateur clique sur la gomme
		{		
			reinit();
			gomme(prochaine_couleur);
			actualiser();
		}
		
		if (a.x >= 120 && a.x <= 230 && a.y >= 110 && a.y <= 125) // si l'utilisateur clique sur le stylo
		{
				reinit();
				main_levee(prochaine_couleur);
				actualiser();
		}
		
		if (a.x >= 120 && a.x <= 230 && a.y >= 155 && a.y <= 170) // si l'utilisateur clique sur remplissage
		{
			reinit();
			//colorie le texte quand selectionné
			Point remplissag = {120, 155};
			afficher_texte("REMPLISSAGE", 15, remplissag, couleur);
			actualiser();
			
			a = attendre_clic();
			remplissage(a, prochaine_couleur);
			reinit();
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
	Point logo = {(H/2) - 135,(L/2) - 150};
	afficher_image("images/logo.bmp", logo);
	animation();
	dessiner_rectangle(coin,H,L,darkgray);
	dessiner_rectangle(coin,MARGE,L,blanc);
	Point p = {MARGE,0};
	Point q = {MARGE,H};
	dessiner_ligne(p,q,noir);
	Point palette_rectangle = {0,L-200};
	dessiner_rectangle(palette_rectangle,MARGE,200,noir);
	cases();
	aide();
	
	//rectangle
	Point rectangle_1 = {10, 20};
	Point rectangle_2 = {10, 60};
	Point rectangle_3 = {80, 20};
	Point rectangle_4 = {80, 60};
	dessiner_ligne(rectangle_1, rectangle_2, noir);
	dessiner_ligne(rectangle_2, rectangle_4, noir);
	dessiner_ligne(rectangle_3, rectangle_4, noir);
	dessiner_ligne(rectangle_3, rectangle_1, noir);
	
	//triangle
	Point a = {45, 80};
	Point b = {10, 120};
	Point c = {80, 120};
	dessiner_ligne(a,b,noir);
	dessiner_ligne(b,c,noir);
	dessiner_ligne(a,c,noir);
	
	//segment
	Point segment_1 = {10, 140};
	Point segment_2 = {80, 180};
	dessiner_ligne(segment_1,segment_2,noir);
	
	//rectangle_plein
	Point rectangle_plein1 = {10,200};
	dessiner_rectangle(rectangle_plein1,70,40,noir);
	
	//cercle plein
	Point centre = {45, 280};
	dessiner_disque(centre, 20, noir);
	
	//cercle vide
	Point cercle_vide = {45,340};
	dessiner_cercle(cercle_vide, 20,noir);
	
	//polygone
	Point polygone1 = {45, 375};
	Point polygone2 = {10, 395};
	Point polygone3 = {80, 395};
	Point polygone4 = {10, 405};
	Point polygone5 = {80, 405};
	Point polygone6 = {45, 425};
	dessiner_ligne(polygone1, polygone2,noir);
	dessiner_ligne(polygone1, polygone3,noir);
	dessiner_ligne(polygone2, polygone4,noir);
	dessiner_ligne(polygone3, polygone5,noir);
	dessiner_ligne(polygone4, polygone6,noir);
	dessiner_ligne(polygone5, polygone6,noir);
	
	//cube
	Point cube = {25, 440};
	dessiner_rectangle(cube,40,40,noir);
	 
	//image
	Point image1 = {120,20};
	afficher_texte("IMAGE",15,image1,noir);
	
	//gomme
	Point gomme = {120, 65};
	afficher_texte("GOMME", 15, gomme, noir);
	
	//main levée
	Point stylo = {120, 110};
	afficher_texte("STYLO",15, stylo, noir);
	
	//remplissage
	Point remplissage = {120, 155};
	afficher_texte("REMPLISSAGE", 15, remplissage, noir);
	
	//texte
	Point texte = {120, 200};
	afficher_texte("TEXTE", 15, texte, noir);
	
	//bouton arrêt
	Point arret = {H - 30, 5};
	afficher_image("images/button-red.bmp", arret);
	
	//bouton clear
	Point clear = {H - 60,5};
	afficher_image("images/bouton-bleu.bmp", clear);
	
	//palette
	Point palette = {10,L-200};
	afficher_image("images/palette.bmp", palette);
	
	//epaisseur
	int i;
	Point epaisseur1 = {40, L-240};
	Point epaisseur2 = {80, L-240};
	Point epaisseur3 = {140, L-240};
	dessiner_disque(epaisseur1, 10, noir);
	dessiner_disque(epaisseur2, 15, noir);
	dessiner_disque(epaisseur3, 30, noir);		
}

void reinit() //reinitialise les formes du menu pour les remettre à leur couleur d'origine
{
	Point coin = {0,0};
	dessiner_rectangle(coin,MARGE,L,blanc);
	Point p = {MARGE,0};
	Point q = {MARGE,H};
	dessiner_ligne(p,q,blanc);
	Point palette_rectangle = {0,L-200};
	dessiner_rectangle(palette_rectangle,MARGE,200,noir);
	cases();
	
	//rectangle
	Point rectangle_1 = {10, 20};
	Point rectangle_2 = {10, 60};
	Point rectangle_3 = {80, 20};
	Point rectangle_4 = {80, 60};
	dessiner_ligne(rectangle_1, rectangle_2, noir);
	dessiner_ligne(rectangle_2, rectangle_4, noir);
	dessiner_ligne(rectangle_3, rectangle_4, noir);
	dessiner_ligne(rectangle_3, rectangle_1, noir);
	
	//triangle
	Point a = {45, 80};
	Point b = {10, 120};
	Point c = {80, 120};
	dessiner_ligne(a,b,noir);
	dessiner_ligne(b,c,noir);
	dessiner_ligne(a,c,noir);
	
	//segment
	Point segment_1 = {10, 140};
	Point segment_2 = {80, 180};
	dessiner_ligne(segment_1,segment_2,noir);
	
	//rectangle_plein
	Point rectangle_plein1 = {10,200};
	dessiner_rectangle(rectangle_plein1,70,40,noir);
	
	//cercle plein
	Point centre = {45, 280};
	dessiner_disque(centre, 20, noir);
	
	//cercle vide
	Point cercle_vide = {45,340};
	dessiner_cercle(cercle_vide, 20,noir);
	
	//polygone
	Point polygone1 = {45, 375};
	Point polygone2 = {10, 395};
	Point polygone3 = {80, 395};
	Point polygone4 = {10, 405};
	Point polygone5 = {80, 405};
	Point polygone6 = {45, 425};
	dessiner_ligne(polygone1, polygone2,noir);
	dessiner_ligne(polygone1, polygone3,noir);
	dessiner_ligne(polygone2, polygone4,noir);
	dessiner_ligne(polygone3, polygone5,noir);
	dessiner_ligne(polygone4, polygone6,noir);
	dessiner_ligne(polygone5, polygone6,noir);
	
	//cube
	Point cube = {25, 440};
	dessiner_rectangle(cube,40,40,noir);
	 
	//image
	Point image1 = {120,20};
	afficher_texte("IMAGE",15,image1,noir);
	
	//gomme
	Point gomme = {120, 65};
	afficher_texte("GOMME", 15, gomme, noir);
	
	//main levée
	Point stylo = {120, 110};
	afficher_texte("STYLO",15, stylo, noir);
	
	//remplissage
	Point remplissage = {120, 155};
	afficher_texte("REMPLISSAGE", 15, remplissage, noir);
	
	//texte
	Point texte = {120, 200};
	afficher_texte("TEXTE", 15, texte, noir);
		
	//bouton arrêt
	Point arret = {H - 30, 5};
	afficher_image("images/button-red.bmp", arret);
	
	//bouton clear
	Point clear = {H - 60,5};
	afficher_image("images/bouton-bleu.bmp", clear);
	
	//palette
	Point palette = {10,L-200};
	afficher_image("images/palette.bmp", palette);
	
	//epaisseur
	int i;
	Point epaisseur1 = {40, L-240};
	Point epaisseur2 = {80, L-240};
	Point epaisseur3 = {140, L-240};
	dessiner_disque(epaisseur1, 10, noir);
	dessiner_disque(epaisseur2, 15, noir);
	dessiner_disque(epaisseur3, 30, noir);	
	
	actualiser();
}

void rectangle_plein(Couleur couleur) // créé un rectangle à partir de deux points
{ 
	// colorie le rectangle plein du menu en rouge
	Point rectangle_plein1 = {10,200};
	dessiner_rectangle(rectangle_plein1,70,40,couleur);
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
	Point rectangle_1 = {10, 20};
	Point rectangle_2 = {10, 60};
	Point rectangle_3 = {80, 20};
	Point rectangle_4 = {80, 60};
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
	Point triangle_a = {45, 80};
	Point triangle_b = {10, 120};
	Point triangle_c = {80, 120};
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
	Point a = {10, 140};
	Point b = {80, 180};
	dessiner_ligne(a,b,couleur);
	actualiser();

	Point segment_1 = attendre_clic();
	Point segment_2 = attendre_clic();
	dessiner_ligne(segment_1,segment_2,couleur);
	reinit();
}

void charger_image(Couleur couleur)
{
	//colorie le texte quand sélectionné
	Point image = {120, 20};
	afficher_texte("IMAGE", 15, image, couleur);
	actualiser();	
	
	Point coin_image = attendre_clic();
	afficher_image("images/uhahah.bpm",coin_image);
}

int power(int a)
{
	return a*a;
}

void cercle_plein(Couleur couleur)
{
	// colorie le cercle plein du menu en rouge
	Point center = {45, 280};
	dessiner_disque(center, 20, couleur);
	actualiser();
	
	Point centre = attendre_clic();
	Point point = attendre_clic();
	int rayon = sqrt(power(centre.x - point.x) + power(centre.y - point.y));
	dessiner_disque(centre, rayon, couleur);
	reinit();
}

void cercle_vide(Couleur couleur)
{
	// colorie le cercle vide du menu avec la couleur choisie
	Point cercle_vide = {45,340};
	dessiner_cercle(cercle_vide, 20,couleur);
	actualiser();
	
	Point centre = attendre_clic();
	Point point = attendre_clic();
	int rayon = sqrt(power(centre.x - point.x) + power(centre.y - point.y));
	dessiner_cercle(centre, rayon, couleur);
	reinit();
}

void main_levee(Couleur couleur)
{
	//change la couleur du texte quand sélectionné
	Point stylo = {120,110};
	afficher_texte("STYLO", 15, stylo, couleur);
	actualiser();
	
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

void gomme(Couleur couleur)
{
	//colorie le texte quand sélectionné
	Point gomme = {120, 65};
	afficher_texte("GOMME", 15, gomme, couleur);
	actualiser();
	
	Point b = attendre_clic();
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

void polygone(Couleur couleur)
{
	//colorie le polygone du menu en la couleur choisie
	Point polygone1 = {45, 380};
	Point polygone2 = {10, 400};
	Point polygone3 = {80, 400};
	Point polygone4 = {10, 410};
	Point polygone5 = {80, 410};
	Point polygone6 = {45, 430};
	dessiner_ligne(polygone1, polygone2,couleur);
	dessiner_ligne(polygone1, polygone3,couleur);
	dessiner_ligne(polygone2, polygone4,couleur);
	dessiner_ligne(polygone3, polygone5,couleur);
	dessiner_ligne(polygone4, polygone6,couleur);
	dessiner_ligne(polygone5, polygone6,couleur);
	actualiser();
	
	Point a = attendre_clic();
	Point b;
	Point c = a;
	int i = 1;
		
	while (i == 1)
	{	
			b = attendre_clic_gauche_droite();
			if (b.x > 0)
			{
				dessiner_ligne(a,b,couleur);
				actualiser();
				a = b;
			}
			
			else 
			{
				i = 0;
			}
	}
	reinitialiser_evenements();
	dessiner_ligne(a,c,couleur);
	reinit();
}

Couleur couleur(Point a)
{
	if (a.x >= 162 && a.x <= 194 && a.y >= L - 150 && a.y <= L - 125) {return blanc;}
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
	Point coin = {(H/2) - 100, (L/2)};
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


void cube(Couleur couleur)
{
		//colorie le cube quand sélectionné
		Point cube = {25, 440};
		dessiner_rectangle(cube, 40, 40, couleur);
		actualiser();
		
		
		Point coin = attendre_clic();
		Point coin_4 = attendre_clic();
		int cote = (sqrt(power(coin.x - coin_4.x) + power(coin.y - coin_4.y))) / sqrt(2);
		Point coin_2 = {coin.x + cote, coin.y};
		Point coin_3 = {coin.x, coin.y + cote};
		
		dessiner_ligne(coin, coin_2, couleur);
		dessiner_ligne(coin, coin_3, couleur);
		dessiner_ligne(coin_2, coin_4, couleur);
		dessiner_ligne(coin_3, coin_4, couleur);
		
		Point cube_1 = {coin.x + (cote/2), coin.y - (cote/2)};
		Point cube_2 = {coin_2.x + (cote/2), coin_2.y - (cote/2)};
		Point cube_3 = {coin_4.x + (cote/2), coin_4.y - (cote/2)};
		dessiner_ligne(coin,cube_1,couleur);
		dessiner_ligne(coin_2, cube_2, couleur);
		dessiner_ligne(cube_1,cube_2,couleur);
		dessiner_ligne(coin_4, cube_3,couleur);
		dessiner_ligne(cube_2,cube_3,couleur); 
		
		reinit();
}

void remplissage(Point a, Couleur couleur)
{	
	if (couleur_point(a) == darkgray)
	{
		changer_pixel(a,couleur);
		Point b = {a.x + 1, a.y};
		Point c = {a.x - 1, a.y};
		Point d = {a.x, a.y + 1};
		Point e = {a.x, a.y - 1};
		remplissage(b, couleur);
		remplissage(c, couleur);
		remplissage(d, couleur);
		remplissage(e, couleur);
	}
	else 
	{
		return;
	}
}

int epaisseur(Point a)
{
	if (a.x >= 0 && a.x <= 50) return 1;
	if (a.x >= 70 && a.x <= 120) return 2;
	if (a.x >= 140 && a.x <= 190) return 3;
}

void cases()
{
    Point inter1 = {0,70};
    Point inter2 = {100,70};
    Point inter3 = {100,0};
    Point inter4 = {100,L-400};
    int i;
    int j;
    for ( i = 0; i <= 7;i++)
    {
        for ( j = 0; j <= 3 ; j++)
        {
            dessiner_ligne(inter1,inter2,noir);
            inter1.y += 1;
            inter2.y += 1;
        }

        inter1.y += 57;
        inter2.y += 57;

    }
    for ( j = 0; j <= 2 ; j++)
    {
        dessiner_ligne(inter3,inter4,noir);
        inter3.x += 1;
        inter4.x += 1;
    }
}

void texte(Couleur couleur)
{
		//colorie le texte quand sélectionné
		Point texte = {120,200};
		afficher_texte("TEXTE", 15, texte, couleur);
		char str[100];
		int taille;
		Point coin;
		printf("Que voulez-vous écrire ?\n");
		scanf("%s", str);
		printf("De quel taille ?\n");
		scanf("%d", &taille);
		printf("Cliquez sur l'endroit où vous voulez votre texte\n");
		coin = attendre_clic();
		afficher_texte(str, taille, coin, couleur);
		actualiser();	
}

void aide()
{
	Point aide_rectangle = {MARGE,L-200};
	Point a_cote_de_celui_la = {H, L-200};
    dessiner_rectangle(aide_rectangle,H-MARGE,200,blanc);
    dessiner_ligne(aide_rectangle, a_cote_de_celui_la, noir);
}
