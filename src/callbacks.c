#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "admin.h"
#include "clubs.h"
#include "agent.h"
#include "email.h"
#include "capteur.h"
#include "nutritioniste.h"
#include <string.h>
#include <stdio.h>
#include "stock.h"
#include "reclamation.h"

int quitter = 2;
int supp = 0;
int radio_rec=1;
int trec[2]={0,0};



int radio=1,token=1;
users w;
GtkTreeView *L;
char x[100];
int check=1;
int radiox=1;
int r=0;
GtkTreeView *treec;
void
on_button1_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_logconnect_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * user, *pw, *auth, *afflist, *error, *aff;
  GtkWidget *clubs0;
  char suser[30], spw[30];
  users s;
  int i;
  fileload();

  user=lookup_widget(button,"authuser");
  pw=lookup_widget(button,"authpw");
  auth=lookup_widget(button,"Authentification");
  error=lookup_widget(button,"logerror");

  strcpy(suser, gtk_entry_get_text(GTK_ENTRY(user)));
  strcpy(spw, gtk_entry_get_text(GTK_ENTRY(pw)));
  i=isid(suser);
  if((strcmp(suser,"a")==0)&&(strcmp(spw,"a")==0))
  {
    afflist = create_Espace_d_administrateur ();
    gtk_widget_show (afflist);
    gtk_widget_destroy(auth);

    aff=lookup_widget(afflist,"liste");
    afficher(aff);
    L=aff;
  }
  else if(checkauth(spw,i)==1){
    s=getuser(i);
    if(strcmp(s.role,"Admin")==0)
    {
      afflist = create_Espace_d_administrateur ();
      gtk_widget_show (afflist);
      gtk_widget_destroy(auth);
      aff=lookup_widget(afflist,"liste");
      afficher(aff);
    }
    else
    if(strcmp(s.role,"Gestion_des_clubs")==0)
    {

      clubs0 = create_clubs0 ();
      gtk_widget_show (clubs0);
      gtk_widget_destroy(auth);
    }else
    if(strcmp(s.role,"Technicien")==0)
    {
      clubs0 = create_Espace_technicien();
      gtk_widget_show(clubs0);
      gtk_widget_destroy(auth);


    }
    else
    if(strcmp(s.role,"Agent_du_stock")==0)
    {
    GtkWidget *aceuil;
    aceuil= create_aceuil();
    gtk_widget_show(aceuil);
    gtk_widget_destroy(auth);


    }
    else
    if(strcmp(s.role,"Agent_du_foyer")==0)
    {
      GtkWidget *affichefoyer;
      affichefoyer = create_affichefoyer ();
      gtk_widget_show (affichefoyer);
      gtk_widget_destroy(auth);
    }
    else
    if(strcmp(s.role,"Nutritioniste")==0)
    {
      GtkWidget *WELCOME;
      WELCOME = create_WELCOME ();
      gtk_widget_show (WELCOME);
      gtk_widget_destroy(auth);
    }
    else
    if(strcmp(s.role,"Etudiant")==0)
    {
      GtkWidget *WELCOME;
      WELCOME = create_rectab ();
      gtk_widget_show (WELCOME);
      gtk_widget_destroy(auth);
    }
    else
    if(strcmp(s.role,"Agent_du_stock")==0)
    {
      GtkWidget *WELCOME;
      WELCOME = create_affiche ();
      gtk_widget_show (WELCOME);
      gtk_widget_destroy(auth);
    }


  }
  else{
    gtk_label_set_text(GTK_LABEL(error), "verifier vos données.");



  }
}


void
on_gotoinsc_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x,*y;
  y=create_Inscription();
  gtk_widget_show(y);
  x= lookup_widget(button,"Authentification");
  gtk_widget_destroy(x);
}


void
on_button3_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}







void
on_button6_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button7_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_checkbutton1_activate               (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_inscvalider_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{

users x;
fileload();


GtkWidget * nom, * prenom, * user, * pw, * role, * inc;


nom = lookup_widget(button,"inscnom");
prenom = lookup_widget(button,"inscprenom");
user = lookup_widget(button,"inscuser");
pw = lookup_widget(button,"inscpw");
role = lookup_widget(button,"inscrole");
inc = lookup_widget(button,"inscerror");

strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(x.user, gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(x.pw, gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(x.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));



if( (isalphabet(x.nom)==1)&&(isalphabet(x.prenom)==1)&&(isid(x.user)==-1)&&(nospace(x.user)==1)&&(nospace(x.pw)==1)){
ajout(x,0);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "inscription avec succes.");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}
}


void
on_gotomodif_clicked                   (GtkButton     *button,
                                        gpointer         user_data)
{
  GtkWidget *y;
  y= create_modifier ();
  gtk_widget_show(y);
}


void
on_afftrouver_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_modifvalider_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
users x;
fileload();


GtkWidget * nom, * prenom, * user, * pw, * role, * inc,*modif;


nom = lookup_widget(button,"modifnom");
prenom = lookup_widget(button,"modifprenom");
pw = lookup_widget(button,"modifpw");
role = lookup_widget(button,"modifrole");
inc = lookup_widget(button,"modiferror");
user=lookup_widget(button,"modifuser");

strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
strcpy(x.user, gtk_entry_get_text(GTK_ENTRY(user)));
strcpy(x.pw, gtk_entry_get_text(GTK_ENTRY(pw)));
strcpy(x.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));



if( (isalphabet(x.nom)==1)&&(isalphabet(x.prenom)==1)&&(isid(x.user)!=-1)&&(nospace(x.user)==1)&&(nospace(x.pw)==1)){
modifier(x);
filesave();
gtk_label_set_text(GTK_LABEL(inc), "Modification affectuer avec succes.");
modif=lookup_widget(button,"modifier");
gtk_widget_destroy(modif);
afficher(L);
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}
}

void
on_rec_clicked                         (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_services();
  gtk_widget_show(x);
  radio=1;
}


void
on_actualiser_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload();
 GtkWidget *liste;
 liste= lookup_widget(button,"liste");
 viderliste(liste);
 afficher(liste);

}


void
on_deconnexion_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *auth, *afflist;

  auth = create_Authentification ();
  afflist = lookup_widget(button,"Espace_d_administrateur");

  gtk_widget_show (auth);
  gtk_widget_destroy(afflist);
}

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=1;

}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio=2;
}

void
on_recaffiche_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *affrec, *jour,*mois,*annee;

  rec x[5000];
  date y;
  int k=0,i,foyer=0,tech=0,rest=0;
  FILE *f=NULL;
  f=fopen("reclamations.txt","r+");
  while(fscanf(f,"%s %d %d %d %s\n",x[k].service,&x[k].date.jour,&x[k].date.mois,&x[k].date.annee,x[k].commentaire)!=EOF){
      k++;
  }
  fclose(f);
  affrec = lookup_widget(button,"affservice");
  jour=lookup_widget(button,"recjour");
  mois=lookup_widget(button,"recmois");
  annee=lookup_widget(button,"recannee");

  y.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  y.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  y.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


  for(i=0;i<k;i++){
    if(datecmp(x[i].date,y)==1){
      if(strcmp(x[i].service,"Agent_du_foyer")==0)
      foyer++;
      else
      if(strcmp(x[i].service,"Technicien")==0)
      tech++;
      else
      if(strcmp(x[i].service,"Agent_du_restaurent")==0)
      rest++;
    }
    if(radio==1){
    if((foyer>tech)&&(foyer>rest))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Agents du foyer.");
    else
    if((tech>foyer)&&(tech>rest))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Techniciens.");
    else
    if((rest>=foyer)&&(rest>=tech))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Service restauration.");
    }
    if(radio==2){
    if(!((foyer>tech)&&(foyer>rest)))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Agents du foyer.");
    else
    if(!((tech>foyer)&&(tech>rest)))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Techniciens.");
    else
    if(!((rest>=foyer)&&(rest>=tech)))
    gtk_label_set_text(GTK_LABEL(affrec), "La service la plus reclamee est:\n Service restauration.");
    }




  }



}

void
on_insctoauth_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
    GtkWidget *y, *x;
    y = create_Authentification ();
    gtk_widget_show (y);
    x= lookup_widget(button,"Inscription");
    gtk_widget_destroy(x);
}


void
on_gotomain_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= lookup_widget(button,"modifier");
  gtk_widget_destroy(x);


  viderliste(L);
  afficher(L);

}

void
on_liste_row_activated                 (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *val, *supp,*op,*valider;
  GtkTreeIter iter;
  gchar *nom,*prenom,*user,*role,*valid;
  GtkTreeModel *model= gtk_tree_view_get_model(treeview);


  if(gtk_tree_model_get_iter(model, &iter, path)){
    gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &nom,1, &prenom,2,&user,3,&role,4,&valid,-1);
    strcpy(w.nom,nom);
    strcpy(w.prenom,prenom);
    strcpy(w.user,user);
    strcpy(w.role,role);
    strcpy(w.valid,valid);
    op=create_options();
    gtk_widget_show(op);
    valider=lookup_widget(op,"opvalid");
    if(strcmp(w.valid,"valide")==0)
    gtk_button_set_label(GTK_BUTTON(valider), "invalider");
    else if(strcmp(w.valid,"nonvalide")==0)
    gtk_button_set_label(GTK_BUTTON(valider), "valider");
  }

L=treeview;
val=lookup_widget(treeview,"affvaliduser");
supp=lookup_widget(treeview,"affsupprimeruser");

gtk_entry_set_text(GTK_LABEL(val),w.user);
gtk_entry_set_text(GTK_LABEL(supp),w.user);




}

void
on_capteures_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *afflist;
  GtkTextView *aff;
  afflist=create_captdef();
  gtk_widget_show(afflist);
  aff=lookup_widget(afflist,"textview1");

  int flagid[5000];
   capteur2 T[5000];
   int n=0,k=0,i;
   char msg[1000],temp[100];
   FILE *f=NULL;
   f=fopen("temperature.txt","r+");
   if(f==NULL){printf("error reading file\n");}
   while(fscanf(f,"%d %d %d %f\n",&T[n].jour,&T[n].heure,&T[n].id,&T[n].val)!=EOF){
       n++;
   }
   fclose(f);
