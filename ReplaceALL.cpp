#include<bits/extc++.h>
using namespace std;
int main(int argc, char** argv) {
    string OLD = R"d(
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%)d";
    string NEW = R"d(
del /f /q .\inp*
del /f /q .\out*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%)d";
    string content;
    getline(ifstream(argv[1]), content, '\0');
    for (size_t i = 0; (i = content.find(OLD, i)) != string::npos;)
        content.replace(i, OLD.size(), NEW), i += NEW.size();
    (ofstream(argv[1]) << content).close();
    exit(0);
}