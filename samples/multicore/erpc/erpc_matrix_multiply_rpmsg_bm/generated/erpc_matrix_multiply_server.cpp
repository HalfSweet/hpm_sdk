/*
 * Copyright (c) 2014-2016, Freescale Semiconductor, Inc.
 * Copyright 2016 NXP
 * Copyright (c) 2022 HPMicro
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * Generated by erpcgen 1.10.0 on Thu Mar 23 09:04:33 2023.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "erpc_matrix_multiply_server.h"
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include <new>
#include "erpc_port.h"
#endif
#include "erpc_manually_constructed.hpp"

#if 11000 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

#if ERPC_NESTED_CALLS_DETECTION
extern bool nestingDetection;
#endif

ERPC_MANUALLY_CONSTRUCTED_STATIC(MatrixMultiplyService_service, s_MatrixMultiplyService_service);



// Constant variable definitions
#pragma weak matrix_size
extern const int32_t matrix_size = 5;


// Call the correct server shim based on method unique ID.
erpc_status_t MatrixMultiplyService_service::handleInvocation(uint32_t methodId, uint32_t sequence, Codec * codec, MessageBufferFactory *messageFactory)
{
    erpc_status_t erpcStatus;
    switch (methodId)
    {
        case kMatrixMultiplyService_erpcMatrixMultiply_id:
        {
            erpcStatus = erpcMatrixMultiply_shim(codec, messageFactory, sequence);
            break;
        }

        case kMatrixMultiplyService_erpcSwitchLightLed_id:
        {
            erpcStatus = erpcSwitchLightLed_shim(codec, messageFactory, sequence);
            break;
        }

        default:
        {
            erpcStatus = kErpcStatus_InvalidArgument;
            break;
        }
    }

    return erpcStatus;
}

// Server shim for erpcMatrixMultiply of MatrixMultiplyService interface.
erpc_status_t MatrixMultiplyService_service::erpcMatrixMultiply_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    Matrix matrix1;
    Matrix matrix2;
    Matrix result_matrix;

    // startReadMessage() was already called before this shim was invoked.

    for (uint32_t arrayCount0 = 0U; arrayCount0 < 5U; ++arrayCount0)
    {
        for (uint32_t arrayCount1 = 0U; arrayCount1 < 5U; ++arrayCount1)
        {
            codec->read(&matrix1[arrayCount0][arrayCount1]);
        }
    }

    for (uint32_t arrayCount0 = 0U; arrayCount0 < 5U; ++arrayCount0)
    {
        for (uint32_t arrayCount1 = 0U; arrayCount1 < 5U; ++arrayCount1)
        {
            codec->read(&matrix2[arrayCount0][arrayCount1]);
        }
    }

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        erpcMatrixMultiply(matrix1, matrix2, result_matrix);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kMatrixMultiplyService_service_id, kMatrixMultiplyService_erpcMatrixMultiply_id, sequence);

        for (uint32_t arrayCount0 = 0U; arrayCount0 < 5U; ++arrayCount0)
        {
            for (uint32_t arrayCount1 = 0U; arrayCount1 < 5U; ++arrayCount1)
            {
                codec->write(result_matrix[arrayCount0][arrayCount1]);
            }
        }

        err = codec->getStatus();
    }

    return err;
}

// Server shim for erpcSwitchLightLed of MatrixMultiplyService interface.
erpc_status_t MatrixMultiplyService_service::erpcSwitchLightLed_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    // startReadMessage() was already called before this shim was invoked.

    // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
    nestingDetection = true;
#endif
    erpcSwitchLightLed();
#if ERPC_NESTED_CALLS_DETECTION
    nestingDetection = false;
#endif
    return codec->getStatus();
}

erpc_service_t create_MatrixMultiplyService_service(void)
{
    erpc_service_t service;

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    service = new (nothrow) MatrixMultiplyService_service();
#else
    if (s_MatrixMultiplyService_service.isUsed())
    {
        service = NULL;
    }
    else
    {
        s_MatrixMultiplyService_service.construct();
        service = s_MatrixMultiplyService_service.get();
    }
#endif

    return service;
}

void destroy_MatrixMultiplyService_service(erpc_service_t service)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    erpc_assert(service != NULL);
    delete (MatrixMultiplyService_service *)service;
#else
    (void)service;
    erpc_assert(service == s_MatrixMultiplyService_service.get());
    s_MatrixMultiplyService_service.destroy();
#endif
}
