/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    ecran-lcd.h
 *  @brief   Affichage sur l'écran LCD et boutons de navigation de musique.
 *
 *  Tâches :
 *    E4 Installation de l'écran LCD
 *    E5 Afficher la musique qui joue
 *    E6 Afficher le volume
 *    E7 Afficher le bouton appuyé
 *    E8 Installation des boutons de navigation de musique
 *
 *  @author  Mathieu Guenette
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef ECRAN_LCD_H
#define ECRAN_LCD_H

#include <config.h>

// Écran LCD (I2C)
const uint8_t LCD_NB_COLONNES = 20;
const uint8_t LCD_NB_LIGNES = 4;

// Contenu de chaque ligne
const uint8_t LIGNE_TITRE = 0;
const uint8_t LIGNE_MUSIQUE = 1;
const uint8_t LIGNE_VOLUME = 2;
const uint8_t LIGNE_BOUTON = 3;

const unsigned long DUREE_AFFICHAGE_BOUTON_MS = 1000;

// Boutons de navigation (à confirmer)
const int BROCHE_BOUTON_PRECEDENT = 39;
const int BROCHE_BOUTON_SUIVANT = 40;
const int BROCHE_BOUTON_VOLUME_MOINS = 41;
const int BROCHE_BOUTON_VOLUME_PLUS = 42;

enum BoutonNavigation : uint8_t
{
    AUCUN_BOUTON,
    BOUTON_PRECEDENT,
    BOUTON_SUIVANT,
    BOUTON_VOLUME_MOINS,
    BOUTON_VOLUME_PLUS
};

extern Bouton boutonPrecedent;
extern Bouton boutonSuivant;
extern Bouton boutonVolumeMoins;
extern Bouton boutonVolumePlus;
extern unsigned long debutAffichageBouton; // en millisecondes

/** @brief Démarre l'écran LCD et affiche le message d'accueil. */
void EcranInit();

/** @brief Efface l'écran. */
void EffacerEcran();

/**
 * @brief Écrit un texte sur une ligne de l'écran.
 * @param ligne Numéro de la ligne (0 à LCD_NB_LIGNES - 1).
 * @param texte Texte à afficher (20 caractères max).
 */
void AfficherLigne(uint8_t ligne, const char *texte);

/**
 * @brief Affiche le titre de la musique en cours (E5).
 * @param titre Titre à afficher.
 */
void AfficherMusique(const char *titre);

/**
 * @brief Affiche le volume (E6).
 * @param pourcentage Volume à afficher (0 à 100).
 */
void AfficherVolume(uint8_t pourcentage);

/**
 * @brief Affiche le bouton appuyé pendant 1 seconde (E7).
 * @param nomBouton Nom du bouton à afficher.
 */
void AfficherBouton(const char *nomBouton);

/** @brief Efface le nom du bouton après 1 seconde, sans bloquer. */
void ActualiserEcran();

/** @brief Configure les broches des boutons de navigation (E8). */
void BoutonsNavigationInit();

/**
 * @brief Indique quel bouton de navigation vient d'être appuyé.
 * @return Bouton appuyé, ou AUCUN_BOUTON.
 */
BoutonNavigation LireBoutonNavigation();

#endif
