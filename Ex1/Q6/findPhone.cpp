#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <name>\n";
        return 1;
    }

    string name;
        for(int i = 1; i<argc; i++){
        name += argv[i];
        name += " ";
    }
    name.pop_back();

    // Pipes for inter-process communication
    int pipe1[2];
    int pipe2[2];
    pipe(pipe1);
    pipe(pipe2);

    // Fork first child process for grep
    pid_t pid1 = fork();
    if (pid1 == 0) {
        // Redirect stdout to pipe1 write end
        dup2(pipe1[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        execlp("grep", "grep", ("\\b" + name + "\\b").c_str(), "phonebook.txt", NULL);
        perror("grep");
        return 1;
    }

    // Fork second child process for sed
    pid_t pid2 = fork();
    if (pid2 == 0) {
        // Redirect stdin from pipe1 read end
        dup2(pipe1[0], STDIN_FILENO);
        // Redirect stdout to pipe2 write end
        dup2(pipe2[1], STDOUT_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("sed", "sed", "s/ /#/g; s/,/ /", NULL);
        perror("sed");
        return 1;
    }

    // Fork third child process for awk
    pid_t pid3 = fork();
    if (pid3 == 0) {
        // Redirect stdin from pipe2 read end
        dup2(pipe2[0], STDIN_FILENO);
        close(pipe1[0]);
        close(pipe1[1]);
        close(pipe2[0]);
        close(pipe2[1]);
        execlp("awk", "awk", "{print $2}", NULL);
        perror("awk");
        return 1;
    }

    // Close pipes in parent process
    close(pipe1[0]);
    close(pipe1[1]);
    close(pipe2[0]);
    close(pipe2[1]);

    // Wait for all child processes to finish
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
    waitpid(pid3, NULL, 0);

    return 0;
}
