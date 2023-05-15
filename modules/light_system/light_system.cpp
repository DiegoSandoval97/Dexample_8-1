//=====[Libraries]=============================================================

#include "arm_book_lib.h"

#include "light_system.h"
#include "bright_control.h"
#include "light_level_control.h"

//=====[Declaration of private defines]========================================

//=====[Declaration of private data types]=====================================

//=====[Declaration and initialization of public global objects]===============

//=====[Declaration and initialization of private global objects]===============

//=====[Declaration of external public global variables]=======================

//=====[Declaration and initialization of public global variables]=============

//=====[Declaration and initialization of private global variables]============

static float dutyCycle = 0.5f;

//=====[Implementations of public functions]===================================

void lightSystemInit()
{
    brightControlInit();
}

void lightSystemUpdate()
{
    dutyCycle = lightLevelControlRead();

    /** Código original
    setDutyCycle( RGB_LED_RED, dutyCycle );
    setDutyCycle( RGB_LED_GREEN, dutyCycle );
    setDutyCycle( RGB_LED_BLUE, dutyCycle );
    */ 
    // Seteo del Duty cycle a mano
    setDutyCycle( RGB_LED_RED, 0.5f );
    setDutyCycle( RGB_LED_GREEN, 0.35f ); // reconoce sólo cambios discretos de 1ms, eso lo ve como 0.3f
    setDutyCycle( RGB_LED_BLUE, 0.8f );

    callTickerCallbackBrightControl(); //nueva función definida para hacer publica al callback

}

//=====[Implementations of private functions]==================================
