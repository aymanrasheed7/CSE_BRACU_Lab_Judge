#include<bits/extc++.h>
using namespace std;
int main(int argc, char** argv) {
    string OLD = R"d(
lll test = 0, batch = 0, TLM = 0;
DWORD TLE = 9, errorCode = 0;
double best = 0, score = 0;
mt19937_64 RNG;
chrono::system_clock::time_point start, finish;
string TID, UID, LNG, CMD, word, content, CMT;)d";
    string NEW = R"d(
lll TLM = 0, test = 0, batch = 0;
DWORD TLE = 9, errorCode = 0;
double best = 0, score = 0;
mt19937_64 RNG;
chrono::system_clock::time_point start, finish;
string TID, UID, LNG, CMD, CMT, word, content;)d";
    string content;
    getline(ifstream(argv[1]), content, '\0');
    for (size_t i = 0; (i = content.find(OLD, i)) != string::npos;)
        content.replace(i, OLD.size(), NEW), i += NEW.size();
    (ofstream(argv[1]) << content).close();
    exit(0);
}