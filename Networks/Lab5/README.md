Thomas Nguyen
Monday 2:15pm


--------------- About --------------
randgenerator.c
For this program I made use of two important library functions in C
that were central to my program. 

strtol() was used to take in the string input on the command line and 
convert it to a long. I used this to read how many bytes of random 
symbols the user wanted to generate.

rand() was used to generate a random number which would be modded by
256 to correlate with an ASCII symbol



entropyCalculator.c
In this program I heavily referenced Cisco's tutorial on writing
an Entropy Calculator. I began by reading the text file and placing
text into my buffer that was 4Mb. As I read through it I incremented
the corresponding byte into my frequency array. Once finished reading
the file, I iterated through the frequency array and calculated the
entropy by turning it into a propability distribution then using the
Shannon Entropy Formula.


--------------- Instructions ---------------
randgenerator.c
 - 2 command line inputs
 - First input: # bytes for random stream of symbols
 - Second input: name of text file writing too

entropyCalculator.c
 - 1 command line input
 - First input: name of text file produced by randgenerator.c

--------------- Entropy Results ---------------
1) 100 Bytes: 6.288758
2) 1000 Bytes: 7.812065
3) 10000 Bytes: 7.984511
4) 100000 Bytes: 7.990844
5) 1000000 Bytes: 7.999835
6) 10000000 Bytes: 7.999981



