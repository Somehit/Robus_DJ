/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    ecran-lcd.cpp
 *  @brief   Affichage sur l'écran LCD et boutons de navigation de musique.
 *
 *  @details Code des fonctions déclarées dans ecran-lcd.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Mathieu Guenette
 *  @date    2026-11-19
 * ============================================================================
 */

#include <ecran-lcd/ecran-lcd.h>

// --- Variables globales (déclarées « extern » dans le .h) ---
/*Bouton boutonPrecedent = {BROCHE_BOUTON_PRECEDENT, LOW, LOW, 0};
Bouton boutonSuivant = {BROCHE_BOUTON_SUIVANT, LOW, LOW, 0};
Bouton boutonVolumeMoins = {BROCHE_BOUTON_VOLUME_MOINS, LOW, LOW, 0};
Bouton boutonVolumePlus = {BROCHE_BOUTON_VOLUME_PLUS, LOW, LOW, 0};

unsigned long debutAffichageBouton = 0;*/

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte musicnote_up[] = {B00000, B01111, B01001, B01001,
                       B11011, B11011, B00000, B00000};

byte musicnote_dw[] = {B00000, B00000, B01111, B01001,
                       B01001, B11011, B11011, B00000};

byte CaseVolumeFull[] = {B11111, B11111, B11111, B11111,
                         B11111, B11111, B11111, B11111};

byte CaseVolumeHalf[] = {B00000, B00000, B00000, B00000,
                         B11111, B11111, B11111, B11111};

byte pausechar[] = {B00000, B00000, B01010, B01010,
                    B01010, B01010, B01010, B00000};

byte playchar[] = {B00000, B00000, B01000, B01100,
                   B01110, B01100, B01000, B00000};

unsigned long precedentMillis = 0; // Pour gérer le temps sans bloquer
int etatDefilement =
    0; // 0 = Pause initiale, 1 = En train de défiler, 2 = Pause de fin
int indexDefilement = 0; // Position actuelle du défilement

int volume;

unsigned long MillisVolumePrecedent = 0;
unsigned long MillisPlayPrecedent = 0;
int ModeLCD;  //0 = MODE_SELECTION, 1 = MODE_AFFICHAGE, 2 = MODE_VOLUME, 3 = MODE_PAUSE, 4 = MODE_PLAY

