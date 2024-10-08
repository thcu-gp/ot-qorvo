/*
 *  Copyright (c) 2024, The OpenThread Authors.
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *  1. Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *  2. Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution.
 *  3. Neither the name of the copyright holder nor the
 *     names of its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 *  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 *  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 *  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 *  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 *  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 *  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 *  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 *  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 *  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 */

/**
 * @file
 * @brief
 *   This file includes the platform-specific initializers.
 */

#include "alarm_qorvo.h"
#include "platform_qorvo.h"
#include "radio_qorvo.h"
#include "random_qorvo.h"
#include "uart_qorvo.h"
#include <openthread/tasklet.h>
#include <openthread/thread.h>

#include "utils/uart.h"

#include "stdio.h"
#include "stdlib.h"

static otInstance *localInstance = NULL;

uint8_t qorvoPlatGotoSleepCheck(void)
{
    if (localInstance)
    {
        return !otTaskletsArePending(localInstance);
    }
    else
    {
        return true;
    }
}

void otSysInit(int argc, char *argv[])
{
    OT_UNUSED_VARIABLE(argc);
    OT_UNUSED_VARIABLE(argv);
    qorvoPlatInit((qorvoPlatGotoSleepCheckCallback_t)qorvoPlatGotoSleepCheck);
    qorvoUartInit();
    qorvoAlarmInit();
    qorvoRandomInit();
    qorvoRadioInit();
}

bool otSysPseudoResetWasRequested(void)
{
    return false;
}

void otSysProcessDrivers(otInstance *aInstance)
{
    if (localInstance == NULL)
    {
        // local copy in case we need to perform a callback.
        localInstance = aInstance;
    }

    // Do not sleep until attached to network to handle UART CLI
    qorvoPlatMainLoop(!otTaskletsArePending(aInstance) &&
                      (otThreadGetDeviceRole(aInstance) != OT_DEVICE_ROLE_DETACHED) &&
                      (otThreadGetDeviceRole(aInstance) != OT_DEVICE_ROLE_DISABLED));
}
