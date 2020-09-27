/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
* this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "task_function.h"
#include "r_gpio_rx_if.h"
/* Start user code for import. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

void Task_Led(void * pvParameters)
{
	gpio_level_t 			eLevel = GPIO_LEVEL_LOW;


	R_GPIO_PinDirectionSet(GPIO_PORT_A_PIN_1, GPIO_DIRECTION_OUTPUT);				// LED

//	R_GPIO_PinDirectionSet(GPIO_PORT_A_PIN_2, GPIO_DIRECTION_INPUT);				// SW
//	R_GPIO_PinControl(GPIO_PORT_A_PIN_2, GPIO_CMD_IN_PULL_UP_ENABLE);

	while(1)
	{
		R_GPIO_PinWrite(GPIO_PORT_A_PIN_1,eLevel);
		eLevel = (eLevel == GPIO_LEVEL_LOW) ? GPIO_LEVEL_HIGH : GPIO_LEVEL_LOW;

		vTaskDelay(1000);
	}
}
