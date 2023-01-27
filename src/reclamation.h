#ifndef RECLAMATION_H_
#define RECLAMATION_H_
#include <gtk/gtk.h>

typedef struct datee{
  int jour;
  int mois;
  int annee;
}datee;

struct reclamation
{
char id[15];
char nom[30];
char categorie[30];
char description[100];
datee date;
};
typedef struct reclamation reclamation;

int datecmp_rec(datee x,datee y);
void ajout_rec(reclamation x);
void viderliste(GtkWidget *liste);
int isalphabet_rec(char t[]);
int isid_rec(char t[]);
int isint_rec(char t[]);
int supprimer_rec(char id[]);
int modifier_rec(reclamation x);
void afficher_rec(GtkWidget* liste);
void rechercher_rec(GtkWidget* liste, char k[]);
int nospace_rec(char s[]);
int filesave_rec();
int fileload_rec();
#endif
