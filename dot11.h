#pragma once

#include <cstdint>

#define beaconType 0x8000

struct RadioTapHeader {
    uint8_t it_version;     /* set to 0 */
    uint8_t it_pad;
    uint16_t it_len;         /* entire length */
    uint32_t it_present;     /* fields present */
} __attribute__((__packed__));

struct FrameControlField {
    uint8_t version : 2;
    uint8_t type : 2 ;
    uint8_t subType : 4;
    uint8_t flags;
} __attribute__((__packed__));

struct BeaconFrame {
    //struct FrameControlField conField;
    uint16_t type;
    uint16_t duration;
    uint8_t recvAddr[6];
//    uint8_t destAddr[6];
//    uint8_t transAddr[6];
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

//typedef struct Dot11 {
//    struct RadioTapHeader radioTapHeader;
//    struct BeaconFrame beaconFrame;
//    struct WirelessManagment wirelessManagment;
//} __attribute__((__packed__)) dot11;

bool parseBeaconFrame(const uint8_t *packet);
void printESSID(struct WirelessManagment *wireMana);
void printchannel(struct WirelessManagment *wireMana);
void printBSSid(struct BeaconFrame *beaconFrame);

