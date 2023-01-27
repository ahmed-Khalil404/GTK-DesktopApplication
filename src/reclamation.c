#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "reclamation.h"

reclamation tr[10000];
int nr=0;

enum
{
	Erecname,
	Erecid,
	Ereccateg,
	Erecdescription,
        Erecdate,
	COLUMNS
};

void viderliste_rec(GtkWidget *liste)
{
        char date[50] ;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	store=NULL;
	store=gtk_tree_view_get_model(liste);

	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("reclamation_name", renderer, "text", Erecname, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("reclamation_id", renderer, "text", Erecid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("categories", renderer, "text", Ereccateg, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("description", renderer, "text", Erecdescription, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("date", renderer, "text", Erecdate, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING);

		gtk_list_store_append(store, &iter);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
}


void rechercher_rec(GtkWidget* liste, char k[])
{
	int  i;
        char date[50] ;
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
        store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("reclamation_name", renderer, "text", Erecname, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("reclamation_id", renderer, "text", Erecid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("categories", renderer, "text", Ereccateg, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("description", renderer, "text", Erecdescription, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("date", renderer, "text", Erecdate, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
		renderer = gtk_cell_renderer_text_new ();
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING , G_TYPE_STRING);
	for (i=0;i<nr;i++){
		if(strncmp(k,tr[i].id,strlen(k))==0){
				sprintf(date,"%d/%d/%d", tr[i].date.jour,tr[i].date.mois,tr[i].date.annee);
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, Erecname, tr[i].nom, Erecid, tr[i].id, Ereccateg, tr[i].categorie, Erecdescription, tr[i].description, Erecdate , date,-1);
	}}

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
}



void afficher_rec(GtkWidget* liste)
{
        int i;
        char date[50] ;
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
        store=gtk_tree_view_get_model(liste);

	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("reclamation_name", renderer, "text", Erecname, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("reclamation_id", renderer, "text", Erecid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("categories", renderer, "text", Ereccateg, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("description", renderer, "text", Erecdescription, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

                renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("date", renderer, "text", Erecdate, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	for(i=0;i<nr;i++)
	{ sprintf(date,"%d/%d/%d", tr[i].date.jour,tr[i].date.mois,tr[i].date.annee);
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, Erecname, tr[i].nom, Erecid, tr[i].id, Ereccateg, tr[i].categorie, Erecdescription, tr[i].description, Erecdate , date,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}

void ajout_rec(reclamation x )
{
    tr[nr]=x;
    nr++;
}

int nospace_rec(char s[])
{
int i=0;
  do{
    if(s[i]==' '){return 0;}
    i++;
  }while (s[i]!='\0') ;
  return 1;
}


int isalphabet_rec(char t[])
{
  int i=0;
  do{
    if(((t[i]<'a')||(t[i]>'z'))&&((t[i]<'A')||(t[i]>'Z'))){return 0;}
    i++;
  }while (t[i]!='\0') ;
  return 1;
}

int isid_rec (char t[])
{
  int i=0,b=0;
  while(t[b]!='\0'){
    if((t[b]<'0')||(t[b]>'9')){return -1;}
    b++;
  }
  for(i=0;i<nr;i++)
  {
      if(strcmp(t,tr[i].id)==0)
      {

          return i;
      }
  }
  return -1;
}

int isint_rec(char t[])
{
    int i=0;
  while (t[i]!='\0'){
    if((t[i]<'0')||(t[i]>'9')){return 0;}
    i++;
  }
  return 1;
}

int supprimer_rec(char id[])
{
    int i,j;
    for(i=0;i<nr;i++)
    {
        if(strcmp(id,tr[i].id)==0)
        {
	    if(i==nr-1){nr--; return 1;}
            for(j=i;j<nr;j++)
            {
                tr[j]=tr[j+1];

            }
            return 1;
        }
    }
    return 0;
}

int modifier_rec(reclamation x)
{
    int i;
    for(i=0;i<nr;i++)
    {
        if(strcmp(x.id,tr[i].id)==0)
        {
            tr[i]=x;
            return 1;
        }
    }
    return 0;
}

int datecmp_rec(datee x,datee y)
{
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

int filesave_rec()
{
    int i;
    FILE *f;
    f=fopen("reclamation.txt","w+");
    if(f==NULL){printf("error reading file"); return 0;}
    for(i=0;i<nr;i++)
    {
        fprintf(f,"%d %d %d %s %s %s %s\n",tr[i].date.jour,tr[i].date.mois,tr[i].date.annee,tr[i].nom,tr[i].id,tr[i].categorie,tr[i].description);
    }
    fclose(f);
    return 1;

}


int fileload_rec()
{
    nr=0;
    FILE *f=NULL;
    f=fopen("reclamation.txt","r+");
    if(f==NULL){printf("error reading file"); return 0;}
    while(fscanf(f,"%d %d %d %s %s %s %s\n",&tr[nr].date.jour,&tr[nr].date.mois,&tr[nr].date.annee,tr[nr].nom,tr[nr].id,tr[nr].categorie,tr[nr].description)
    !=EOF){
        nr++;
    }
    fclose(f);
    return nr;

}