strcpy(msg,"\n");
  for(i=0;i<n;i++)
 {

     if((T[i].val<10)||(T[i].val>30))
     {

         if(isnotflagged(T[i].id,flagid,k))
         {

             sprintf(temp,"le capteur avec ID: %d est défectueux.\n",T[i].id);
             strcat(msg,temp);
             flagid[k]=T[i].id;
             k++;
         }
     }
 }
 GtkTextBuffer *buff;

buff=gtk_text_view_get_buffer(GTK_TEXT_VIEW(aff));
gtk_text_buffer_set_text(buff,msg,-1);





}

void
on_opmodif_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x,*y,*z;
  y= create_modifier ();
  gtk_widget_show(y);
  x= lookup_widget(button,"options");
  gtk_widget_destroy(x);
  z=lookup_widget(y,"modifuser");
  gtk_entry_set_text(z,w.user);

}


void
on_opsupp_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload();
  supprimer(w.user);
  GtkWidget *x;
  x= lookup_widget(button,"options");
  gtk_widget_destroy(x);
  afficher(L);
  filesave();
}


void
on_opvalid_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{fileload();

if(strcmp(w.valid,"nonvalide")==0){
  setvalide(isid(w.user),1);
}else
if(strcmp(w.valid,"valide")==0){
  setvalide(isid(w.user),0);
}
filesave();
GtkWidget *x,*aff;
x= lookup_widget(button,"options");
gtk_widget_destroy(x);
aff=lookup_widget(L,"liste");
afficher(aff);
}

void
on_ajoutvalider_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  users x;
  fileload();

  int i=0;
  GtkWidget * nom, * prenom, * user, * pw, * role, * inc,*check;


  nom = lookup_widget(button,"ajoutnom");
  prenom = lookup_widget(button,"ajoutprenom");
  user = lookup_widget(button,"ajoutuser");
  pw = lookup_widget(button,"ajoutpw");
  role = lookup_widget(button,"ajoutrole");
  inc = lookup_widget(button,"ajouterror");
  check=lookup_widget(button,"ajoutval");
  strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(x.prenom, gtk_entry_get_text(GTK_ENTRY(prenom)));
  strcpy(x.user, gtk_entry_get_text(GTK_ENTRY(user)));
  strcpy(x.pw, gtk_entry_get_text(GTK_ENTRY(pw)));
  strcpy(x.role, gtk_combo_box_get_active_text(GTK_COMBO_BOX(role)));

  if(gtk_toggle_button_get_active(check))i=1;

  if( (isalphabet(x.nom)==1)&&(isalphabet(x.prenom)==1)&&(isid(x.user)==-1)&&(nospace(x.user)==1)&&(nospace(x.pw)==1)){
  ajout(x,i);
  filesave();
  gtk_label_set_text(GTK_LABEL(inc), "ajout avec succes.");
  }
  else{
  gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
  }
}

void
on_affajouter_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_Ajout ();
  gtk_widget_show(x);
}

void
on_gettrouver_changed                  (GtkEditable     *editable,
                                        gpointer         user_data)
{

  fileload();

  char suser[30];
  GtkWidget *liste, *user, *crtr;
  user=lookup_widget(editable,"gettrouver");
  liste=lookup_widget(editable,"liste");
  crtr=lookup_widget(editable,"searchtype");
  strcpy(suser, gtk_entry_get_text(GTK_ENTRY(user)));



  viderliste(liste);
  afftrouver(liste, suser,gtk_combo_box_get_active_text(GTK_COMBO_BOX(crtr)));

}

void
on_affmodif_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *y;
    y= create_modifier ();
    gtk_widget_show(y);
}


void
on_checkvalid_toggled                  (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_affsupprimer_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  char x[100];
  fileload();


  GtkWidget * user, * errorsupp, * inc;

  user = lookup_widget(button,"affsupprimeruser");
  inc = lookup_widget(button,"affsupperror");

  strcpy(x, gtk_entry_get_text(GTK_ENTRY(user)));



  if(isid(x)!=-1){
  supprimer(x);

  filesave();
  gtk_label_set_text(GTK_LABEL(inc), "succes.");
  }
  else{
  gtk_label_set_text(GTK_LABEL(inc), "utilisateur inexistant.");
  }
}

void
on_affvalider_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{

  int i;
  char x[100];
  fileload();

  GtkWidget * user, * errorsupp, * inc, * check;

  user = lookup_widget(button,"affvaliduser");
  check = lookup_widget(button,"checkvalid");
  inc = lookup_widget(button,"affvaliderror");

  strcpy(x, gtk_entry_get_text(GTK_ENTRY(user)));


  i=isid(x);
  if(i!=-1){
  	if(gtk_toggle_button_get_active(check)){

  		setvalide(i,1);
  	}
  	else{

  		setvalide(i,0);
  	}
  	filesave();
  	gtk_label_set_text(GTK_LABEL(inc), "succes.");
  }
  else{
  	gtk_label_set_text(GTK_LABEL(inc), "utilisateur inexistant.");
  }
}

///////////////////////////////////////////////PARTIE CLUBS /////////////////////////////////////////////////////////////////////////////////////

void
on_treeview1_row_activated_clubs       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *val, *supp,*low,*entry_mid;
  GtkTreeIter iter;
  gchar *clubname,*clubid,*clubmembers,*eventnum;
  GtkTreeModel *model= gtk_tree_view_get_model(treeview);

  if(gtk_tree_model_get_iter(model, &iter, path)){

    gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&clubname,1, &clubid,2, &clubmembers,3,&eventnum,-1);
    strcpy(x,clubid);}
    low=create_options_clubs();
    gtk_widget_show(low);
    supp=lookup_widget(treeview,"entry124");
    gtk_entry_set_text(GTK_LABEL(supp),x);
}


void
on_button10_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutc;
  ajoutc = create_ajoutc ();
  gtk_widget_show (ajoutc);
}


void
on_button11_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutc;
 ajoutc = create_modifc ();
 gtk_widget_show (ajoutc);

}


void
on_button12_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{
  char x[100];
  fileload_clubs();


  GtkWidget * club, * inc,*error;

  club = lookup_widget(button,"entry124");
  inc = lookup_widget(button,"label36");

  strcpy(x, gtk_entry_get_text(GTK_ENTRY(club)));


  if(isid_clubs(x)!=-1)
  {
  supprimer_clubs(x);
  filesave_clubs();
  GtkWidget * low;
  low=create_message();
  gtk_widget_show(low);
  error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "succes.");
  listclr_clubs(treec);
  afficherc_clubs(treec);
  }
  else{
    GtkWidget * low;
    low=create_message();
    gtk_widget_show(low);
    error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "utilisateur inexistant.");
}
}


void
on_button13_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{

}


void
on_button_click_clicked_clubs          (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload_clubs();
    club y;
  char h[100];
  GtkWidget *x,*comboboxentry1,*objet_graphique;
  comboboxentry1=lookup_widget(button,"comboboxentry1");
  strcpy(h,gtk_combo_box_get_active_text(GTK_COMBO_BOX(comboboxentry1)));
  if (strcmp(h,"Par nombre des etudiants ")==0)
  {
  x = lookup_widget(button,"label_actif");
  y=getactiveclub_clubs();
  gtk_label_set_text(GTK_LABEL(x), y.clubname );
  }
  else if (strcmp(h,"Par evenement")==0)
  {
  x = lookup_widget(button,"label_actif");
  y=getactivecluba_clubs();
  gtk_label_set_text(GTK_LABEL(x), y.clubname);}
  }

  void
  on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
  {
  check=0;
}


void
on_button5_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload_clubs();
    int i;
    char clubname[30];
    GtkWidget *liste, *user;
    user=lookup_widget(button,"entry123");
    liste=lookup_widget(button,"treeview1");
    strcpy(clubname, gtk_entry_get_text(GTK_ENTRY(user)));
    i=isid_clubs(clubname);
    if(i!=-1){
      viderliste_clubs(liste);
      afftrouver_clubs(liste, i);
    }
    else{
      viderliste_clubs(liste);
    }
}


void
on_checkbutton1_toggled_clubs          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
check=1;
}


void
on_checkbutton2_toggled_clubs          (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
check=0;
}


void
on_retour_menuclub2_clicked_clubs      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * clubc, *x;
  clubc = create_clubs0 ();
  gtk_widget_show (clubc);
  x= lookup_widget(button,"modifc");
  gtk_widget_destroy(x);
}


void
on_button2_ajout_clubs                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *modifc, *x;
  modifc = create_ajoutc ();
  gtk_widget_show (modifc);
  x= lookup_widget(button,"modifc");
  gtk_widget_destroy(x);
}


void
on_button_menre_clubs                  (GtkButton       *button,
                                        gpointer         user_data)
{
  club y;
  fileload_clubs();
  int i;
  char nome[20],id[20],nomb[20],even[20];
  GtkWidget * ajoutc;
  GtkWidget * nom, * ide, *nombre, * evenement, * error,*entry_mid,*modifc,*label51;


  nom=lookup_widget(button,"entry_mnombre");
  ide=lookup_widget(button,"entry_mid");
  nombre=lookup_widget(button,"entry_mnom");
  evenement=lookup_widget(button,"entry_meven");
  error=lookup_widget(button,"label37");

  strcpy(y.clubname, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(y.clubid, gtk_entry_get_text(GTK_ENTRY(ide)));
  strcpy(y.clubmembers, gtk_entry_get_text(GTK_ENTRY(nombre)));
  strcpy(y.eventnum, gtk_entry_get_text(GTK_ENTRY(evenement)));
  if( (isalphabet_clubs(y.clubname)==1)&&(isint_clubs(y.clubid)==1)&&(isint_clubs(y.eventnum)==1)&&(isint_clubs(y.clubmembers)==1)&&(isid_clubs(y.clubid)!=-1)&&(nospace(y.eventnum)==1)&&(strlen(y.clubid)==4))
  {
  modifier_clubs(y);
  filesave_clubs();
  GtkWidget * low;
  low=create_message();
  gtk_widget_show(low);
  error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "Modification avec succee.");
  listclr_clubs(treec);
  afficherc_clubs(treec);

  }
  else{
    GtkWidget * low;
    low=create_message();
    gtk_widget_show(low);
    error=lookup_widget(low,"label51");
    gtk_label_set_text(GTK_LABEL(error), "verifier vos données.");
  }
  if (check==0)
  {GtkWidget * modifc;
   modifc=lookup_widget(button,"modifc");
   gtk_widget_destroy(modifc);}
}


