/*
 *  Copyright (c) 2019, The OpenThread Authors.
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
 *   This file includes gp712 compile-time configuration constants for OpenThread.
 */

#ifndef OPENTHREAD_CORE_GP712_CONFIG_H_
#define OPENTHREAD_CORE_GP712_CONFIG_H_

/**
 * @def OPENTHREAD_CONFIG_PLATFORM_INFO
 *
 * The platform-specific string to insert into the OpenThread version string.
 *
 */
#define OPENTHREAD_CONFIG_PLATFORM_INFO "GP712"

/**
 * @def OPENTHREAD_CONFIG_PLATFORM_INFO
 *
 * Define to 1 to enable otPlatFlash* APIs to support non-volatile storage.
 *
 * When defined to 1, the platform MUST implement the otPlatFlash* APIs
 * instead of the otPlatSettings*
 *
 */
#define OPENTHREAD_CONFIG_PLATFORM_FLASH_API_ENABLE 1

/**
 * @def OPENTHREAD_CONFIG_PLATFORM_ASSERT_MANAGEMENT
 *
 * The assert is managed by platform defined logic when this flag is set.
 *
 */
#define OPENTHREAD_CONFIG_PLATFORM_ASSERT_MANAGEMENT 0

/**
 * @def OPENTHREAD_CONFIG_DIAG_ENABLE
 *
 * Define as 1 to enable the diag feature.
 *
 */
#ifndef OPENTHREAD_CONFIG_DIAG_ENABLE
#define OPENTHREAD_CONFIG_DIAG_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_PLATFORM_USEC_TIMER_ENABLE
 *
 * This is required for the CSL receiver feature
 *
 */
#ifndef OPENTHREAD_CONFIG_PLATFORM_USEC_TIMER_ENABLE
#define OPENTHREAD_CONFIG_PLATFORM_USEC_TIMER_ENABLE OPENTHREAD_CONFIG_MAC_CSL_RECEIVER_ENABLE
#endif

#if defined(OPENTHREAD_CONFIG_MAC_CSL_RECEIVER_ENABLE) && defined(DEBUG)
#define OPENTHREAD_CONFIG_MAC_CSL_DEBUG_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_NCP_SPI_ENABLE
 *
 * Define as 1 to enable SPI NCP interface.
 *
 */
#ifndef OPENTHREAD_CONFIG_NCP_SPI_ENABLE
#define OPENTHREAD_CONFIG_NCP_SPI_ENABLE 0
#endif

/**
 * @def OPENTHREAD_CONFIG_NCP_HDLC_ENABLE
 *
 * Define to 1 to enable NCP HDLC support.
 *
 */
#ifndef OPENTHREAD_CONFIG_NCP_HDLC_ENABLE
#define OPENTHREAD_CONFIG_NCP_HDLC_ENABLE 1
#endif

/**
 * @def OPENTHREAD_CONFIG_HEAP_INTERNAL_SIZE
 *
 * Configure the available heap size.
 * The heap is used by Mbedtls
 *
 */
#ifndef OPENTHREAD_CONFIG_HEAP_INTERNAL_SIZE
#define OPENTHREAD_CONFIG_HEAP_INTERNAL_SIZE (2048 * sizeof(void *))
#endif

/**
 * @def OPENTHREAD_CONFIG_TLS_ENABLE
 *
 * Define as 1 to enable support for TLS over TCP.
 *
 */
#if OPENTHREAD_CONFIG_TLS_ENABLE
#define OPENTHREAD_CONFIG_TLS_ENABLE 0
#endif

#endif // OPENTHREAD_CORE_GP712_CONFIG_H_
