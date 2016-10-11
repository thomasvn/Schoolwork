// -------------------- Programming Task One (one.c) --------------------
Goal:
    - Create our own shell by instantiating a child process

How It Works:
    1. All the code is inside a while loop that is always true
        - You can only exit the while loop by typing in "exit"
    2. Read a command (string) from the user
    3. Create a new process by using the function fork();
        - If the process is the child, use the function execve(); to transform
        the calling process into a new process (running the executable file)
        - If the process is the parent, use the function waitpid(); to wait
        for the child to terminate first

How I Tested My Solution:
    1. gcc -o hello hello.c
    2. gcc -o one one.c
    3. ./one

    Once after running the executable, I should be prompted for a command which
    would create a new process. To test, run "./hello" executable and check to
    make sure we receive the correct output. Test the command "exit" to see if
    this returns from the process.


// -------------------- Programming Task Two (two.c) --------------------
Goal:
    - Create 16 child processes
    - No process can create more than 2 child processes

How It Works:
    1. Iterate through a For-Loop 16 times
    2. On each iteration, call the function fork(); to create a child process
    3. After having forked a child process. Check to see whether we are looking
    at the child process or the parent process
        - If the parent process, terminate.
        - If the child process, print out statements then continue iteration.

How I Tested My Solution:
    1. gcc -o two two.c
    2. ./two

    Every time there is a forked process, I ensured that it would print a
    statement about itself. This includes which iteration we are in at the
    for-loop. I made sure that for each of the 16 iterations, there was one
    child.


// -------------------- Programming Task Three (three.c) --------------------
Goal:
    - Create 19 child processes
    - Any given process can only create 0, 2, or 3 children

How It Works:
    1. Iterate through a For-Loop 9 times
    2. Fork child1 if:
        - This is the first iteration
        - The current process is child2
    3. Print out statements about child1 then terminate child1
    3. Fork child2 if the current process is the parent of child1
    4. If the process is the parent of both child1 AND child2 ... terminate
    5. Print out statements about child2 and let this lone process iterate
    through the code again in the for-loop

Edge Case:
    1. On the very last iteration, the parent needs to make three children
    instead of the normal two in order to achieve 19 children

How I Tested My Solution:
    1. gcc -o three three.c
    2 ./three

    Every time there is a forked process, I ensured that it would print a
    statement about itself. This includes which iteration we are in at the
    for-loop. For each of the 9 iterations, there are either two or three
    children that are printed to the screen. I made sure that each iteration
    number had two children and the last iteration had three. That would amount
    to 19 child processes
