/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f1xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f1xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/
extern CAN_HandleTypeDef hcan;
/* USER CODE BEGIN EV */
extern uint32_t MailBox;
extern uint8_t ReceivedData[8];
extern uint8_t SentData[8];
extern uint8_t ReceivedData2[9];
extern uint32_t MailBox;
extern CAN_RxHeaderTypeDef RxReceiver;
extern CAN_TxHeaderTypeDef TxTransmitter;
extern UART_HandleTypeDef huart2;
extern uint32_t addr;


extern uint8_t angle1;
extern uint8_t angle2;
/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M3 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
  while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Prefetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */

  /* USER CODE END SysTick_IRQn 0 */
  HAL_IncTick();
  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F1xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f1xx.s).                    */
/******************************************************************************/

/**
  * @brief This function handles USB low priority or CAN RX0 interrupts.
  */
void USB_LP_CAN1_RX0_IRQHandler(void)
{
  /* USER CODE BEGIN USB_LP_CAN1_RX0_IRQn 0 */
	char buff[20];

	HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
	if (HAL_CAN_GetRxMessage(&hcan, CAN_RX_FIFO0, &RxReceiver, ReceivedData)== HAL_OK)
	{
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		//TxTransmitter.StdId = RxReceiver.StdId;
		//itoa((int)RxReceiver.StdId,buff,16);
		//HAL_UART_Transmit(&huart2, buff, strlen(buff), 100);
		//HAL_UART_Transmit(&huart2, "Toogle Led\n", 11, 100);

		itoa((int) RxReceiver.DLC, buff, 10);
		HAL_UART_Transmit(&huart2, "DLC: ", strlen("DLC: "), 100);
		HAL_UART_Transmit(&huart2, buff, strlen(buff), 100);
		HAL_UART_Transmit(&huart2, "\n", 1, 100);


		for(int i =0;i<8;i++)
		{
			itoa((int) ReceivedData[i], buff, 10);
			HAL_UART_Transmit(&huart2, buff, strlen(buff), 100);
			HAL_UART_Transmit(&huart2, "\n", 1, 100);
			/*
			if (i == 4) {
				lcd16x2_i2c_clear();
				lcd16x2_i2c_setCursor(0, 0);
				lcd16x2_i2c_printf("Angle 1: %d", 10);

			}
			if (i == 5) {
				lcd16x2_i2c_setCursor(1, 0);
				lcd16x2_i2c_printf("Angle 2: %d", 15);
			}
			*/
			/*
			if(i == 4)
			{
				lcd16x2_i2c_clear();
				lcd16x2_i2c_printf("Angle 1: %d",ReceivedData[4]);
				lcd16x2_i2c_setCursor(1,0);
			}
			if(i == 5)
			{

				lcd16x2_i2c_printf("Angle 1: %d",ReceivedData[5]);
			}
			*/
		}

		angle1 = ReceivedData[4];
		angle2 = ReceivedData[5];
		itoa((int) ReceivedData[5]*359/255, buff, 10);
		HAL_UART_Transmit(&huart2, "ANGLE: ", strlen("ANGLE: "), 100);

		HAL_UART_Transmit(&huart2, buff, strlen(buff), 100);
		HAL_UART_Transmit(&huart2, "\n", 1, 100);


		/*
		itoa((int) ReceivedData[1], buff, 10);
		HAL_UART_Transmit(&huart2, buff, strlen(buff), 100);
		HAL_UART_Transmit(&huart2, "\n", 1, 100);

		itoa((int) ReceivedData[2], buff, 10);
		HAL_UART_Transmit(&huart2, buff, strlen(buff), 100);
		HAL_UART_Transmit(&huart2, "\n", 1, 100);

		itoa((int) ReceivedData[3], buff, 10);
		HAL_UART_Transmit(&huart2, buff, strlen(buff), 100);
		HAL_UART_Transmit(&huart2, "\n", 1, 100);
		*/
		/*
		HAL_UART_Transmit(&huart2, "Toogle Led\n", 11, 100);
		HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_5);
		*/
	}
  /* USER CODE END USB_LP_CAN1_RX0_IRQn 0 */
  HAL_CAN_IRQHandler(&hcan);
  /* USER CODE BEGIN USB_LP_CAN1_RX0_IRQn 1 */

  /* USER CODE END USB_LP_CAN1_RX0_IRQn 1 */
}

/**
  * @brief This function handles EXTI line[15:10] interrupts.
  */
void EXTI15_10_IRQHandler(void)
{
  /* USER CODE BEGIN EXTI15_10_IRQn 0 */

	HAL_CAN_AddTxMessage(&hcan, &TxTransmitter, SentData, &MailBox);
	HAL_UART_Transmit(&huart2, "Led toogle\n", strlen("Led toogle\n"), 100);

	//uint8_t SentData2[8] =
	//HAL_CAN_AddTxMessage(&hcan, &TxTransmitter, SentData2, &addr);
  /* USER CODE END EXTI15_10_IRQn 0 */
  HAL_GPIO_EXTI_IRQHandler(B1_Pin);
  /* USER CODE BEGIN EXTI15_10_IRQn 1 */

  /* USER CODE END EXTI15_10_IRQn 1 */
}

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