void
on_button_asortir_clubs                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutc;
  ajoutc=lookup_widget(button,"ajoutc");
  gtk_widget_destroy(ajoutc);
}


void
on_button1_retour1_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * clubc, *x;
  clubc = create_clubs0 ();
  gtk_widget_show (clubc);
  x= lookup_widget(button,"ajoutc");
  gtk_widget_destroy(x);
}


void
on_button3_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *modifc, *x;
  modifc = create_modifc ();
  gtk_widget_show (modifc);
  x= lookup_widget(button,"ajoutc");
  gtk_widget_destroy(x);
}


void
on_button_aenre_clubs                  (GtkButton       *button,
                                        gpointer         user_data)
{
  club x;

  int i;
  char nome[20],id[20],nomb[20],even[20];
  GtkWidget * ajoutc;
  GtkWidget * nom, * ide, *nombre, * evenement, * error;
  nom=lookup_widget(button,"entry_anom");
  ide=lookup_widget(button,"entry_aid");
  nombre=lookup_widget(button,"spinbutton1");
  evenement=lookup_widget(button,"spinbutton2");

  char a[20],b[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(nombre)));
  sprintf(b,"%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(evenement)));

  strcpy(x.clubname, gtk_entry_get_text(GTK_ENTRY(nom)));
  strcpy(x.clubid, gtk_entry_get_text(GTK_ENTRY(ide)));
  strcpy(x.clubmembers, a);
  strcpy(x.eventnum, b);
  if( (isalphabet_clubs(x.clubname)==1)&&(isint_clubs(x.clubid)==1)&&(isint_clubs(x.eventnum)==1)&&(isint_clubs(x.clubmembers)==1)&&(isid_clubs(x.clubid)==-1)&&(nospace(x.eventnum)==1)&&(strlen(x.clubid)==4))
  {
  fileload_clubs();
  ajout_clubs(x);
  filesave_clubs();
  GtkWidget * low;
  low=create_message();
  gtk_widget_show(low);
  error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error),"Ajout avec succes.");
  listclr_clubs(treec);
  afficherc_clubs(treec);
  }
  else{
    GtkWidget * low;
    low=create_message();
    gtk_widget_show(low);
    error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "verifier vos données.");
  }
}


void
on_radiobutton321_toggled_clubs        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {radio=1;}
}


void
on_radiobutton123_toggled_clubs        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  {radio=2;}
}


void
on_button4_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x,*y,*z,*a,*modifc,*e,*togglebutton123,*togglebutton321;
  if(radio==1)
  {
    exit(1);
    radio=2;
  }
  else if (radio==2)
  {
    x= lookup_widget(button,"confirmation");
    gtk_widget_destroy(x);
    radio=1;

  }
}


void
on_button7_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modifc,*entry_mid,*low;
  low=create_modifc();
  gtk_widget_show(low);
  entry_mid=lookup_widget(low,"entry_mid");
  gtk_entry_set_text(GTK_LABEL(entry_mid),x);
}


void
on_button8_clicked_clubs               (GtkButton       *button,
                                        gpointer         user_data)
{
  char y[100];
  fileload_clubs();


  GtkWidget * club, * inc,*error;
  GtkWidget * low;


  strcpy(y, x);
  if(isid_clubs(x)!=-1)
  {
  supprimer_clubs(y);
  filesave_clubs();
  GtkWidget * low;
  low=create_message();
  gtk_widget_show(low);
  error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error),"succes");
  listclr_clubs(treec);
  afficherc_clubs(treec);

  }
  else{
    GtkWidget * low,*a;
    low=create_message();
    gtk_widget_show(low);
    error=lookup_widget(low,"label51");
  gtk_label_set_text(GTK_LABEL(error), "utilisateur inexistant.");
  a= lookup_widget(button,"clubs0");
  gtk_widget_destroy(a);
  }
}


void
on_button99_clicked_clubs              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= lookup_widget(button,"options_clubs");
  gtk_widget_destroy(x);
}

void
on_entry123_changed_clubs              (GtkEditable     *editable,
                                        gpointer         user_data)
{
  fileload_clubs();
  int i;
  char clubname[30];
  GtkWidget *liste;
  liste=lookup_widget(editable,"treeview1");
  strcpy(clubname, gtk_entry_get_text(GTK_ENTRY(editable)));
  i=isid_clubs(clubname);
  if(1){
    viderliste_clubs(liste);
    afftrouver_clubs(liste,clubname);
  }
  else{
    viderliste_clubs(liste);
  }
}

void
on_button_sortir0_clubs                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modifc,*a;
  modifc = create_confirmation ();
  gtk_widget_show (modifc);
}

void
on_button_list_clicked_clubs           (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkTreeView *aff;
  aff=lookup_widget(button,"treeview1");
  treec=aff;
  listclr_clubs(treec);
  afficherc_clubs(treec);
}

void
on_button_msortir_clubs                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modifc;
  modifc=lookup_widget(button,"modifc");
  gtk_widget_destroy(modifc);
}
///////////////////////////////////////////////PARTIE CAPTEURS /////////////////////////////////////////////////////////////////////////////////////






void
on_gotoajoutercapt_clicked_capteur     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Ajouter_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_liste_row_activated_capteur         (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkWidget *val, *supp,*low,*modifid;
  GtkTreeIter iter;
  gchar * id, * type, * position, * etat, * valeur;
  GtkTreeModel *model= gtk_tree_view_get_model(treeview);
  char x[100];

  if(gtk_tree_model_get_iter(model, &iter, path)){

    gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1, &type,2, &position,3,&type,4,&valeur,-1);
    strcpy(x,id);}
    low=create_modifier_un_capteur();
    gtk_widget_show(low);
    modifid=lookup_widget(low,"modifid");
    gtk_entry_set_text(GTK_LABEL(modifid),x);
}


void
on_afftouver_clicked_capteur           (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload_capteur();
  int i;
  char sid[30];
  GtkWidget *liste, *id;
  id=lookup_widget(button,"gettrouver");
  liste=lookup_widget(button,"liste");
  strcpy(sid, gtk_entry_get_text(GTK_ENTRY(id)));

  i=isid_capteur(sid);
  if(i!=-1){
    viderliste_capteur(liste);
    afftrouver_capteur(liste, i);
  }
  else{
    viderliste_capteur(liste);
  }
}


void
on_gotomodifiercapteur_clicked_capteur (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_modifier_un_capteur();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_affsupprimer_clicked_capteur        (GtkButton       *button,
                                        gpointer         user_data)
{
char x[100];
fileload_capteur();


GtkWidget * id, * inc, * inc2, *conf;

id = lookup_widget(button,"affsupprimercapt");
inc = lookup_widget(button,"affsupperror");
inc2 = lookup_widget(button,"label59");

strcpy(x, gtk_entry_get_text(GTK_ENTRY(id)));



if(isid_capteur(x)!=-1 && r==1){
supprimer_capteur(x);
filesave_capteur();
gtk_label_set_text(GTK_LABEL(inc), "succes.");
r=0;
}
if(isid_capteur(x)==-1 && r==1){
gtk_label_set_text(GTK_LABEL(inc), "capteur inexistant.");
r=0;
}
if (r==0);
{
gtk_label_set_text(GTK_LABEL(inc2), "confirmé la suppression");
r=1;
}
}


void
on_afficher_clicked_capteur            (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_capteur();
GtkWidget *liste;
liste=lookup_widget(button,"liste");
afficher_capteur(liste);
}


void
on_gotoalarme_clicked_capteur          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_afficher_alarme();
  gtk_widget_show(x);
  a= lookup_widget(button,"Espace_technicien");
  gtk_widget_destroy(a);
}


void
on_buttonsortie_clicked_capteur        (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_confirmation_capteur ();
  gtk_widget_show(x);
}


void
on_ajoutervalider_clicked_capteur      (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
fileload_capteur();


GtkWidget * id, * type, * position, * etat, * valeur, * inc;


id = lookup_widget(button,"ajouterid");
type = lookup_widget(button,"ajoutertype");
position = lookup_widget(button,"ajouterposition");
etat = lookup_widget(button,"ajouteretat");
valeur=lookup_widget(button,"spinbutton1");
inc = lookup_widget(button,"ajoutererror");

  char a[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(valeur)));

strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(x.position, gtk_entry_get_text(GTK_ENTRY(position)));
strcpy(x.etat, gtk_entry_get_text(GTK_ENTRY(etat)));
strcpy(x.valeur, a);



if((isid_capteur(x.id)==-1)&&(isint_capteur(x.id)==1)&&(nospace_capteur(x.id)==1)&&(isalphabet_capteur(x.type)==1)&&(isalphabet_capteur(x.position)==1)&&(isint_capteur(x.etat)==1)&&(isint_capteur(x.valeur)==1)){
ajout_capteur(x);
filesave_capteur();
gtk_label_set_text(GTK_LABEL(inc), "ajouter avec succes.");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}
}


void
on_buttonacc1_clicked_capteur          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"Ajouter_un_capteur");
  gtk_widget_destroy(a);
}


void
on_modifvalider_clicked_capteur        (GtkButton       *button,
                                        gpointer         user_data)
{
capteur x;
fileload_capteur();


GtkWidget * id, * type, * position, * etat, * valeur, * inc;


id = lookup_widget(button,"modifid");
type = lookup_widget(button,"modiftype");
position = lookup_widget(button,"modifposition");
etat = lookup_widget(button,"modifetat");
inc = lookup_widget(button,"affmodifiererror");
valeur=lookup_widget(button,"spinbutton2");

  char a[20];
  sprintf(a, "%d",gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(valeur)));


strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
strcpy(x.position, gtk_entry_get_text(GTK_ENTRY(position)));
strcpy(x.etat, gtk_entry_get_text(GTK_ENTRY(etat)));
strcpy(x.valeur, a);





if((isid_capteur(x.id)!=-1)&&(isint_capteur(x.id)==1)&&(nospace_capteur(x.id)==1)&&(isalphabet_capteur(x.type)==1)&&(isalphabet_capteur(x.position)==1)&&(isint_capteur(x.etat)==1)&&(isint_capteur(x.valeur)==1)){
modifier_capteur(x);
filesave_capteur();
gtk_label_set_text(GTK_LABEL(inc), "Modification affectuer avec succes.");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}
}


