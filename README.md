# CS 3353 PA02 Sorting Analysis
[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/c%2B%2B-17-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B17)
[![Language](https://img.shields.io/badge/language-python3-green.svg)](https://isocpp.org/)

## Table of Contents
* [Problem Statement](#problem-statement)
* [Building and Running](#building-and-running)
* [Data Generation](#data-generation)
* [Performance Analysis](#performance-analysis)
* [Conclusions](#conclusions-drawn-from-analysis)
* [Final Note](#final-note-about-sizes)

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
Now run the project and the application will output a file including the performance data for the sorting algorithms relative to each file size/configuration.

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
that the dataset was fully sorted after each performance statistic. The confirmation messages are only triggered when the STL std::is_sorted method verifies that the container is sorted. 

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

### Data Generation Script
The python script used for generating randomized data can be found here:
[data_generation.py](./Data/data_generation.py)

## Performance Analysis

### Integer Performance Graphs
![image](https://user-images.githubusercontent.com/78129094/137661526-cf0ea9c0-6eb2-4975-b8dc-1ab06a230972.png)


![image](https://user-images.githubusercontent.com/78129094/137661604-688ca0ed-002a-4100-b1ed-4620c05cb566.png)

![image](https://user-images.githubusercontent.com/78129094/137661625-cee3edc8-ce46-4ab0-840e-1cdbb64b20e7.png)

![image](https://user-images.githubusercontent.com/78129094/137661651-536c4b28-e7d7-46d3-9927-9fb6786c2b2b.png)

![image](https://user-images.githubusercontent.com/78129094/137661670-63b2ed4d-776a-4ce1-a257-7b09532b9f01.png)

### String Performance Graphs

![image](https://user-images.githubusercontent.com/78129094/137663740-46a68f1c-6b6b-4068-b137-7eed526ca907.png)

![image](https://user-images.githubusercontent.com/78129094/137663752-fc6f9b1a-97e2-439f-86e8-461bc62f2dad.png)

![image](https://user-images.githubusercontent.com/78129094/137664037-09a269ae-b33b-4d3a-b1b1-b8249d2e83cb.png)

![image](https://user-images.githubusercontent.com/78129094/137665251-fa540a2e-412a-4108-8294-2292b191166b.png)

![image](https://user-images.githubusercontent.com/78129094/137665264-7782a8d7-9989-43d1-a4c5-64b43e768a69.png)

### Discussion about Graphs

#### On Insertion Sort

One of the immediate conclusions that can be drawn on Insertion Sort from these graphs is its efficiency with small datasets. 
With datasets less than 10,000, Insertion Sort performed as well as if not better than Quick Sort and Heap Sort. However, with larger data sets Insertion's efficiency deteriates very quickly, as expected. The only other interesting fact about Insertion Sort in this data is that it performed very quickly on an already sorted (descending order) dataset, in direct contrast to Quick Sort. Speaking of Quick Sort...

#### On Quick Sort

The most immediate observation about Quick Sort from the graphs is that Quick Sort is absolutely amazing for randomized, unique data. With randomized data of 0 duplicates, Quick Sort performed unbelievably quickly. In other data configurations however, Quick Sort struggled greatly. For starters, with duplicate data, Quick Sort began losing ground to Heap Sort relatively quickly. The 20% duplicate dataset did not trip up Quick Sort that much, but the 40% duplicate dataset slowed it down quite a bit. Next up, Quick Sort was absolutely abysmal with the sorted datasets. Quick Sort performed the worst out of all 3 algorithms on the sorted datasets, which is shocking. If there is any premonition that the dataset might be sorted, avoid Quick Sort at all costs. 

#### On Heap Sort

Heap Sort really seemed to come away with the win from this data. It had no major struggles like the first two sorts, and seems very ideal for a wide range of applications. It doesn not, however, have a very clear strength like the other sorts. The only times that Heap Sort ended up being slower than another algorithm were two cases: It lost to Quick Sort when sorting randomized data with 0% duplicates, and it lost to Insertion Sort when sorting already sorted data (ascending order).

#### Juxtoposition of Integer and String Data

Despite an increase in runtime when sorting strings vs sorting integers, there was very little change in the trends of the data. Every trend observed in the integer data appeared in the string data.

## Conclusions Drawn from Analysis

### Insertion Sort

#### Perfect for very small datasets, avoid when needing to sort larger datasets

### Quick Sort

#### Perfect for random datasets with no duplicates, avoid large amounts of duplicates, and avoid already sorted data AT ALL COSTS

### Heap Sort

#### Very ideal for sorting a large range of data configurations; really a "jack of all trades" algorithm

## Final Note about Sizes

### Data Set Sizes
To reiterate, the data set sizes are small mainly because I had a lot of trouble with Quick Sort seg-faulting on the large data sets. This mainly had to do with the fact that my Quick Sort algorithm chooses its pivot at the beginning of the vector, rather than randomly or in the middle. Because of this, when attempting to sort an already sorted vector, the algorithm deteriates to worst case complexity and the call stack overflows from too many recursive calls. If I could have used a different pivot choice strategy, I would have, but only having access to iterators limited my ability to implement such logic. 
