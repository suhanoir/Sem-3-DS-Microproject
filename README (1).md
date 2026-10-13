# Intelligent Dynamic Production Scheduling System Using Data Structures in C++

**Data Structures Micro-Project \| Alliance University**\
**Alliance School of Advanced Computing**

## Team Members

    No. Name                 USN
  ----- -------------------- ---------------
      1 Suhan Raj M          2511021060830
      2 Preetham Gowda M     2511021060823
      3 Jeevan C             2511021060832
      4 Rishika Teja Reddy   2511021060834
      5 K Lakshmi Sri        2511021060824
      6 Dev Siddharth        2511021060841

------------------------------------------------------------------------

## 1. Project Overview

This project is a **console-based C++ simulation of production
scheduling**. It demonstrates how fundamental data structures and
algorithms can help organize manufacturing operations, prioritize work,
find machines, and maintain machine schedules.

The current source code uses a small **electronics-manufacturing
example** with operations such as Assembly, Soldering, Testing, Quality
Check, and Packaging. It includes sample machines named Assembly
Machine, Soldering Machine, and Testing Machine.

The program is an educational simulation. It does not control real
factory equipment and does not use AI, machine learning, a database, or
a graphical interface.

## 2. Problem Statement

A production environment may contain several operations with different
priorities and dependencies. Machines have limited availability, and
changes such as machine failures or urgent orders can affect the
schedule. If operations are not organized carefully, work may wait
unnecessarily and machine assignments may become inefficient.

This project demonstrates a simple C++ approach to representing
operations and machines, checking basic dependencies, prioritizing
operations, assigning work to available machines, and displaying the
resulting machine schedules.

## 3. Objectives

-   Apply Data Structures and Algorithms to a production-scheduling
    example.
-   Store operation and machine details in arrays.
-   demonstrate stack, queue, and linked-list operations.
-   Arrange operations by priority using Merge Sort.
-   Search for machines using Linear Search.
-   Search for operations by ID using Binary Search on data sorted by
    ID.
-   Display machine schedules.
-   Demonstrate basic responses to machine failure and the addition of
    an urgent operation.
-   Help students explain how data structures are used in a practical
    scenario.

## 4. Current Features

The current `main.cpp` provides these menu options:

1.  Display operations.
2.  Sort operations by priority using Merge Sort.
3.  Display dependency IDs using a stack.
4.  Add dependency-free, incomplete operations to the ready queue.
5.  Schedule queued operations on available machines and store
    assignments in linked lists.
6.  Search for an operation by ID.
7.  Display each machine's linked-list schedule.
8.  Simulate a machine failure by marking the selected machine
    unavailable.
9.  Add a sample urgent operation with priority 10.
10. Exit.

## 5. Data Structures and Algorithms

  -----------------------------------------------------------------------
  Concept                 How it appears in the   Course Outcome
                          current code            
  ----------------------- ----------------------- -----------------------
  Array                   Fixed-size arrays store CO-1
                          operations, machines,   
                          queue items, and stack  
                          items.                  

  Stack                   Stores dependency IDs   CO-1
                          and displays them in    
                          last-in, first-out      
                          order.                  

  Queue                   Stores IDs of           CO-2
                          operations selected as  
                          ready for scheduling.   

  Singly linked list      Stores the sequence of  CO-2
                          operation IDs assigned  
                          to each machine.        

  Linear Search           Finds a machine by its  CO-3
                          ID.                     

  Binary Search           Finds an operation by   CO-3
                          ID after the operations 
                          are sorted by ID.       

  Merge Sort              Sorts operations in     CO-3
                          descending order of     
                          priority.               
  -----------------------------------------------------------------------

### CO-1: Arrays and Stack

Arrays store a fixed collection of operation and machine records. The
stack demonstrates LIFO processing for dependency IDs. In the current
version, the stack displays dependency IDs; it does **not** yet validate
the full dependency chain or control the complete execution order.

### CO-2: Queue and Linked List

