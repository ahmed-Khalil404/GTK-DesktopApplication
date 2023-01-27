#ifndef NUTRITIONISTE_H_INCLUDED
#define NUTRITIONISTE_H_INCLUDED
#include <gtk/gtk.h>





typedef struct dateou{
  int jour;
  int mois;
  int annee;
}dateou;



struct menu
{
char idog[100];
dateou d;
char type[100];
char repas[100];
float qd;
char ds[100];
};
typedef struct menu menu;
//void recherche_une_menu(GtkWidget* liste, int i)
void afficher_menu(GtkWidget* liste);
void ajouter_menu(menu m );
menu saisie_menu(menu T[],int n);
menu saisiemod_menu(menu T[],int n);
int isid_menu( char t[]);
int isalphabet_menu(char t[]);
int isint_menu(char t[]);
int supprimer_menu(char idog[]);
int modifier_menu(menu x );
/*void recherche(GtkWidget* liste, int i);*/
int filesave_menu();
int fileload_menu();
void afficher_menu_rechercher(GtkWidget *liste);
int meuilleur_menu();
void recherche_menu(idog);

#endif // FONCTIONC_H_INCLUDED
