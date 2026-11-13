/**
 * ============================================================================
 *  Robot DJ — Projet de session S1 (Robus)
 * ============================================================================
 *  @file    telecommande.h
 *  @brief   Télécommande infrarouge : envoi des codes et réception sur le robot.
 *
 *  Tâches :
 *    D3 Réception des commandes sur le robot (IR)
 *    D4 Bouton 1 : chorégraphie + musique au hasard
 *    D5 Assemblage des composants de la télécommande
 *    D6 Bouton 2 : on/off du robot
 *
 *  @author  Naguy Cantin
 *  @date    2026-11-13
 * ============================================================================
 */

#ifndef TELECOMMANDE_H
#define TELECOMMANDE_H

#include <config.h>

// Broches côté télécommande
const int BOUTON_DANSE = 4;        // bouton 1
const int BOUTON_MARCHE_ARRET = 5; // bouton 2
const int BOUTON_URGENCE = 3;      // bouton 3
const int LED_ROUGE = 6;
const int LED_VERTE = 7;
const int LED_IR = 46; // imposée par LibRobus sur Arduino Mega (timer 5)

// Broche côté robot
const int RECEPTEUR_IR = IR_RECV_PIN; // 37

// Codes infrarouges
const uint8_t ADRESSE_IR = 0x10;
const uint8_t CODE_DANSE = 0x20;
const uint8_t CODE_MARCHE_ARRET = 0x30;
const uint8_t CODE_ARRET_URGENCE = 0x40;

extern IRsend irsend;
extern Bouton boutonDanse;
extern Bouton boutonMarcheArret;
extern Bouton boutonUrgence;
extern bool robotEnMarche;

// --- Côté télécommande ---

/** @brief Configure les boutons et les DEL de la télécommande. */
void TelecommandeInit();

/**
 * @brief Détecte un nouvel appui sur un bouton, avec anti-rebond.
 * @param bouton Bouton à vérifier.
 * @return true au moment où le bouton vient d'être appuyé.
 */
bool AppuiDetecte(Bouton &bouton);

/**
 * @brief Envoie un code au robot par la DEL infrarouge.
 * @param code Code à envoyer (CODE_DANSE, CODE_MARCHE_ARRET, CODE_ARRET_URGENCE).
 */
void EnvoyerCode(uint8_t code);

/** @brief Lit les boutons et envoie le code correspondant. */
void ActualiserTelecommande();

// --- Côté robot ---

/**
 * @brief Lit le récepteur infrarouge sans bloquer (D3).
 * @param code Reçoit la commande si un code valide est arrivé.
 * @return true si un code valide a été reçu.
 */
bool RecevoirCode(uint8_t &code);

/**
 * @brief Fait l'action qui correspond à un code reçu.
 * @param code Code reçu par RecevoirCode().
 */
void TraiterCode(uint8_t code);

/** @brief Lance une danse : chorégraphie, bras, musique au hasard, lumières (D4). */
void LancerDanse();

/**
 * @brief Allume ou éteint le robot (D6).
 * @return true si le robot est maintenant en marche.
 */
bool BasculerMarcheArret();

#endif
