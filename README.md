# Huffmann-Algorithm
Huffman Coding is a lossless data compression algorithm where each character in the data is assigned a variable length prefix code. 
The least frequent character gets the largest code and the most frequent one gets the smallest code. Encoding the data using this technique is very easy and efficient.
However, decoding the bitstream generated using this technique is inefficient.Decoders(or Decompressors)require the knowledge of the encoding mechanism used in order to decode the encoded data back to the original characters. Hence information about the encoding process needs to be passed to the decoder along with the encoded data as a table of characters and their corresponding codes.
In regular Huffman coding of a large data, this table takes up a lot of memory space and also if a large no. of unique characters are present in the data then the compressed(or encoded) data size increases because of the presence of the codebook.
