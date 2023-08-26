
   SOIENT
       /********************************* Les variables ************************************/
       A1 , A2 , A3 : ARB ;
       M , N , I , J : ENTIERS ;
       Continue : BOOLEEN ;

      /****************************** Les modules utilises **********************************/
       Insert : ACTION ;
      {inserer dans un arbre (acceptant des doubles)}

       Rech_bst : FONCTION ( BOOLEEN ) ;
      {retourne vrai si une valeur existe dans un bst}

       Gen_bst : FONCTION ( ARB ) ;
      {genere un arbre de recherche a n donnees }

       Suiv_ord : FONCTION ( ARB ) ;
      {retourne le suivant preordre/inordre/postordre d'un noeud selon un entier entre 1 et 3}

       Prem_ord : FONCTION ( ARB ) ;
      {retourne le premier preordre/inordre/postordre noeud selon un entier entre 1 et 3}

       Fusion : FONCTION ( ARB ) ;
      {fusion entre deux arbres par un ordre de parcour selon un entier entre 1 et 5}

       Feuille : FONCTION ( BOOLEEN ) ;
      {retoure vrai si le noeud est une feuille}

       Liberer_arb : ACTION;
      {libeber tous les noeuds d'un arbre}

      /********************** Vérification de validité de la fusion ************************/

       Validite : FONCTION ( BOOLEEN ) ;
      {tester si tout les elements d'un arbre sont dans deux autres arbres}


      /***********************    Algorithme de naviguation ********************************/
       Prem_inord , Prem_postord : FONCTION ( ARB ) ;

       Suiv_inord , Suiv_postord , Suiv_preord : FONCTION ( ARB ) ;

  /******************************** Programme principale **********************************/

   DEBUT

       M := 10 ;
       N := 50 ;

       Continue := VRAI;
       { Si il y a un erreur dans la fusion, on exit directement }

       I := 1 ;
       TQ ( I <= M ) ET ( Continue = VRAI )

           A1 := Gen_bst ( N ) ;
           { Générer l’arbre A1 avec N donnes aleatoires}

           A2 := Gen_bst ( N ) ;
           { Générer l’arbre A2 avec N donnes aleatoires}

           POUR J := 1 , 5

               A3 := Fusion ( A1 , A2 , J ) ;
               { Appliquer la fusion selon l'entier J de les 5 ordres de parcour}

               SI ( Validite ( A3, A2, A1 ) = FAUX )
                  Continue := FAUX
               FSI ;
               { Vérifier la validité de la fusion }

               APPEL Liberer_arb( A3 ) ;

           FPOUR ;

           APPEL Liberer_arb( A1 ) ;
           APPEL Liberer_arb( A2 ) ;

           I := I+1;

       FTQ ;

       SI ( Continue = VRAI )
          ECRIRE ( 'La fusion est correcte ' ) ;

       SINON
          ECRIRE ( 'La fusion n est pas correcte ' ) ;

       FSI;

   FIN

  /****************************** Fin du programme principale ****************************/

  /********************************** Corps des modules **********************************/
   {inserer dans un arbre A un nouveau element d'info X (acceptant des doubles)}
   ACTION Insert ( A , X )
   SOIENT
       A : ARB ;
       X : ENTIER ;
       P : ARB ;

   DEBUT
       SI A = NIL
           CREERNOEUD ( A ) ;
           AFF_INFO ( A , X ) ;
           AFF_FD ( A , NIL ) ;
           AFF_FD ( A , NIL ) ;

       SINON
           SI INFO ( A ) < X
               P := FD ( A ) ;
               APPEL Insert ( P , X ) ;
               AFF_FD ( A , P ) ;
               AFF_PERE ( P , A ) ;

           SINON
               P := FG ( A ) ;
               APPEL Insert ( P , X ) ;
               AFF_FG ( A , P ) ;
               AFF_PERE ( P , A ) ;

           FSI
       FSI
   FIN

  /************************* Fonction de recherche dans bst **************************/
   {retourne vrai si une valeur X existe dans un arbre bst A}
   FONCTION Rech_bst ( A , X ) : BOOLEEN
   SOIENT
       A : ARB ;
       X : ENTIER ;
       Bool : BOOLEEN ;

   DEBUT
       SI A = NIL
           Bool := FAUX ;

       SINON
           SI INFO ( A ) < X
               Bool := Rech_bst ( FD ( A ) , X ) ;

           SINON
               SI INFO ( A ) > X
                   Bool := Rech_bst ( FG ( A ) , X ) ;

               SINON
                   Bool := VRAI ;

               FSI
           FSI
       FSI ;
       Rech_bst := Bool ;

   FIN

  /********************* Fonction qui genere un bst a n data ******************************/
   {genere un arbre de recherche a N donnees aleatoires }
   FONCTION Gen_bst ( N ) : ARB
   SOIENT
       N : ENTIER ;
       X , I : ENTIER ;
       A : ARB ;

   DEBUT
       POUR I := 1 , N
           X := ALEANOMBRE ( 1000 ) ;
           TQ Rech_bst ( A , X )
               X := ALEANOMBRE ( 1000 ) ;

           FTQ ;
           APPEL Insert ( A , X ) ;

       FPOUR ;
       Gen_bst := A ;

   FIN
  /**************************************************/
   {retoure vrai si le noeud est une feuille}
   FONCTION Feuille ( N ) : BOOLEEN
   SOIT
       N : ARB ;

   DEBUT
       SI N = NIL
           Feuille := VRAI ;

       SINON
           Feuille := ( ( FG ( N ) = NIL ) ET ( FD ( N ) = NIL ) ) ;

       FSI
   FIN

  /************************** Algorithme de naviguation *******************************/
   {retourne le premier inordre d'un arbre A}
   FONCTION Prem_inord ( A ) : ARB
   SOIENT
       A : ARB ;
       P : ARB ;

   DEBUT
       P := A ;
       SI P <> NIL
           TQ FG ( P ) <> NIL
               P := FG ( P ) ;

           FTQ ;

       FSI ;
       Prem_inord := P
   FIN
  /*************************************/
  {retourne le premier postordre d'un arbre A}
   FONCTION Prem_postord ( A ) : ARB
   SOIENT
       A : ARB ;
       P : ARB ;

   DEBUT
       P := A ;
       TQ NON Feuille ( P )
           SI FG ( P ) <> NIL
               P := FG ( P ) ;

           SINON
               P := FD ( P ) ;

           FSI ;

       FTQ ;
       Prem_postord := P ;

   FIN
  /*************************************/
   {retourne le suivant inordre d'un noeud A}
   FONCTION Suiv_inord ( A ) : ARB
   SOIENT
       A : ARB ;
       P , Q : ARB ;
       Trouv : BOOLEEN ;

   DEBUT
       Q := A ;
       SI FD ( Q ) <> NIL
           P := Prem_inord ( FD ( Q ) ) ;

       SINON
           Trouv := FAUX ;
           P := PERE ( Q ) ;
           TQ ( P <> NIL ) ET ( NON Trouv )
               SI Q = FG ( P )
                   Trouv := VRAI ;

               SINON
                   Q := P ;
                   P := PERE ( Q ) ;

               FSI ;

           FTQ ;

       FSI ;
       Suiv_inord := P ;

   FIN
  /*************************************/
  {retourne le suivant postordre d'un noeud A}
   FONCTION Suiv_postord ( A ) : ARB
   SOIENT
       A : ARB ;
       Father , Brother , Res : ARB ;
       Trouv : BOOLEEN ;

   DEBUT
       Father := PERE ( A ) ;
       SI ( Father = NIL )
           Res := NIL ;

       SINON
           SI ( A = FD ( Father ) ) OU ( FD ( Father ) = NIL )
               Res := Father ;

           SINON
               Brother := FD ( Father ) ;
               Res := Prem_postord ( Brother ) ;

           FSI ;

       FSI ;
       Suiv_postord := Res ;

   FIN
  /*************************************/
  {retourne le suivant preordre d'un noeud A}
   FONCTION Suiv_preord ( A ) : ARB
   SOIENT
       A : ARB ;
       Father , Res , P DES ARB ;
       Trouv UN BOOLEEN ;

   DEBUT
       P := A ;
       SI FG ( A ) <> NIL
           Res := FG ( A ) ;

       SINON
           SI FD ( A ) <> NIL
               Res := FD ( A ) ;

           SINON
               Father := PERE ( P ) ;
               Res := NIL ;
               Trouv := FAUX ;
               TQ ( Father <> NIL ) ET ( NON Trouv )
                   SI ( P = FG ( Father ) ) ET ( FD ( Father ) <> NIL )
                       Trouv := VRAI ;
                       Res := FD ( Father ) ;

                   SINON
                       P := Father ;
                       Father := PERE ( Father ) ;

                   FSI ;

               FTQ ;

           FSI ;

       FSI ;
       Suiv_preord := Res ;

   FIN

  /********************** Modules de la fusion ************************************/
   {retourne le suivant preordre/inordre/postordre d'un noeud A selon un entier Choix entre 1 et 3}
   FONCTION Suiv_ord ( A , Choix ) : ARB
   SOIENT
       A : ARB ;
       Choix : ENTIER ;

   DEBUT
       SI Choix = 1
           Suiv_ord := Suiv_preord ( A ) ;

       SINON
           SI Choix = 2
               Suiv_ord := Suiv_inord ( A ) ;

           SINON
               Suiv_ord := Suiv_postord ( A ) ;

           FSI ;

       FSI ;

   FIN
  /*************************************/
   {retourne le premier preordre/inordre/postordre de noeud A selon un entier Choix entre 1 et 3}
   FONCTION Prem_ord ( A , Choix ) : ARB
   SOIENT
       A : ARB ;
       Choix : ENTIER ;

   DEBUT
       SI Choix = 1
           Prem_ord := A ;

       SINON
           SI Choix = 2
               Prem_ord := Prem_inord ( A ) ;

           SINON
               Prem_ord := Prem_postord ( A ) ;

           FSI ;

       FSI ;

   FIN
  /*************************************/
   {retourne le resultat de fusion entre deux arbres A1 et A2 ...}
   {...par un ordre de parcour selon un entier Choix entre 1 et 5}
   FONCTION Fusion ( A1 , A2 , Choix ) : ARB
   SOIENT
       A1 , A2 : ARB ;
       C1 , C2 , A3 : ARB ;
       Choix : ENTIER ;
       N1 , N2 , C : ENTIERS ;

   DEBUT
       {Choix va indique quel cas (ordre de parcour) on fait le fusion}
       {avec N1 et N2 indique l'ordre de parcours de A1 et A2}
       SI Choix = 1
           N1 := 2 ;
          /*inordre*/
           N2 := 1 ;
          /*preordre*/

       SINON
           SI Choix = 2
               N1 := 2 ;
              /*inordre*/
               N2 := 3 ;
              /*postordre*/

           SINON
               SI Choix = 3
                   N1 := 1 ;
                  /*preordre*/
                   N2 := 1 ;
                  /*preordre*/

               SINON
                   SI Choix = 4
                       N1 := 3 ;
                      /*postordre*/
                       N2 := 3 ;
                      /*postordre*/

                   SINON
                       N1 := 1 ;
                      /*preordre*/
                       N2 := 3 ;
                      /*postordre*/

                   FSI ;

               FSI ;

           FSI ;

       FSI ;

       C1 := Prem_ord ( A1 , N1 ) ;
       {le premier noeud de l'arbre A1 d'un ordre seleon N1}
       C2 := Prem_ord ( A2 , N2 ) ;
       {le premier noeud de l'arbre A2 d'un ordre seleon N2}

       {effuctuer la fusion jusqu'a terminer le parcours d'un des deux arbres A1 et A2}
       TQ ( C1 <> NIL ) ET ( C2 <> NIL )

           SI INFO ( C2 ) < INFO ( C1 )
               APPEL Insert ( A3 , INFO ( C2 ) ) ;
               C2 := Suiv_ord ( C2 , N2 ) ;
               {on avance dans l'arbre A2 si on insert son element qui est inferior}

           SINON
               APPEL Insert ( A3 , INFO ( C1 ) ) ;
               C1 := Suiv_ord ( C1 , N1 ) ;
               {on avance dans l'arbre A1 si on insert son element qui est inferior ou egal}
           FSI ;

       FTQ ;

       SI C2 = NIL
           {on va inserer le rest des elements de A1 selon le meme ordre de parcour}
           TQ ( C1 <> NIL )
               APPEL Insert ( A3 , INFO ( C1 ) ) ;
               C1 := Suiv_ord ( C1 , N1 ) ;

           FTQ ;

       SINON
           {on va inserer le rest des elements de A2 selon le meme ordre de parcour}
           TQ ( C2 <> NIL )
               APPEL Insert ( A3 , INFO ( C2 ) ) ;
               C2 := Suiv_ord ( C2 , N2 ) ;

           FTQ ;

       FSI ;
       Fusion := A3 ;

   FIN

  /******************** Module de Vérification de validité de la fusion *****************/
   {tester si tout les elements d'un arbre A3 sont dans deux autres arbres A1 et A2}
   {on va parcourir inordre A1 et A2 on parallele avec A3}
   {on va tester l'egalite de la valeur mininmal entre A1 et A2 avec A3 }
   {si on trouve une seule inegalite donc la fusion n'etait pas correct et on retourne FAUX, Sinon on retourne VRAI}
   FONCTION Validite ( A3,A2,A1 ) : BOOLEEN
   SOIENT

       A3,A2,A1 : ARB ;
       C3,C2,C1 : ARB ;
       I : ENTIER ;
       EGAL : BOOLEEN ;

   DEBUT
       EGAL := VRAI ;
       C1 := Prem_inord ( A1 ) ;
       C2 := Prem_inord ( A2 ) ;
       C3 := Prem_inord ( A3 ) ;

       TQ ( C1 <> NIL ) ET ( C2 <> NIL )
           SI INFO ( C2 ) < INFO ( C1 )
               si info(c2) <> info(c3)
                  egal := faux;
               fsi;
               C2 := Suiv_inord ( C2 ) ;

           SINON
               si info(c1) <> info(c3)
                  egal := faux;
               fsi;
               C1 := Suiv_inord ( C1 ) ;

           FSI ;
           c3 := suiv_inord(c3);

       FTQ ;
       SI C2 = NIL
           TQ ( C1 <> NIL )
               si info(c1) <> info(c3)
                  egal := faux;
               fsi;
               C1 := Suiv_inord ( C1 ) ;
               c3 := suiv_inord(c3);

           FTQ ;

       SINON
           TQ ( C2 <> NIL )
               si info(c2) <> info(c3)
                  egal := faux;
               fsi ;
               C2 := Suiv_inord ( C2 ) ;
               c3 := suiv_inord(c3);

           FTQ ;

       FSI ;

       Validite := Egal ;

   FIN
   /*************************************/
   ACTION Liberer_arb (A)
   {libeber tous les noeuds d'un arbre A}
   SOIENT
         A : ARB ;
   DEBUT
        SI ( A <> NIL)
           APPEL Liberer_arb ( FG( A ) ) ;
           APPEL Liberer_arb ( FD( A ) ) ;
           LIBERERNOEUD ( A )  ;
        FSI;
   FIN
