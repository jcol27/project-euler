#include <stdio.h>
#include <math.h>

/*
There are eight coins in general circulation:
    1p, 2p, 5p, 10p, 20p, 50p, £1 (100p), and £2 (200p).
How many different ways can £2 be made using any number of coins?

This can be solved in many ways, but generating combinations 
sequentially is a reasonable mix of memory efficiency and time
efficiency.
*/

int main() {
    int goal = 200;
    int ways = 0;
    int count = 0;

    // Represent each way with a custom base number system
    int way[8] = {0,0,0,0,0,0,0,0};

    while (!(way[0]==1 && way[7]==2)) {
        // Check if way sums to 200p
        if (way[0]*200 + way[1]*100 + way[2]*50 + way[3]*20 + way[4]*10 + way[5]*5 + way[6]*2 + way[7]*1 == goal) {
            ways++;
            way[7] = 0;
            way[6]++;
            if (way[6] == 101) {
                way[6] = 0;
                way[5]++;
                if (way[5] == 41) {
                    way[5] = 0;
                    way[4]++;
                    if (way[4] == 21) {
                        way[4] = 0;
                        way[3]++;
                        if (way[3] == 11) {
                            way[3] == 0;
                            way[2]++;
                            if (way[2] == 5) {
                                way[2] = 0;
                                way[1]++;
                                if (way[1] == 3) {
                                    way[1] = 0;
                                    way[0]++;
                                }
                            }
                        }
                    }
                }
            }          
        }
        else {
            way[7]++;
            if (way[7] == 201) {
                way[7] = 0;
                way[6]++;
                if (way[6] == 101) {
                    way[6] = 0;
                    way[5]++;
                    if (way[5] == 41) {
                        way[5] = 0;
                        way[4]++;
                        if (way[4] == 21) {
                            way[4] = 0;
                            way[3]++;
                            if (way[3] == 11) {
                                way[3] = 0;
                                way[2]++;
                                if (way[2] == 5) {
                                    way[2] = 0;
                                    way[1]++;
                                    if (way[1] == 3) {
                                        way[1] = 0;
                                        way[0]++;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printf("ways = %d", ways);
}