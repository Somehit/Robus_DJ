/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    telecommande.cpp
 *  @brief   Télécommande infrarouge : envoi des codes et réception sur le robot.
 *
 *  @details Code des fonctions déclarées dans telecommande.h.
 *           Chaque fonction du .h doit être écrite ici, avec exactement la même
 *           signature. Les explications (paramètres, retour) sont dans le .h.
 *
 *  @author  Naguy Cantin
 *  @date    2026-11-13
 * ============================================================================
 */

#include <telecommande/telecommande.h>

// Autres modules utilisés par les fonctions de ce fichier
#include <musique/musique.h> // JouerMusiqueAuHasard, ArreterMusique
#include <mouvement/mouvement.h> // LancerChoregraphieAuHasard, stopMotors
#include <bras-robotique/bras-robotique.h> // LancerMouvementBras, BrasAuRepos
#include <lumiere-disco/lumiere-disco.h> // AllumerBouleDisco, EteindreBouleDisco
#include <securite/securite.h> // BasculerArretUrgence, arretUrgenceActif

// --- Variables globales (déclarées « extern » dans le .h) ---
IRsend irsend;

Bouton boutonDanse = {BOUTON_DANSE, LOW, LOW, 0};
Bouton boutonMarcheArret = {BOUTON_MARCHE_ARRET, LOW, LOW, 0};
Bouton boutonUrgence = {BOUTON_URGENCE, LOW, LOW, 0};

bool robotEnMarche = false; // le robot démarre en veille, le bouton 2 l'allume

// TODO : écrire ici les fonctions déclarées dans telecommande.h