void
on_buttonacc2_clicked_capteur          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"modifier_un_capteur");
  gtk_widget_destroy(a);
}


void
on_afficheralarme_clicked_capteur      (GtkButton       *button,
                                        gpointer         user_data)
{
int nb,nb1;
char chnb[30];
char chnb1[30];
GtkWidget *nbResultat,*message,*window1=lookup_widget(GTK_WIDGET(button),"afficher_alarme");
GtkWidget *p1=lookup_widget(window1,"treeview2");
GtkWidget *p2=lookup_widget(window1,"treeview3");
nb=chercheralarmemouvement_capteur(p1,"mouvement.txt");
nb1=chercheralarmefumee_capteur(p2,"fumee.txt");
sprintf(chnb,"%d",nb);
sprintf(chnb1,"%d",nb1);
}


void
on_buttonacc3_clicked_capteur          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x, *a;
  x=create_Espace_technicien ();
  gtk_widget_show(x);
  a= lookup_widget(button,"afficher_alarme");
  gtk_widget_destroy(a);
}


void
on_radiobutton1_toggled_capteur        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radiox=1;
}


void
on_radiobutton2_toggled_capteur        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
radiox=2;
}


void
on_button1_clicked_capteur             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *a,*togglebutton1,*togglebutton2;
if(radiox==2)
{
gtk_toggle_button_set_active(GTK_RADIO_BUTTON (togglebutton2),TRUE);
a= lookup_widget(button,"confirmation_capteur");
gtk_widget_destroy(a);
radiox=1;}
else
{gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton1),TRUE);
exit(1);
radiox=2;}
}


void
on_checkbutton1_toggled_capteur        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(togglebutton))
r=1;
else
r=0;
}







//////////////////////
void
on_radiobutton_quitter_oui_toggled     (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		quitter = 1;
}


void
on_radiobuttonquitter_non_toggled      (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		quitter = 2;
}


void
on_button12_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *verification;
	GtkWidget *aceuil;

	aceuil = lookup_widget(button,"aceuil");
	verification = create_verification();

	gtk_widget_hide(aceuil);
	gtk_widget_show(verification);

}


void
on_button_ok_verification_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *verification;
	GtkWidget *aceuil;

	verification = lookup_widget(button,"verification");

	if(quitter == 1){
		gtk_widget_destroy(verification);
	} else if(quitter ==2) {
		gtk_widget_hide(verification);
		aceuil=create_aceuil();
		gtk_widget_show(aceuil);
	}
}


void
on_checkbutton_supprimer_toggled       (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
	if(gtk_toggle_button_get_active(togglebutton))
		supp = 1;
	else
		supp = 0;
}


void
on_ajouter_clicked_stock               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget * ajout;
	ajout = create_ajout ();
 	gtk_widget_show (ajout);
}


void
on_modifier_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modification ;
	modification = create_modification ();
 	gtk_widget_show (modification);
}


void
on_supression_clicked_stock            (GtkButton       *button,
                                        gpointer         user_data)
{
	GtkWidget *supprime ;
	supprime = create_supprime ();
 	gtk_widget_show (supprime);



}


void
on_affichage_clicked_stock             (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * aff;
  aff=lookup_widget(button,"tab1");
  afficher_stock(aff);
}


void
on_button22_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{fileload_stock();
  int i;
  char id[30];
  GtkWidget *tab1, *ID;
  ID=lookup_widget(button,"entry12");
  tab1=lookup_widget(button,"tab1");
  strcpy(id, gtk_entry_get_text(GTK_ENTRY(ID)));

  i=isid_stock(id);
  if(i!=-1){
    viderliste_stock(tab1);
    trouver_stock(tab1, i);
  }
  else{
    viderliste_stock(tab1);
  }


}


void
on_button21_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget * affiche;
	affiche=lookup_widget(button,"affiche");
	gtk_widget_destroy(affiche);
}





void
on_button14_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{


}


void
on_button16_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget * ajout;
	ajout=lookup_widget(button,"ajout");
	gtk_widget_destroy(ajout);


}


void
on_button19_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget * supprime;
	supprime =lookup_widget(button,"supprime");
	gtk_widget_destroy(supprime);

}


void
on_button9_clicked_stock               (GtkButton       *button,
                                        gpointer         user_data)
{char x[100];

fileload_stock();


GtkWidget * iden,  * inc;
GtkWidget *checkbutton_supprimer;

iden = lookup_widget(button,"supprimeid");
inc = lookup_widget(button,"label22");
checkbutton_supprimer = lookup_widget(button,"checkbutton_supprimer");

strcpy(x, gtk_entry_get_text(GTK_ENTRY(iden)));



if(supprimer_stock(x) && supp == 1){

filesave_stock();
gtk_label_set_text(GTK_LABEL(inc), "succes.");
} else if(supp !=1){
gtk_label_set_text(GTK_LABEL(inc), "cochez la confirmation de la supprimation!");
}else {
gtk_label_set_text(GTK_LABEL(inc), "produit inexistant.");
}

}


void
on_checkbutton_supprimer_toggled_stock (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{if(gtk_toggle_button_get_active(togglebutton))
		supp = 1;
	else
		supp = 0;

}


void
on_button10_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget * affiche;
	affiche = create_affiche ();
 	gtk_widget_show (affiche);


}


void
on_button11_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget * repture;
	GtkWidget *tab2;
	GtkWidget *label_repture_message;
	int test;

	repture = create_repture ();
	tab2 = lookup_widget(repture,"tab2");
	label_repture_message = lookup_widget(repture,"label_repture_message");

	test = afficher_repture_stock(tab2);
	if(test==0){
		gtk_widget_show(label_repture_message);
	}

 	gtk_widget_show (repture);

}


void
on_button12_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *verification;
	GtkWidget *aceuil;

	aceuil = lookup_widget(button,"aceuil");
	verification = create_verification();

	gtk_widget_hide(aceuil);
	gtk_widget_show(verification);


}


void
on_button13_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{stock x;
fileload_stock();
int i ;
char nom[20],type[20],ident[20],mss[20],quant[20];
  GtkWidget * ajout;
GtkWidget * nomp, * typep, * identite, * quantite, *ms, * inc;
nomp= lookup_widget(button,"entry8");
typep = lookup_widget(button,"entry9");
identite = lookup_widget(button,"entry7");
quantite = lookup_widget(button,"spinbutton_modifier");
ms = lookup_widget(button,"comboboxentry1");
inc = lookup_widget(button,"label39");

strcpy(x.N_P, gtk_entry_get_text(GTK_ENTRY(nomp)));
strcpy(x.TY_P, gtk_entry_get_text(GTK_ENTRY(typep)));
strcpy(x.ID, gtk_entry_get_text(GTK_ENTRY(identite)));
sprintf(x.QTD,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite)));
strcpy(x.M_S, gtk_combo_box_get_active_text(GTK_COMBO_BOX(ms)));


if( (isalphabet_stock(x.N_P)==1)&&(isalphabet_stock(x.TY_P)==1)&&(isint_stock(x.ID)==1)&&(isid_stock(x.ID)!=-1)&&(nospace_stock(x.QTD)==1)&&(isint_stock(x.QTD)==1))
{
modifier_stock(x);
filesave_stock();
gtk_label_set_text(GTK_LABEL(inc), "Modification affectuer avec succes.");
}
else{
gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
 }



}


void
on_button17_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget * modification;
	modification=lookup_widget(button,"modification");
	gtk_widget_destroy(modification);

}


void
on_button24_clicked_stock              (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget * repture;
	repture=lookup_widget(button,"repture");
	gtk_widget_destroy(repture);


}


void
on_radiobuttonquitter_non_toggled_stock
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
	quitter= 2;

}


void
on_radiobutton_quitter_oui_toggled_stock
                                        (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
		quitter = 1;

}


