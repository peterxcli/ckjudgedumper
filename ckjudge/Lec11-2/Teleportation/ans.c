unsigned long construct(unsigned char parts[16]) {
    unsigned long long l1 = 0, l2 = 0;
    for (int i = 15; i >= 8; i--) {
        l1 = (l1 << 8) | parts[i];
        l2 = (l2 << 8) | parts[i-8];
    }
    return l1 ^ l2;
}