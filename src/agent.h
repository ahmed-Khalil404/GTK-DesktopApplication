#ifndef AGENT_H_INCLUDED
#define AGENT_H_INCLUDED
#include<gtk/gtk.h>

typedef struct etudiant
{
char nomE[30];
char prenomE[30];
char identifiantE[30];
char genre[30];
char num_etage[30];
char num_chambre[30];	
int niveau;

}etudiant;


void ajout_etudiant(etudiant E);
int supprimer_etudiant(char identifiant[]);
int modifier_etudiant(etudiant E);
int recherche_etudiant(char identifiant[]);
void afficher_etudiant(GtkWidget *liste);
void afficheniveau(int tab[]);
void trouver_etudiant(GtkWidget* liste, char f[],char choix[]);
void viderliste_etudiant(GtkWidget *liste);

int nospace_etudiant(char s[]);
int isalphabet_etudiant(char t[]);
int uniqueid_etudiant(char t[]);
int isint_etudiant(char t[]);
int fileload_etudiant();
int filesave_etudiant();
#endif // AGENT_H_INCLUDED
