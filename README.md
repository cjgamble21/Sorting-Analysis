# CS 3353 PA02 Abstract Sorting
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)

## Table of Contents
* [Problem Statement](#problem-statement)
* [Building and Running](#building-and-running)
* [Data Generation](#data-generation)
* [Performance Analysis](#performance-analysis)

## Problem Statement
In this project, we are implementing sorting algorithms and running those algorithms on varying size and types of data sets. 
With our performance data we will analyze each individual sorting algorithms strengths and weaknesses.
Our method of implementation will be with custom containers, and each sorting algorithm will simply take a beginning and an end iterator to the container.
This keeps the logic of sorting separate from the logic of the containers. 

## Building and Running

### Running the project
This project is recommended to be built and run in CLion. Open the project's root directory in CLion. 
Once opened, head to the file Driver.cpp. In Driver, change the file path to the absolute path of the IntegerData 
or StringData directory in the project, depending on which data set you want to test.
For example, since I am on a Mac and because I want to test sorting on integer data, my absolute file path would be: 
```
/Users/cjgamble/CLionProjects/21f-pa02-connor-gamble/Data/IntegerData
```
Once the absolute path is specified, change the output file name to begin with the data type you are sorting. 
If you are sorting strings, the output file name should be: 
```
"StringResultData.txt"
```
Now run the project and the application will output a csv file of the performance data for the sorting algorithms relative to each file size/configuration.

### Sample input
Every input file is a specific configuration and size, as specified by the name of the file. 
A file can have either integers or strings, have a varying size, be sorted in ascending order, descending order, or not at all, or have either 20% duplicates or 40% duplicates. 

For example:
```
data_integer_100000_null_0.2.txt
```
This data file is full of integers, has a size of 100000, is not sorted, and has 20% duplicates. 

### Sample Output
This project will output a file that gives the raw performance data of each algorithm on each input file. 
Each section will give the path of the input file, the performance of each algorithm on that data set, and a message confirming 
that the dataset was fully sorted after each performance statistic.

Each section will look something like this:
```
Data File: /Users/cjgamble/21f-pa02-connor-gamble/Data/IntegerData/data_integer_1000_ascend_0.0.txt

Insertion Sort: 35.23 seconds

Data set is fully sorted!

Quick Sort: 2.34 seconds

Data set is fully sorted!

Heap Sort: 1.38 seconds

Data set is fully sorted!
```
## Data Generation

### Generation Algorithm
All data was generated using the following algorithm:

Two data sets:
```
Integers && Strings
```

Six data set sizes: 
```
{100, 1000, 10000, 20000, 50000, 100000}
```

For each data set size:
```
Randomized data set with 0% duplicates
Data set with 0% duplicates sorted in ascending order
Data set with 0% duplicates sorted in descending order
Randomized data set with 20% duplicates
Randomized data set with 40% duplicates
```
The sizes I chose were relatively small for two reasons:
```
1. Running insertion sort on extremely large datasets would take hours
2. Running quick sort on large datasets that are already sorted causes call stack overflows
```

### Generating Integer Data
All integer data was generated with a pseudo-random number generator. 
The number range varied betweeen 1 and 3,000,000. 

### Generating String Data
All string data was generated as 10 character strings, all alphanumeric capital letters. In a loop run 10 times, a pseudo-random number generator picked a number between 65 and 90, then that number was casted to a character and appended to the data string.

## Performance Analysis

### Integer Performance Graphs
![image](https://user-images.githubusercontent.com/78129094/137661526-cf0ea9c0-6eb2-4975-b8dc-1ab06a230972.png)


![image](https://user-images.githubusercontent.com/78129094/137661604-688ca0ed-002a-4100-b1ed-4620c05cb566.png)

![image](https://user-images.githubusercontent.com/78129094/137661625-cee3edc8-ce46-4ab0-840e-1cdbb64b20e7.png)

![image](https://user-images.githubusercontent.com/78129094/137661651-536c4b28-e7d7-46d3-9927-9fb6786c2b2b.png)

![image](https://user-images.githubusercontent.com/78129094/137661670-63b2ed4d-776a-4ce1-a257-7b09532b9f01.png)

### String Performance Graphs
