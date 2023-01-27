#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
#include"agent.h"

etudiant TE[5000];
int ne=0;

enum
{
	ENOME,
	EPRENOME,
	EGENRE,
	EIDENTIFIANTE,
	ECHAMBRE,
	EETAGE,
	ENIVEAU,
	
	COLUMNS,
};


void viderliste_etudiant(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOME, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", EPRENOME, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text", EGENRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text", EIDENTIFIANTE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Chambre", renderer, "text", ECHAMBRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etage", renderer, "text", EETAGE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Niveau", renderer, "text", ENIVEAU, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}

	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);

		gtk_list_store_append(store, &iter);
		gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);

}



void trouver_etudiant(GtkWidget* liste, char f[],char choix[])
{
	int i;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL)
	{

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOME, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);	

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", EPRENOME, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text", EGENRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text", EIDENTIFIANTE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Chambre", renderer, "text", ECHAMBRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etage", renderer, "text", EETAGE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Niveau", renderer, "text", ENIVEAU, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_INT);



	if(strcmp(choix,"Identifiant")==0){
		for(i=0;i<ne;i++)
		{
			if(strncmp(TE[i].identifiantE,f,strlen(f))==0)
			{
				gtk_list_store_append(store, &iter);
				gtk_list_store_set(store, &iter,ENOME, TE[i].nomE, EPRENOME, TE[i].prenomE,EGENRE, TE[i].genre, EIDENTIFIANTE, TE[i].identifiantE ,ECHAMBRE , TE[i].num_chambre, EETAGE, TE[i].num_etage,ENIVEAU, TE[i].niveau,-1);
			}}}

	else
		if(strcmp(choix,"Nom")==0){
			for(i=0;i<ne;i++)
			{
				if(strncmp(TE[i].nomE,f,strlen(f))==0)
				{
					gtk_list_store_append(store, &iter);
					gtk_list_store_set(store, &iter,ENOME, TE[i].nomE, EPRENOME, TE[i].prenomE,EGENRE, TE[i].genre, EIDENTIFIANTE, TE[i].identifiantE ,ECHAMBRE , TE[i].num_chambre, EETAGE, TE[i].num_etage,ENIVEAU, TE[i].niveau,-1);
				}}}

	else
			if(strcmp(choix,"Prenom")==0){
				for(i=0;i<ne;i++)
				{
					if(strncmp(TE[i].prenomE,f,strlen(f))==0)
					{
						gtk_list_store_append(store, &iter);
						gtk_list_store_set(store, &iter,ENOME, TE[i].nomE, EPRENOME, TE[i].prenomE,EGENRE, TE[i].genre, EIDENTIFIANTE, TE[i].identifiantE ,ECHAMBRE , TE[i].num_chambre, EETAGE, TE[i].num_etage,ENIVEAU, TE[i].niveau,-1);
					}}}

	else{
					for(i=0;i<ne;i++)
					{

							gtk_list_store_append(store, &iter);
							gtk_list_store_set(store, &iter, ENOME, TE[i].nomE, EPRENOME, TE[i].prenomE,EGENRE, TE[i].genre, EIDENTIFIANTE, TE[i].identifiantE ,ECHAMBRE , TE[i].num_chambre, EETAGE, TE[i].num_etage,ENIVEAU, TE[i].niveau,-1);




	/*for(i=0;i<ne;i++)
	{ 
		if (strncmp(TE[i].identifiantE,f,strlen(f))==0)
		{

		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ENOME, TE[i].nomE, EPRENOME, TE[i].prenomE,EGENRE, TE[i].genre, EIDENTIFIANTE, TE[i].identifiantE ,ECHAMBRE , TE[i].num_chambre, EETAGE, TE[i].num_etage,ENIVEAU, TE[i].niveau,-1);

*/
	}
	}



	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}