void
on_button_ok_verification_clicked_stock
                                        (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *verification;
GtkWidget *aceuil;

	verification = lookup_widget(button,"verification");

	if(quitter == 1){
		gtk_widget_destroy(verification);
	} else if(quitter ==2) {
		gtk_widget_hide(verification);
		aceuil=create_aceuil();
		gtk_widget_show(aceuil);
	}}


  int rog;
  int radioog=1;

  ///////////////////////tache ajout ///////////////////////////////////

  ///////////////////////ajout => menu//////////////////////////////////
  void
  on_retour1_clicked_menu                     (GtkButton       *button,
                                       gpointer         user_data)
  {
  GtkWidget *Gestiondemenu;
  GtkWidget *Ajouter_menu;

  Gestiondemenu=create_Gestiondemenu();
  gtk_widget_show(Gestiondemenu);
  Ajouter_menu=lookup_widget(button,"Ajouter_menu");
  gtk_widget_hide(Ajouter_menu);
  }
  /////////////////////menu ==> ajout ///////////////////////////////////
  void
  on_ajouter_menu_clicked              (GtkButton       *button,
                                          gpointer         user_data)
  {

  GtkWidget *Gestiondemenu;
  GtkWidget *Ajouter_menu;
  Ajouter_menu=create_Ajouter_menu();
  gtk_widget_show(Ajouter_menu);
  Gestiondemenu=lookup_widget(button,"Gestiondemenu");
  gtk_widget_hide(Gestiondemenu);

  }
  /////////////////fontion ajout////////////////////////////////////////
  void
  on_ajouter_menu_og_clicked_menu             (GtkButton       *button,
                                          gpointer         user_data)
  {
  menu m;
  fileload_menu();
  GtkWidget*input1;
  GtkWidget*input2;
  GtkWidget*input3;
  GtkWidget*input4;
  GtkWidget*input5;
  GtkWidget*input6;
  GtkWidget*input7;
  GtkWidget*input8;
  GtkWidget*sortie1;


  input2=lookup_widget(button,"entry3");
  input1=lookup_widget(button,"entry7");
  input3=lookup_widget(button,"combobox1");
  input4=lookup_widget(button,"spinbutton1");
  input5=lookup_widget(button,"spinbutton2");
  input6=lookup_widget(button,"spinbutton3");
  input7=lookup_widget(button,"spinbutton9");
  input8=lookup_widget(button,"entry22");
  sortie1=lookup_widget(button,"label35");

  strcpy(m.ds,gtk_entry_get_text(GTK_ENTRY(input8)));
  strcpy(m.idog,gtk_entry_get_text(GTK_ENTRY(input1)));
  strcpy(m.repas,gtk_entry_get_text(GTK_ENTRY(input2)));
  strcpy(m.type,gtk_combo_box_get_active_text(GTK_COMBO_BOX(input3)));
  m.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input4));
  m.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input5));
  m.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(input6));
  m.qd=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(input7));


  if(isid_menu(m.idog)==-1)
  {
  ajouter_menu(m);
  gtk_label_set_text(GTK_LABEL(sortie1),"ajout effectué avec succes");
  filesave_menu();}
  else {
  gtk_label_set_text(GTK_LABEL(sortie1),"id existant deja ");
  }
  }

  /////////////////////tache supprimer ////////////////////////////////
  ////////////////////menu ==> supprimer : par selection////////////////////////////////
  void
  on_supprimer_menu_clicked_menu              (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *OGaccueil;
  GtkWidget *OGsupprime;
  GtkWidget *OGtreeview_menu;
  GtkTreeSelection *selection;
  GtkTreeModel *model;
  GtkTreeIter iter;
  	gchar * idog;
  	gchar * jour;
  	gchar * mois;
  	gchar * annee;
  	gchar * type;
   	gchar *repas;
  	gchar *qd;
          gchar *ds;
          gchar *inc;
          menu m;


  GtkWidget *input0;
  OGaccueil=lookup_widget(button,"Gestiondemenu");
  OGtreeview_menu=lookup_widget(OGaccueil,"treeview_menu");
  selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(OGtreeview_menu));

  if(gtk_tree_selection_get_selected(selection,&model,&iter))
  {
  gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&idog,1,&jour,2,&mois,3,&annee,4,&type,5,&repas,6,&qd,7,&ds,8,-1);

  	strcpy(m.idog,idog);
  	strcpy(m.type,type);
  	strcpy(m.repas,repas);
                 strcpy(m.ds,ds);
                m.d.jour=jour;
                m.d.mois=mois;
                m.d.annee=annee;
  }
  gtk_widget_destroy(OGaccueil);
  OGsupprime=create_Supprimer_menu();
  gtk_widget_show(OGsupprime);
  input0=lookup_widget(OGsupprime,"entry21");
  gtk_entry_set_text (GTK_ENTRY(input0),m.idog);
  }
  ////////////////////supprimer => menu////////////////////////////////
  void
  on_retour3_clicked_menu                     (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *Gestiondemenu;
  GtkWidget *Supprimer_menu;

  Gestiondemenu=create_Gestiondemenu();
  gtk_widget_show(Gestiondemenu);
  Supprimer_menu=lookup_widget(button,"Supprimer_menu");
  gtk_widget_hide(Supprimer_menu);
  }
  ///////////////////  fonction supprimer /////////////////////////////
  void
  on_confirmer_menu_clicked_menu              (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *input1;
  GtkWidget *sortie3;
  GtkWidget *outputMsg;
  char text[100];
  char idog[30];


  input1=lookup_widget(button,"entry21");
  sortie3=lookup_widget(button,"label37");
  strcpy(idog,gtk_entry_get_text(GTK_ENTRY(input1)));
   if(rog)
    {
    supprimer_menu(idog);
    gtk_label_set_text(GTK_LABEL(sortie3),"Suppression effectué avec succes");
   filesave_menu();
   rog=0;
    }
    else
    {
     strcpy (text," confirmez d'abord ");
      outputMsg=lookup_widget(button,("label59"));
      gtk_label_set_text(GTK_LABEL(outputMsg),text);

    }

  }

  //////////////////confirmer pour supprimer ///////////////////////
  void
  on_conf_suppr_toggled_menu                  (GtkToggleButton *togglebutton,
                                          gpointer         user_data)
  {

  if(gtk_toggle_button_get_active(togglebutton))
  rog=1;
  else
  rog=0;
  }


  ///////////////////////////tache de modification //////////////////////

  ////////////////////////// modif ==> menu ////////////////////////////
  void
  on_retour2_clicked_menu                     (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *Gestiondemenu;
  GtkWidget *Modifier_menu;

  Gestiondemenu=create_Gestiondemenu();
  gtk_widget_show(Gestiondemenu);
  Modifier_menu=lookup_widget(button,"Modifier_menu");
  gtk_widget_hide(Modifier_menu);
  }
  //////////////////////fonction modif ///////////////////////////////

  void
  on_modifier2_clicked_menu                  (GtkButton       *button,
                                          gpointer         user_data)
  {

  fileload_menu();
  menu m;

  GtkWidget * idog, * jour, * mois , * annee, * type, * repas ,*qd,*ds,*inc;


  idog=lookup_widget(button,"entry9");
  repas=lookup_widget(button,"entry11");
  ds=lookup_widget(button,"entry23");
  type=lookup_widget(button,"combobox2");
  jour=lookup_widget(button,"spinbutton4");
  mois=lookup_widget(button,"spinbutton5");
  annee=lookup_widget(button,"spinbutton6");
  qd=lookup_widget(button,"spinbutton8");
  inc=lookup_widget(button,"label52");
  strcpy(m.ds, gtk_entry_get_text(GTK_ENTRY(ds)));
  strcpy(m.repas, gtk_entry_get_text(GTK_ENTRY(repas)));
  strcpy(m.idog, gtk_entry_get_text(GTK_ENTRY(idog)));
  strcpy(m.type, gtk_combo_box_get_active_text(GTK_COMBO_BOX(type)));
  m.d.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  m.d.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  m.d.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
  m.qd=gtk_spin_button_get_value_as_float(GTK_SPIN_BUTTON(qd));


  modifier_menu(m);
  filesave_menu();
  gtk_label_set_text(GTK_LABEL(inc), "Modification affectuer avec succes.");

  }


  ////////////////////////menu => modif : par selection ///////////////
  void
  on_modifier_menu_clicked_menu               (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *OGaccueil;
  GtkWidget *OGmodif;
  GtkWidget *OGtreeview_menu;
  GtkTreeSelection *selection;
  GtkTreeModel *model;
  GtkTreeIter iter;
  	gchar * idog;
  	gchar * jour;
  	gchar * mois;
  	gchar * annee;
  	gchar * type;
   	gchar *repas;
  	gchar *qd;
          gchar *ds;
          gchar *inc;
          menu m;



  GtkWidget*input1;
  GtkWidget*input2;
  GtkWidget*input3;
  GtkWidget*input4;
  GtkWidget*input5;
  GtkWidget*input6;
  GtkWidget*input7;
  GtkWidget*input8;
  GtkWidget*input9;

  OGaccueil=lookup_widget(button,"Gestiondemenu");
  OGtreeview_menu=lookup_widget(OGaccueil,"treeview_menu");
  selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(OGtreeview_menu));

  if(gtk_tree_selection_get_selected(selection,&model,&iter))
  {
  gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0,&idog,1,&jour,2,&mois,3,&annee,4,&type,5,&repas,6,&qd,7,&ds,8,-1);

  	strcpy(m.idog,idog);
  	strcpy(m.type,type);
  	strcpy(m.repas,repas);
          strcpy(m.ds,ds);
          m.d.jour=jour;
          m.d.mois=mois;
          m.d.annee=annee;
  }
  gtk_widget_hide(OGaccueil);
  OGmodif=create_Modifier_menu ();
  gtk_widget_show(OGmodif);
  input1=lookup_widget(OGmodif,"entry11");
  input2=lookup_widget(OGmodif,"entry9");
  input3=lookup_widget(OGmodif,"spinbutton4");
  input4=lookup_widget(OGmodif,"spinbutton5");
  input5=lookup_widget(OGmodif,"spinbutton6");
  input6=lookup_widget(OGmodif,"combobox2");
  input7=lookup_widget(OGmodif,"spinbutton8");
  input8=lookup_widget(OGmodif,"entry23");

  gtk_entry_set_text (GTK_ENTRY(input1),m.repas);
  gtk_entry_set_text (GTK_ENTRY(input2),m.idog);
  gtk_entry_set_text (GTK_ENTRY(input8),m.ds);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input3),m.d.jour);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input4),m.d.mois);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),m.d.annee);
  gtk_spin_button_set_value(GTK_SPIN_BUTTON(input7),m.qd);

  }





  /////////////////////////tache affichage /////////////////////////////
  void
  on_Afficher_menu_clicked_menu               (GtkButton       *button,
                                          gpointer         user_data)
  {
  fileload_menu();
  GtkWidget *treeview_menu;
  treeview_menu=lookup_widget(button,"treeview_menu");
  afficher_menu(treeview_menu);
  filesave_menu();
  }





  //////////////////////tache rechercher///////////////////////////////
  void
  on_chercher_menu_clicked_menu               (GtkButton       *button,
                                          gpointer         user_data)
  {
  fileload_menu();
    int i;
    char sid[30];
    GtkWidget *liste, *idog;
    idog=lookup_widget(button,"entry200");
    liste=lookup_widget(button,"treeview_menu");
    strcpy(sid, gtk_entry_get_text(GTK_ENTRY(idog)));

    i=isid_menu(sid);
    if(i!=-1){
      viderliste_menu(liste);
      recherche_une_menu(liste, i);
    }
    else{
      viderliste_menu(liste);
    }
  }

  //////////////////////meuilleur menu/////////////////////////////////

  ////////////////////fontion meuilleur////////////////////////////////
  void
  on_afficher_meuilleur_clicked_menu         (GtkButton       *button,
                                          gpointer         user_data)
  {
  FILE *f;
  menu T[1000];
  f=fopen("menu.txt","r+");
  GtkWidget *sortie1;
  int index;
  int n=0;
  index=meuilleur_menu();
  sortie1=lookup_widget(button,"label61");
  while((fscanf(f,"%s %d %d %d %s %s %f %s \n",T[n].idog,&T[n].d.jour,&T[n].d.mois,&T[n].d.annee,T[n].type,T[n].repas,&T[n].qd,&T[n].ds)!=EOF)&&(n!=index))
      {
          n++;
      }
  gtk_label_set_text(GTK_LABEL(sortie1),T[index].repas);
}
  /////////////////////welcome = > meuilleur/////////////////////////////
  void
  on_gotomeuilleur_clicked_menu               (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *meuilleur;
  GtkWidget *WELCOME;

  meuilleur=create_meuilleur();
  gtk_widget_show(meuilleur);
  WELCOME=lookup_widget(button,"WELCOME");
  gtk_widget_hide(WELCOME);
  }
  ////////////////////////////////////////////////////////////////////////
  void
  on_button6_clicked_                    (GtkButton       *button,
                                          gpointer         user_data)
  {


  }




  void
  on_confirmermodification_toggled       (GtkToggleButton *togglebutton,
                                          gpointer         user_data)
  {

  }


  ////////////////////////quiter l'application/////////////////////////
  void
  on_validermenu_clicked_menu                 (GtkButton       *button,
                                          gpointer         user_data)
  {

  GtkWidget *a,*welcome,*togglebutton1,*togglebutton2,*Quiter;
  if (radioog==2)
  {
  gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton2),TRUE);
  a=lookup_widget(button,"Gestiondemenu");
  gtk_widget_destroy(a);
  welcome=create_WELCOME();
  Quiter=create_Quiter();
  gtk_widget_destroy(Quiter);
  gtk_widget_show(welcome);
  radioog=1;
  }
  else
  {gtk_toggle_button_set_active(GTK_RADIO_BUTTON(togglebutton1),TRUE);
  exit(1);
  radioog=2;
  }
  }

  void
  on_quiterapp_clicked_menu                   (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *Quiter;
  GtkWidget *WELCOME;

  Quiter=create_Quiter();
  gtk_widget_show(Quiter);
  WELCOME=lookup_widget(button,"WELCOME");
  gtk_widget_hide(WELCOME);
  }

  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////
  void
  on_radiobutton1_toggled_menu                (GtkToggleButton *togglebutton,
                                          gpointer         user_data)
  {

  if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  radioog=1;
  }
  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////
  void
  on_radiobutton2_toggled_menu                (GtkToggleButton *togglebutton,
                                          gpointer         user_data)
  {

  if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton)))
  radioog=2;
  }
  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////
  void
  on_gotogestionmenu_clicked_menu             (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *Gestiondemenu;
  GtkWidget *WELCOME;

  Gestiondemenu=create_Gestiondemenu();
  gtk_widget_show(Gestiondemenu);
  WELCOME=lookup_widget(button,"WELCOME");
  gtk_widget_hide(WELCOME);
  }
  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////

  void
  on_button12_clicked_menu                    (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *WELCOME;
  GtkWidget *Gestiondemenu;

  WELCOME=create_WELCOME();
  gtk_widget_show(WELCOME);
  Gestiondemenu=lookup_widget(button,"Gestiondemenu");
  gtk_widget_hide(Gestiondemenu);
  }
  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////

  void
  on_retourquiter_clicked_menu                (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *WELCOME;
  GtkWidget *Quiter;

  WELCOME=create_WELCOME();
  gtk_widget_show(WELCOME);
  Quiter=lookup_widget(button,"Quiter");
  gtk_widget_hide(Quiter);
  }
  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////

  void
  on_retourmeuilleur_clicked_menu             (GtkButton       *button,
                                          gpointer         user_data)
  {
  GtkWidget *WELCOME;
  GtkWidget *meuilleur;

  WELCOME=create_WELCOME();
  gtk_widget_show(WELCOME);
  meuilleur=lookup_widget(button,"meuilleur");
  gtk_widget_hide(meuilleur);
  }
  //////////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////////








  void
  on_treeview_menu_row_activated_menu        (GtkTreeView     *treeview,
                                          GtkTreePath     *path,
                                          GtkTreeViewColumn *column,
                                          gpointer         user_data)
  {
  fileload_menu();
  GtkTreeIter iter;
  	gchar* idog;
  	gchar* repas;
  	gchar* type;
  	gint* jour;
  	gint* mois;
  	gint* annee;
  	gfloat* qd;
          gchar* ds;
  	menu m;

  	GtkTreeModel *model = gtk_tree_view_get_model(treeview);

  	if(gtk_tree_model_get_iter(model,&iter,path))
  	{
  	gtk_tree_model_get (GTK_LIST_STORE(model), &iter,0, &idog,1,&repas,2,&type,3,&jour,4,&mois ,5,&annee ,6,&qd,-1);
  	strcpy(m.idog,idog);
  	strcpy(m.repas,idog);
  	strcpy(m.type,type);
  	m.d.jour=*jour;
  	m.d.mois=*mois;
  	m.d.annee=*annee;
  	m.qd=*qd;
  	afficher_menu(treeview);
  filesave_menu();
  	}
  }





  ////////////////////////////////////////////////////////////////////////////////////agent de foyer///////////////////////////////////////////

  int radiogenre;
  int confirm;

