#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "admin.h"

enum
{
	ENOM,
	EPRENOM,
	EUSER,
	EROLE,
	EVALID,
	COLUMNS,
};



users T[5000];
int n=0;









int isnotflagged(int a,int x[], int k){
int i;
for(i=0;i<k;i++)
{
    if(a==x[i])
    {
        return 0;
    }
}
return 1;
}







void viderliste(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", EPRENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text", EUSER, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Departement", renderer, "text", EROLE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Validite", renderer, "text", EVALID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		gtk_list_store_append(store, &iter);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
}


void afftrouver(GtkWidget* liste, char x[], char crtr[]){


	int i;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", EPRENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text", EUSER, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Departement", renderer, "text", EROLE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Validite", renderer, "text", EVALID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);
	if(strcmp(crtr,"Nom d'utilisateur")==0){
		for(i=0;i<n;i++)
		{
			if(strncmp(T[i].user,x,strlen(x))==0)
			{
				gtk_list_store_append(store, &iter);
				gtk_list_store_set(store, &iter, ENOM, T[i].nom, EPRENOM, T[i].prenom, EUSER, T[i].user, EROLE, T[i].role, EVALID, T[i].valid,-1);
			}}}
		else
		if(strcmp(crtr,"Nom")==0){
			for(i=0;i<n;i++)
			{
				if(strncmp(T[i].nom,x,strlen(x))==0)
				{
					gtk_list_store_append(store, &iter);
					gtk_list_store_set(store, &iter, ENOM, T[i].nom, EPRENOM, T[i].prenom, EUSER, T[i].user, EROLE, T[i].role, EVALID, T[i].valid,-1);
				}}}
			else
			if(strcmp(crtr,"Prenom")==0){
				for(i=0;i<n;i++)
				{
					if(strncmp(T[i].prenom,x,strlen(x))==0)
					{
						gtk_list_store_append(store, &iter);
						gtk_list_store_set(store, &iter, ENOM, T[i].nom, EPRENOM, T[i].prenom, EUSER, T[i].user, EROLE, T[i].role, EVALID, T[i].valid,-1);
					}}}
				else{
					for(i=0;i<n;i++)
					{

							gtk_list_store_append(store, &iter);
							gtk_list_store_set(store, &iter, ENOM, T[i].nom, EPRENOM, T[i].prenom, EUSER, T[i].user, EROLE, T[i].role, EVALID, T[i].valid,-1);
					}}

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}



void afficher(GtkWidget* liste){

	int i;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", EPRENOM, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom d'utilisateur", renderer, "text", EUSER, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Departement", renderer, "text", EROLE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Validite", renderer, "text", EVALID, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	for(i=0;i<n;i++)
	{
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ENOM, T[i].nom, EPRENOM, T[i].prenom, EUSER, T[i].user, EROLE, T[i].role, EVALID, T[i].valid,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void setvalide(int i, int c)
{
if(c==1){
	strcpy(T[i].valid,"valide");
	}
else{
	strcpy(T[i].valid,"nonvalide");

	}
}

int checkauth(char pw[],int i)
{
	if ((i!=-1)&&(strcmp(pw,T[i].pw)==0)&&(strcmp("valide",T[i].valid)==0)) {return 1;}
	else{return 0;}
}


users getuser( int i){
	users s;
	s=T[i];
	return s;

}

int nospace(char s[])
{
int i=0;
  do{
    if(s[i]==' '){return 0;}
    i++;
  }while (s[i]!='\0') ;
  return 1;
}

void ajout(users x, int k){
    T[n]=x;
		if(k==1){
    strcpy(T[n].valid,"valide");}
		else{
		strcpy(T[n].valid,"nonvalide");}
    n++;
}




int isalphabet(char t[]){
  int i=0,k;
  do{
    k=t[i];
    if(((k<97)||(k>122))&&((k<65)||(k>90))){return 0;}
    i++;
  }while (t[i]!='\0') ;
  return 1;
}

int isid (char t[]){
  int i=0;
  for(i=0;i<n;i++)
  {
      if(strcmp(t,T[i].user)==0)
      {
          return i;
      }
  }
  return -1;
}

int isint(char t[])
{
    int i=0;
  while (t[i]!='\0'){
    if((t[i]<'0')||(t[i]>'9')){printf("%d not integer\n",i);return 0;}
    i++;
  }
  return 1;
}

int supprimer(char user[])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        if(strcmp(user,T[i].user)==0)
        {
					if(i==n-1){n--; return 1;}
            for(j=i;j<n;j++)
            {
                T[j]=T[j+1];


            }
            n--; return 1;
        }
    }
    return 0;
}



int modifier( users x)
{
	char temp[30];
    int i;
    for(i=0;i<n;i++)
    {
        if(strcmp(x.user,T[i].user)==0)
        {
	strcpy(temp,T[i].valid);
	T[i]=x;
	strcpy(T[i].valid,temp);
            return 1;
        }
    }
    return 0;
}


int datecmp(date x,date y){
	if(x.annee>y.annee)
	return 1;
	else
	if(x.annee<y.annee)
	return -1;

	if(x.mois>y.mois)
	return 1;
	else
	if(x.mois<y.mois)
	return -1;

	if(x.jour>y.jour)
	return 1;
	else
	if(x.jour<y.jour)
	return -1;
	else
	if (x.jour==y.jour)
	return 0;

}



int filesave()
{
    int i;
    FILE *f;
    f=fopen("users.txt","w+");
    if(f==NULL){ return 0;}
    for(i=0;i<n;i++)
    {
        fprintf(f,"%s %s %s %s %s %s\n",T[i].nom,T[i].prenom,T[i].user,T[i].pw,T[i].role,T[i].valid);
    }
    fclose(f);
    return 1;

}
int fileload()
{
    n=0;
    FILE *f=NULL;
    f=fopen("users.txt","r+");
    if(f==NULL){ return 0;}
    while(fscanf(f,"%s %s %s %s %s %s\n",T[n].nom,T[n].prenom,T[n].user,T[n].pw,T[n].role,T[n].valid)!=EOF){
        n++;
    }
    fclose(f);
    return 1;

}
