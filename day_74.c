//Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

#define MAX 1000   // adjust as needed

typedef struct {
    char name[100];
    int count;
} Candidate;

int findIndex(Candidate arr[], int size, const char* name) {
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].name, name) == 0) return i;
    }
    return -1;
}

const char* winner(char votes[][100], int n) {
    Candidate candidates[MAX];
    int size = 0;

    // Count votes
    for (int i = 0; i < n; i++) {
        int idx = findIndex(candidates, size, votes[i]);
        if (idx == -1) {
            strcpy(candidates[size].name, votes[i]);
            candidates[size].count = 1;
            size++;
        } else {
            candidates[idx].count++;
        }
    }

    // Find max votes
    int maxVotes = 0;
    char* winnerName = candidates[0].name;
    for (int i = 0; i < size; i++) {
        if (candidates[i].count > maxVotes) {
            maxVotes = candidates[i].count;
            winnerName = candidates[i].name;
        } else if (candidates[i].count == maxVotes) {
            if (strcmp(candidates[i].name, winnerName) < 0) {
                winnerName = candidates[i].name;
            }
        }
    }

    return winnerName;
}

int main() {
    char votes[6][100] = {"john","john","paul","paul","george","john"};
    int n = 6;

    printf("Winner: %s\n", winner(votes, n)); // Output: john
    return 0;
}