#pragma once

#include <cstdint>

#define BEACON_TYPE 0x8000
#define BEACON_FRAME_SIZE 24

struct RadioTapHeader {
    uint8_t version;
    uint8_t pad;
    uint16_t length;
    uint32_t present;
} __attribute__((__packed__));

struct BeaconFrame {
    uint16_t type;
    uint16_t duration;
    uint8_t recvAddr[6];
    uint8_t sourAddr[6];
    uint8_t BSSId[6];
    uint8_t fragNum : 4;
    uint8_t seqNum1 : 4;
    uint8_t seqNum2 : 4;
    uint8_t seqNum3 : 4;
} __attribute__((__packed__));

struct FixedPrameters {
    uint64_t timeStamp;
    uint16_t intelval;
    uint16_t capaInfo;
} __attribute__((__packed__));

struct WirelessManagment {
    struct FixedPrameters fixPrams;
    uint8_t tagPrams[0];

} __attribute__((__packed__));

void printBeaconFrame(const uint8_t *packet);
void printESSID(struct WirelessManagment *wireMana);
void printchannel(struct WirelessManagment *wireMana);
void printBSSid(struct BeaconFrame *beaconFrame);

