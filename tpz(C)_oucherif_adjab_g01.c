  /**--------------------------------------------------------**/
  /**       C o n v e r s i o n   Z vers C (Standard)        **/
  /**             R�alis�e par Pr D.E ZEGOUR                 **/
  /**             E S I - Alger                              **/
  /**             Copywrite 2014                             **/
  /**--------------------------------------------------------**/


  /*********************************  Les variables ************************************/

  #include <stdio.h>
  #include <stdlib.h>
  #include <Time.h>
  #include <math.h>
  #include <unistd.h>


  typedef int bool ;

  #define True 1
  #define False 0

  /** Impl�mentation **\: ARBRE BINAIRE DE ENTIERS**/

  /** Arbres de recherche binaire **/

  typedef int Typeelem_Ai   ;
  typedef struct Noeud_Ai * Pointeur_Ai ;

  struct Noeud_Ai
    {
      Typeelem_Ai  Val ;
      Pointeur_Ai Fg ;
      Pointeur_Ai Fd ;
      Pointeur_Ai Pere ;
     } ;

  Typeelem_Ai Info_Ai( Pointeur_Ai P )
    { return P->Val;   }

  Pointeur_Ai Fg_Ai( Pointeur_Ai P)
    { return P->Fg ; }

  Pointeur_Ai Fd_Ai( Pointeur_Ai P)
    { return P->Fd ; }

  Pointeur_Ai Pere_Ai( Pointeur_Ai P)
    { return P->Pere ; }

  void Aff_info_Ai ( Pointeur_Ai P, Typeelem_Ai Val)
    {
       P->Val = Val ;
    }

  void Aff_fg_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fg =  Q;  }

  void Aff_fd_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Fd =  Q ; }

  void Aff_pere_Ai( Pointeur_Ai P, Pointeur_Ai Q)
    { P->Pere =  Q ; }

  void Creernoeud_Ai( Pointeur_Ai *P)
    {
      *P = (struct Noeud_Ai *) malloc( sizeof( struct Noeud_Ai))   ;
      (*P)->Fg = NULL;
      (*P)->Fd = NULL;
      (*P)->Pere = NULL;
    }

  void Liberernoeud_Ai( Pointeur_Ai P)
    { free( P ) ; }

  /** Variables du programme principal **/
  Pointeur_Ai A1=NULL;
  Pointeur_Ai A2=NULL;
  Pointeur_Ai A3=NULL;
  int M;
  int N;
  int I;
  int J;
  bool Continue;

  /** Fonctions standards **/

  int Aleanombre( int N )
    { return ( rand() % N ); }


  /** Prototypes des fonctions **/

  void Insert (Pointeur_Ai *A , int *X);
  bool  Rech_bst (Pointeur_Ai *A , int *X) ;
  Pointeur_Ai Gen_bst (int *N) ;
  bool  Feuille (Pointeur_Ai *N) ;
  Pointeur_Ai Prem_inord (Pointeur_Ai *A) ;
  Pointeur_Ai Prem_postord (Pointeur_Ai *A) ;
  Pointeur_Ai Suiv_inord (Pointeur_Ai *A) ;
  Pointeur_Ai Suiv_postord (Pointeur_Ai *A) ;
  Pointeur_Ai Suiv_preord (Pointeur_Ai *A) ;
  Pointeur_Ai Suiv_ord (Pointeur_Ai *A , int *Choix) ;
  Pointeur_Ai Prem_ord (Pointeur_Ai *A , int *Choix) ;
  Pointeur_Ai Fusion (Pointeur_Ai *A1 , Pointeur_Ai *A2 , int *Choix) ;
  bool  Validite (Pointeur_Ai *A3 , Pointeur_Ai *A2 , Pointeur_Ai *A1) ;

  /******************************  Fin du programme principale ****************************/
  /**********************************  Corps des modules **********************************/
  /*inserer dans un arbre A un nouveau element d'info X (acceptant des doubles)*/
  void Insert (Pointeur_Ai *A , int *X)
    {
      /** Variables locales **/
      Pointeur_Ai P=NULL;

      /** Corps du module **/
     if( *A == NULL) {
       Creernoeud_Ai (& *A ) ;
       Aff_info_Ai ( *A , *X ) ;
       Aff_fd_Ai ( *A , NULL ) ;
       Aff_fd_Ai ( *A , NULL ) ;
       }
     else
       {
       if( Info_Ai ( *A ) < *X) {
         P  =  Fd_Ai ( *A ) ;
         Insert ( & P , & *X ) ;
         Aff_fd_Ai ( *A , P ) ;
         Aff_pere_Ai ( P , *A ) ;
         }
       else
         {
         P  =  Fg_Ai ( *A ) ;
         Insert ( & P , & *X ) ;
         Aff_fg_Ai ( *A , P ) ;
         Aff_pere_Ai ( P , *A ) ;

       }
     }
    }
  /*************************  Fonction de recherche dans bst **************************/
  /*retourne vrai si une valeur X existe dans un arbre bst A*/
  bool  Rech_bst (Pointeur_Ai *A , int *X)
    {
      /** Variables locales **/
      bool  Rech_bst2 ;
      bool Bool;
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( *A == NULL) {
       Bool  =  False ;
       }
     else
       {
       if( Info_Ai ( *A ) < *X) {
         _Px1 =  Fd_Ai ( *A ) ;
         Bool  =  Rech_bst ( &_Px1, & *X ) ;
         }
       else
         {
         if( Info_Ai ( *A ) > *X) {
           _Px2 =  Fg_Ai ( *A ) ;
           Bool  =  Rech_bst ( &_Px2, & *X ) ;
           }
         else
           {
           Bool  =  True ;

         }
       }
     } ;
     Rech_bst2  =  Bool ;

     return Rech_bst2 ;
    }
  /*********************  Fonction qui genere un bst a n data ******************************/
  /*genere un arbre de recherche a N donnees aleatoires */
  Pointeur_Ai Gen_bst (int *N)
    {
      /** Variables locales **/
      Pointeur_Ai Gen_bst2 =NULL;
      int X;
      int I;
      Pointeur_Ai A=NULL;

      /** Corps du module **/
     for( I  =  1 ;I <=  *N ; ++I){
       X  =  Aleanombre(10*(*N)) ;
       while( Rech_bst ( & A , & X )) {
         X  =  Aleanombre(10*(*N)) ;

       } ;
       Insert ( & A , & X ) ;

     } ;
     Gen_bst2  =  A ;

     return Gen_bst2 ;
    }
  /**************************************************/
  /*retoure vrai si le noeud est une feuille*/
  bool  Feuille (Pointeur_Ai *N)
    {
      /** Variables locales **/
      bool  Feuille2 ;

      /** Corps du module **/
     if( *N == NULL) {
       Feuille2  =  True ;
       }
     else
       {
       Feuille2  =  ( ( Fg_Ai ( *N ) == NULL ) && ( Fd_Ai ( *N ) == NULL ) ) ;

     }
     return Feuille2 ;
    }
  /**************************  Algorithme de naviguation *******************************/
  /*retourne le premier inordre d'un arbre A*/
  Pointeur_Ai Prem_inord (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai Prem_inord2 =NULL;
      Pointeur_Ai P=NULL;

      /** Corps du module **/
     P  =  *A ;
     if( P != NULL) {
       while( Fg_Ai ( P ) != NULL) {
         P  =  Fg_Ai ( P ) ;

       } ;

     } ;
     Prem_inord2  =  P;
     return Prem_inord2 ;
    }
  /*************************************/
  /*retourne le premier postordre d'un arbre A*/
  Pointeur_Ai Prem_postord (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai Prem_postord2 =NULL;
      Pointeur_Ai P=NULL;

      /** Corps du module **/
     P  =  *A ;
     while( ! Feuille ( & P )) {
       if( Fg_Ai ( P ) != NULL) {
         P  =  Fg_Ai ( P ) ;
         }
       else
         {
         P  =  Fd_Ai ( P ) ;

       } ;

     } ;
     Prem_postord2  =  P ;

     return Prem_postord2 ;
    }
  /*************************************/
  /*retourne le suivant inordre d'un noeud A*/
  Pointeur_Ai Suiv_inord (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai Suiv_inord2 =NULL;
      Pointeur_Ai P=NULL;
      Pointeur_Ai Q=NULL;
      bool Trouv;
      Pointeur_Ai _Px1=NULL;

      /** Corps du module **/
     Q  =  *A ;
     if( Fd_Ai ( Q ) != NULL) {
       _Px1 =  Fd_Ai ( Q ) ;
       P  =  Prem_inord ( &_Px1) ;
       }
     else
       {
       Trouv  =  False ;
       P  =  Pere_Ai ( Q ) ;
       while( ( P != NULL ) && ( ! Trouv )) {
         if( Q == Fg_Ai ( P )) {
           Trouv  =  True ;
           }
         else
           {
           Q  =  P ;
           P  =  Pere_Ai ( Q ) ;

         } ;

       } ;

     } ;
     Suiv_inord2  =  P ;

     return Suiv_inord2 ;
    }
  /*************************************/
  /*retourne le suivant postordre d'un noeud A*/
  Pointeur_Ai Suiv_postord (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai Suiv_postord2 =NULL;
      Pointeur_Ai Father=NULL;
      Pointeur_Ai Brother=NULL;
      Pointeur_Ai Res=NULL;
      bool Trouv;

      /** Corps du module **/
     Father  =  Pere_Ai ( *A ) ;
     if( ( Father == NULL )) {
       Res  =  NULL ;
       }
     else
       {
       if( ( *A == Fd_Ai ( Father ) ) || ( Fd_Ai ( Father ) == NULL )) {
         Res  =  Father ;
         }
       else
         {
         Brother  =  Fd_Ai ( Father ) ;
         Res  =  Prem_postord ( & Brother ) ;

       } ;

     } ;
     Suiv_postord2  =  Res ;

     return Suiv_postord2 ;
    }
  /*************************************/
  /*retourne le suivant preordre d'un noeud A*/
  Pointeur_Ai Suiv_preord (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai Suiv_preord2 =NULL;
      Pointeur_Ai Father=NULL;
      Pointeur_Ai Res=NULL;
      Pointeur_Ai P=NULL;
      bool Trouv;

      /** Corps du module **/
     P  =  *A ;
     if( Fg_Ai ( *A ) != NULL) {
       Res  =  Fg_Ai ( *A ) ;
       }
     else
       {
       if( Fd_Ai ( *A ) != NULL) {
         Res  =  Fd_Ai ( *A ) ;
         }
       else
         {
         Father  =  Pere_Ai ( P ) ;
         Res  =  NULL ;
         Trouv  =  False ;
         while( ( Father != NULL ) && ( ! Trouv )) {
           if( ( P == Fg_Ai ( Father ) ) && ( Fd_Ai ( Father ) != NULL )) {
             Trouv  =  True ;
             Res  =  Fd_Ai ( Father ) ;
             }
           else
             {
             P  =  Father ;
             Father  =  Pere_Ai ( Father ) ;

           } ;

         } ;

       } ;

     } ;
     Suiv_preord2  =  Res ;

     return Suiv_preord2 ;
    }
  /**********************  Modules de la fusion ************************************/
  /*retourne le suivant preordre/inordre/postordre d'un noeud A selon un entier Choix entre 1 et 3*/
  Pointeur_Ai Suiv_ord (Pointeur_Ai *A , int *Choix)
    {
      /** Variables locales **/
      Pointeur_Ai Suiv_ord2 =NULL;

      /** Corps du module **/
     if( *Choix == 1) {
       Suiv_ord2  =  Suiv_preord ( & *A ) ;
       }
     else
       {
       if( *Choix == 2) {
         Suiv_ord2  =  Suiv_inord ( & *A ) ;
         }
       else
         {
         Suiv_ord2  =  Suiv_postord ( & *A ) ;

       } ;

     } ;

     return Suiv_ord2 ;
    }
  /*************************************/
  /*retourne le premier preordre/inordre/postordre de noeud A selon un entier Choix entre 1 et 3*/
  Pointeur_Ai Prem_ord (Pointeur_Ai *A , int *Choix)
    {
      /** Variables locales **/
      Pointeur_Ai Prem_ord2 =NULL;

      /** Corps du module **/
     if( *Choix == 1) {
       Prem_ord2  =  *A ;
       }
     else
       {
       if( *Choix == 2) {
         Prem_ord2  =  Prem_inord ( & *A ) ;
         }
       else
         {
         Prem_ord2  =  Prem_postord ( & *A ) ;

       } ;

     } ;

     return Prem_ord2 ;
    }
  /*************************************/
  /*retourne le resultat de fusion entre deux arbres A1 et A2 ...*/
  /*...par un ordre de parcour selon un entier Choix entre 1 et 5*/
  Pointeur_Ai Fusion (Pointeur_Ai *A1 , Pointeur_Ai *A2 , int *Choix)
    {
      /** Variables locales **/
      Pointeur_Ai Fusion2 =NULL;
      Pointeur_Ai C1=NULL;
      Pointeur_Ai C2=NULL;
      Pointeur_Ai A3=NULL;
      int N1;
      int N2;
      int C;
      int _Px1;
      int _Px2;
      int _Px3;
      int _Px4;

      /** Corps du module **/
     if( *Choix == 1) {
       N1  =  2 ;
      /*inordre*/
       N2  =  1 ;
      /*preordre*/
       }
     else
       {
       if( *Choix == 2) {
         N1  =  2 ;
        /*inordre*/
         N2  =  3 ;
        /*postordre*/
         }
       else
         {
         if( *Choix == 3) {
           N1  =  1 ;
          /*preordre*/
           N2  =  1 ;
          /*preordre*/
           }
         else
           {
           if( *Choix == 4) {
             N1  =  3 ;
            /*postordre*/
             N2  =  3 ;
            /*postordre*/
             }
           else
             {
             N1  =  1 ;
            /*preordre*/
             N2  =  3 ;
            /*postordre*/

           } ;

         } ;

       } ;

     } ;
     C1  =  Prem_ord ( & *A1 , & N1 ) ;
    /*le premier noeud de l'arbre *A1 d'un ordre seleon N1*/
     C2  =  Prem_ord ( & *A2 , & N2 ) ;
    /*le premier noeud de l'arbre *A2 d'un ordre seleon N2*/
    /*effuctuer la fusion jusqu'a terminer le parcours d'un des deux arbres *A1 et *A2*/
     while( ( C1 != NULL ) && ( C2 != NULL )) {
       if( Info_Ai ( C2 ) < Info_Ai ( C1 )) {
         _Px1 =  Info_Ai ( C2 ) ;
         Insert ( & A3 , &_Px1) ;
         C2  =  Suiv_ord ( & C2 , & N2 ) ;
        /*on avance dans l'arbre *A2 si on insert son element qui est inferior*/
         }
       else
         {
         _Px2 =  Info_Ai ( C1 ) ;
         Insert ( & A3 , &_Px2) ;
         C1  =  Suiv_ord ( & C1 , & N1 ) ;
        /*on avance dans l'arbre *A1 si on insert son element qui est inferior ou egal*/

       } ;

     } ;
    /*on va inserer le rest des elements de *A1 selon le meme ordre de parcour*/
     if( C2 == NULL) {
       while( ( C1 != NULL )) {
         _Px3 =  Info_Ai ( C1 ) ;
         Insert ( & A3 , &_Px3) ;
         C1  =  Suiv_ord ( & C1 , & N1 ) ;

       } ;
       }
    /*on va inserer le rest des elements de *A2 selon le meme ordre de parcour*/
     else
       {
       while( ( C2 != NULL )) {
         _Px4 =  Info_Ai ( C2 ) ;
         Insert ( & A3 , &_Px4) ;
         C2  =  Suiv_ord ( & C2 , & N2 ) ;

       } ;

     } ;
     Fusion2  =  A3 ;

     return Fusion2 ;
    }
  /********************  Module de V�rification de validit� de la fusion *****************/
  /*tester si tout les elements d'un arbre A3 sont dans deux autres arbres A1 et A2*/
  /*on va parcourir inordre A1 et A2 on parallele avec A3*/
  /*on va tester l'egalite de la valeur mininmal entre A1 et A2 avec A3 */
  /*si on trouve une seule inegalite donc la fusion n'etait pas correct et on retourne FAUX, Sinon on retourne VRAI*/
  bool  Validite (Pointeur_Ai *A3 , Pointeur_Ai *A2 , Pointeur_Ai *A1)
    {
      /** Variables locales **/
      bool  Validite2 ;
      Pointeur_Ai C3=NULL;
      Pointeur_Ai C2=NULL;
      Pointeur_Ai C1=NULL;
      int I;
      bool Egal;

      /** Corps du module **/
     Egal  =  True ;
     C1  =  Prem_inord ( & *A1 ) ;
     C2  =  Prem_inord ( & *A2 ) ;
     C3  =  Prem_inord ( & *A3 ) ;
     while( ( C1 != NULL ) && ( C2 != NULL )) {
       if( Info_Ai ( C2 ) < Info_Ai ( C1 )) {
         if( Info_Ai ( C2 ) != Info_Ai ( C3 )) {
           Egal  =  False ;

         } ;
         C2  =  Suiv_inord ( & C2 ) ;
         }
       else
         {
         if( Info_Ai ( C1 ) != Info_Ai ( C3 )) {
           Egal  =  False ;

         } ;
         C1  =  Suiv_inord ( & C1 ) ;

       } ;
       C3  =  Suiv_inord ( & C3 ) ;

     } ;
     if( C2 == NULL) {
       while( ( C1 != NULL )) {
         if( Info_Ai ( C1 ) != Info_Ai ( C3 )) {
           Egal  =  False ;

         } ;
         C1  =  Suiv_inord ( & C1 ) ;
         C3  =  Suiv_inord ( & C3 ) ;

       } ;
       }
     else
       {
       while( ( C2 != NULL )) {
         if( Info_Ai ( C2 ) != Info_Ai ( C3 )) {
           Egal  =  False ;

         } ;
         C2  =  Suiv_inord ( & C2 ) ;
         C3  =  Suiv_inord ( & C3 ) ;

       } ;

     } ;
     Validite2  =  Egal ;

     return Validite2 ;
    }
