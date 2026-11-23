/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    main.cpp
 *  @brief   Point d'entrée du robot : setup() et loop().
 *
 *  @details Le main est volontairement VIDE pour l'instant. La boucle
 * principale (tâche J3) appellera les fonctions des modules inclus ci-dessous.
 *
 *           Tâche (Google Sheets) :
 *             J3 (P0) Coder la boucle principale
 *
 *  @author  Harjot Singh Dragneer
 *  @date    2026-11-13
 * ============================================================================
 */

#include <bras-robotique/bras-robotique.h>
#include <config.h>
#include <ecran-lcd/ecran-lcd.h>
#include <lumiere-disco/lumiere-disco.h>
#include <microphone/microphone.h>
#include <mouvement/mouvement.h>
#include <musique/musique.h>
#include <securite/securite.h>
#include <telecommande/telecommande.h>

void setup() {
  EcranInit();

 Serial.begin(9600);
}


listeLecture liste_chanson_artiste[64] = {
    {"Ca m'enerve", "Helmut Fritz"},
    {"C'est beau la bourgeoisie", "Discobitch"},
    {"The bad touch", "Bloodhound Gang"},
    {"Heart Attack", "Demi Lovato"},
    {"Can't Hold Us", "Macklemore & Ryan Lewis"},
    {"S&M", "Rihanna"},
    {"S&M", "Rihanna"}};

    int test =1;
    int vol;
    bool BoutonONS=false;

void loop() {
  vol = (analogRead(A7))/10;
  ControleLCD(liste_chanson_artiste, vol);
/*
    if (LireBoutonNavigation() == AUCUN_BOUTON) {
      BoutonONS = false;
    }    
    if (LireBoutonNavigation() == BOUTON_PRECEDENT && BoutonONS == false) {
      BoutonONS = true;
      vol = vol - 2;
      EffacerEcran();
    }
    if (LireBoutonNavigation() == BOUTON_SUIVANT && BoutonONS == false) {
      BoutonONS = true;
      vol = vol + 2;
            EffacerEcran();
    }

  AfficherVolume(vol); 
  delay(500);
*/


//ControleLCD(liste_chanson_artiste);

}


