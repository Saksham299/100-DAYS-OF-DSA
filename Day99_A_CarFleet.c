#include <stdio.h>

int main() {
    int n, target;
    scanf("%d %d", &n, &target);

    int pos[100], speed[100];

    for (int i = 0; i < n; i++) scanf("%d", &pos[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (pos[j] > pos[i]) {
                int tp = pos[i]; pos[i] = pos[j]; pos[j] = tp;
                int ts = speed[i]; speed[i] = speed[j]; speed[j] = ts;
            }

    float time[100];
    for (int i = 0; i < n; i++)
        time[i] = (float)(target - pos[i]) / speed[i];

    int fleets = 0;
    float maxTime = 0;

    for (int i = 0; i < n; i++) {
        if (time[i] > maxTime) {
            fleets++;
            maxTime = time[i];
        }
    }

    printf("%d", fleets);
    return 0;
}
