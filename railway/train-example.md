Train example
=============

Exercise 1
----------

A train station contains a number of boxes. This information is stored in a text file with 3 columns. Each row is one box, which has:

* label [string]
* weight in kg [double]
* destination [string]

The station loads the boxes onto trains. One train for each destination.
Print the following output:

* Train to station A: total weight 120.4 t
* Train to station B: total weight 20.23 t



Exercise 2
----------

Same input as before.

Now, a train consists of the engine and a maximum of 7 carriages. 

Each carriage can hold 2 standard shipping containers. 

A standard container can hold a maximum weight of 25t.


Print the following output:

* To station Aaa: 
  * Train 1: 7 carriages, 14 containers, total weight 120t
  * Train 2: 3 carriages, 5 containers, total weight 12t
* To station Bbb: 
  * Train 1: 5 carriages, 10 containers, total weight 75t
* To station Ccc: 
  * Train 1: 7 carriages, 14 containers, total weight 120t
  * Train 2: 7 carriages, 14 containers, total weight 300t
  * Train 3: 2 carriages, 3 containers, total weight 30t