//utilisation de bouton radio
void
_1on_radiobuttonf_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{



}


void
_1on_radiobuttong_toggled              (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton2g_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{

}


void
on_radiobutton2f_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{


}



//ajouter

void
_1on_buttonajoutfoyer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  radiogenre=1;
  etudiant e;
  fileload_etudiant();

  GtkWidget * ajouter;
  GtkWidget * nomE, * prenomE, * identifiantE, * num_chambre, * num_etage, * genre, * niveau, * msg, *togglebutton1, *togglebutton2;


  nomE = lookup_widget(button,"entrynom");
  prenomE = lookup_widget(button,"entryprenom");
  identifiantE= lookup_widget(button,"entryidentif");
  num_chambre= lookup_widget(button,"entrychambre");
  num_etage= lookup_widget(button,"comboboxentry1");
  niveau = lookup_widget(button,"spinbutton1");
  msg=lookup_widget(button,"labelsucces");
  togglebutton1=lookup_widget(button,"radiobuttonf");
  togglebutton2=lookup_widget(button,"radiobuttong");

  strcpy(e.nomE, gtk_entry_get_text(GTK_ENTRY(nomE)));
  strcpy(e.prenomE, gtk_entry_get_text(GTK_ENTRY(prenomE)));
  strcpy(e.identifiantE, gtk_entry_get_text(GTK_ENTRY(identifiantE)));

  if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton2)))
  strcpy(e.genre,"Male");
  else if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton1)))
  strcpy(e.genre,"Femelle");

  strcpy(e.num_chambre,gtk_entry_get_text(GTK_ENTRY(num_chambre)));



  strcpy(e.num_etage, gtk_combo_box_get_active_text(GTK_COMBO_BOX(num_etage)));
  e.niveau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(niveau));

  if( (isalphabet_etudiant(e.nomE)==1)&&(isint_etudiant(e.num_chambre)==1)&&(isint_etudiant(e.identifiantE)==1)&&(isalphabet_etudiant(e.prenomE)==1)&&(uniqueid_etudiant(e.identifiantE)==-1)&&(nospace_etudiant(e.identifiantE)==1)&&(nospace_etudiant(e.num_chambre)==1))
  {
  ajout_etudiant(e);
  filesave_etudiant();
  gtk_label_set_text(GTK_LABEL(msg), "Votre Ajout a été effectuée avec succés");


}

else
{
gtk_label_set_text(GTK_LABEL(msg), "Vérifier vos données");
}

}

//retour de l'ajout
void
_1on_retourajoutfoyer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutfoyer,* affichefoyer;
  	affichefoyer=create_affichefoyer();
  	gtk_widget_show(affichefoyer);

  	ajoutfoyer=lookup_widget(button,"ajoutfoyer");
  	gtk_widget_destroy(ajoutfoyer);
}

//modifier
void
_1on_buttonmodiffoyer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  etudiant e;
  radiogenre=1;
  fileload_etudiant();


  GtkWidget * nomE, * prenomE, * identifiantE, * num_chambre, * num_etage, * genre, * niveau, * msg, *togglebutton1, *togglebutton2;


  nomE = lookup_widget(button,"entrynom1");
  prenomE = lookup_widget(button,"entryprenom1");
  identifiantE= lookup_widget(button,"entryidentif1");
  num_chambre= lookup_widget(button,"entrychambre1");
  num_etage= lookup_widget(button,"comboboxentry2");
  niveau = lookup_widget(button,"spinbutton2");
  msg = lookup_widget(button,"labelsuccesmodif");
  togglebutton1=lookup_widget(button,"radiobutton2f");
  togglebutton2=lookup_widget(button,"radiobutton2g");

  strcpy(e.nomE, gtk_entry_get_text(GTK_ENTRY(nomE)));
  strcpy(e.prenomE, gtk_entry_get_text(GTK_ENTRY(prenomE)));
  strcpy(e.identifiantE, gtk_entry_get_text(GTK_ENTRY(identifiantE)));

  if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton2)))
  strcpy(e.genre,"Male");
  else if(gtk_toggle_button_get_active(GTK_RADIO_BUTTON(togglebutton1)))
  strcpy(e.genre,"Femelle");

  strcpy(e.num_chambre,gtk_entry_get_text(GTK_ENTRY(num_chambre)));

  strcpy(e.num_etage, gtk_combo_box_get_active_text(GTK_COMBO_BOX(num_etage)));
  e.niveau=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(niveau));

  if( (isalphabet_etudiant(e.nomE)==1)&&(isalphabet_etudiant(e.prenomE)==1)&&(uniqueid_etudiant(e.identifiantE)!=-1)&&(nospace_etudiant(e.identifiantE)==1)&&(isint_etudiant(e.identifiantE)==1)&&(isint_etudiant(e.num_chambre)==1)&&(nospace_etudiant(e.num_chambre)==1)){
  modifier_etudiant(e);
  filesave_etudiant();
  gtk_label_set_text(GTK_LABEL(msg), "Votre Modification a été effectuée avec succés");

  }

  else{
  gtk_label_set_text(GTK_LABEL(msg), "Verifier vos données");
  }

}

//retour de modif
void
_1on_retourmodiffoyer_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget* affichefoyer;
  affichefoyer=create_affichefoyer();
  gtk_widget_show(affichefoyer);

  GtkWidget * modiffoyer;
  modiffoyer=lookup_widget(button,"modiffoyer");
  gtk_widget_destroy(modiffoyer);
}


