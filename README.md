Monty interpreter

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument.

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account


The opcode push pushes an element to the stack.

The opcode pall prints all the values on the stack, starting from the top of the stack.

The opcode pint prints the value at the top of the stack, followed by a new line.

The opcode pop removes the top element of the stack.

The opcode swap swaps the top two elements of the stack.

The opcode add adds the top two elements of the stack.

The opcode nop doesn’t do anything.

The opcode sub subtracts the top element of the stack from the second top element of the stack.

The opcode div divides the second top element of the stack by the top element of the stack.

The opcode mul multiplies the second top element of the stack with the top element of the stack.

The opcode mod computes the rest of the division of the second top element of the stack by the top element of the stack.

When the first non-space character of a line is #, treat this line as a comment (don’t do anything).
