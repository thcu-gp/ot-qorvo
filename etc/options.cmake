#
#  Copyright (c) 2019, The OpenThread Authors.
#  All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are met:
#  1. Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#  2. Redistributions in binary form must reproduce the above copyright
#     notice, this list of conditions and the following disclaimer in the
#     documentation and/or other materials provided with the distribution.
#  3. Neither the name of the copyright holder nor the
#     names of its contributors may be used to endorse or promote products
#     derived from this software without specific prior written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
#  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
#

# Additional debugging option
option(OT_MBEDTLS_DEBUG "enable Mbedtls debugging" OFF)
if (OT_MBEDTLS_DEBUG)
    add_definitions(-DQORVO_MBEDTLS_DEBUG)
endif()

# Uart transport option
option(OT_QORVO_SOCKET "enable socket interface for uart transport on RPi based platforms" OFF)

# Number of supported children
option(OT_QORVO_SUPPORTED_CHILDREN "The amount of children supported on the platform" OFF)
if (OT_QORVO_SUPPORTED_CHILDREN)
    add_definitions(-DOPENTHREAD_CONFIG_MLE_MAX_CHILDREN=${OT_QORVO_SUPPORTED_CHILDREN})
endif()

option(OT_COMMISSIONER "Enable Commissioner role (disabled by default)" OFF)
if (OT_COMMISSIONER)
    add_definitions(-DOPENTHREAD_CONFIG_COMMISSIONER_ENABLE=1)
else()
    add_definitions(-DOPENTHREAD_CONFIG_COMMISSIONER_ENABLE=0)
endif()

option(OT_JOINER "Enable Joiner role (enabled by default)" ON)
if (OT_JOINER)
    add_definitions(-DOPENTHREAD_CONFIG_JOINER_ENABLE=1)
else()
    add_definitions(-DOPENTHREAD_CONFIG_JOINER_ENABLE=0)
endif()

option(OT_TCP "Enabled TCP/TLS (disabled by default)" OFF)
if (OT_TCP)
    add_definitions(-DOPENTHREAD_CONFIG_TCP_ENABLE=1)
else()
    add_definitions(-DOPENTHREAD_CONFIG_TCP_ENABLE=0)
endif()