void
_1on_treeviewfoyer_row_activated       (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
  GtkWidget *supp;
  GtkTreeIter iter;
  gchar *nomE,*prenomE,*genre,*identifiantE,*num_chambre,*num_etage,* niveau;
  char x[100];

  GtkTreeModel *model = gtk_tree_view_get_model(treeview);

  if (gtk_tree_model_get_iter(model, &iter, path)){
   //obtention des valeurs de la ligne selectionnée
     gtk_tree_model_get (GTK_LIST_STORE(model), &iter, 0, &nomE, 1, &prenomE,2,&genre,3,&identifiantE,4,&num_chambre,5,&num_etage,6,&niveau,-1);
    strcpy(x,identifiantE);
    }


  supp=lookup_widget(treeview,"entrysuprim");
  gtk_entry_set_text(GTK_LABEL(supp),x);

  //MISE À JOUR DE L'AFFICHAGE DE LA TREEVIEW
  afficher_etudiant(treeview);
}

//chercher
void
_1on_boutonrechercheretudiant_clicked  (GtkButton       *button,
                                        gpointer         user_data)
{


}


void
on_entrychercher_changed               (GtkEditable     *editable,
                                        gpointer         user_data)
{
    fileload_etudiant();

    char identifiantsaisie[30];
    GtkWidget *liste, *identifiantE,*choix;
    liste=lookup_widget(editable,"liste");
    choix=lookup_widget(editable,"type");
    strcpy(identifiantsaisie, gtk_entry_get_text(editable));


      viderliste_etudiant(liste);
      trouver_etudiant(liste, identifiantsaisie,gtk_combo_box_get_active_text(GTK_COMBO_BOX(choix)));

}


//utilisation de case a cocher
void
_1on_checkbuttonsuprim_toggled         (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
  if(gtk_toggle_button_get_active(togglebutton))
  confirm=1;
  else
  confirm=0;

}

//supprimer
void
_1on_boutonsupprimeretudiant_clicked   (GtkButton       *button,
                                        gpointer         user_data)
{
  char x[100];
  fileload_etudiant();

  GtkWidget * identifiantE,* errorsupp, * msg;

  identifiantE = lookup_widget(button,"entrysuprim");
  msg= lookup_widget(button,"labelerror");

  strcpy(x, gtk_entry_get_text(GTK_ENTRY(identifiantE)));



  if((uniqueid_etudiant(x)!=-1)&&(confirm==1))
  {
  supprimer_etudiant(x);

  filesave_etudiant();
  gtk_label_set_text(GTK_LABEL(msg), "Suppresion avec succés");
  filesave_etudiant();
  confirm=0;
  }
  else{
  gtk_label_set_text(GTK_LABEL(msg), "vous devez confirmer la suppression");
  }

}

//goto affiche
void
_1on_boutonafficheretudiant_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{
  fileload_etudiant();
  GtkWidget *liste;
  liste= lookup_widget(button,"liste");

  afficher_etudiant(liste);

}

//goto ajout
void
_1on_boutonajouteretudiant_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * affichefoyer,* ajoutfoyer;
  	ajoutfoyer = create_ajoutfoyer ();
    	gtk_widget_show (ajoutfoyer);

  	affichefoyer=lookup_widget(button,"affichefoyer");
  	gtk_widget_destroy(affichefoyer);


}

//goto modif
void
_1on_boutonmodifieretudiant_clicked    (GtkButton       *button,
                                        gpointer         user_data)
{


  GtkWidget *accueilfoyer;
  GtkWidget *modiffoyer;
  GtkWidget *treeview_foyer;
  GtkTreeSelection *selection;
  GtkTreeModel *model;
  GtkTreeIter iter;
  gchar * nomE;
  gchar * prenomE;
  gchar * genre;
  gchar * identifiantE;
  gchar *num_chambre;
  gchar *num_etage;
  gchar *niveau;
  gchar *inc;
  etudiant E;



  GtkWidget*input1;
  GtkWidget*input2;
  GtkWidget*input3;
  GtkWidget*input4;
  GtkWidget*input5;
  GtkWidget*input6;
  GtkWidget*input7;
  GtkWidget*input8;
  GtkWidget*input9;

  accueilfoyer=lookup_widget(button,"affichefoyer");
  treeview_foyer=lookup_widget(accueilfoyer,"liste");
  selection=gtk_tree_view_get_selection(GTK_TREE_VIEW(treeview_foyer));

  if(gtk_tree_selection_get_selected(selection,&model,&iter))
  {
  gtk_tree_model_get(GTK_LIST_STORE(model), &iter,0, &nomE, 1, &prenomE,2,&genre,3,&identifiantE,4,&num_chambre,5,&num_etage,6,&niveau,-1);

  strcpy(E.nomE,nomE);
  strcpy(E.prenomE,prenomE);
  strcpy(E.identifiantE,identifiantE);
  strcpy(E.num_chambre,num_chambre);
  strcpy(E.num_etage,num_etage);
  strcpy(E.genre,genre);

  }
  gtk_widget_hide(accueilfoyer);
  modiffoyer=create_modiffoyer();
  gtk_widget_show(modiffoyer);

  input1=lookup_widget(modiffoyer,"entrynom1");
  input2=lookup_widget(modiffoyer,"entryprenom1");
  input3=lookup_widget(modiffoyer,"entryidentif1");
  input4=lookup_widget(modiffoyer,"entrychambre1");
  input5=lookup_widget(modiffoyer,"spinbutton2");
  input5=lookup_widget(modiffoyer,"comboboxentry2");

gtk_entry_set_text (GTK_ENTRY(input1),E.nomE);
gtk_entry_set_text (GTK_ENTRY(input2),E.prenomE);
gtk_entry_set_text (GTK_ENTRY(input3),E.identifiantE);
gtk_entry_set_text (GTK_ENTRY(input4),E.num_chambre);


gtk_spin_button_set_value(GTK_SPIN_BUTTON(input5),E.niveau);



}

//goto niveau
void
_1on_boutonniveau_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * niveau;
    niveau = create_niveau ();
    gtk_widget_show (niveau);

  GtkWidget * affichefoyer;
  affichefoyer=lookup_widget(button,"affichefoyer");
  gtk_widget_destroy(affichefoyer);

}

//tache2: afficher niveau des etudiants
void
_1on_afficheniveauetudiant_clicked     (GtkButton       *button,
                                        gpointer         user_data)
{

  GtkWidget *affniveau1,*affniveau2,*affniveau3,*affniveau4,*affniveau5,*n1,*n2,*n3,*n4,*n5;
  int i,tab[5];
  char str[150];

  affniveau1 = lookup_widget(button,"affniveau1");
  affniveau2 = lookup_widget(button,"affniveau2");
  affniveau3 = lookup_widget(button,"affniveau3");
  affniveau4 = lookup_widget(button,"affniveau4");
  affniveau5 = lookup_widget(button,"affniveau5");



  afficheniveau(tab);
  sprintf(str,"Le Nombre des etudiants de 1ère année: %d",tab[0]);
   gtk_label_set_text(GTK_LABEL(affniveau1),str);
  sprintf(str,"Le Nombre des etudiants de 2ère année: %d",tab[1]);
   gtk_label_set_text(GTK_LABEL(affniveau2),str);
  sprintf(str,"Le Nombre des etudiants de 3ère année: %d",tab[2]);
   gtk_label_set_text(GTK_LABEL(affniveau3),str);
  sprintf(str,"Le Nombre des etudiants de 4ère année: %d",tab[3]);
   gtk_label_set_text(GTK_LABEL(affniveau4),str);
  sprintf(str,"Le Nombre des etudiants de 5ère année: %d",tab[4]);
   gtk_label_set_text(GTK_LABEL(affniveau5),str);


   FILE *f=NULL;
      f=fopen("niveau.txt","a+");
      if(f==NULL){printf("error reading file");}
      else{
          fprintf(f,"%d %d %d %d %d\n",tab[0],tab[1],tab[2],tab[3],tab[4]);
      }
      fclose(f);

}


//retoure de niveau
void
_1on_retourniveauetudiant_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget* affichefoyer;
  affichefoyer=create_affichefoyer();
  gtk_widget_show(affichefoyer);

  GtkWidget * niveau;
  niveau=lookup_widget(button,"niveau");
  gtk_widget_destroy(niveau);
}











///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void
on_button2_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
}

void
on_recfinal_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *rec, *jour,*mois,*annee;

  reclamation x[5000];
  datee y;
  int k=0,i,foyer=0,tech=0,rest=0;
  FILE *f=NULL;
  f=fopen("reclamation.txt","r+");
  while(fscanf(f,"%d %d %d %s %s %s %s\n",&x[k].date.jour,&x[k].date.mois,&x[k].date.annee,x[k].nom,x[k].id,x[k].categorie,x[k].description)
    !=EOF)
 {
      k++;
  }
  fclose(f);
  rec = lookup_widget(button,"affres");
  jour=lookup_widget(button,"recjour");
  mois=lookup_widget(button,"recmois");
  annee=lookup_widget(button,"recannee");

  y.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
  y.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
  y.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


  for(i=0;i<k;i++){

    if(datecmp_rec(x[i].date,y)==1){
      if(strcmp(x[i].categorie,"Foyer")==0)
      foyer++;
      else
      if(strcmp(x[i].categorie,"Technique")==0)
      tech++;
      else
      if(strcmp(x[i].categorie,"Restaurant")==0)
      rest++;
    }

    }
    if ((foyer==0)&&(rest==0)&&(tech==0))
{ gtk_label_set_text(GTK_LABEL(rec), "Aucun service réclamé depuis cette date");}
else
{
    if(radio_rec==1){
    if((foyer>tech)&&(foyer>rest))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le plus reclamé est:\n Foyer.");
    else
    if((tech>foyer)&&(tech>rest))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le plus reclamé est:\n Technique.");
    else
    if((rest>=foyer)&&(rest>=tech))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le plus reclamé est:\n Restaurant.");
    }
    if(radio_rec==2){
    if(!((foyer>tech)&&(foyer>rest)))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le moins reclamé est:\n Foyer.");
    else
    if(!((tech>foyer)&&(tech>rest)))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le moins reclamé est:\n Technique.");
    else
    if(!((rest>=foyer)&&(rest>=tech)))
    gtk_label_set_text(GTK_LABEL(rec), "Le service le moins reclamé est:\n Restaurant.");
    }
}
}


