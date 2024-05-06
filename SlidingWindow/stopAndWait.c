#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define PACKET_SIZE 1024
#define TIMEOUT 1

void send_packet(char* packet) {
    int seq_num = 0;
    printf("\nSending packet: %s\n", packet);
}

//receive acknowledgement
bool receive_ack() {
    printf("\nReceiving acknowledgement for packet \n");
    return true;
}

int main() {
    char packet[PACKET_SIZE];
    int seq_num = 0;

    while(true) {
        sprintf(packet, "Packet %d", seq_num);
        send_packet(packet);

        printf("\nWaiting for acknowledgement\n");
        sleep(TIMEOUT);

        if(receive_ack()) {
            printf("\nAcknowledgement received for Packet %d\n", seq_num);
            seq_num++;
        } else {
            printf("\nTimeout, resending packet\n");
        }
        if(seq_num == 10) {
            break;
        }

    }
    return 0;
}