The queue holds IDs of operations that have no dependency and are not
marked completed when the ready-queue option is selected. Linked lists
store the operation IDs assigned to each machine and allow the schedule
to be built node by node.

### CO-3: Searching and Sorting

Merge Sort orders operations by priority, with higher-priority
operations first. Linear Search locates a machine by ID. Binary Search
locates an operation by ID; Binary Search requires the data to be
ordered by ID, so the current search option sorts the operation array by
ID before searching.

## 6. Sample Production Data

### Operations

  ------------------------------------------------------------------------
              ID Operation         Priority Processing Time  Dependency ID
                                              (illustrative 
                                                     units) 
  -------------- ----------- -------------- --------------- --------------
               1 Assembly                 3              20              0

               2 Soldering                2              15              1

               3 Testing                  4              10              2

               4 Quality                  5               8              3
                 Check                                      

               5 Packaging                1              12              4
  ------------------------------------------------------------------------

A dependency ID of `0` means that the operation has no prerequisite in
this sample. Other dependency IDs refer to a prerequisite operation.

### Machines

-   Assembly Machine
-   Soldering Machine
-   Testing Machine

The processing times are sample values used for demonstration; they are
not claimed to be measured industrial data.

## 7. Workflow

1.  Start the program and choose a menu option.
2.  View the operations and their priorities/dependencies.
3.  Sort operations by priority if required.
4.  Inspect dependency IDs using the stack demonstration.
5.  Add eligible operations to the ready queue.
6.  Schedule queued operations on machines marked available.
7.  View the machine schedules stored in linked lists.
8.  Search for operations or simulate a machine failure.
9.  Add a sample urgent operation and observe its priority value.
10. Exit the program.

## 8. Project Structure

The current implementation is contained in one source file:

``` text
ProductionSchedulingSystem/
├── main.cpp
└── README.md
```

The source file defines the `Operation` and `Machine` structures,
array-based `Queue` and `Stack` classes, linked-list schedule functions,
searching functions, Merge Sort, display functions, and the menu-driven
`main()` function.

This single-file structure is intentional for the current beginner-level
version. The code can later be separated into header (`.h`) and source
(`.cpp`) files after the team is comfortable with the implementation.

## 9. Requirements

-   A C++ compiler such as GCC/g++ or MinGW.
-   A terminal or IDE such as Visual Studio Code, Code::Blocks, or an
    equivalent C++ environment.

No third-party libraries are required.

## 10. Compile and Run

Open a terminal in the folder containing `main.cpp`.

### GCC / MinGW

``` bash
g++ -std=c++11 -Wall -Wextra main.cpp -o production_scheduler
```

Run on Linux/macOS:

``` bash
./production_scheduler
```

Run on Windows Command Prompt:

``` bat
production_scheduler.exe
```

If you use an IDE, create a C++ console project, add `main.cpp`, build,
and run it.

## 11. Course Outcome Mapping

### CO-1

**Evaluate the performance of array and stack data structures for data
organization.**

-   Arrays store fixed collections of machines and operations.
-   The stack demonstrates push, pop, and LIFO processing of dependency
    IDs.
-   The team can discuss the simplicity and fixed capacity of
    array-based storage.

### CO-2

**Evaluate the suitability of queue and linked list data structures for
data organization.**

-   The queue maintains a list of ready operation IDs.
-   Linked lists store each machine's assigned operation sequence.
-   The team can discuss FIFO queue behavior and dynamic node insertion
    in a linked list.

### CO-3

**Evaluate the suitability of searching and sorting algorithms for
efficient data processing.**

-   Linear Search locates a machine by ID.
-   Binary Search locates an operation by ID in ID-sorted data.
-   Merge Sort arranges operations by priority.

## 12. Limitations of the Current Version

Be accurate about these limitations during the demonstration and viva:

-   The current example is a small electronics-manufacturing scenario,
    not the automotive scenario discussed during planning.
-   The program uses predefined sample data and does not load production
    data from a file or database.
