#include <opcodes.h>


bool checkOverflow(uint8_t a, uint8_t b) {
    return (a > UINT8_MAX - b);
}

bool checkUnderflow(uint8_t a, uint8_t b) {
    return a < b;
}

void op0nnn(uint8_t opcode, Chip8State *state) {
    uint8_t address = opcode & 0x0FFF;
    state->PC = address;
} // not used 

void op00E0(uint8_t opcode, Chip8State *state) {
    // todo - clears display
}

void op00EE(uint8_t opcode, Chip8State *state) {
    (state->SP)--;
    state->PC = state->SP;
}

void op1nnn(uint8_t opcode, Chip8State *state) {
    uint8_t address = opcode && 0x0FFF;
    state->PC = address;
}

void op2nnn(uint8_t opcode, Chip8State *state) {
    state->SP++;
    state->PC = state->SP;
}

void op3xnn(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t nn = opcode & 0x00FF;
    if (state->V[x] == nn) {
        state->PC = state->PC + 2;
    }
}

void op4xkh(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t nn = opcode & 0x00FF;
    if (state->V[x] != nn) {
        state->PC = state->PC + 2;
    }
}

void op5xy0(uint8_t opcode, Chip8State *state ) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;
    if (state->V[x] == state->V[y]){
        state->PC = state->PC + 2;
    }
}

void op6xnn(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t nn = opcode & 0x00FF;

    state->V[x] = nn;
}

void op7xnn(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t nn = opcode & 0x00FF;

    state->V[x] = state->V[x] + nn;
}

void op8xy0(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;
    state->V[x] = state->V[y];
}

void op8xy1(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    state->V[x] = state->V[x] | state->V[y];
}

void op8xy2(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    state->V[x] = state->V[x] & state->V[y];
}

void op8xy3(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    state->V[x] = state->V[x] ^ state->V[y];
}

void op8xy4(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    // checking if overflow first
    if (checkOverflow(state->V[x], state->V[y]))
        state->V[0xF] = 1;
    
    state->V[x] = state->V[x] + state->V[y];
}

void op8xy5(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    if (checkUnderflow(state->V[x], state->V[y])) {
        state->V[0xF] = 0;
    }
    else {
        state->V[0xF] = 1;
    }

    state->V[x] = state->V[x] - state->V[y];
}

void op8xy6(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    if (state->V[x] & 1) {
        state->V[0xF] = 1;
    }
    else {
        state->V[0xF] = 0;
    }

    state->V[x] = state->V[x] >> 1;
}

void op8xy7 (uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    if (state->V[y] > state->V[x]) {   // checking overflow manually cuz more understandable
        state->V[0xF] = 1; 
    }
    else {
        state->V[0xF] = 0;
    }
    state->V[x] = state->V[y] - state->V[x];
}

void op8xye(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    bool msb = state->V[x] & 0b10000000;

    if (msb == 1) {
        state->V[0xF] = 1;
    }
    else {
        state->V[0xF] = 0;
    }

    state->V[x] = state->V[x] << 1;
} 

void op9xy0(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t y = opcode & 0x00F0;

    if (state->V[x] != state->V[y]){
        state->PC = state->PC + 2;
    }
}

void opannn(uint8_t opcode, Chip8State *state) {
    uint8_t nnn = opcode & 0x0FFF;

    state->I = nnn;
}

void opbnnn(uint8_t opcode, Chip8State *state) {
    uint8_t nnn = opcode & 0x0FFF;

    state->PC = nnn + state->V[0];
}

void opcxnn(uint8_t opcode, Chip8State *state) {
    uint8_t x = opcode & 0x0F00;
    uint8_t nn = opcode & 0x00FF;

    state->V[x] = (rand() % 255) & nn;
}

void opdxyn(uint8_t opcode, Chip8State *state) {
    // todo
}

void opex9e(uint8_t opcode, Chip8State *state) {
    // todo
}

void opexa1(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx07(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx0a(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx15(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx18(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx1e(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx29(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx33(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx55(uint8_t opcode, Chip8State *state) {
    // todo
}

void opfx65(uint8_t opcode, Chip8State *state) {
    // todo
}
