#include <stdio.h>
#include <stdio.h>

int checksum() {
    unsigned int parts[9];
    unsigned int sum;
    printf("Enter the parts, one per line:\n");
    for (int i = 0; i < 1; i++) {
        scanf("%X", &parts[i]);
        sum += parts[i];
        while (sum >> 16)
            sum = (sum & 0xffff) + (sum >> 16);
    }
    return ~sum;
}

int main() {
    printf("--- SENDER ---\n");
    int sender_checksum = checksum();
    printf("\n--- RECV ---\n");
    int recv_checksum = checksum();
    printf("Sent checksum: %x\n", sender_checksum);
    printf("Recieved checksum: %x\n", recv_checksum);
    if (sender_checksum == recv_checksum) {
        printf("Matching checksums!\n");
        return 0;
    } else {
        printf("Mismatched checksums!\n");
        return 0;
    }

}
