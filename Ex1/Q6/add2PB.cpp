#include <iostream>
#include <string>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <name>,<phone_number>\n";
        return 1;
    }
    string line;
    for(int i = 1; i<argc; i++){
        line += argv[i];
        line += " ";
    }
    line.pop_back();
    string sed_command = "sed -i '$a\\" + line + "' phonebook.txt";
    execlp("sh", "sh", "-c", sed_command.c_str(), NULL);
    perror("execlp");
    return 1;
}
