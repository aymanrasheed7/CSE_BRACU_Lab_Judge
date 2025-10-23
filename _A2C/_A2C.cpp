#include<bits/extc++.h>
#include<windows.h>
using namespace std;
using lll = long long;
lll TLM = 0, test = 0, batch = 0;
DWORD TLE = 9, errorCode = 0;
double best = 0, score = 0;
mt19937_64 RNG;
chrono::system_clock::time_point start, finish;
string TID, UID, LNG, CMD, CMT, word, content;
inline void runSolution() {
    PROCESS_INFORMATION processInfo;
    STARTUPINFOA startupInfo = { sizeof(STARTUPINFOA) };
    SECURITY_ATTRIBUTES securityAttr = {
        sizeof(SECURITY_ATTRIBUTES), NULL, TRUE };
    HANDLE hInput = CreateFileA("in.txt", GENERIC_READ, FILE_SHARE_READ,
        &securityAttr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    HANDLE hOutput = CreateFileA("out.txt", GENERIC_WRITE, FILE_SHARE_WRITE,
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
    if ((errorCode = verdict != "Accepted") &&
        ifstream(verdict + ".txt").peek() == ifstream::traits_type::eof()) {
        getline(ifstream("in.txt"), content, '\0');
        (ofstream(verdict + ".txt") << content).close();
    }
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
    if (best <= score) updateSubmission();
    cout << "\nTentative score = " << score << "/1\n\n";
    exit(0);
}
lll cpp = 2000, java = 3000, py = 6000, nBatch = 10, tn9 = 1000000000;
lll weight[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
lll nTest[] = { 0, 2, 2, 20, 2, 200, 20, 2000, 2, 200, 20000 };
lll maxN[] = { 0, 10, 10, 50, 500, 50, 500, 50, 5000, 500, 50 };
lll maxS[] = { 0, 10, 100, 1000, 10000, 100000,
    1000000, 10000000, 100000000, tn9, tn9 };
lll maxAi[] = { 0, 10, 100, 1000, 10000, 100000,
    1000000, 10000000, 100000000, tn9, tn9 };
lll outputHash[] = { 0, 7469, 7469, 6067, 7469, 57751,
    20949, 21208, 61770, 57375, 47854 };
vector<string> OutputC, OutputD;
vector<lll> InputN, InputS;
vector<vector<lll>> InputA;
inline lll getRandInt(lll low, lll high) {
    return uniform_int_distribution<lll>(low, high)(RNG);
}
inline void prepareInput() {
    if (batch == 1) {
        InputN = { 7, 3 };
        InputS = { 3, 5 };
        InputA = { {2, 1, 1, 2, 2, 1, 1}, {1, 3, 2} };
    }
    else if (batch == 2) {
        InputN = { 6, 4 };
        InputS = { 18, 10 };
        InputA = { {1, 5, 8, 9, 9, 10}, {1, 5, 6, 8} };
    }
    else {
        InputN.resize(nTest[batch]);
        InputS.resize(nTest[batch]);
        InputA.resize(nTest[batch]);
        for (test = 0; test < nTest[batch]; ++test) {
            lll N = InputN[test] = getRandInt(1, maxN[batch]);
            InputS[test] = getRandInt(1, maxS[batch]);
            InputA[test].resize(InputN[test]);
            for (lll i = 0; i < N; ++i)
                InputA[test][i] = getRandInt(1, maxAi[batch]);
            if (getRandInt(0, 1) & 1) {
                lll i = getRandInt(0, N - 1),
                    j = getRandInt(0, N - 1),
                    k = getRandInt(0, N - 1);
                if (i != j && j != k && k != i) InputS[test] =
                    InputA[test][i] + InputA[test][j] + InputA[test][k];
            }
        }
    }
    ofstream fout("in.txt");
    for (fout << nTest[batch] << "\n", test = 0; test < nTest[batch]; ++test) {
        fout << InputN[test] << " " << InputS[test] << "\n";
        for (lll i = 0; i < InputN[test]; ++i)
            fout << InputA[test][i] << (i + 1 < InputN[test] ? " " : "\n");
    }
    fout.close();
}
lll base = 257, mod = 65537;
inline lll getHash(string str, lll ret = 0) {
    for (auto& c : str) ret = (ret * base + lll(c)) % mod;
    return ret;
}
inline lll getHash(vector<string> vec, lll ret = 0) {
    for (auto& str : vec) ret = (ret * base + getHash(str)) % mod;
    return ret;
}
inline void assertThrow(bool condition) {
    if (!condition) throw exception();
}
inline void validateOutput() {
    try {
        OutputC.clear(), OutputD.clear();
        for (ifstream fin("out.txt"); fin >> word; OutputC.push_back(word))
            if (word == "-1") OutputD.push_back("-1");
            else OutputD.push_back("0");
        assertThrow(getHash(OutputD) == outputHash[batch]);
        // cout << getHash(OutputD) << endl;
        // system("pause");
        for (lll k = test = 0; test < nTest[batch]; ++k, ++test)
            if (OutputC[k] != "-1") assertThrow(InputS[test]
                == InputA[test][stoi(OutputC[k]) - 1] +
                InputA[test][stoi(OutputC[k + 1]) - 1] +
                InputA[test][stoi(OutputC[k + 2]) - 1]), k += 2;
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
    for (string& s : vector<string>({ "RunTimeError",
        "TimeLimitExceeded", "WrongAnswer" })) ofstream(s + ".txt").close();
    ifstream(TID + "_" + UID + "." + LNG).ignore(3) >> best;
    for (batch = 1; batch <= nBatch; errorCode = 0, ++batch) {
        RNG.seed(batch), cout << "Running on Batch " << batch << endl;
        prepareInput(), start = chrono::system_clock::now();
        runSolution(), finish = chrono::system_clock::now();
        if (errorCode == TLE) endBatch("TimeLimitExceeded");
        else if (errorCode) endBatch("RunTimeError");
        else if (validateOutput(), !errorCode && (endBatch("Accepted"),
            best <= (score += weight[batch]))) updateSubmission();
    }
    cout.unsetf(ios::fixed), printScoreAndExit();
}