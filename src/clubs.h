#ifndef CLUBS_H_
#define CLUBS_H_

struct club
{
    char clubname[50];
    char clubid[15];
    char clubmembers[10];
    char eventnum[100];
};
typedef struct club club;


void afftrouver_clubs(GtkWidget* liste, char m[]);
void viderliste_clubs(GtkWidget *liste);
club getactiveclub_clubs();
void listclr_clubs(GtkWidget *liste);
void afficherc_clubs(GtkWidget* liste);
void ajout_clubs(club x);
int isalphabet_clubs(char t[]);
int isid_clubs(char t[]);
int isint_clubs(char t[]);
int supprimer_clubs(char id[]);
int modifier_clubs(club x);
club getactivecluba_clubs();
void clubactif_clubs();
int filesave_clubs();
int fileload_clubs();
char find_clubs(char id);
char find1_clubs(char id);
#endif
