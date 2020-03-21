/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Pins v5.0
processor: MKE18F512xxx16
package_id: MKE18F512VLH16
mcu_data: ksdk2_0
processor_version: 5.0.0
pin_labels:
- {pin_num: '20', pin_signal: ADC0_SE11/ACMP0_IN4/EXTAL32/PTC3/FTM0_CH3/CAN0_TX, label: v_lc1}
- {pin_num: '21', pin_signal: ADC0_SE10/ACMP0_IN5/XTAL32/PTC2/FTM0_CH2/CAN0_RX, label: i_lc1}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

#include "fsl_common.h"
#include "fsl_port.h"
#include "pin_mux.h"

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitBootPins
 * Description   : Calls initialization functions.
 *
 * END ****************************************************************************************************************/
void BOARD_InitBootPins(void)
{
    BOARD_InitPins();
}

/* clang-format off */
/*
 * TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
BOARD_InitPins:
- options: {callFromInitBoot: 'true', coreID: core0, enableClock: 'true'}
- pin_list:
  - {pin_num: '4', peripheral: GPIOE, signal: 'GPIO, 10', pin_signal: ADC2_SE12/PTE10/CLKOUT/FTM2_CH4/FXIO_D4/TRGMUX_OUT4}
  - {pin_num: '3', peripheral: GPIOE, signal: 'GPIO, 11', pin_signal: ADC2_SE13/PTE11/PWT_IN1/LPTMR0_ALT1/FTM2_CH5/FXIO_D5/TRGMUX_OUT5}
  - {pin_num: '2', peripheral: GPIOD, signal: 'GPIO, 0', pin_signal: ADC2_SE0/PTD0/FTM0_CH2/LPSPI1_SCK/FTM2_CH0/FXIO_D0/TRGMUX_OUT1}
  - {pin_num: '1', peripheral: GPIOD, signal: 'GPIO, 1', pin_signal: ADC2_SE1/PTD1/FTM0_CH3/LPSPI1_SIN/FTM2_CH1/FXIO_D1/TRGMUX_OUT2}
  - {pin_num: '20', peripheral: ADC0, signal: 'SE, 11', pin_signal: ADC0_SE11/ACMP0_IN4/EXTAL32/PTC3/FTM0_CH3/CAN0_TX}
  - {pin_num: '21', peripheral: ADC0, signal: 'SE, 10', pin_signal: ADC0_SE10/ACMP0_IN5/XTAL32/PTC2/FTM0_CH2/CAN0_RX}
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS ***********
 */
/* clang-format on */

/* FUNCTION ************************************************************************************************************
 *
 * Function Name : BOARD_InitPins
 * Description   : Configures pin routing and optionally pin electrical features.
 *
 * END ****************************************************************************************************************/
void BOARD_InitPins(void)
{
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortC);
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortD);
    /* Clock Control: Clock enabled */
    CLOCK_EnableClock(kCLOCK_PortE);

    /* PORTC2 (pin 21) is configured as ADC0_SE10 */
    PORT_SetPinMux(PORTC, 2U, kPORT_PinDisabledOrAnalog);

    /* PORTC3 (pin 20) is configured as ADC0_SE11 */
    PORT_SetPinMux(PORTC, 3U, kPORT_PinDisabledOrAnalog);

    /* PORTD0 (pin 2) is configured as PTD0 */
    PORT_SetPinMux(PORTD, 0U, kPORT_MuxAsGpio);

    /* PORTD1 (pin 1) is configured as PTD1 */
    PORT_SetPinMux(PORTD, 1U, kPORT_MuxAsGpio);

    /* PORTE10 (pin 4) is configured as PTE10 */
    PORT_SetPinMux(PORTE, 10U, kPORT_MuxAsGpio);

    /* PORTE11 (pin 3) is configured as PTE11 */
    PORT_SetPinMux(PORTE, 11U, kPORT_MuxAsGpio);
}
/***********************************************************************************************************************
 * EOF
 **********************************************************************************************************************/