void afficher_etudiant(GtkWidget* liste)
{

	int i;

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;

	store=NULL;
	store=gtk_tree_view_get_model(liste);
	if(store==NULL){
		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Nom", renderer, "text", ENOME, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Prenom", renderer, "text", EPRENOME, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Genre", renderer, "text", EGENRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Identifiant", renderer, "text", EIDENTIFIANTE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);


		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Chambre", renderer, "text", ECHAMBRE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Etage", renderer, "text", EETAGE, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("Niveau", renderer, "text", ENIVEAU, NULL);
		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);
	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_STRING, G_TYPE_INT);

	for(i=0;i<ne;i++)
	{
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, ENOME, TE[i].nomE, EPRENOME, TE[i].prenomE,EGENRE, TE[i].genre, EIDENTIFIANTE, TE[i].identifiantE,ECHAMBRE , TE[i].num_chambre, EETAGE, TE[i].num_etage,ENIVEAU, TE[i].niveau,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}


void ajout_etudiant(etudiant E)
{
    TE[ne]=E;
    ne++;
}


int nospace_etudiant(char s[])
{
int i=0;
  do{
    if(s[i]==' '){return 0;}
    i++;
  }while (s[i]!='\0') ;
  return 1;
}


  int isalphabet_etudiant(char t[])
  {
  int i=0,k;
  do{
    k=t[i];
    if(((k<97)||(k>122))&&((k<65)||(k>90))){return 0;}
    i++;
  }while (t[i]!='\0') ;
  return 1;
}

int uniqueid_etudiant (char t[])
{
  int i=0;
  for(i=0;i<ne;i++)
  {
      if(strcmp(t,TE[i].identifiantE)==0)
      {
          return i;
      }
  }
  return -1;
}

int isint_etudiant(char t[])
{
    int i=0;
  while (t[i]!='\0'){
    if((t[i]<'0')||(t[i]>'9')){printf("%d not integer\n",i);return 0;}
    i++;
  }
  return 1;
}



  int supprimer_etudiant(char identifiant[])
{
    int i,j;
    for(i=0;i<ne;i++)
    {
        if(strcmp(identifiant,TE[i].identifiantE)==0)
        {
            for(j=i;j<ne;j++)
            {
                TE[j]=TE[j+1];


            }
	    ne--;	
            return 1;
        }

    }
return 0;
}


int modifier_etudiant(etudiant E)
{
    int i;
    for(i=0;i<ne;i++)
    {
        if(strcmp(E.identifiantE,TE[i].identifiantE)==0)
        {
            TE[i]=E;
            return 1;
        }
    }
return 0;
}


void afficheniveau(int tab[])
{
int i;
for(i=0;i<5;i++){
tab[i]=0;}
for(i=0;i<ne;i++)
 {

     if (TE[i].niveau==1)
       tab[0]++;
    else if (TE[i].niveau==2)
       tab[1]++;
     else if (TE[i].niveau==3)
       tab[2]++;
    else if (TE[i].niveau==4)
       tab[3]++;
    else if (TE[i].niveau==5)
       tab[4]++;
  }
}




  int filesave_etudiant()
{
    int i;
    FILE *f;
    f=fopen("etudiantheberge.txt","w+");
    if(f==NULL){ return 0;}
    for(i=0;i<ne;i++)
    {
        fprintf(f,"%s %s %s %s %s %s %d\n",TE[i].nomE,TE[i].prenomE,TE[i].genre,TE[i].identifiantE,TE[i].num_chambre,TE[i].num_etage,TE[i].niveau);
    }
    fclose(f);
    return 1;

}


int fileload_etudiant()
{  
    ne=0;
    
    FILE *f=NULL;
    f=fopen("etudiantheberge.txt","r+");
    if(f==NULL)
    { 
     return 0;
    }
    while(fscanf(f,"%s %s %s %s %s %s %d\n",TE[ne].nomE,TE[ne].prenomE,TE[ne].genre,TE[ne].identifiantE,TE[ne].num_chambre,TE[ne].num_etage,&TE[ne].niveau)!=EOF)
    {
        ne++;
    }

    fclose(f);
    return ne;

}

