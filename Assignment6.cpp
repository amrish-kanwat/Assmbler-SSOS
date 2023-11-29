#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main()
{
    int sum = 0;
    int count;
    int fd[2];

    // crteate a pipe
    pipe(fd);

    cout << "Insert a number: ";
    cin >> count;
    for (int i = 0; i < count; i++)
    {
        // create a child process
        pid_t pid = fork();
        if (pid == 0)
        {
            // user input and write it to the pipe
            int num;
            cout << "Enter the number: ";
            cin >> num;
            write(fd[1], &num, sizeof(num));
            exit(0);
            //exit child process
        }
        else
        {
            // wait for child process to finish
            wait(NULL);

            // read from the pipe
            int num;
            read(fd[0], &num, sizeof(num));
            sum += num;
        }
    }

    // print the sum
    cout << "Sum: " << sum << endl;
    return 0;
}