void
on_button_ordre_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_recordre();
  gtk_widget_show(x);
  radio_rec=1;
}


void
on_button_save1_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
reclamation x;
fileload_rec();


GtkWidget * nom, * id, * description, * categorie, * jour, * mois , * annee , * inc;


nom = lookup_widget(button,"entry_nom_rec");
id = lookup_widget(button,"entry_id_rec");
description = lookup_widget(button,"entry_desc_rec");
categorie = lookup_widget(button,"comboboxentry1_rec");
inc = lookup_widget(button,"label_mess");
jour=lookup_widget(button,"spin_jour_rec");
mois=lookup_widget(button,"spin_mois_rec");
annee=lookup_widget(button,"spin_annee_rec");

strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.description, gtk_entry_get_text(GTK_ENTRY(description)));
strcpy(x.categorie, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));
x.date.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
x.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
x.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));

if( (isalphabet_rec(x.nom)==1)&&(isid_rec(x.id)==-1)&&(nospace_rec(x.id)==1)&&(nospace_rec(x.nom)==1))
{
ajout_rec(x);
filesave_rec();
gtk_label_set_text(GTK_LABEL(inc), "ajout avec succès.");
}
else
{
gtk_label_set_text(GTK_LABEL(inc), "Vérifier vos données.");
}
}


void
on_button_retoura_rec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget * rectab;
	rectab = create_rectab ();
 	gtk_widget_show (rectab);
}


void
on_button_save2_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
reclamation x;
fileload_rec();


GtkWidget * nom, * id, * categorie, * description, * inc , *jour , *mois , *annee ;


nom = lookup_widget(button,"entry_nomdeja_rec");
id = lookup_widget(button,"entry_identif_rec");
description = lookup_widget(button,"nouvdesc_rec");
categorie = lookup_widget(button,"comboboxentry2_rec");
inc = lookup_widget(button,"label16");
jour=lookup_widget(button,"spin_jour1_rec");
mois=lookup_widget(button,"spin_mois1_rec");
annee=lookup_widget(button,"spin_annee1_rec");

strcpy(x.nom, gtk_entry_get_text(GTK_ENTRY(nom)));
strcpy(x.id, gtk_entry_get_text(GTK_ENTRY(id)));
strcpy(x.description, gtk_entry_get_text(GTK_ENTRY(description)));
strcpy(x.categorie, gtk_combo_box_get_active_text(GTK_COMBO_BOX(categorie)));
x.date.jour= gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
x.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
x.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));


if( (isalphabet_rec(x.nom)==1)&&(isid_rec(x.id)!=-1)&&(nospace_rec(x.id)==1)&&(nospace_rec(x.nom)==1))
{
modifier_rec(x);
filesave_rec();
gtk_label_set_text(GTK_LABEL(inc), "Modification effectuée avec succès.");
}
else
{
gtk_label_set_text(GTK_LABEL(inc), "Vérifier vos données.");
}

}


void
on_button_retour2_rec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget * rectab;
	rectab = create_rectab ();
 	gtk_widget_show (rectab);
}


void
on_button10_rec_clicked                (GtkButton       *button,
                                        gpointer         user_data)
{
char x[100];
fileload_rec();


GtkWidget * id, * errorsupp, * inc;

id = lookup_widget(button,"entry_idasupp_rec");
inc = lookup_widget(button,"label_res");

strcpy(x, gtk_entry_get_text(GTK_ENTRY(id)));



if(isid_rec(x)!=-1)
{
supprimer_rec(x);

filesave_rec();
gtk_label_set_text(GTK_LABEL(inc), "succès");
}
else
{
gtk_label_set_text(GTK_LABEL(inc), "utilisateur inexistant.");
}

}


void
on_button_retour_supp_rec_clicked      (GtkButton       *button,
                                        gpointer         user_data)
{
        GtkWidget * rectab;
	rectab = create_rectab ();
 	gtk_widget_show (rectab);
}


void
on_radiobutton2_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio_rec=1;
}


void
on_radiobutton3_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
radio_rec=2;
}


void
on_button_affiche_rec_clicked          (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_rec();
GtkWidget * aff;
  aff=lookup_widget(button,"treeview1_rec");
  afficher_rec(aff);
}


void
on_button_recherche_rec_clicked        (GtkButton       *button,
                                        gpointer         user_data)
{
fileload_rec();
  int i;
  char sid[30];
  GtkWidget *liste, *id;
  id=lookup_widget(button,"gettrouver_rec");
  liste=lookup_widget(button,"treeview1_rec");
  strcpy(sid, gtk_entry_get_text(GTK_ENTRY(id)));

  i=isid_rec(sid);
  if(i!=-1)
  {
    viderliste_rec(liste);
    rechercher_rec(liste, i);
  }
  else
  {
    viderliste_rec(liste);
  }
}


void
on_button_ajout_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * ajoutrec;
  ajoutrec = create_ajoutrec ();
  gtk_widget_show (ajoutrec);
}


void
on_button_modif_rec_clicked            (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * modif_rec;
  modif_rec = create_modif_rec ();
  gtk_widget_show (modif_rec);
}


void
on_button_rec_supression_clicked       (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget * supression;
  supression = create_supression ();
  gtk_widget_show (supression);

}


void
on_buttonorderrec_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x=create_recordre();
  gtk_widget_show(x);
  radio_rec=1;

}


void
on_button1_rec_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
 GtkWidget *x;
  x=create_services();
  gtk_widget_show(x);
  radio=1;

}


void
on_checkbutton2_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
trec[1]=1;
}


void
on_checkbutton1_rec_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
trec[0]=1;
}



void
on_ajouter_menu_clicked_clubs          (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *Gestiondemenu;
  GtkWidget *Ajouter_menu;
  Ajouter_menu=create_Ajouter_menu();
  gtk_widget_show(Ajouter_menu);
  Gestiondemenu=lookup_widget(button,"Gestiondemenu");
  gtk_widget_hide(Gestiondemenu);
}


void
on_button73_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{



}

void
on_button31_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
  stock x;
  fileload_stock();
  GtkWidget * ajout;
  GtkWidget * nomp, * typep, * identite, * quantite, * ms, * inc;
  nomp = lookup_widget(button,"entry126");
  typep = lookup_widget(button,"entry127");
  identite = lookup_widget(button,"entry128");
  quantite= lookup_widget(button,"spinbutton3");
  ms= lookup_widget(button,"comboboxentry2");
  inc= lookup_widget(button,"label173");

  strcpy(x.N_P, gtk_entry_get_text(GTK_ENTRY(nomp)));
  strcpy(x.TY_P, gtk_entry_get_text(GTK_ENTRY(typep)));
  strcpy(x.ID, gtk_entry_get_text(GTK_ENTRY(identite)));
  sprintf(x.QTD,"%d", gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(quantite)));
  strcpy(x.M_S, gtk_combo_box_get_active_text(GTK_COMBO_BOX(ms)));



  if( (isalphabet_stock(x.N_P)==1)&&(isalphabet_stock(x.TY_P)==1)&&(isid_stock(x.ID)==-1)&&(nospace_stock(x.ID)==1)){
  ajouts_stock (x);
  filesave_stock();
  gtk_label_set_text(GTK_LABEL(inc), "Ajout avec succes.");
  }
  else{
  gtk_label_set_text(GTK_LABEL(inc), "Verifier vos données.");
}}




void
on_gedttrouver_rec_changed             (GtkEditable     *editable,
                                        gpointer         user_data)
{
  GtkWidget* liste;
  char x[100];
  strcpy(x, gtk_entry_get_text(GTK_ENTRY(editable)));
  liste = lookup_widget(editable,"treeview1_rec");
  rechercher_rec(liste,x);
}





void
on_instagram_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
system("xdg-open https://www.instagram.com/solid__programmers/");
}


void
on_Facebook_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
system("xdg-open https://www.facebook.com/Solid-Programmers-108064095085748");
}


void
on_Website_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
system("xdg-open https://bensassiahmedkhali.wixsite.com/my-site-1");
}


void
on_submit_clicked                      (GtkButton       *button,
                                        gpointer         user_data)
{
  char text[200];
    char subject[100]="subject: ",to[100]="to :",body[100],email[100];
    GtkWidget *cmpt;
    GtkWidget *text_email;
    GtkWidget *subj,*bod;
    cmpt = lookup_widget (button,"destination");
    subj= lookup_widget(button,"subject");
    bod= lookup_widget(button,"body");
    strcat(to,gtk_entry_get_text(GTK_ENTRY(cmpt)));
    strcpy(email,gtk_entry_get_text(GTK_ENTRY(cmpt)));
    strcat(subject,gtk_entry_get_text(GTK_ENTRY(subj)));

    GtkTextIter start, end;
  GtkTextBuffer *buffer = gtk_text_view_get_buffer (bod);
  gchar *text1;

  gtk_text_buffer_get_bounds (buffer, &start, &end);
  text1 = gtk_text_buffer_get_text (buffer, &start, &end, FALSE);
    strcpy(body,text1);
    strcat(to,"\r\n");
    strcat(subject,"\r\n");
    strcat(body,"\r\n");
    send_email(email,to,subject,body);
/*
    GtkWidget *hh_mail;
    hh_mail=lookup_widget(button,"hh_mail");


    strcpy (text,"votre email a été envoyé");
    text_email=lookup_widget(button,("text_email"));
    GdkColor color;
    gdk_color_parse("green",&color);
    gtk_widget_modify_fg(text_email,GTK_STATE_NORMAL,&color);
    gtk_label_set_text(GTK_LABEL(text_email),text);*/

}

void
on_gotomail_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *x;
x= create_window1();
gtk_widget_show(x);
}

void
on_email_clubs_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= create_window1();
  gtk_widget_show(x);
}


void
on_email_tech_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{GtkWidget *x;
x= create_window1();
gtk_widget_show(x);

}


void
on_email_stock_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= create_window1();
  gtk_widget_show(x);
}


void
on_email_menu_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= create_window1();
  gtk_widget_show(x);
}


void
on_email_foyer_clicked                 (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= create_window1();
  gtk_widget_show(x);
}


void
on_email_rec_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
  GtkWidget *x;
  x= create_window1();
  gtk_widget_show(x);
}

void
on_email_annuler_clicked               (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *x;
x= lookup_widget(button,"window1");
gtk_widget_destroy(x);
}
