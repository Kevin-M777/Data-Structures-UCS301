#include <iostream>
#include <queue>
#include <string>
using namespace std;

void firstNonRepeating(string stream) {
    queue<char> q;
    int freq[256] = {0};   // storing count for each character
    for (char ch : stream) {
        freq[(unsigned char)ch]++; //to ensure that range of 0 to 255 is used , typecasting has been done
        q.push(ch);
        while (!q.empty() && freq[(unsigned char)q.front()] > 1) 
        { //removes repeating characters from front
            q.pop();
        }
        if(q.empty())cout<<-1<<" ";
        else cout<<q.front()<<" ";
            
    }
}

int main() {
    string input = "aabc";   
    firstNonRepeating(input);
    return 0;
}
