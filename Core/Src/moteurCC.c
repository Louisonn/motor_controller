#include "moteurCC.h"
#include "main.h"


static TIM_HandleTypeDef pwm_htim;
uint32_t pwm_channel;

#define SENS_DE_ROTATION 1		// Sens 0 ou 1

void moteurCC_init(TIM_HandleTypeDef *htim, uint32_t Channel)
{
	pwm_htim = *htim;
	pwm_channel = Channel;

	HAL_TIM_PWM_Start(&pwm_htim, pwm_channel);
	__HAL_TIM_SetCompare(&pwm_htim, pwm_channel, 0);
	HAL_GPIO_WritePin(In1_GPIO_Port, In1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(In2_GPIO_Port, In2_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
}

void moteurCC_consigne(int8_t consigne)
{
	if (consigne >= 0 && consigne <=100)
	{
		//Allumage des LED 3 et 6 sur la board pour indiquer changement de sens
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);

		//Allumage PINS In1 et In2 du driver pour gestion du sens
		HAL_GPIO_WritePin(In1_GPIO_Port, In1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(In2_GPIO_Port, In2_Pin, GPIO_PIN_SET);
		__HAL_TIM_SetCompare(&pwm_htim, pwm_channel, consigne);
	}
	else if (consigne < 0 && consigne >=-100)
	{
		//Allumage des LED 3 et 6 sur la board pour indiquer changement de sens
		HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_SET);

		//Allumage PINS In1 et In2 du driver pour gestion du sens
		HAL_GPIO_WritePin(In1_GPIO_Port, In1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(In2_GPIO_Port, In2_Pin, GPIO_PIN_RESET);
		__HAL_TIM_SetCompare(&pwm_htim, pwm_channel, -consigne);
	}

}

void moteurCC_deinit()
{
	HAL_GPIO_WritePin(In1_GPIO_Port, In1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(In2_GPIO_Port, In2_Pin, GPIO_PIN_RESET);

	HAL_GPIO_WritePin(LED1_GPIO_Port, LED1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(LED2_GPIO_Port, LED2_Pin, GPIO_PIN_RESET);
	HAL_TIM_PWM_DeInit(&pwm_htim);
}
