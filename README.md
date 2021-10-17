# CS 3353 PA02 Abstract Sorting
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)

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
For example, since I am on a Mac, my absolute file path is: 
```
/Users/cjgamble/CLionProjects/21f-pa02-connor-gamble/Data/IntegerData
```
Once the absolute path is specified, run the project and the application will output a csv file of the performance data for the sorting algorithms, relative to each file size/configuration.

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
that the dataset was fully sorted.

Each section will look something like this:
```
Data File: /Users/cjgamble/21f-pa02-connor-gamble/Data/IntegerData/data_integer_1000_ascend_0.0.txt

Insertion Sort: 35.23 seconds

Quick Sort: 2.34 seconds

Heap Sort: 1.38 seconds

Data set is fully sorted!
```
## Data Generation
