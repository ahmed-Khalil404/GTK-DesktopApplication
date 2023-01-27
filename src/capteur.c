#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "capteur.h"
GtkListStore *adstore;/*creation du modele de type liste*/
GtkTreeViewColumn *adcolumn;/*visualisation des colonnes*/
GtkCellRenderer *cellad;/*afficheur de cellule(text,image..)*/
FILE *f;
int h ;
FILE *f1;
int h1 ;




capteur T_capt[5000];
int n_capt=0;




enum
{
	EID,
	ETYPE,
	EPOSITION,
	EETAT,
	EVALEUR,
	COLUMNS,
};

void afficher_capteur(GtkWidget* liste){

	int i;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TYPE", renderer, "text", ETYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("POSITION", renderer, "text", EPOSITION, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ETAT", renderer, "text", EETAT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("VALEUR", renderer, "text", EVALEUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	for(i=0;i<n_capt;i++)
	{
	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, EID, T_capt[i].id, ETYPE, T_capt[i].type, EPOSITION, T_capt[i].position, EETAT, T_capt[i].etat, EVALEUR, T_capt[i].valeur,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void afftrouver_capteur(GtkWidget* liste, int i){



	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TYPE", renderer, "text", ETYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("POSITION", renderer, "text", EPOSITION, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ETAT", renderer, "text", EETAT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("VALEUR", renderer, "text", EVALEUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


	gtk_list_store_append(store, &iter);
	gtk_list_store_set(store, &iter, EID, T_capt[i].id, ETYPE, T_capt[i].type, EPOSITION, T_capt[i].position, EETAT, T_capt[i].etat, EVALEUR, T_capt[i].valeur,-1);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void viderliste_capteur(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", EID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TYPE", renderer, "text", ETYPE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("POSITION", renderer, "text", EPOSITION, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ETAT", renderer, "text", EETAT, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("VALEUR", renderer, "text", EVALEUR, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		gtk_list_store_append(store, &iter);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
}


int nospace_capteur(char s[])
{
int i=0;
  do{
    if(s[i]==' '){return 0;}
    i++;
  }while (s[i]!='\0') ;
  return 1;
}

void ajout_capteur(capteur x){
    T_capt[n_capt]=x;
    n_capt++;
}




int isalphabet_capteur(char t[]){
  int i=0,k;
  do{
    k=t[i];
    if(((k<97)||(k>122))&&((k<65)||(k>90))){return 0;}
    i++;
  }while (t[i]!='\0') ;
  return 1;
}

int isid_capteur(char t[]){
  int i=0;
  for(i=0;i<n_capt;i++)
  {
      if(strcmp(t,T_capt[i].id)==0)
      {
          return i;
      }
  }
  return -1;
}

int isint_capteur(char t[])
{
    int i=0;
  while (t[i]!='\0'){
    if((t[i]<'0')||(t[i]>'9')){printf("%d not integer\n",i);return 0;}
    i++;
  }
  return 1;
}

int supprimer_capteur(char id[])
{
    int i,j;
    for(i=0;i<n_capt;i++)
    {
        if(strcmp(id,T_capt[i].id)==0)
        {
            for(j=i;j<n_capt;j++)
            {
                T_capt[j]=T_capt[j+1];


            }
            n_capt--; return 1;
        }
    }
    return 0;
}



int modifier_capteur( capteur x)
{
	char temp[30];
    int i;
    for(i=0;i<n_capt;i++)
    {
        if(strcmp(x.id,T_capt[i].id)==0)
        {
	T_capt[i]=x;
            return 1;
        }
    }
    return 0;
}





int filesave_capteur()
{
    int i;
    FILE *f;
    f=fopen("capteur.txt","w+");
    if(f==NULL){ return 0;}
    for(i=0;i<n_capt;i++)
    {
        fprintf(f,"%s %s %s %s %s\n",T_capt[i].id,T_capt[i].type,T_capt[i].position,T_capt[i].etat,T_capt[i].valeur);
    }
    fclose(f);
    return 1;

}
int fileload_capteur()
{
    n_capt=0;
    FILE *f=NULL;
    f=fopen("capteur.txt","r+");
    if(f==NULL){ return 0;}
    while(fscanf(f,"%s %s %s %s %s\n",T_capt[n_capt].id,T_capt[n_capt].type,T_capt[n_capt].position,T_capt[n_capt].etat,T_capt[n_capt].valeur)!=EOF){
        n_capt++;
    }
    fclose(f);
    return 1;

}

int chercheralarmemouvement_capteur(GtkWidget* treeview2,char*l)
{

capteurx c;
int nb=0;
float max=1;
        /* Creation du modele */
        adstore = gtk_list_store_new(4,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_STRING,
                                     G_TYPE_FLOAT);
        /* Insertion des elements */
        f=fopen(l,"r");
while(fscanf(f,"%d %d %s %f\n",&c.jour,&c.mois,c.idx,&c.val)!=EOF)
        {
if(c.val==max){nb++;
GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.jour ,
                            1,c.mois,
                            2,c.idx,
                            3,c.val,-1);}
}
        fclose(f);

/* Creation de la 1ere colonne */
if(h==0)
{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Jour",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);



/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Mois",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
/* Ajouter la 4emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID mouve",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
/* Ajouter la 5emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);

        /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Valeur",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);

/* Ajouter la 7emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview2), adcolumn);  

h++;}


  gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview2),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}
int chercheralarmefumee_capteur(GtkWidget* treeview3,char*l)
{

capteurx c;
int nb=0;
float max=1;
        /* Creation du modele */
        adstore = gtk_list_store_new(4,
                                     G_TYPE_INT,
                                     G_TYPE_INT,
                                     G_TYPE_STRING,
                                     G_TYPE_FLOAT);
        /* Insertion des elements */
        f1=fopen(l,"r");
while(fscanf(f1,"%d %d %s %f\n",&c.jour,&c.mois,c.idx,&c.val)!=EOF)
        {
if(c.val==max){nb++;
GtkTreeIter pIter;
         /* Creation de la nouvelle ligne */
         gtk_list_store_append(adstore, &pIter);
         /* Mise a jour des donnees */
         gtk_list_store_set(adstore, &pIter,
                            0,c.jour ,
                            1,c.mois,
                            2,c.idx,
                            3,c.val,-1);}
}
        fclose(f1);

/* Creation de la 1ere colonne */
if(h1==0)
{cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Jour",
                                                            cellad,
                                                            "text", 0,
                                                            NULL);


        /* Ajouter la 1er colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);



/* Creation de la 4eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Mois",
                                                            cellad,
                                                            "text", 1,
                                                            NULL);
/* Ajouter la 4emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

/* Creation de la 5eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("ID fumee",
                                                            cellad,
                                                            "text", 2,
                                                            NULL);
/* Ajouter la 5emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);

        /* Creation de la 6eme colonne */
        cellad = gtk_cell_renderer_text_new();
        adcolumn = gtk_tree_view_column_new_with_attributes("Valeur",
                                                            cellad,
                                                            "text", 3,
                                                            NULL);

/* Ajouter la 7emme colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(treeview3), adcolumn);  

h1++;}


  gtk_tree_view_set_model ( GTK_TREE_VIEW (treeview3),
                                  GTK_TREE_MODEL(adstore)  );
return nb;
}
