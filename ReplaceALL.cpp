#include<bits/extc++.h>
using namespace std;
int main(int argc, char** argv) {
    string OLD = R"d(
    if (!ifstream(TID + "_" + UID + "." + LNG)) updateSubmission();
    getline(ifstream("Solution." + LNG), content, '\0');
    for (char& c : content) c = tolower(c);
    for (ifstream fin(TID + "_Forbidden.txt"); fin >> word;)
        if (content.find(word) != string::npos)
            cout << "ForbiddenKeyword: " << word << "\n", printScoreAndExit();
    if ((LNG == "cpp" && system("c++ Solution.cpp -o b.exe")) ||
        (LNG == "java" && system("javac Solution.java")) ||
        (LNG == "py" && system("pypy -m py_compile Solution.py")))
        cout << "CompilationError\n", printScoreAndExit();
    ifstream(TID + "_" + UID + "." + LNG).ignore(3) >> best;)d";
    string NEW = R"d(
    if (!ifstream(TID + "_" + UID + "." + LNG)) updateSubmission();
    ifstream(TID + "_" + UID + "." + LNG).ignore(3) >> best;
    getline(ifstream("Solution." + LNG), content, '\0');
    for (char& c : content) c = tolower(c);
    for (ifstream fin(TID + "_Forbidden.txt"); fin >> word;)
        if (content.find(word) != string::npos)
            cout << "ForbiddenKeyword: " << word << "\n", printScoreAndExit();
    if ((LNG == "cpp" && system("c++ Solution.cpp -o b.exe")) ||
        (LNG == "java" && system("javac Solution.java")) ||
        (LNG == "py" && system("pypy -m py_compile Solution.py")))
        cout << "CompilationError\n", printScoreAndExit();)d";
    string content;
    getline(ifstream(argv[1]), content, '\0');
    for (size_t i = 0; (i = content.find(OLD, i)) != string::npos;)
        content.replace(i, OLD.size(), NEW), i += NEW.size();
    (ofstream(argv[1]) << content).close();
    exit(0);
}