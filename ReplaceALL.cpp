#include<bits/extc++.h>
using namespace std;
int main(int argc, char** argv) {
    string OLD = R"d(base = 257, mod = 65537;)d";
    string NEW = R"d(base = 257, mod = 2147483647;)d";
    string content;
    getline(ifstream(argv[1]), content, '\0');
    for (size_t i = 0; (i = content.find(OLD, i)) != string::npos;)
        content.replace(i, OLD.size(), NEW), i += NEW.size();
    (ofstream(argv[1]) << content).close();
    exit(0);
}