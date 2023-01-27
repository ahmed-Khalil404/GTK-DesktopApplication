
#define FONCTION_H_INCLUDED
#include <gtk/gtk.h>
typedef struct stock 
{
char ID[30];
char N_P[30];
char TY_P[30];
char M_S[30];
char QTD[30] ;
} stock ;
void afficher_stock(GtkWidget* liste);
void trouver_stock(GtkWidget* liste, int i);
void viderliste_stock(GtkWidget *liste);
 void ajouts_stock(stock x);
  int isalphabet_stock(char t[]);
  int isid_stock( char t[]);
  int isint_stock(char t[]);
  int supprimer_stock( char ID[]);
  int modifier_stock(stock x);
  int filesave_stock();
  int fileload_stock();
int nospace_stock(char s[]);
int afficher_repture_stock(GtkWidget* liste);

