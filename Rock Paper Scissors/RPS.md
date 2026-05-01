# ✊ Rock Paper Scissors — CLI Game

A lightweight, terminal-based Rock Paper Scissors game written in pure C. Designed with clean separation of concerns across a header, implementation, and entry point file.

---

## 📁 Project Structure

```
.
├── main.c       # Entry point — game loop and flow control
├── RPS.c        # Core logic — input handling, game rules, display
└── RPS.h        # Header — constants, macros, and function declarations
```

---

## ⚙️ Build & Run

### Requirements
- GCC or any C99-compatible compiler
- A Unix-like terminal (Linux, macOS, WSL)

### Compile

```bash
gcc main.c -o rps
```

### Run

```bash
./rps
```

---

## 🎮 Gameplay

On each turn, the player is shown a menu and prompted to enter a number:

```
##################################
#         Choose a number        #
##################################
#            (1) Scissors        #
#            (2) Paper           #
#            (3) Rock            #
#            (4) Exit            #
##################################
```

The computer randomly selects its move, the winner is determined by standard RPS rules, and the result is printed. The game loops until the player chooses to exit.

### Win Conditions

| Player   | Computer | Result |
|----------|----------|--------|
| Rock     | Scissors | Win    |
| Scissors | Paper    | Win    |
| Paper    | Rock     | Win    |
| Any      | Same     | Tie    |

---

## 🧩 Architecture

### `RPS.h`
Defines all constants and macros used across the project:

| Macro             | Value | Description                   |
|-------------------|-------|-------------------------------|
| `SCISSORS`        | `1`   | Scissors choice                |
| `PAPER`           | `2`   | Paper choice                   |
| `ROCK`            | `3`   | Rock choice                    |
| `WIN`             | `1`   | Result: player wins            |
| `LOSE`            | `-1`  | Result: player loses           |
| `TIE`             | `0`   | Result: tie                    |
| `EXIT_STATUS`     | `0`   | Signals the game to exit       |
| `UNDEFINED_INPUT` | `-1`  | Signals invalid input          |

### `RPS.c`
Contains all game functions:

| Function                          | Description                                  |
|-----------------------------------|----------------------------------------------|
| `display_menu()`                  | Prints the choice menu to stdout             |
| `input_handler()`                 | Reads and validates user input via `fgets`   |
| `computer_choice()`               | Generates a random computer move             |
| `winner_or_loser(computer, user)` | Determines and returns the game result       |
| `print_winner(result)`            | Displays WIN / LOSE / TIE message            |
| `print_error()`                   | Displays an error message for invalid input  |
| `credits()`                       | Displays a goodbye message on exit           |

### `main.c`
Runs the main game loop:
1. Display the menu
2. Read and validate user input
3. If exit — show credits and break
4. If valid — get computer choice, determine winner, print result
5. If invalid — print error
6. Repeat

---

## 🔒 Input Safety

Input is read using `fgets` into a fixed-size buffer (`64` bytes) to prevent buffer overflows. `sscanf` is then used to parse the integer, and bounds checking ensures only values `1–4` are accepted. Any other input is safely handled as `UNDEFINED_INPUT`.

---

## ⚠️ Known Limitations

- `srand(time(NULL))` is called on every turn inside `computer_choice()`, which can produce identical results if two turns happen within the same second. Moving `srand` to `main()` would fix this.
- `choices[]` is defined in the header file, which will cause **multiple definition errors** if `RPS.h` is included in more than one translation unit. It should be declared `extern` in the header and defined once in `RPS.c`.
- `main.c` includes `RPS.c` directly instead of compiling them as separate translation units, which is non-standard practice.

---

## 🛠️ Suggested Improvements

- Move `srand(time(NULL))` to the top of `main()`
- Add a score tracker across rounds
- Add difficulty levels (e.g., computer biases its choices)
- Support keyboard input (`r`, `p`, `s`) in addition to numbers