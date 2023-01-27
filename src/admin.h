#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include <gtk/gtk.h>

typedef struct date{
  int jour;
  int mois;
  int annee;
}date;

typedef struct rec{
  char service[50];
  char commentaire[1000];
  date date;
}rec;

typedef struct capteur
{
    int heure;
    int jour;
    int id;
    float val;

}capteur2;

typedef struct slist{
	char s[100];
}slist;

typedef struct users{
char nom[30];
char prenom[30];
char user[30];
char pw[30];
char role[30];
char valid[30];
}users;

users getuser( int i);
int isnotflagged(int a,int x[], int k);
int datecmp(date x,date y);
void afftrouver(GtkWidget* liste,char x[], char crtr[]);
void viderliste(GtkWidget *liste);
void afficher(GtkWidget* liste);
void setvalide(int i, int c);
int nospace(char s[]);
void ajout( users x, int k );
int isalphabet(char t[]);
int isid(char t[]);
int isint(char t[]);
int supprimer(char user[]);
int modifier(users x);
int recherche( char user[]);
int checkauth(char pw[],int i);
int fileload();
int filesave();
#endif
