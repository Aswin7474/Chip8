#ifndef OPCODES_H
#define OPCODES_H 
#include <cstdint>
#include <ctime>
#include <cstdlib>
typedef struct Chip8State {
    uint8_t *memory;  // changed from 8 bit to 16 to shut up an error
    uint8_t *screen;
    uint8_t V[16];
    uint16_t PC;
    uint16_t SP;
    uint8_t delay;
    uint8_t sound;
    uint16_t I; 
} Chip8State;


void op0nnn(uint8_t opcode, Chip8State *state);
void op00E0(uint8_t opcode, Chip8State *state);
void op00EE(uint8_t opcode, Chip8State *state);
void op1nnn(uint8_t opcode, Chip8State *state);
void op2nnn(uint8_t opcode, Chip8State *state);
void op3xnn(uint8_t opcode, Chip8State *state);
void op4xkh(uint8_t opcode, Chip8State *state);
void op5xy0(uint8_t opcode, Chip8State *state);
void op6xnn(uint8_t opcode, Chip8State *state);
void op7xnn(uint8_t opcode, Chip8State *state);
void op8xy0(uint8_t opcode, Chip8State *state);
void op8xy1(uint8_t opcode, Chip8State *state);
void op8xy2(uint8_t opcode, Chip8State *state);
void op8xy3(uint8_t opcode, Chip8State *state);
void op8xy4(uint8_t opcode, Chip8State *state);
void op8xy5(uint8_t opcode, Chip8State *state);
void op8xy6(uint8_t opcode, Chip8State *state);
void op8xy7(uint8_t opcode, Chip8State *state);
void op8xye(uint8_t opcode, Chip8State *state);
void op9xy0(uint8_t opcode, Chip8State *state);
void opannn(uint8_t opcode, Chip8State *state);
void opbnnn(uint8_t opcode, Chip8State *state);
void opcxnn(uint8_t opcode, Chip8State *state);
void opdxyn(uint8_t opcode, Chip8State *state);
void opex9e(uint8_t opcode, Chip8State *state);
void opexa1(uint8_t opcode, Chip8State *state);
void opfx07(uint8_t opcode, Chip8State *state);
void opfx0a(uint8_t opcode, Chip8State *state);
void opfx15(uint8_t opcode, Chip8State *state);
void opfx18(uint8_t opcode, Chip8State *state);
void opfx1e(uint8_t opcode, Chip8State *state);
void opfx29(uint8_t opcode, Chip8State *state);
void opfx33(uint8_t opcode, Chip8State *state);
void opfx55(uint8_t opcode, Chip8State *state);
void opfx65(uint8_t opcode, Chip8State *state);

#endif
