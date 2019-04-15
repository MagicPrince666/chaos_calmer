#include <stdint.h>

struct ev_msg {
    uint8_t addr[6];
    uint32_t status;
    uint32_t reason;
};
