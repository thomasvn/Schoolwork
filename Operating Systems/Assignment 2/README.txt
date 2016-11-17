-------------------- Task 1 (main.c) --------------------
Goal:
    - Find the source file that prints the copyright message when MINIX boots
    - Make a personal edit to the MINIX startup banner

Solution:
    ** Note that the main.c that was turned in is an abridged version of the
       entire file found in MINIX **
    - In main.c, locate the announce function that is used to display the
      startup banner
    - Create a print statement where appropriate to print out a personalized
      statement for the MINIX startup banner

Testing:
    - Make sure that you have a local version of main.c as a backup
        - Set up FTP between the two machines and run the "get" command on
          your local machine to retrieve a local copy of the file in your VM
    - Make sure that the path of working directory is /usr/src/
    - Run "Make World" to let the makefile compile the OS
    - Reboot the MINIX VM


-------------------- Task 2 (proc.c) --------------------
Goal:
    - Find the function that contains the process scheduling algorithm
    - Alter the process scheduling algorithm to randomly select lower priority
      processes
    - Ensure that the OS does not cease to function

Description of Current Minix Scheduler:
    - We are looking at the function pick_proc in proc.c
    - How it works:
        1. Iterate over schedule queues
        2. Pick the head of the next priority queue that is ready
        3. Initialize and configure the kernel trace subsystem for that process
        4. Continue iterating over schedule queues


Solution:
    ** Note that the proc.c that was turned in is an abridged version of the
       entire file found in MINIX **
    - Before we proceed with step #2 specified above, we need to randomize the
      process that is chosen
    - If the process index is greater than 6 (low priority), randomize the index
      to be a number between 7-15
    - Save the index, so that we can return to this process index in the
      iteration after we complete TRACE

Testing:
    - Make sure that you have a local version of main.c as a backup
        - Set up FTP between the two machines and run the "get" command on
          your local machine to retrieve a local copy of the file in your VM
    - Make sure that the path of working directory is /usr/src/
    - Run "Make World" to let the makefile compile the OS
    - Reboot the MINIX VM

Alternative Testing:
    - How I WOULD test my code even if it's impractical
    - Understanding that the expected impact of randomizing low priority
      processes should be a slowing of the OS operations.
    - We can more properly test this hypothesis by randomizing the lowest 2
      processes, then slowly incrementing the lowest 3, then the lowest 4, and
      so on until we have randomized the 7th - 15th process.
    - By doing so, we can more effectively visualize the effects we are making
      on the OS by randomizing the process scheduling algorithm
