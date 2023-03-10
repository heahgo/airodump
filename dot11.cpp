#include "dot11.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <netinet/in.h>

void printchannel(struct WirelessManagment *wireMana) {
    int idx = 0;
    while (true) {
        if (wireMana->tagPrams[idx] != 3) {
            idx += wireMana->tagPrams[idx + 1] +2;
            continue;
        }
        idx += wireMana->tagPrams[idx + 1];
        printf("CH : %d\n", wireMana->tagPrams[idx + 1]);
        break;
    }
}

void printESSID(struct WirelessManagment *wireMana) {
    uint8_t ssidLen = wireMana->tagPrams[1];
    char *ssid = (char *)malloc(sizeof(char) * ssidLen + 1);
    memcpy(ssid, &wireMana->tagPrams[2], ssidLen);
    strncat(ssid, "", 1);
    printf("SSID : %s\n", ssid);
    free(ssid);
}

void printBSSid(struct BeaconFrame *beaconFrame) {
    printf("BSS id : %02x:%02x:%02x:%02x:%02x:%02x\n\n",
           beaconFrame->BSSId[0],
           beaconFrame->BSSId[1],
           beaconFrame->BSSId[2],
           beaconFrame->BSSId[3],
           beaconFrame->BSSId[4],
           beaconFrame->BSSId[5]
           );
}

void printBeaconFrame(const uint8_t *packet) {
    struct RadioTapHeader *radioHead = (RadioTapHeader *)packet;
    struct BeaconFrame *beaconFrame = (BeaconFrame *)(packet + radioHead->length);
    struct WirelessManagment *wireMana = (WirelessManagment *)(packet + radioHead->length + BEACON_FRAME_SIZE);

    if (beaconFrame->frameControl != ntohs(BEACON)) // This Not Beacon Frame!!
        return;

    printchannel(wireMana);
    printESSID(wireMana);
    printBSSid(beaconFrame);

}
