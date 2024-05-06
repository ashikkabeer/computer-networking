#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define PACKET_SIZE 1024
#define TIMEOUT 5
#define WINDOW_SIZE 4

void send_packet(char* packet) {
    printf("\nSending packet: %s\n", packet);
}

//receive acknowledgement
bool receive_ack() {
    printf("\nReceiving acknowledgement for packet \n");
    return true;
}

int main() {
    char packet[WINDOW_SIZE][PACKET_SIZE];
    int seq_num = 0;
    int base = 0;

    while (true){
        for(int i=base;i<base+WINDOW_SIZE;i++) {
            if(i<seq_num) {
                send_packet(packet[i%WINDOW_SIZE]);
            } else {
                break;
            }
        }

        printf("\nWaiting for acknowledgement\n");
        sleep(TIMEOUT);

        if(receive_ack()) {
            printf("\nAcknowledgement received for Packet %d\n", base);
            base++;
        } else {
            printf("\nTimeout, resending packet\n");
        }
    }
    return 0;
    
}