//---------------------------------------
      void Liberer_arb (Pointeur_Ai *A)
    {
      /** Variables locales **/
      Pointeur_Ai _Px1=NULL;
      Pointeur_Ai _Px2=NULL;

      /** Corps du module **/
     if( ( *A != NULL )) {
       _Px1 =  Fg_Ai ( *A ) ;
       Liberer_arb ( &_Px1) ;
       _Px2 =  Fd_Ai ( *A ) ;
       Liberer_arb ( &_Px2) ;
       Liberernoeud_Ai ( *A ) ;

     } ;

    }
/**************************  Module de Simulation *****************************/
//---------------------------------------
int max(int a,int b){
    if (a>=b)
        return a;
    else
        return b;
}
//---------------------------------------
//fct qui retourne la profendeur maximale
int profend_max (Pointeur_Ai p){
    if (p== NULL)
         return 0;
    else{
        if (Fg_Ai(p)==NULL && Fd_Ai(p)==NULL)
            return 1;
        else
        return 1+max( profend_max(Fg_Ai(p)),profend_max(Fd_Ai(p)));
           }
}
//---------------------------------------
int min(int a,int b){
    if (a<=b)
        return a;
    else
        return b;
}
//---------------------------------------
//fct qui retourne la profendeur minimale
int profend_min (Pointeur_Ai p){
    if (p== NULL)
        return 0;
    else
        if (Fg_Ai(p)==NULL || Fd_Ai(p)==NULL)
            return 1;
        else
          return 1+min(profend_min(Fg_Ai(p)),profend_min(Fg_Ai(p)));
}
//---------------------------------------
//fct pour calculer le nombre de feuilles
int nb_feuilles (Pointeur_Ai p )
{
    if (p ==NULL)
        return 0;
    else{
        if(Fd_Ai(p)==NULL && Fg_Ai(p)==NULL )
            return 1;
        else
            return nb_feuilles(Fg_Ai(p)) +nb_feuilles(Fd_Ai(p));

    }
}
//---------------------------------------
//fcts pour calculer le nombre de noeuds
int nb_noeud (Pointeur_Ai A){
    if (A==NULL)
        return 0;
    else
        return 1+nb_noeud(Fg_Ai(A))+nb_noeud(Fd_Ai(A));

}
//---------------------------------------
// fct pour calculer la hauteur d'un arbre
int hauteur (Pointeur_Ai p ){
    if (p== NULL)
        return 0;
    else
        if (Fg_Ai(p)==NULL && Fd_Ai(p)==NULL)
            return 0;
        else
            return 1+max(hauteur(Fd_Ai(p)),hauteur(Fd_Ai(p)));
}
//---------------------------------------
//fct qui calcule le nombre de noeuds d'un niveau
int nb_niv(Pointeur_Ai r, int level)
{
    if ((r == NULL) || (level == 0))
    {
        return 0;
    }
    else
    {
        if (level == 1)
        {
            return 1;
        }
        else
        {
            return (nb_niv(Fg_Ai(r),level-1)+nb_niv(Fd_Ai(r),level-1));
        }
    }
}
//---------------------------------------
/**************************Les modules utilisees pour afficher les arbre ***********************/
/************************** en utilisant les commandes de Graphviz  ****************************/
//ce module genere le code en lanage Dot dans le fichier qui a l'extension .dot
void genererDotCode(Pointeur_Ai root, FILE* file) {
    if (root == NULL) {
        return;
    }

    if (Fg_Ai(root) != NULL) {
        fprintf(file, "%d -> %d [dir=none];\n",Info_Ai(root),Info_Ai(Fg_Ai(root)));
    }

    if (Fd_Ai(root) != NULL) {
       fprintf(file, "%d -> %d [dir=none];\n",Info_Ai(root),Info_Ai(Fd_Ai(root)));

    }

    genererDotCode(Fg_Ai(root), file);
    genererDotCode(Fd_Ai(root), file);
}
/*************************************************************/
//ce module genere un fichier bst.dot , appelle la fonction generedotcode ; et apres  genere le graph dans le fichier bst.png
//pour affichier l'arbre a1 par exemple ; il suffit de faire dessinbst(a1);
//il afficher a1 dans le fichier bst.png
void dessinBST(Pointeur_Ai root) {
    FILE* file = fopen("bst.dot", "w");
    if (file == NULL) {
        printf("Impossible d'ouvrir le fichier de sortie.\n");
        return;
    }

    fprintf(file, "digraph BST {\n");
    fprintf(file, "    node [shape=circle];\n");

    genererDotCode(root, file);

    fprintf(file, "}\n");

    fclose(file);
    system("dot -Tpng bst.dot -o bst.png");
    printf("L'arbre BST a été dessiné dans le fichier bst.png.\n");
}

