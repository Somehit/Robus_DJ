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
    {"The bad touch", "Bloodhound Gang"},
    {"Lush Life", "Zara Larsson"},
    {"Turn Down for What", "DJ Snake & Lil Jon"},
    {"I Was Made for Lovin' You", "Kiss "},
    {"Mélanine", "Heuss l'Enfoiré"},
    {"Get Lucky", "Daft Punk"},
    {"California Gurls", "Katy Perry"},
    {"Light Years (feat. Inéz)", "John Summit"},
    {"Into the Groove", "Madonna"},
    {"Easy Lover", "Philip Bailey & Phil Collins"},
    {"Mentir", "Marie-Mai"},
    {"Under the Bridge", "Red Hot Chili Peppers"},
    {"Shut Up and Drive", "Rihanna"},
    {"Whenever, Wherever", "Shakira"},
    {"I Gotta Feeling", "Black Eyed Peas"},
    {"No Batidão", "ZXKAI & slxughter"},
    {"One More Time", "Daft Punk"},
    {"Passo Bem Solto (Slowed)", "ATLXS"},
    {"Free Bird", "Lynyrd Skynyrd"},
    {"I Will Survive", "Gloria Gaynor"},
    {"Immortals", "Fall Out Boy"},
    {"It's the Most Wonderful Time of the Year", "jschlatt"},
    {"Let's Do It Again", "AngryBaby"},
    {"Alors on danse", "Stromae"},
    {"Crazy in Love (feat. Jay-Z)", "Beyoncé"},
    {"Watermelon Sugar", "Harry Styles"},
    {"Deux frères", "PNL"},
    {"Zipette", "Ninho"},
    {"Les Champs-Élysées", "Joe Dassin"},
    {"Cette année-là", "Claude François"}

  };

void loop() {
//  vol = (analogRead(A7))/10;
  ControleLCD(liste_chanson_artiste);
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


