#include<bits/extc++.h>
using namespace std;
int main(int argc, char** argv) {
    string OLD = R"d(outputHash)d";
    string NEW = R"d(oHash)d";
    string content;
    getline(ifstream(argv[1]), content, '\0');
    for (size_t i = 0; (i = content.find(OLD, i)) != string::npos;)
        content.replace(i, OLD.size(), NEW), cout << (i += NEW.size()) << endl;
    (ofstream(argv[1]) << content).close();
    exit(0);
}