#include <stdio.h>
#include <string.h>
#include "nutritioniste.h"
#include <string.h>
#include <gtk/gtk.h>

menu T[1000];
int n_menu=0;
enum
{
	EID,
	EJOUR,
        EMOIS,
        EANNEE,
	ETYPE,
	EREPAS,
	EQUANTITE,
        EDS,
	COLUMNS,
};
//////////////////////
void afficher_menu_rechercher(GtkWidget *liste)
{
        GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter    iter;
	GtkListStore *store;

char idog[30];
char repas[30];
char type[30];
char ds[30];
dateou d;
float qd;

 store=NULL;

        fileload_menu();
	store=gtk_tree_view_get_model(liste);
	if (store==NULL)
	{
                    renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



		renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("repas", renderer, "text", EREPAS, NULL);		                     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);






renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", EQUANTITE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

         renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("duree de service", renderer, "text", EDS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_FLOAT,G_TYPE_STRING);



		{
	gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, EID, idog, EJOUR, d.jour,EMOIS,d.mois,EANNEE,d.annee, ETYPE, type,EREPAS,repas,EQUANTITE,qd,EDS,ds,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);
	}

//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////

void ajouter_menu(menu m )
{
    T[n_menu]=m;

    n_menu++;
}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////

menu saisie_menu(menu T[],int n_menu)
{
   menu m;
  do
  {
    printf(" identifiant(il doit unique) :");
    scanf("%s",m.idog);
  } while((isid_menu(m.idog)==0)||(isint_menu(m.idog)==0));

    printf("date : ");
    printf("\ndonner le jour : ");
    scanf("%d",&m.d.jour);
    printf("\ndonner le mois : ");
    scanf("%d",&m.d.mois);
    printf("\ndonner le annee : ");
    scanf("%d",&m.d.annee);


    printf("\ntype de repas :");
    scanf("%s",m.type);



     printf("\nom du plas : ");
     scanf("%s",m.repas);


  do
  {
      printf("\ntaper la quantite de dechet");
      scanf("%f",&m.qd);
  }while(m.qd<0);

  printf("\n duree de servie : ");
     scanf("%s",m.ds);
  return m;

}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
menu saisiemod_menu(menu T[],int n_menu)
{
   menu m;
  do
  {
    printf(" identifiant(il doit unique) :");
    scanf("%s",m.idog);
  } while((isid_menu(m.idog)==1)||(isint_menu(m.idog)==0));
    printf("date : ");
    printf("\ndonner le jour : ");
    scanf("%d",&m.d.jour);
    printf("\ndonner le mois : ");
    scanf("%d",&m.d.mois);
    printf("\ndonner le annee : ");
    scanf("%d",&m.d.annee);

  do
  {
    printf("\ntype de nouvelle repas :");
    scanf("%s",m.type);
  }while((strcmp(m.type,"petit dejeuner")!=0)&&(strcmp(m.type,"dejeuner")!=0)&&(strcmp(m.type,"diner")!=0));


     printf("\nnom du nouvelle plas : ");
     scanf("%s",m.repas);


      printf("\ntaper la nouvelle quantite de dechet :");
      scanf("%f",&m.qd);

      printf("\n duree de servie : ");
     scanf("%s",m.ds);

  return m;
}

//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
int isid_menu(char t[])
{
  int i=0,b=0;
  for(i=0;i<n_menu;i++)
  {
      if(strcmp(t,T[i].idog)==0)
      {

          return i;
      }
  }
  return -1;
}
////////////////////////////////////////
////////////////////////////////////////
///////////////////////////////////////
int isalphabet_menu(char t[])
{
  int i=0,k;
  do{
    k=t[i];
    if(((k<97)||(k>122))&&((k<65)||(k>90))){return 0;}
    i++;
  }while (t[i]!='\0') ;
  return 1;
}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
int isint_menu(char t[])
{
    int i=0;
  while (t[i]!='\0'){
    if((t[i]<'0')||(t[i]>'9'))
        {
            printf("%d not integer\n",i);
            return 0;
        }
    i++;
  }
  return 1;
}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
int supprimer_menu(char idog[])
{
    int i,j;
    for(i=0;i<n_menu;i++)
    {
        if(strcmp(idog,T[i].idog)==0)
        {
            for(j=i;j<n_menu;j++)
            {
                T[j]=T[j+1];

            }
            n_menu--;
            return 1;
        }
    }
    return 0;
}

//////////////////////////////////////
//////////////////////////////////////

//////////////////////////////////////

