#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>

#define WINDOW_SIZE 4
#define PACKET_SIZE 1024
#define TIMEOUT 5 // Timeout in seconds

// Simulate sending a packet over the network
void send_packet(char* packet) {
    // Simulate sending packet over the network
    printf("Sending packet: %s\n", packet);
}

bool receive_acknowledgment(int acknum) {
    // Simulate receiving acknowledgment
    // For simplicity, always return true (acknowledgment received)
    return true;
}

int main() {
    char packet[WINDOW_SIZE][PACKET_SIZE];
    bool ack[WINDOW_SIZE] = {false};
    int seq_num = 0;

    while (true) {
        for(int i =0; i<WINDOW_SIZE; i++) {
           if(seq_num < WINDOW_SIZE) {
            sprintf(packet[i], "Packet %d", seq_num);

            send_packet(packet[i]);

            seq_num++;
           }
        }

    }
    printf("\nWaiting for acknowledgment\n");
    sleep(TIMEOUT);

    for(int i = 0;i<WINDOW_SIZE;i++) {
        if(!ack[i] && receive_acknowledgment(i)) {
            printf("\nAcknowledgment received for Packet %d\n", i);
            ack[i] = true;
        }
    }
    for(int i = 0;i<WINDOW_SIZE;i++) {
        if(!ack[i]) {
            printf("\nTimeout, resending packet %d\n", i);
            send_packet(packet[i]);
        }
    }
    return 0;
    
}