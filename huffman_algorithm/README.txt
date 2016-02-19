Idea:

The Tool has three parts:
1. The Code Generator
2. The Compressor
3. The Decompressor


/*CODE GENERATOR*/

/*Things Done:*/
1) ASCII values of chars are used as keys for hashing.
2) Chars are read from i/p file and number of occurences is counted
3) A new Index table is created to store the sorted order of ASCII values
4) Only the indices of ASCII values are sorted in non-increasing order
5) This Index table is now converted to a doubly linked circular list
6) Nodes of this list can also be used as nodes of a tree
7) The list itself is then transformed into a Huffman Tree using derived nodes
8) A traversal of this tree is done to obtain code for Dotty Dump
/*************/

/*To Be Done:*/
- Interleaving a procedure to assign Huffman Code for symbols, with Traverse procedure
- Output an intermediate file with Huffman Codes of all symbols used by the input file.
/************/

/*CODE GENERATOR*/




/*COMPRESSOR*/

/*Things Done*/
/*************/

/*To Be Done*/
- Build a Huffman Tree using the Intermediate file
- Create a Compressed file by replacing symbols by corresponding codes
- Generate Code Analysis and Compression Ratio details
/*******************/

/*COMPRESSOR*/




/*DECOMPRESSOR*/

/*Things Done:*/
/**************/

/*To Be Done:*/
- Build a Huffman Tree using the Intermediate file
- Create Decompressed file by replacing the codes by corresponding symbols
/********************/

/*DECOMPRESSOR*/

------------------------------------------------------------------------------------
