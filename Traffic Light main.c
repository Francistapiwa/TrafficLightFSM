#include <stdio.h>
#include <string.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

typedef enum {
    RED,
    RED_YELLOW,
    GREEN,
    YELLOW
} TrafficLightState;

void app_main(void) {
    TrafficLightState state = RED;
    int counter = 0;
    int pedestrian_button = 0;
    int pedestrian_press_time = 0;

    for (;;) {
        char c = 0;
        scanf("%c", &c);

        if (c == 'p') {
            pedestrian_button = 1;
            pedestrian_press_time = counter;
            printf("Pedestrian button pressed at %d seconds.\n", counter);
        }

        switch (state) {
            case RED:
                printf("Time: %d, State: RED -> Next: RED_YELLOW\n", counter);
                if (counter >= 20) {
                    state = RED_YELLOW;
                    counter = 0;
                }
                break;

            case RED_YELLOW:
                printf("Time: %d, State: RED_YELLOW -> Next: GREEN\n", counter);
                if (counter >= 5) {
                    state = GREEN;
                    counter = 0;
                }
                break;

            case GREEN:
                printf("Time: %d, State: GREEN -> Next: YELLOW\n", counter);
                if (counter >= 20 || (pedestrian_button && counter - pedestrian_press_time >= 20)) {
                    state = YELLOW;
                    counter = 0;
                    pedestrian_button = 0;
                }
                break;

            case YELLOW:
                printf("Time: %d, State: YELLOW -> Next: RED\n", counter);
                if (counter >= 5) {
                    state = RED;
                    counter = 0;
                }
                break;
        }

        counter++;
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
