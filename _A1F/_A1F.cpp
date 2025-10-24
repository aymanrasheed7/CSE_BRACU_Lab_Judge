#include<bits/extc++.h>
#include<windows.h>
using namespace std;
using lll = long long;
lll TLM = 0, test = 0, batch = 0;
DWORD TLE = 9, errorCode = 0;
double best = 0, score = 0;
mt19937_64 RNG;
chrono::system_clock::time_point start, finish;
string TID, UID, LNG, CMD, CMT, inp, out, word, content;
inline void runSolution() {
    PROCESS_INFORMATION processInfo;
    STARTUPINFOA startupInfo = { sizeof(STARTUPINFOA) };
    SECURITY_ATTRIBUTES securityAttr = {
        sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    HANDLE hInput = CreateFileA(inp.c_str(), GENERIC_READ, FILE_SHARE_READ,
        &securityAttr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE hOutput = CreateFileA(out.c_str(), GENERIC_WRITE, FILE_SHARE_WRITE,
        &securityAttr, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hInput == INVALID_HANDLE_VALUE || hOutput == INVALID_HANDLE_VALUE)
        return (void)(cout << "Failed to handle stdio\n", errorCode = -1);
    startupInfo.dwFlags |= STARTF_USESTDHANDLES;
    startupInfo.hStdInput = hInput, startupInfo.hStdOutput = hOutput;
    startupInfo.hStdError = GetStdHandle(STD_ERROR_HANDLE);
    HANDLE hJob = CreateJobObject(NULL, NULL);
    if (!hJob)
        return (void)(cout << "Failed to CreateJobObject()\n", errorCode = -1);
    if (!CreateProcessA(NULL, (LPSTR)CMD.c_str(), NULL, NULL, TRUE,
        CREATE_SUSPENDED, NULL, NULL, &startupInfo, &processInfo))
        return (void)(cout << "Failed to CreateProcessA()\n", errorCode = -1);
    if (!AssignProcessToJobObject(hJob, processInfo.hProcess)) {
        TerminateProcess(processInfo.hProcess, errorCode = -1);
        return (void)(cout << "Failed to AssignProcessToJobObject()\n");
    }
    ResumeThread(processInfo.hThread);
    if (WaitForSingleObject(processInfo.hProcess, TLM)
        != WAIT_OBJECT_0) TerminateJobObject(hJob, TLE);
    GetExitCodeProcess(processInfo.hProcess, &errorCode); CloseHandle(hInput);
    CloseHandle(hOutput); CloseHandle(processInfo.hThread);
    CloseHandle(processInfo.hProcess); CloseHandle(hJob);
}
inline void endBatch(string verdict) {
    if (verdict != "Accepted") errorCode = -1;
    cout << fixed << setprecision(9) << "Batch " << batch << " ended in " <<
        (chrono::duration_cast<chrono::nanoseconds>(finish - start).count()
            * 1e-9) << "s and the result is: " + verdict + "\n";
}
inline void updateSubmission() {
    system(("echo " + CMT + to_string(score) + " " + UID +
        " %COMPUTERNAME% %USERNAME%>" + TID + "_" + UID + "." + LNG).c_str());
    getline(ifstream("Solution." + LNG), content, '\0');
    (ofstream(TID + "_" + UID + "." + LNG, ios::app) << content).close();
    cout << "Submission updated: " << TID + "_" + UID + "." + LNG << endl;
}
inline void printScoreAndExit() {
    cout.unsetf(ios::fixed);
    if (best <= score) updateSubmission();
    cout << "\nTentative score = " << score << "/1\n\n", exit(0);
}
lll cpp = 1000, java = 2000, py = 2000, nBatch = 10, tn6 = 1000000;
double weight[] = { 0, 0.05, 0.05, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.2 };
lll nTest[] = { 0, 1, 1, 2, 100000, 25000, 4000, 1000, 250, 40, 10 };
lll maxN[] = { 0, 7, 14, 5, 10, 20, 50, 100, 200, 500, 1000 };
lll maxAi[] = { 0, 10, 100, tn6, tn6, tn6, tn6, tn6, tn6, tn6, tn6 };
vector<string> OutputBi;
vector<lll> InputN;
vector<vector<lll>> InputA;
inline lll getRandInt(lll low, lll high) {
    return uniform_int_distribution<lll>(low, high)(RNG);
}
inline void prepareInput() {
    if (batch == 1) {
        InputA = { {4, 2, 4, 7, 1, 6, 1} };
    }
    else if (batch == 2) {
        InputA = { {4, 8, 2, 9, 1, 5, 4, 6, 8, 1, 7, 13, 11, 8} };
    }
    else if (batch == 3) {
        InputA = { {3, 5, 9, 7, 1}, {221} };
    }
    else {
        InputN.resize(nTest[batch]);
        InputA.resize(nTest[batch]);
        for (test = 0; test < nTest[batch]; ++test) {
            InputN[test] = getRandInt(1, maxN[batch]);
            InputA[test].resize(InputN[test]);
            for (lll i = 0; i < InputN[test]; ++i)
                InputA[test][i] = getRandInt(1, maxAi[batch]);
        }
    }
    InputN.resize(nTest[batch] = InputA.size());
    for (test = 0; test < nTest[batch]; ++test)
        InputN[test] = InputA[test].size();
    ofstream fout(inp);
    for (fout << nTest[batch] << '\n', test = 0; test < nTest[batch]; ++test) {
        fout << InputN[test] << '\n' << InputA[test][0];
        for (lll i = 1; i < InputN[test]; ++i) fout << " " << InputA[test][i];
        fout << '\n';
    }
    fout.close();
}
inline void assertThrow(bool condition) {
    if (!condition) throw exception();
}
inline void validateOutput() {
    try {
        OutputBi.clear();
        for (ifstream fin(out); fin >> word; OutputBi.push_back(word))
            stoi(word);
        assertThrow(OutputBi.size() ==
            accumulate(InputN.begin(), InputN.end(), 0));
        lll k = 0;
        for (test = 0; test < nTest[batch]; ++test) {
            for (lll j = 0, i = 0; i < InputN[test];) {
                for (j = i; j < InputN[test] &&
                    (InputA[test][j] ^ InputA[test][i] ^ 1) & 1; ++j);
                sort(InputA[test].begin() + i, InputA[test].begin() + j);
                for (; i < j; ++i)
                    assertThrow(InputA[test][i] == stoi(OutputBi[k++]));
            }
        }
    }
    catch (...) {
        endBatch("WrongAnswer");
    }
}
int main(int argc, char** argv) {
    TID = argv[1], UID = argv[2], LNG = argv[3];
    if (LNG == "cpp") TLM = cpp, CMD = "b.exe";
    else if (LNG == "java") TLM = java, CMD = "java Solution";
    if (LNG != "py") CMT = "// ";
    else CMT = "## ", TLM = py, CMD = "pypy Solution.py";
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
    ifstream(TID + "_" + UID + "." + LNG).ignore(3) >> best;
    for (batch = score = 1; batch <= nBatch; score -= weight[batch++]);
    assert(abs(score) < 1e-9), score = 0;
    for (batch = 1; batch <= nBatch; errorCode = 0, ++batch) {
        RNG.seed(batch), cout << "Running on Batch " << batch << endl;
        inp = "inp" + to_string(batch) + ".txt";
        out = "out" + to_string(batch) + ".txt";
        prepareInput(), start = chrono::system_clock::now();
        runSolution(), finish = chrono::system_clock::now();
        if (errorCode == TLE) endBatch("TimeLimitExceeded");
        else if (errorCode) endBatch("RunTimeError");
        else if (validateOutput(), !errorCode && (endBatch("Accepted"),
            best <= (score += weight[batch]))) updateSubmission();
    }
    printScoreAndExit();
}