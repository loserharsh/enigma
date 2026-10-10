Enigma

A C++ project where I'm building my own Enigma-style encryption machine from scratch.

I'm trying to understand how the machine works by implementing the logic myself instead of just using an existing library or copying someone else's implementation.

How it works

The machine takes a letter, converts it into a number from "0" to "25", passes it through different components, and converts the result back into a letter.

- Alphabet: "A = 0", "B = 1", ..., "Z = 25".
- Plugboard: Swaps letters using pairs of connections.
- Rotors: Use a scrambled wiring of 26 letters. Each rotor has a position that changes how the wiring maps an input to an output.
- Reflector: Sends the signal back through the rotors in reverse.
- Rotor stepping: The rotors move as letters are processed, changing the encryption for each keypress.

The math

I'm using arrays to represent the wiring and modulo arithmetic to keep letter indices within the range "0–25".

For example, converting a letter to a number:

int letter = ch - 'A';

Converting the number back into a letter:

char ch = letter + 'A';

Modulo arithmetic handles the circular alphabet, so moving past "Z" wraps around to "A".

Current implementation

- [x] Alphabet-to-number conversion
- [x] Rotor forward mapping
- [x] Reverse rotor mapping
- [x] Rotor positions and stepping
- [x] Reflector wiring
- [ ] Connect the plugboard to the encryption loop
- [ ] Test the complete machine
- [ ] Improve terminal input and output

Why I'm building this

I wanted to build an Enigma machine, so I'm figuring out the logic one component at a time.

The rotor wirings are my own chosen permutations, not the original historical wirings. The goal is to understand the mathematics, arrays, mappings, and mechanics behind this kind of encryption system.

Still a work in progress.