#include <iostream>
#include <string>

using namespace std;

int artsVotes{0}, donationVotes{0}, innovationVotes{0}, musicVotes{0}, danceVotes{0};
int candidateVotes[4]{0}; // Array to keep track of candidate votes

void displayResults() {
    int maxVotes = 0;
    int winningCandidate = -1;

    for (int i = 0; i < 4; ++i) {
        if (candidateVotes[i] > maxVotes) {
            maxVotes = candidateVotes[i];
            winningCandidate = i + 1; // candidate numbers are 1-based
        }
    }

    cout << "********* Candidate " << winningCandidate << " wins the election! **************" << endl;
}

void recordVote(int candidate) {
    if (candidate >= 1 && candidate <= 4) {
        candidateVotes[candidate - 1] += 1;
    } else {
        cout << "Invalid candidate number!" << endl;
    }
}

void voteClub(int club) {
    cout << "Thank you for voting for ";
    switch(club) {
        case 1: cout << "ARTS CLUB"; artsVotes++; break;
        case 2: cout << "DONATION CLUB"; donationVotes++; break;
        case 3: cout << "INNOVATION CLUB"; innovationVotes++; break;
        case 4: cout << "MUSIC CLUB"; musicVotes++; break;
        case 5: cout << "DANCE CLUB"; danceVotes++; break;
        default: cout << "an invalid club"; return;
    }
    cout << "!" << endl;
    
    cout << "Please choose a candidate:" << endl;
    cout << "1) Candidate 1" << endl;
    cout << "2) Candidate 2" << endl;
    cout << "3) Candidate 3" << endl;
    cout << "4) Candidate 4" << endl;
    cout << "5) View results" << endl;

    int choice;
    cin >> choice;

    if (choice == 5) {
        displayResults();
    } else {
        recordVote(choice);
    }
}

int main() {
    string username;
    string password;

    while (true) {
        cout << "Enter your username: ";
        cin >> username;

        cout << "Enter your password (alphabetic characters only): ";
        cin >> password;

        cout << "Welcome to the Online Voting System!" << endl;
        cout << "Choose a club to vote for:" << endl;
        cout << "1) Arts Club" << endl;
        cout << "2) Donation Club" << endl;
        cout << "3) Innovation Club" << endl;
        cout << "4) Music Club" << endl;
        cout << "5) Dance Club" << endl;

        int clubChoice;
        cin >> clubChoice;

        if (clubChoice >= 1 && clubChoice <= 5) {
            voteClub(clubChoice);
        } else {
            cout << "Invalid club choice. Please select a number between 1 and 5." << endl;
        }

        char continueVoting;
        cout << "Would you like to vote again? (y/n): ";
        cin >> continueVoting;

        if (continueVoting != 'y' && continueVoting != 'Y') {
            break;
        }
    }

    return 0;
}