-   Processing times are stored and displayed, but the current scheduler
    does not calculate a full time-based timetable.
-   The stack displays dependency IDs; it does not fully verify
    dependencies or automatically unlock the next operation after
    completion.
-   The ready queue currently selects operations whose dependency ID is
    `0`; dependency completion is not fully integrated into queue
    generation.
-   The scheduler assigns a queued operation to the first machine marked
    available. It does not check whether that machine supports the
    operation type.
-   A machine assigned an operation is marked unavailable, but there is
    no completion-time simulation to make it available again.
-   The machine-failure option marks a machine unavailable but does not
    yet move its scheduled work to another machine or perform complete
    dynamic rescheduling.
-   The urgent-order option adds a generic operation named
    `URGENT ORDER`; it does not create a complete vehicle order with a
    dependency chain.
-   Scheduled maintenance and performance metrics such as utilization,
    waiting time, and order completion rate are not fully implemented.
-   The schedule linked lists are not automatically cleared or freed
    before the program exits.

These are improvement opportunities, not features that should be claimed
as complete in the current version.

## 13. Suggested Future Improvements

If time permits, the project can be improved in this order:

1.  Use meaningful manufacturing operation and machine names.
2.  Check prerequisite completion before adding an operation to the
    ready queue.
3.  Match each operation to a compatible machine.
4.  Track machine busy/available status consistently.
5.  Add a completion step so a machine can become available for later
    work.
6.  Implement actual rescheduling after machine failure.
7.  Add a maintenance schedule and an urgent order with valid
    dependencies.
8.  Calculate and display basic performance metrics.
9.  Add a demonstration menu for each data structure and algorithm.
10. Split the program into `.h` and `.cpp` files once the team
    understands the single-file version.

## 14. Viva Preparation

**Q1. What is production scheduling?**\
Production scheduling is deciding the order in which operations should
be performed and assigning them to available resources.

**Q2. Why are we using C++?**\
C++ lets us implement and demonstrate data structures and algorithms
directly.

**Q3. Why use an array?**\
An array stores a fixed number of operation or machine records and
allows access by index.

**Q4. What is a stack?**\
A stack follows LIFO: the last item pushed is the first item popped.

**Q5. How is the stack used here?**\
It stores dependency IDs and displays them in LIFO order. In the current
version, it does not implement complete dependency validation.

**Q6. What is a queue?**\
A queue follows FIFO: the first item inserted is the first item removed.

**Q7. How is the queue used here?**\
It holds operation IDs that are considered ready for scheduling.

**Q8. Why use a linked list for schedules?**\
A linked list can grow one node at a time as operation assignments are
added.

**Q9. What is Linear Search?**\
It checks items one by one until it finds the requested value or reaches
the end.

**Q10. What is Binary Search?**\
It repeatedly halves a sorted search range. The data must be sorted by
the same key used for searching.

**Q11. What is Merge Sort?**\
Merge Sort divides the array into smaller parts, sorts them recursively,
and merges the sorted parts. Its typical time complexity is O(n log n).

**Q12. Does the program use AI?**\
No. It is a rule-based educational simulation using data structures and
algorithms.

**Q13. Does the current program fully reschedule work after a machine
failure?**\
Not yet. The current version marks the selected machine unavailable and
displays a message. Full reassignment and rescheduling are future
improvements.

**Q14. What are the three course outcomes demonstrated?**\
CO-1 uses arrays and a stack; CO-2 uses a queue and linked lists; CO-3
uses searching and sorting algorithms.

## 15. Conclusion

This micro-project provides a beginner-friendly demonstration of how
arrays, stacks, queues, linked lists, searching, and sorting can be
applied to a production-scheduling scenario. The current version
establishes the basic menu-driven structure and data-structure
demonstrations. Dependency validation, realistic machine compatibility,
maintenance, complete failure recovery, dynamic rescheduling, and
performance reporting are important next steps before describing the
system as a fully dynamic production scheduler.
