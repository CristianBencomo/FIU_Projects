Charles King 5961386
This is my README

I successfully implemented all the parts of this assignment I was able to implement the hash table and add all the words from the dictionary.txt file to the data structure. I used the recursive hash function the professor gave and used strrev to reverse the word as he specified to work properly. 

I initally added the nodes to the beginning of the list/at the head list and then recoded the logic to add the node to the end of the list like the professor specified in the lecture. 
Worth mentioning that when I did this the hash value of the words in the dictionary changed and I could not understand why. The program works perfectly other than that small inconsistency and still searches perfectly.

The search feature was also implemented with the tokenization of the input file with multiple delimiters except alphabetical characters, dash and the apostrophe character and then compared to the words in the same bucket with the same hash to check if it exist.
Single letters were not recognized and tokenized and I could not understand why. The delimiters I added do not include single letters characters. 

The input file does require a new line at the end of the last character of the file inorder to recognize the last line and tokenize the words. 

If the word is not found then that word is misspelled and printed to the console. 

Program can be executed with a.exe dictionary.txt input.txt