int modifier_menu(menu m )
{
    char temp[30];
    int i;
    for(i=0;i<n_menu;i++)
    {
        if(strcmp(m.idog,T[i].idog)==0)
        {
            T[i]=m;

            return 1;
        }
    }
    return 0;
}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
int meuilleur_menu()
{
    int i,j;
    float min;
    char plat[100];
    min=T[0].qd;
    j=0;
    for(i=0;i<n_menu;i++)
    {
       if (min>T[i].qd)
       {
           min=T[i].qd;
           j=i;

       }
    }

return j ;

}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////

void afficher_menu(GtkWidget* liste)
 {
 	int i;
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;



        store=NULL;
         store=gtk_tree_view_get_model(liste);
        if (store==NULL)
                 {
                    renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



		renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("repas", renderer, "text", EREPAS, NULL);		                     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);






renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", EQUANTITE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

         renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("duree de service", renderer, "text", EDS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_FLOAT,G_TYPE_STRING);

	for(i=0;i<n_menu;i++)
	{
		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, EID, T[i].idog, EJOUR, T[i].d.jour,EMOIS,T[i].d.mois,EANNEE,T[i].d.annee, ETYPE, T[i].type,EREPAS,T[i].repas,EQUANTITE,T[i].qd,EDS,T[i].ds,-1);
	}
	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);

}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
void recherche_une_menu(GtkWidget* liste, int i)
{
GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;


        store=NULL;
        store=gtk_tree_view_get_model(liste);
        if (store==NULL)
                 {
                    renderer = gtk_cell_renderer_text_new ();
                    renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("id", renderer, "text", EID, NULL);		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



		renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("repas", renderer, "text", EREPAS, NULL);		                     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);






renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", EQUANTITE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

         renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("duree de service", renderer, "text", EDS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_FLOAT,G_TYPE_STRING);


		gtk_list_store_append(store, &iter);
		gtk_list_store_set(store, &iter, EID, T[i].idog, EJOUR, T[i].d.jour,EMOIS,T[i].d.mois,EANNEE,T[i].d.annee, ETYPE, T[i].type,EREPAS,T[i].repas,EQUANTITE,T[i].qd,EDS,T[i].ds,-1);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
	g_object_unref(store);


}
//////////////////////////////////////
//////////////////////////////////////
//////////////////////////////////////
int filesave_menu()
{
    int i;
    FILE *f;
    f=fopen("menu.txt","w+");
    if(f==NULL)
        {
            printf("error reading file");
            return 0;
        }
    for(i=0;i<n_menu;i++)
    {
        fprintf(f,"%s %d %d %d %s %s  %f %s \n",T[i].idog,T[i].d.jour,T[i].d.mois,T[i].d.annee,T[i].type,T[i].repas,T[i].qd,T[i].ds);
    }
    fclose(f);
    return 1;

}
int fileload_menu()
{
    n_menu=0;
    FILE *f=NULL;
    f=fopen("menu.txt","r+");
    if(f==NULL)
        {
            printf("error reading file");
            return 0;
        }
    while(fscanf(f,"%s %d %d %d %s %s %f %s \n",T[n_menu].idog,&T[n_menu].d.jour,&T[n_menu].d.mois,&T[n_menu].d.annee,T[n_menu].type,T[n_menu].repas,&T[n_menu].qd,&T[n_menu].ds)!=EOF)
    {
        n_menu++;
    }
    fclose(f);
    return n_menu;

}

//////////////////////////////////
//////////////////////////////////
void viderliste_menu(GtkWidget *liste)
{
	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;



	store=NULL;
        store=gtk_tree_view_get_model(liste);
        if (store==NULL)
                 {
                    renderer = gtk_cell_renderer_text_new ();
		column =gtk_tree_view_column_new_with_attributes("id", renderer,"text", EID, NULL);		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



		renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("jour", renderer, "text", EJOUR, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("mois", renderer, "text", EMOIS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("annee", renderer, "text", EANNEE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);




		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("type", renderer, "text", ETYPE, NULL);		gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);



		renderer = gtk_cell_renderer_text_new ();
		column = gtk_tree_view_column_new_with_attributes("repas", renderer, "text", EREPAS, NULL);		                     gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);






renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("quantite", renderer, "text", EQUANTITE, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

         renderer = gtk_cell_renderer_text_new ();
	column=gtk_tree_view_column_new_with_attributes("duree de service", renderer, "text", EDS, NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW(liste),column);

	}
	store = gtk_list_store_new(COLUMNS, G_TYPE_STRING, G_TYPE_INT,G_TYPE_INT,G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING,G_TYPE_FLOAT,G_TYPE_STRING);


		gtk_list_store_append(store, &iter);

	gtk_tree_view_set_model(GTK_TREE_VIEW(liste), GTK_TREE_MODEL(store));
		g_object_unref(store);
}
