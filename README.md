# Data Compression Techniques: BWT, Run-Length, and Huffman Encoding

This project demonstrates a series of data compression techniques by combining the **Burrows-Wheeler Transform (BWT)**, **Run-Length Encoding (RLE)**, and **Huffman Coding**. The code is implemented in C++ and includes both encoding and decoding functions for each method.

## Overview

The project implements the following algorithms:

- **Burrows-Wheeler Transform (BWT):**
  - **Encoding:** Rearranges the characters of the input string to group similar characters together, making it more amenable to compression.
  - **Decoding:** Reverses the transformation using sorted rotations and a "last-to-first" mapping.

- **Run-Length Encoding (RLE):**
  - **Encoding:** Compresses sequences of repeated characters by replacing them with a special marker and a count.
  - **Decoding:** Expands the compressed sequences back to the original form.

- **Huffman Coding:**
  - **Encoding:** Constructs a Huffman tree based on character frequencies and generates a binary code for each character.
  - **Decoding:** Traverses the Huffman tree according to the binary codes to recover the original text.

The main function demonstrates the use of these transformations by processing an input string, displaying intermediate encoded forms, and finally recovering the original text.

## Files

- **`main.cpp`**  
  Contains the complete source code including implementations for BWT, RLE, and Huffman encoding/decoding, along with a demonstration in the `main()` function.

## Getting Started

### Prerequisites

- A C++ compiler that supports C++11 or later (e.g., `g++`, `clang++`).
- The project uses the `<bits/stdc++.h>` header, which is available in GCC. Ensure your environment is set up for GCC or modify the includes as necessary for other compilers.

### Compilation

To compile the project, run:

```bash
g++ -std=c++11 -O2 -o compression main.cpp
```

This command compiles the project with C++11 support and produces an executable named `compression`.

### Running the Program

After compiling, run the executable:

```bash
./compression
```

The program will:
1. Read a single line of text from standard input.
2. Perform BWT encoding and then apply run-length encoding on the BWT output.
3. Execute Huffman encoding on the original input.
4. Decode the Huffman-encoded string.
5. Decode the run-length encoded string back to the BWT-encoded form.
6. Finally, decode the BWT string to recover the original input.

Intermediate results for each step are printed to the console.

## Detailed Algorithm Descriptions

### Burrows-Wheeler Transform (BWT)
The BWT encoding function builds a suffix array of the input text and constructs the transformed string by collecting the character preceding each suffix (using a cyclic rotation). The decoding function reconstructs the original string using sorting and mapping techniques.

### Run-Length Encoding (RLE)
This simple compression method scans the string for consecutive repeated characters. It encodes these runs by outputting a special marker (`|x`), the character, and the number of times it repeats. The decoding function reverses this process, expanding the encoded runs back to their original form.

### Huffman Coding
Huffman coding builds a frequency table for all characters in the input, constructs a Huffman tree, and then generates variable-length binary codes (shorter for more frequent characters). The encoding function converts the original text into a binary string using these codes, and the decoding function uses the Huffman tree to recover the text.

## Contributing

Contributions are welcome! If you encounter issues or have ideas for improvements, please fork the repository and submit a pull request with your changes. For major changes, please open an issue first to discuss what you would like to change.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.
