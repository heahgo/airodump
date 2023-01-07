#include "dot11.h"
#include <cstdio>
#include <netinet/in.h>

bool parseBeaconFrame(const uint8_t *packet) {
    struct RadioTapHeader *radioHead = (RadioTapHeader *)packet;
    struct BeaconFrame *beaconFrame = (BeaconFrame *)(packet + radioHead->it_len);

    if (beaconFrame->type != ntohs(beaconType)) {
        //printf("This Not Beacon Frame!!\n\n");
        return false;
    }

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
