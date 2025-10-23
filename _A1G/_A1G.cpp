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
lll cpp = 1000, java = 2000, py = 2000, nBatch = 5;
lll weight[] = { 0, 1, 1, 2, 3, 3 };
lll nTest[] = { 0, 1, 2, 100, 100, 10 };
lll maxN[] = { 0, 7, 5, 10, 100, 1000 };
lll maxAi[] = { 0, 10, 10, 1000, 1000, 1000 };
lll maxBi[] = { 0, 100, 100, 1000, 1000, 1000 };
lll hsh[] = { 0, 31283, 18490, 27804, 47097, 36270 };
vector<string> OutputCi;
vector<lll> InputN;
vector<vector<lll>> InputA, InputB;
inline lll getRandInt(lll low, lll high) {
    return uniform_int_distribution<lll>(low, high)(RNG);
}
inline void prepareInput() {
    if (batch == 1) {
        InputA = { {7, 4, 9, 3, 2, 5, 1} };
        InputB = { {40, 50, 50, 20, 10, 10, 10} };
    }
    else if (batch == 2) {
        InputA = { {7, 2, 5, 3}, {1} };
        InputB = { {80, 60, 80, 50}, {1} };
    }
    else {
        InputN.resize(nTest[batch]);
        InputA.resize(nTest[batch]);
        InputB.resize(nTest[batch]);
        for (test = 0; test < nTest[batch]; ++test) {
            InputN[test] = getRandInt(1, maxN[batch]);
            InputA[test].resize(InputN[test]);
            InputB[test].resize(InputN[test]);
            for (lll i = 0, N = InputN[test]; i < N; ++i)
                InputA[test][i] = i + 1 + maxAi[batch] - N,
                InputB[test][i] = getRandInt(1, maxBi[batch]);
            shuffle(InputA[test].begin(), InputA[test].end(), RNG);
        }
    }
    InputN.resize(nTest[batch] = InputA.size());
    for (test = 0; test < nTest[batch]; ++test)
        InputN[test] = InputA[test].size();
    ofstream fout("in.txt");
    for (fout << nTest[batch] << "\n", test = 0; test < nTest[batch]; ++test) {
        fout << InputN[test] << "\n";
        for (lll i = 0; i < InputN[test]; ++i)
            fout << InputA[test][i] << (i + 1 < InputN[test] ? " " : "\n");
        for (lll i = 0; i < InputN[test]; ++i)
            fout << InputB[test][i] << (i + 1 < InputN[test] ? " " : "\n");
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
        OutputCi.clear();
        for (ifstream fin("out.txt"); fin >> word; OutputCi.push_back(word));
        assertThrow(getHash(OutputCi) == hsh[batch]);
        // cout << getHash(OutputCi) << endl;
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