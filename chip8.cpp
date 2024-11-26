#include <iostream>
#include <opcodes.h>

Chip8State* initChip8() {
    Chip8State* s = (Chip8State *)calloc(1, sizeof(Chip8State));
    s->SP = 0xfa0;
    s->PC = 0x200;
    s->memory = (uint8_t *)calloc(1, 4096);
    s->screen = &s->memory[0xf00];
    return s;
}

int main() {
    Chip8State *state = initChip8();
    srand(time(0));

    uint8_t *opcode = &state->memory[state->PC];
    int highnib = (*opcode & 0xF000);

    switch (highnib){
        case 0x0:
            switch(*opcode) {
                case 0x00E0:
                    op00E0(*opcode, state);
                    break;
                case 0x00EE:
                    op00EE(*opcode, state);
                    break;
            }
            break;
        case 0x1000:
            op1nnn(*opcode, state);
            break;
        case 0x2000:
            op2nnn(*opcode, state);
            break;
        case 0x3000:
            op3xnn(*opcode, state);
            break;
        case 0x4000:
            op4xkh(*opcode, state);
            break;
        case 0x5000:
            op5xy0(*opcode, state);
            break;
        case 0x6000:
            op6xnn(*opcode, state);
            break;
        case 0x7000:
            op7xnn(*opcode, state);
        case 0x8000:
            switch(*opcode & 0x000F) {
                case 0x0000:
                    op8xy0(*opcode, state);
                    break;
                case 0x0001:
                    op8xy1(*opcode, state);
                    break;
                case 0x0002:
                    op8xy2(*opcode, state);
                    break;
                case 0x0003:
                    op8xy3(*opcode, state);
                    break;
                case 0x0004:
                    op8xy4(*opcode, state);
                    break;
                case 0x0005:
                    op8xy5(*opcode, state);
                    break;
                case 0x0006:
                    op8xy6(*opcode, state);
                    break;
                case 0x0007:
                    op8xy7(*opcode, state);
                    break;
                case 0x000E:
                    op8xye(*opcode, state);
            }
            break;
        case 0x9000:
            op9xy0(*opcode, state);
            break;
        case 0xA000:
            opannn(*opcode, state);
            break;
        case 0xB000:
            opbnnn(*opcode, state);
            break;
        case 0xC000:
            opcxnn(*opcode, state);
            break;
        case 0xD000:
            opdxyn(*opcode, state);
            break;
        case 0xE000:
            switch (*opcode & 0x00FF) {
                case 0x009E:
                    opex9e(*opcode, state);
                    break;
                case 0x00A1:
                    opexa1(*opcode, state);
                    break;
            }
            break;
        case 0xF000:
            switch (*opcode & 0x00FF) {
                case 0x0007:
                    opfx07(*opcode, state);
                    break;
                case 0x000A:
                    opfx0a(*opcode, state);
                    break;
                case 0x0015:
                    opfx15(*opcode, state);
                    break;
                case 0x0018:
                    opfx18(*opcode, state);
                    break;
                case 0x001E:
                    opfx1e(*opcode, state);
                    break;
                case 0x0029:
                    opfx29(*opcode, state);
                    break;
                case 0x0033:
                    opfx33(*opcode, state);
                    break;
                case 0x0055:
                    opfx55(*opcode, state);
                    break;
                case 0x0065:
                    opfx65(*opcode, state);
                    break;
            }
    }
}



