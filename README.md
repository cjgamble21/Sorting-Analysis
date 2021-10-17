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
