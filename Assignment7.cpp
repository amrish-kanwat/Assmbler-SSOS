#include <unistd.h>
#include <iostream>
#include <fstream>
#include <signal.h>

using namespace std;

string userInput; // Variable to store user input

// Function to be called when Ctrl+C (SIGINT) is sent to the process
void handleSignal(int signum) {
    string filename;
    cout << "\nDo you want to save the text to a file? Press Y for Yes or N for No: ";
    char choice;
    cin >> choice;

    if (choice == 'Y' || choice == 'y') {
        cout << "Enter a file name: ";
        cin >> filename;

        ofstream outputFile(filename, ios::out); // Open file for writing

        if (outputFile.is_open()) {
            // Write content to the file
            outputFile << userInput;

            // Close the file when done
            outputFile.close();

            cout << "File saving completed";
        } else {
            cout << "Error: Unable to create file '" << filename << "'.\n";
        }
    }
}

int main() {
    // Register signal and signal handler
    signal(SIGINT, handleSignal);

    cout << "Enter text (Ctrl+C to save and exit):\n";

    // Read user input into the global variable
    getline(cin, userInput);

    // Pause to keep the program running
    sleep(1000);

    return 0;
}

/*

Enter text (Ctrl+C to save and exit):
Myself Devraj Gurjar From MBM UB NIVERSITY JODHPUR

Do you want to save the text to a file? Press Y for Yes or N for No: Y
Enter a file name: INTRO.txt
File saving completed.

*/