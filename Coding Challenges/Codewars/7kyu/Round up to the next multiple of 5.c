int round_to_next5(int n) {

    return n + (((4 - (n % 5)) + 1) % 5);
}