/**********************  Program Principal ************************************/

  int main(int argc, char *argv[])
    {
      srand(time(NULL));
     ///Initialization de variables de simulation
     //Pour chaque mertice, on va cree un fishier et sauvgarder les donne neccessaires
     //Temp de fusiom
     FILE* tmp = fopen("Temp.txt", "r");
     fprintf(tmp, "Nombre de noeud, Cas(1), Cas(2), Cas(3), Cas(4), Cas(5)\n");
     clock_t start, end;
     double temp;
     double rest[5] = {0.0};

     //Profondeur
     FILE* prof = fopen("prof.txt", "r");
     fprintf(prof, "Nombre de noeud, Cas(1), Cas(2), Cas(3), Cas(4), Cas(5)\n");
     int resp[5] = {0};

     //Le rapport de nombre de feuile sur le nombre de noeud interne
     FILE* nbn = fopen("nbnoeud.txt", "r");
     fprintf(nbn, "Nombre de noeud, Cas(1), Cas(2), Cas(3), Cas(4), Cas(5)\n");
     double intr;
     double resfn[5] = {0.0};

     //Le rapport de nombre de noeuds a gauche sur le nombre de noeud a droite
     FILE* nbgd = fopen("nodegd.txt", "r");
     fprintf(nbgd, "Nombre de noeud, Cas(1), Cas(2), Cas(3), Cas(4), Cas(5)\n");
     double resgd[5] = {0.0};

     //Profondeur minimal
     FILE* profm = fopen("profm.txt", "r");
     fprintf(profm, "Nombre de noeud, Cas(1), Cas(2), Cas(3), Cas(4), Cas(5)\n");
     int respm[5] = {0};

     //Nombre de noeud par niveau
     FILE* nbniv = fopen("nbniv.txt", "r");
     int resnv[5] = {0};
     int k;
     fprintf(nbniv, "Niveau, ");
     for (k=1;k<=100;k++)
     {
        fprintf(nbniv,"%d, ",k);
     }
     fprintf(nbniv,"\n");
     ///fin d'initialization
     srand(time(NULL));
     M  =  50 ;
     N  =  50 ; // N (Le nombre de noeuds de A1 et A2 ) sera augmenter de 50 jusqu'a 25600
     //Donc pour ce partie le nombre de noeuds de A3 est 2*N
     Continue  =  True ;
     I  =  0 ;
     while( ( I <= M ) && ( Continue == True ))
    {
       ///Generations aleatoires de A1 et A2
       A1  =  Gen_bst ( & N ) ;
      /* G�n�rer l�arbre A1 avec N donnes aleatoires*/
       A2  =  Gen_bst ( & N ) ;
      /* G�n�rer l�arbre A2 avec N donnes aleatoires*/
      //Initializations de fishiers
      if (I % 5 == 0)
      {
        fprintf(tmp,"%d, ",N);
        fprintf(prof,"%d, ",N);
        fprintf(nbn,"%d, ",N);
        fprintf(nbgd,"%d, ",N);
        fprintf(profm,"%d, ",N);
      }
       for( J  =  1 ;J <=  5 ; ++J){
         start = clock(); //just pour calculer le temps de fusion
         ///Fusion de A1 et A2 dans A3
         A3  =  Fusion ( & A1 , & A2 , & J ) ;
         end = clock();
        /* Appliquer la fusion selon l'entier J de les 5 ordres de parcour*/
         ///Simulations
         //Temp d exucution
         temp = ((double) (end - start)) / CLOCKS_PER_SEC;
         rest[J-1] = temp + rest[J-1];
         if (I % 5 == 0)
         {
             rest[J-1] = rest[J-1]/5;
             fprintf(tmp,"%.4f, ",rest[J-1]);
             rest[J-1] = 0;
             if (J == 5)
             {
                 fprintf(tmp,"\n");
             }
         }
         //Profondeur
         resp[J-1] = profend_max(A3) + resp[J-1];
         if (I % 5 == 0)
         {
             resp[J-1] = resp[J-1]/5;
             fprintf(prof,"%d, ",resp[J-1]);
             resp[J-1] = 0 ;
             if (J == 5)
             {
                 fprintf(prof,"\n");
             }
         }

         //Le rapport de nombre de feuile sur le nombre de noeud
         intr = (double)nb_feuilles(A3);
         resfn[J-1] = intr/(2*(double)N-intr) + resfn[J-1];
         if (I % 5 == 0)
         {
             resfn[J-1] = resfn[J-1]/5;
             fprintf(nbn,"%.3f, ",resfn[J-1]);
             resfn[J-1] = 0;
             if (J == 5)
             {
                 fprintf(nbn,"\n");
             }
         }

         //Le rapport de nombre de noeuds a gauche sur le nombre de noeud a droite
         resgd[J-1] = (double)nb_noeud(Fg_Ai(A3))/(double)nb_noeud(Fd_Ai(A3)) + resgd[J-1];
         if (I % 5 == 0)
         {
             resgd[J-1] = resgd[J-1]/5;
             fprintf(nbgd,"%.3f, ",resgd[J-1]);
             resgd[J-1] = 0;
             if (J == 5)
             {
                 fprintf(nbgd,"\n");
             }
         }

        //Profondeur minimal
         respm[J-1] = profend_min(A3) + respm[J-1];
         if (I % 5 == 0)
         {
             respm[J-1] = respm[J-1]/5;
             fprintf(profm,"%d, ",respm[J-1]);
             respm[J-1] = 0;
             if (J == 5)
             {
                 fprintf(profm,"\n");
             }
         }

         //Nombre de noeud par niveau
         if (I==30)
         {
             fprintf(nbniv, "Cas(%d), ",J);
             for (k=1;k<=100;k++)
             {
                fprintf(nbniv,"%d, ",nb_niv(A3,k));
             }
             fprintf(nbniv,"\n");
          }

          ///Fin de Simulations


         if( ( Validite ( & A3 , & A2 , & A1 ) == False )) {
           Continue  =  False;
         } ;
        /* Verifier la validite de la fusion */

         //liberer A3 pour ne consomer pas la memoire
         Liberer_arb(&A3);

       } ; //fPour

       //liberer A1 et A2
       Liberer_arb(&A1);
       Liberer_arb(&A2);



       usleep(100000);
       system("cls");
       printf("\n\n\n\tREMARQUES:\n\n");
       printf("\t-Si le programme met beaucoup de temps a se terminer, vous pouvez prendre le nombre de ittirations M=45 ou 40.\n\n");
       printf("\t-Sinon, si le programme s'arrete a la derniere iteration pour M=50,\n");
       printf("\tc'est qu'il a deja fini d'ecrire sur les fichiers,vous pouvez donc sortir normalement, et merci.\n\n\n");

       printf ( "\t\t\t\t       Fusion en cours ... \n\n",N ) ;
       printf ( "\t\t\tLe nombre de donnes de A1 et A2 a fusioner est %d\n",N ) ;
       printf ( "\t\t\t\t   (%d) La fusion est correcte \n",I ) ;
       I  =  I + 1 ;

       //chaque 5 ittirations on double le nombre de noeuds de A1 et A2
       if (I % 5 == 0)
       {
           N = 2*N;
       }

     } ;//fTq

      system("cls");
      //Tester la validation de fusion
     if( ( Continue == True )) {
       printf ( "\n\n\n\t\t\t\t\tLa fusion total est correcte \n\n" ) ;
       printf ( "\t\tFin de simulation de A3, les donnees ont ete enregistrees avec succes dans les fichiers  \n\n\n" ) ;
       }
     else
       {
       printf ( "\t\tLa fusion n est pas correcte, les donnes sont faux \n\n" ) ;

     } ;



      system("PAUSE");
      return 0;
    }
/********************** Fin du Program Principal ************************************/
