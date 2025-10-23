#include<bits/extc++.h>
using namespace std;
int main(int argc, char** argv) {
    string OLD = R"d(
mt19937_64 rng;
chrono::system_clock::time_point start, finish;
string TID, UID, LNG, comment, content, word, cmd;
lll test = 0, batch = 0, timeLimit = 0;
DWORD TLE = 9, errorCode = 0;
double best = 0, score = 0;)d";
    string NEW = R"d(
lll test = 0, batch = 0, timeLimit = 0;
DWORD TLE = 9, errorCode = 0;
double best = 0, score = 0;
mt19937_64 rng;
chrono::system_clock::time_point start, finish;
string TID, UID, LNG, cmd, word, content, comment;)d";
    string content;
    getline(ifstream(argv[1]), content, '\0');
    for (size_t i = 0; (i = content.find(OLD, i)) != string::npos;)
        content.replace(i, OLD.size(), NEW), i += NEW.size();
    (ofstream(argv[1]) << content).close();
    exit(0);
}