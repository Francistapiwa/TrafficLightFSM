# Traffic Light Finite State Machine (FSM) - ESP32 FreeRTOS

This project implements a Finite State Machine (FSM) for a traffic light system using C and FreeRTOS on the ESP32 platform. It simulates state transitions (RED → RED_YELLOW → GREEN → YELLOW → RED) and includes pedestrian button handling using non-blocking input.

## FSM Definition (5-Tuple)

1. **States (Q)**: `{ RED, RED_YELLOW, GREEN, YELLOW }`  
2. **Alphabet (Σ)**: `{ pedestrian button press, timer expiry }`  
3. **Transition Function (δ)**:
   - `RED` → `RED_YELLOW` (on timer expiry)
   - `RED_YELLOW` → `GREEN` (on timer expiry)
   - `GREEN` → `YELLOW` (on timer expiry or if pedestrian button was pressed for 20 seconds)
   - `YELLOW` → `RED` (on timer expiry)
4. **Initial State (q₀)**: `RED`
5. **Final State (F)**: `{ GREEN }` (conceptually treated as final for assignment purposes)

## How It Works

- The system cycles through traffic light states with delays.
- It listens for a pedestrian button press using `scanf` (simulate by entering `p`).
- Button press and counter time determine if a transition should be triggered sooner.

## Technologies Used

- ESP-IDF (ESP32)
- FreeRTOS
- C programming
- `scanf` for simulated pedestrian input

## Usage

1. Clone the repo:
   ```bash
   git clone https://github.com/yourusername/traffic-light-fsm.git
   cd traffic-light-fsm
