#ifndef NGWEBSOCKETS_H
#define NGWEBSOCKETS_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdarg.h>
#include <stdint.h>
#include <stdlib.h>

// websocket frame type
typedef enum {
    NGWEBSOCKETS_CONTINUATION = 0x0,
    NGWEBSOCKETS_TEXT = 0x1,
    NGWEBSOCKETS_BINARY = 0x2,
    // 0x3 - 0x7 reserved for the non-control frame
    NGWEBSOCKETS_CLOSE = 0x8,
    NGWEBSOCKETS_PING = 0x9,
    NGWEBSOCKETS_PONG = 0xA,
    // 0xb - 0xf reserved for control frame
} ngwebsocket_frame_type;

typedef enum {
    NONE = 0,
    NGWEBSOCKETS_STATUS_NORMAL = 1000,
    NGWEBSOCKETS_STATUS_GOING_AWAY = 1001,
    NGWEBSOCKETS_STATUS_PROTOCOL_ERROR = 1002,
    NGWEBSOCKETS_STATUS_UNACCEPT = 1003,

} ngwebsockets_status;

// the main state machine of the ngwebsocket
typedef struct ngwebsockets_session ngwebsockets_session;

// callback on text
typedef int (*ngwebsockets_on_text_callback)(ngwebsockets_session*,
                                             const uint8_t* at,
                                             size_t len,
                                             void* user_data);

// callback on binary
typedef int (*ngwebsockets_on_binanry_callback)(ngwebsockets_session*,
                                                const uint8_t*,
                                                size_t len,
                                                void* user_data);

#ifdef __cplusplus
}
#endif

#endif

