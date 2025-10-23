#include<bits/extc++.h>
using namespace std;
int main(int argc, char** argv) {
    string OLD = R"d(
    for (batch = 1; batch <= nBatch; score += weight[batch++]);
    assert(score = 1), score = 0;
    for (batch = 1; batch <= nBatch; errorCode = 0, ++batch) {)d";
    string NEW = R"d(
    for (batch = score = 1; batch <= nBatch; score -= weight[batch++]);
    for (assert(!score), batch = 1; batch <= nBatch; errorCode = 0, ++batch) {)d";
    string content;
    getline(ifstream(argv[1]), content, '\0');
    for (size_t i = 0; (i = content.find(OLD, i)) != string::npos;)
        content.replace(i, OLD.size(), NEW), i += NEW.size();
    (ofstream(argv[1]) << content).close();
    exit(0);
}