#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include "stock.h"

stock t[7000];
int n_stock=0;
enum
{
	En_p,
	Ety_p,
	Eid,
	Em_s,
	Eqtd,
	COLUMNS,
};

void viderliste_stock(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("N_P", renderer, "text", En_p, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TY_P", renderer, "text", Ety_p, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", Eid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("M_S", renderer, "text", Em_s, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("QTD", renderer, "text", Eqtd, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

		gtk_list_store_append(store, &iter);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
}


void trouver_stock(GtkWidget* liste, int i){



	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("N_P", renderer, "text", En_p, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TY_P", renderer, "text", Ety_p, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", Eid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("M_S", renderer, "text", Em_s, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("QTD", renderer, "text", Eqtd, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);


			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store, &iter, En_p, t[i].N_P, Ety_p, t[i].TY_P, Eid, t[i].ID, Em_s, t[i].M_S, Eqtd, t[i].QTD,-1);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}



void afficher_stock(GtkWidget* liste){

	int i;
        fileload_stock();

GtkCellRenderer *renderer=NULL;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("N_P", renderer, "text", En_p, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TY_P", renderer, "text", Ety_p, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", Eid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("M_S", renderer, "text", Em_s, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("QTD", renderer, "text", Eqtd, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	for(i=0;i<n_stock;i++)
	{
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, En_p, t[i].N_P, Ety_p, t[i].TY_P, Eid, t[i].ID, Em_s, t[i].M_S, Eqtd, t[i].QTD,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}

int nospace_stock(char s[])
{
int i=0;
  do{
    if(s[i]==' '){return 0;}
    i++;
  }while (s[i]!='\0') ;
  return 1;
}

 void ajouts_stock(stock x )
 {
 t[n_stock]=x;
 n_stock++;
}

int isalphabet_stock(char t[])
{
  int i=0;
  do{
    if(((t[i]<'a')||(t[i]>'z'))&&((t[i]<'A')||(t[i]>'Z'))){return 0;}
    i++;
  }while (t[i]!='\0') ;
  return 1;
}


  int supprimer_stock( char idd[] )
{
    int i,j;
    for(i=0;i<n_stock;i++)
    {
        if(strcmp(idd,t[i].ID)==0)
        {
            for(j=i;j<n_stock;j++)
            {
                t[j]=t[j+1];

            }           n_stock--;
            return 1;
        }
    }
    return 0;
}
int isid_stock (char tt[]){
  int i=0;
  for(i=0;i<n_stock;i++)
  {
      if(strcmp(tt,t[i].ID)==0)
      {
          return i;
      }
  }
  return -1;
}

int isint_stock(char tt[])
{
    int i=0;
  while (tt[i]!='\0'){
    if((tt[i]<'0')||(tt[i]>'9')){printf("%d not integer\n",i);return 0;}
    i++;
  }
  return 1;
}

  int modifier_stock(stock x)
{
    int i;
    for(i=0;i<n_stock;i++)
    {
        if(strcmp(x.ID,t[i].ID)==0)
        {
            t[i]=x;
            return 1;
        }
    }
    return 0;
}


  int filesave_stock()
{
    int i;
    FILE *f;
    f=fopen("STOCK.txt","w+");
    if(f==NULL){printf("error reading file"); return 0;}
    for(i=0;i<n_stock;i++)
    {
        fprintf(f,"%s %s %s %s %s\n",t[i].N_P,t[i].TY_P,t[i].ID,t[i].M_S,t[i].QTD);
    }
    fclose(f);
    return 1;
}

int fileload_stock()
{
    n_stock=0;
    FILE *f=NULL;
    f=fopen("STOCK.txt","r+");
    if(f==NULL){printf("error reading file"); return 0;}
    while(fscanf(f,"%s %s %s %s %s\n",t[n_stock].N_P,t[n_stock].TY_P,t[n_stock].ID,t[n_stock].M_S ,t[n_stock].QTD)!=EOF){
        n_stock++;
    }
    fclose(f);
    return n_stock;
}
char Verifier_Rupture_stock(stock x)
{
 int i;
char s[100];
    for(i=0;i<n_stock;i++)
    {
        if(atoi(t[i].QTD)==0)
        {
            strcpy(s,t[i].ID);
        }
    }
return s ;
}

int afficher_repture_stock(GtkWidget* liste){

	int i;
	int test=0;
        fileload_stock();

	GtkCellRenderer *renderer=NULL;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("N_P", renderer, "text", En_p, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("TY_P", renderer, "text", Ety_p, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("ID", renderer, "text", Eid, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("M_S", renderer, "text", Em_s, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("QTD", renderer, "text", Eqtd, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING);

	for(i=0;i<n_stock;i++)
	{
		if(strcmp(t[i].QTD,"0")==0){
			test = 1;
			gtk_list_store_append(store, &iter);
			gtk_list_store_set(store, &iter, En_p, t[i].N_P, Ety_p, t[i].TY_P, Eid, t[i].ID, Em_s, t[i].M_S, Eqtd, t[i].QTD,-1);
		}
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

	return test;

}
