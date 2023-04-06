/*
 * moteurDC.h
 *
 *  Created on: Feb 2, 2023
 *      Author: dsolet
 */

#ifndef INC_MOTEURCC_H_
#define INC_MOTEURCC_H_

#include "main.h"
#include "tim.h"
#include "gpio.h"
/**
* @brief Fonction qui initialise le moteur : Activation du signal PWM avec un rapport cyclique à 0
* @param[in] htim 	    Adresse de la structure de données relative au timer à utiliser
* @param[in] Channel 	Identifiant du Channel du timer à utiliser
*/
void moteurCC_init(TIM_HandleTypeDef *htim, uint32_t Channel);

/**
* @brief Fonction qui permet de modifier la vitesse du moteur en fonction d'une consigne
* @param[in] consigne	    Valeur de la consigne comprise entre -100 et 100
*/
void moteurCC_consigne(int8_t consigne);

/**
* @brief Fonction qui desinitialise le moteur : Desactivation du signal PWM
* @param[in] htim 	    Adresse de la structure de données relative au timer à utiliser
* @param[in] Channel 	Identifiant du Channel du timer à utiliser
*/
void moteurCC_deinit();



#endif /* INC_MOTEURCC_H_ */
