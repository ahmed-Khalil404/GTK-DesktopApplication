#ifndef CAPTEUR_H_INCLUDED
#define CAPTEUR_H_INCLUDED
#include <gtk/gtk.h>



typedef struct {
char id[20];
char type[20];
char position[20];
char etat[20];
char valeur[20]
}capteur;

typedef struct {
char idx[20];
int jour;
int mois;
float val;
}capteurx;



void afficher_capteur(GtkWidget* liste);
void afftrouver_capteur(GtkWidget* liste, int i);
void viderliste_capteur(GtkWidget *liste);
int nospace_capteur(char s[]);
void ajout_capteur( capteur x );
int isalphabet_capteur(char t[]);
int isid_capteur(char t[]);
int isint_capteur(char t[]);
int supprimer_capteur(char id[]);
int modifier_capteur(capteur x);
int fileload_capteur();
int filesave_capteur();
int chercheralarmemouvement_capteur(GtkWidget* treeview2,char*l);
int chercheralarmefumee_capteur(GtkWidget* treeview3,char*l);

#endif