// Fonction utilitaire à appeler dès que vous changez la variable "num"
void EcranInit() {
  ModeLCD = 0;

  pinMode(BROCHE_BOUTON_PRECEDENT, INPUT_PULLUP);
  pinMode(BROCHE_BOUTON_SUIVANT, INPUT_PULLUP);
  pinMode(BROCHE_BOUTON_SELECTION, INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.clear();

  lcd.createChar(0, musicnote_up);
  lcd.createChar(1, musicnote_dw);
  lcd.createChar(2, CaseVolumeFull);
  lcd.createChar(3, CaseVolumeHalf);
  lcd.createChar(4, pausechar);
  lcd.createChar(5, playchar);

  etatDefilement = 0;
  indexDefilement = 0;

  precedentMillis =
      millis(); // Relance le chrono à zéro pour la nouvelle chanson
  MillisVolumePrecedent =
      millis(); // Relance le chrono à zéro pour la nouvelle chanson
  MillisPlayPrecedent =
      millis(); // Relance le chrono à zéro pour la nouvelle chanson
}

void EffacerEcran() {

  lcd.clear();
  etatDefilement = 0;
  //indexDefilement = 0;
  lcd.setCursor(0, 0);
}

void ControleLCD(listeLecture listeChansonArtiste[]) {

  int VolumeActuelle = (analogRead(BROCHE_VOLUME)) / 10;
  static int VolumePrecedent = VolumeActuelle; // = VolumeActuelle;
  bool VolumeChange = VolumeActuelle > (VolumePrecedent + 1) ||
                      VolumeActuelle < (VolumePrecedent - 1);

  static int ModePrecedent = 0;
  static int num = 0;
  static bool BoutonONS = false;

  // Verif si le volume a changer
  if (VolumeChange) {
    if (ModeLCD != MODE_VOLUME) {
      ModePrecedent = ModeLCD;
    }

    MillisVolumePrecedent = millis();
    ModeLCD = MODE_VOLUME;
  }

  if (ModeLCD == MODE_SELECTION) {

    if (LireBoutonNavigation() == AUCUN_BOUTON) {
      BoutonONS = false;
      AfficherSelection(listeChansonArtiste, num);
    }

    if (LireBoutonNavigation() == BOUTON_PRECEDENT && BoutonONS == false &&
        num > 0) {
      BoutonONS = true;
      EffacerEcran();
      num--;
    }

    if (LireBoutonNavigation() == BOUTON_SUIVANT && BoutonONS == false &&
        num < NB_CHANSON_MAX) {
      BoutonONS = true;
      EffacerEcran();
      num++;
    }

    if (LireBoutonNavigation() == BOUTON_SELECTION && BoutonONS == false) {
      BoutonONS = true;
      ModeLCD = MODE_AFFICHAGE;
      EffacerEcran();
    }
  }

  if (ModeLCD == MODE_AFFICHAGE) {

    if (LireBoutonNavigation() == AUCUN_BOUTON) {
      BoutonONS = false;
      AfficherMusique(listeChansonArtiste, num, ETAT_PLAYING);
    }

    if (LireBoutonNavigation() == BOUTON_PRECEDENT) {
      BoutonONS = false;
      ModeLCD = MODE_PAUSE;
      EffacerEcran();
    }

    if (LireBoutonNavigation() == BOUTON_SELECTION && BoutonONS == false) {
      BoutonONS = true;
      ModeLCD = MODE_SELECTION;
      EffacerEcran();
    }
  }

  if (ModeLCD == MODE_PAUSE) {

    if (LireBoutonNavigation() == AUCUN_BOUTON) {
      BoutonONS = false;
      AfficherMusique(listeChansonArtiste, num, ETAT_PAUSE);
    }

    if (LireBoutonNavigation() == BOUTON_SUIVANT && BoutonONS == false) {
      BoutonONS = true;
      MillisPlayPrecedent = millis();
      ModeLCD = MODE_PLAY;
      EffacerEcran();
    }

    if (LireBoutonNavigation() == BOUTON_SELECTION && BoutonONS == false) {
      BoutonONS = true;
      ModeLCD = MODE_SELECTION;
      EffacerEcran();
    }
  }

  if (ModeLCD == MODE_PLAY) {

    unsigned long MillisPlayActuel = millis();

    if (MillisPlayActuel - MillisPlayPrecedent < DUREE_AFFICHAGE_PLAY) {

      AfficherMusique(listeChansonArtiste, num, ETAT_PLAY);

    } else {
      ModeLCD = MODE_AFFICHAGE;
      EffacerEcran();
    }
  }

  if (ModeLCD == MODE_VOLUME) {

    unsigned long MillisVolumeActuel = millis();

    if (MillisVolumeActuel - MillisVolumePrecedent < DUREE_AFFICHAGE_VOLUME) {

      if (VolumeChange) {
        AfficherVolume(VolumeActuelle);
      }

    } else {
      ModeLCD = ModePrecedent;
      EffacerEcran();
    }
  }

  if (VolumeChange) {
    VolumePrecedent = VolumeActuelle;
  }
}

void AfficherSelection(listeLecture listeChansonArtiste[], int num) {

  String l1point = "." + listeChansonArtiste[num].chanson;
  String l1 = (num + 1) + l1point;
  String l2 = " -" + listeChansonArtiste[num].ariste;
  int len1 = l1.length();
  int len2 = l2.length();
  int lenMax = max(len1, len2);

  unsigned long actuelMillis = millis();

  // --- ÉTAT 0 : PAUSE INITIALE DE 2 SECONDES ---
  if (etatDefilement == 0) {
    lcd.setCursor(0, 0);
    lcd.print(l1.substring(0, 16));
    lcd.setCursor(0, 1);
    lcd.print(l2.substring(0, 16));

    if (actuelMillis - precedentMillis >= DUREE_AFFICHAGE_DEBUT) {
      precedentMillis = actuelMillis;
      if (lenMax > 16) {
        etatDefilement = 1; // On passe au défilement si le texte est long
        indexDefilement = 1;
      } else {
        etatDefilement = 2; // Sinon, on saute directement à la pause de fin
      }
    }
  }

  // --- ÉTAT 1 : DÉFILEMENT (Toutes les 700ms) ---
  else if (etatDefilement == 1) {
    if (actuelMillis - precedentMillis >= DUREE_AFFICHAGE_DEFILEMENT) {
      precedentMillis = actuelMillis;

      String l1Extended = l1 + "                ";
      String l2Extended = l2 + "                ";

      // Rafraîchissement Ligne 1
      lcd.setCursor(0, 0);
      if (len1 > 16) {
        lcd.print(l1Extended.substring(indexDefilement, indexDefilement + 16));
      } else {
        lcd.print(l1.substring(0, 16));
      }

      // Rafraîchissement Ligne 2
      lcd.setCursor(0, 1);
      if (len2 > 16) {
        lcd.print(l2Extended.substring(indexDefilement, indexDefilement + 16));
      } else {
        lcd.print(l2.substring(0, 16));
      }

      indexDefilement++;

      // Si on a atteint la fin du texte le plus long
      if (indexDefilement > (lenMax - 16)) {
        etatDefilement = 2; // On passe à la pause de fin
      }
    }
  }

  // --- ÉTAT 2 : PAUSE DE FIN DE 2 SECONDES ---
  else if (etatDefilement == 2) {
    if (actuelMillis - precedentMillis >= DUREE_AFFICHAGE_FIN) {
      // La pause est finie, on réinitialise pour recommencer au début du texte
      EffacerEcran();
    }
  }
}

void AfficherMusique(listeLecture listeChansonArtiste[], int num, int etat) {

  String l2 = " " + listeChansonArtiste[num].chanson;
  int len2 = l2.length();

  unsigned long actuelMillis = millis();

  // --- ÉTAT 0 : PAUSE INITIALE DE 2 SECONDES ---
  if (etatDefilement == 0) {

    lcd.setCursor(0, 0);
    if (etat == ETAT_PLAYING) {
      lcd.print("Now playing ");
      lcd.write(byte(0));
      lcd.write(byte(1));
      lcd.write(byte(0));
      lcd.write(":");

    } else if (etat == ETAT_PAUSE) {
      lcd.print("Pause ");
      lcd.write(byte(4));
    } else if (etat == ETAT_PLAY) {
      lcd.print("Play ");
      lcd.write(byte(5));
    }

    lcd.setCursor(0, 1);
    lcd.print(l2.substring(0, 16));

    if (actuelMillis - precedentMillis >= DUREE_AFFICHAGE_DEBUT) {
      precedentMillis = actuelMillis;
      if (len2 > 16) {
        etatDefilement = 1; // On passe au défilement si le texte est long
        indexDefilement = 1;
      } else {
        etatDefilement = 2; // Sinon, on saute directement à la pause de fin
      }
    }
  }

  // --- ÉTAT 1 : DÉFILEMENT (Toutes les 700ms) ---
  else if (etatDefilement == 1) {
    if (actuelMillis - precedentMillis >= DUREE_AFFICHAGE_DEFILEMENT) {
      precedentMillis = actuelMillis;

      String l2Extended = l2 + "                ";

      // Rafraîchissement Ligne 2
      lcd.setCursor(0, 1);
      if (len2 > 16) {
        lcd.print(l2Extended.substring(indexDefilement, indexDefilement + 16));
      } else {
        lcd.print(l2.substring(0, 16));
      }

      indexDefilement++;

      // Si on a atteint la fin du texte le plus long
      if (indexDefilement > (len2 - 16)) {
        etatDefilement = 2; // On passe à la pause de fin
      }
    }
  }

  // --- ÉTAT 2 : PAUSE DE FIN DE 2 SECONDES ---
  else if (etatDefilement == 2) {
    if (actuelMillis - precedentMillis >= DUREE_AFFICHAGE_FIN) {
      // La pause est finie, on réinitialise pour recommencer au début du texte
      EffacerEcran();
    }
  }
}

void AfficherVolume(int pourcentage) {

  EffacerEcran();

  int Volume032 = (32.0 / 100.0) * pourcentage;
  // int Volume016 = Volume032/2;
  //  int Volume016 = FVolume016;
  String l1 = "Volume: "; //+ pourcentage;

  lcd.setCursor(0, 0);
  lcd.print(l1);
  lcd.print(pourcentage);
  lcd.write("%");

  lcd.setCursor(0, 1);
  // lcd.print(Volume016);

  for (int i = 0; i < (Volume032 / 2); i++) {
    lcd.write(byte(2));
  }
  if (Volume032 % 2 == 1) {
    lcd.write(byte(3));
  }
}

BoutonNavigation LireBoutonNavigation() {

  if (digitalRead(BROCHE_BOUTON_PRECEDENT) == LOW) {
    return BOUTON_PRECEDENT;
  }

  if (digitalRead(BROCHE_BOUTON_SUIVANT) == LOW) {
    return BOUTON_SUIVANT;
  }

  if (digitalRead(BROCHE_BOUTON_SELECTION) == LOW) {
    return BOUTON_SELECTION;
  }

  if (digitalRead(BROCHE_BOUTON_PAUSE) == LOW) {
    return BOUTON_PAUSE;
  }

  if (digitalRead(BROCHE_BOUTON_PLAY) == LOW) {
    return BOUTON_PLAY;
  }

  return AUCUN_BOUTON;
}