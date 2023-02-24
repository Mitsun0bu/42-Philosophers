# 42-Philosophers

~~~ INTRO ~~~

This program has been made for the "philosophers" 42 School project (2021).  
The goal of this project was to create a program where philosopher(s) alternatively eat, think, or sleep. Every philosopher needs to eat and should never starve.

~~~ TO RUN THE PROGRAM ~~~

1. Clone this repository in the folder of your choice using `git clone` command
2. Compile the program using `make` command
3. Launch the executable with `./philo n_philosophers time_to_die time_to_eat time_to_sleep [n_times_each_philosopher_must_eat]` (the last argument is optional)

~~~ THE ROUTINE AND RULES OF THE PROGRAM ~~~

One or more philosophers are seated at a round table with a large bowl of spaghetti in the middle.  
There are also forks on the table, one between each philosophers.

**Routine** :
1. Philosophers take their right and their left forks to eat, one in each hand.   
2. When they finished eating, they put their forks back on the table and start sleeping.   
3. Once awake, they start thinking again.

**Rules** :
- The philosophers alternatively **eat**, **think**, or **sleep**.   
- While they are eating, they are not thinking nor sleeping.   
- While they are thinking, they are not eating nor sleeping.   
- While they are sleeping, they are not eating nor thinking.   
- There are **as many forks as philosophers**.    
- The **simulation stops when a philosopher dies of starvation.**    
- Every philosopher **needs to eat** and **should never starve.**     
- **Philosophers don’t speak with each other.**     
- Philosophers don’t know if another philosopher is about to die.     
    
