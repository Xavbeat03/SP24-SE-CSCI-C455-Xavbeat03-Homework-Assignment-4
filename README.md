# SP24-SE-CSCI-C455-Xavbeat03-Homework-Assignment-4
Homework Assignment 4 for Analysis of Algorithms

First Download and install CLion on your computer, the best way to do this is to install JetBrains Toolbox. 

The description below is for you to think about how to start writing this code.

Implement a Priority Queue based on a Max-Heap for airports records in the given air16.txt

Download air16.txt file. Your priority queue should have the highest altitude airport at the front of the queue. Your priority queue should have the following operations. Priority Queue is represented by the letter S in the following functions.

* Insert (S, x) - inserts element x into the priority queue
* Maximum (S) - returns a copy of the key-value tuple that has the largest key in the priority queue
* Extract-Max (S) - removes the record from the priority queue and returns the key-value tuple that is with the largest key
* Increase-Key (S, x, k) - increases the value of the key located at position 'x' in the queue; k is required to be greater than the key already stored at location 'x'

You can find the implementation details of the above functions and Max_Heapify in Module #4. You should implement the algorithms given in the course lectures, not something you find on the Internet.  You must also design and implement the necessary data structure to hold the records with the keys. It is beneficial to use an OpenRecord that you learned in C343.  
Airport Data Overview:

    The Airport Data (air16.txt) 

    Download (air16.txt) file contains data for airports related to the name, code, location, and altitude. The file consists of 16 records, and value 16 is the first item in the file.

Airport Record Format in Data Set:
There are 13 fields in each record, in the order listed below, and the field's data type is included:

1. code - (string) The airport's International Air Transport Association's 3-letter code
2. name - (string) Airport's name 
3. city - (string) City where the airport is located 
4. country - (string) Country where the airport is located 
5. latitude degree - (int) Airport's degrees latitude 
6. latitude minutes - (int) Airport's minutes latitude 
7. latitude seconds - (int) Airport's seconds latitude 
8. latitude direction - (string) N or S 
9. longitude degree - (int) Airport's degrees longitude 
10. longitude minutes - (int) Airport's minutes longitude 
11. longitude seconds - (int) Airport's seconds longitude 
12. longitude direction - (string) E or W 
13. altitude - (int) Airport's altitude in feet (KEY!!!!)

You must compile your program in CLion. Submit your code and all outputs of testing all the functions. 