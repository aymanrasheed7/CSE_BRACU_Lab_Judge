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
lll cpp = 2000, java = 3000, py = 6000, nBatch = 10, tn9 = 1000000000;
double weight[] = { 0, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1, 0.1 };
lll nTest[] = { 0, 2, 2, 20, 20, 20, 20000, 2000, 200, 20, 2 };
lll maxNM[] = { 0, 10, 10, 10, 100, 1000, 50, 500, 5000, 50000, 500000 };
lll maxAiBi[] = { 0, 100, 100, 100, tn9, tn9, tn9, tn9, tn9, tn9, tn9 };
lll outputHash[] = { 0, 37476, 38759, 18014, 11865, 9430,
    13694, 4023, 48266, 18711, 53502 };
vector<string> OutputC;
vector<lll> InputN, InputM, InputK;
vector<vector<lll>> InputA, InputB;
inline lll getRandInt(lll low, lll high) {
    return uniform_int_distribution<lll>(low, high)(RNG);
}
inline void prepareInput() {
    if (batch == 1) {
        InputN = { 3, 4 };
        InputM = { 6, 4 };
        InputK = { 8, 5 };
        InputA = { {2, 10, 12}, {1, 3, 5, 7} };
        InputB = { {3, 4, 6, 7, 8, 9}, {2, 2, 4, 8} };
    }
    else if (batch == 2) {
        InputN = { 7, 4 };
        InputM = { 9, 1 };
        InputK = { 15, 2 };
        InputA = { {2, 3, 8, 8, 10, 12, 14}, {1, 2, 3, 4} };
        InputB = { {1, 1, 4, 5, 6, 8, 13, 15, 16}, {10} };
    }
    else {
        InputN.resize(nTest[batch]);
        InputM.resize(nTest[batch]);
        InputK.resize(nTest[batch]);
        InputA.resize(nTest[batch]);
        InputB.resize(nTest[batch]);
        for (test = 0; test < nTest[batch]; ++test) {
            lll N = InputN[test] = getRandInt(1, maxNM[batch]);
            lll M = InputM[test] = getRandInt(1, maxNM[batch]);
            lll K = InputK[test] = getRandInt(1, N + M);
            InputA[test].resize(N);
            InputB[test].resize(M);
            for (lll i = 0; i < N; ++i)
                InputA[test][i] = getRandInt(1, maxAiBi[batch]);
            for (lll i = 0; i < M; ++i)
                InputB[test][i] = getRandInt(1, maxAiBi[batch]);
            sort(InputA[test].begin(), InputA[test].end());
            sort(InputB[test].begin(), InputB[test].end());
        }
    }
    ofstream fout(inp);
    for (fout << nTest[batch] << "\n", test = 0; test < nTest[batch]; ++test) {
        fout << InputN[test] << " " <<
            InputM[test] << " " << InputK[test] << "\n";
        for (lll i = 0; i < InputN[test]; ++i)
            fout << InputA[test][i] << (i + 1 < InputN[test] ? " " : "\n");
        for (lll i = 0; i < InputM[test]; ++i)
            fout << InputB[test][i] << (i + 1 < InputM[test] ? " " : "\n");
    }
    fout.close();
}
lll base = 257, mod = 2147483647;
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
        OutputC.clear();
        for (ifstream fin(out); fin >> word; OutputC.push_back(word));
        assertThrow(getHash(OutputC) == outputHash[batch]);
        // cout << getHash(OutputC) << endl;
        // system("pause");
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