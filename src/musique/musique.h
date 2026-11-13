/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    musique.h
 *  @brief   Lecture de la musique (lecteur MP3 + enceinte).
 *
 *  Tâches :
 *    B3 Faire jouer de la musique depuis le stockage
 *    B4 Changement de volume
 *    B5 Changement de musique (au hasard, sans répétition)
 *    B6 Sélectionner les musiques pour la carte SD
 *    B7 Next song / previous song
 *
 *  @author  Jérémy Drouin, Yassine Ennaji (B6)
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef MUSIQUE_H
#define MUSIQUE_H

#include <config.h>

const uint8_t NB_MUSIQUES = 5; // à ajuster (B6)
const uint8_t AUCUNE_MUSIQUE = 0;

// Volume en pourcentage
const uint8_t VOLUME_MIN = 0;
const uint8_t VOLUME_MAX = 100;
const uint8_t VOLUME_DEFAUT = 50;
const uint8_t PAS_VOLUME = 10;

extern const char *const TITRES_MUSIQUES[NB_MUSIQUES]; // 20 caractères max
extern uint8_t musiqueActuelle; // 1 à NB_MUSIQUES, ou AUCUNE_MUSIQUE
extern uint8_t volumeActuel;
extern bool musiqueEnCours;

/** @brief Démarre le lecteur MP3 et règle le volume à VOLUME_DEFAUT. */
void MusiqueInit();

/**
 * @brief Fait jouer une piste (B3).
 * @param numero Numéro de la piste (1 à NB_MUSIQUES).
 */
void JouerMusique(uint8_t numero);

/** @brief Arrête la musique en cours. */
void ArreterMusique();

/**
 * @brief Fait jouer une piste au hasard, sans répétition (B5).
 * @return Numéro de la piste choisie.
 */
uint8_t JouerMusiqueAuHasard();

/**
 * @brief Passe à la piste suivante (B7).
 * @return Numéro de la nouvelle piste.
 */
uint8_t MusiqueSuivante();

/**
 * @brief Revient à la piste précédente (B7).
 * @return Numéro de la nouvelle piste.
 */
uint8_t MusiquePrecedente();

/**
 * @brief Indique si la piste en cours vient de se terminer.
 * @return true si la piste vient de finir.
 */
bool MusiqueTerminee();

/**
 * @brief Donne le titre d'une piste.
 * @param numero Numéro de la piste (1 à NB_MUSIQUES).
 * @return Titre de la piste, ou "" si le numéro est invalide.
 */
const char *TitreMusique(uint8_t numero);

/**
 * @brief Règle le volume (B4).
 * @param pourcentage Volume voulu (0 à 100).
 */
void ReglerVolume(uint8_t pourcentage);

/**
 * @brief Monte le volume de PAS_VOLUME (B4).
 * @return Nouveau volume en pourcentage.
 */
uint8_t MonterVolume();

/**
 * @brief Baisse le volume de PAS_VOLUME (B4).
 * @return Nouveau volume en pourcentage.
 */
uint8_t BaisserVolume();

#endif
