#include "dot11.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>

bool printchannel() {}

bool printESSID(struct WirelessManagment *wireMana) {
//    uint8_t idx = 0;
//    while (true) {
//        if (wireMana->tagPrams[idx] != 0) {
//            idx += wireMana->tagPrams[idx + 1];
//            continue;
//        }
//    }

    uint8_t ssidLen = wireMana->tagPrams[1];
    char *ssid = (char *)malloc(sizeof(char) * ssidLen);
    memcpy(ssid, &wireMana->tagPrams[2], ssidLen);
    printf("SSID = %s\n", ssid);
    free(ssid);

    return true;
}

bool parseBeaconFrame(const uint8_t *packet) {
    uint8_t becaonFrameSize = 24;
    struct RadioTapHeader *radioHead = (RadioTapHeader *)packet;
    struct BeaconFrame *beaconFrame = (BeaconFrame *)(packet + radioHead->it_len);
    struct WirelessManagment *wireMana = (WirelessManagment *)(packet + radioHead->it_len + becaonFrameSize);

    if (beaconFrame->type != ntohs(beaconType)) // This Not Beacon Frame!!
        return false;

    printESSID(wireMana);
    printf("Reciver addres: %02x:%02x:%02x:%02x:%02x:%02x\n",
           beaconFrame->recvAddr[0],
           beaconFrame->recvAddr[1],
           beaconFrame->recvAddr[2],
           beaconFrame->recvAddr[3],
           beaconFrame->recvAddr[4],
           beaconFrame->recvAddr[5]
           );
    printf("Sourec Address: %02x:%02x:%02x:%02x:%02x:%02x\n",
           beaconFrame->sourAddr[0],
           beaconFrame->sourAddr[1],
           beaconFrame->sourAddr[2],
           beaconFrame->sourAddr[3],
           beaconFrame->sourAddr[4],
           beaconFrame->sourAddr[5]
           );
    printf("BSS id: %02x:%02x:%02x:%02x:%02x:%02x\n\n",
           beaconFrame->BSSId[0],
           beaconFrame->BSSId[1],
           beaconFrame->BSSId[2],
           beaconFrame->BSSId[3],
           beaconFrame->BSSId[4],
           beaconFrame->BSSId[5]
           );

    return true;
}
