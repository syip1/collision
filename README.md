# Ball Collision Simulator
The aim of this project is to create a quick simulation engine for the motion of balls or other objects. The most important element here is to determine when collisions happen.  
As a first try, we just compute all the pairwise collision times and take the minimum of those -- this is O(N^2) per collision.  
There should be a faster implementation using priority queues which we will try to implement later.  
