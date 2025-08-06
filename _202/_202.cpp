#include<bits/extc++.h>
#include<windows.h>
using namespace std;
mt19937 rng;
chrono::system_clock::time_point start, finish;
int test = 0, best = 0, score = 0, batch = 0, total = 0, timeLimit = 0;
string TID, UID, LNG, comment, content, word;
DWORD TLE = 9, errorCode = 0;
char cmd[64];
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
    if (!CreateProcessA(NULL, cmd, NULL, NULL, TRUE,
        CREATE_SUSPENDED, NULL, NULL, &startupInfo, &processInfo))
        return (void)(cout << "Failed to CreateProcessA()\n", errorCode = -1);
    if (!AssignProcessToJobObject(hJob, processInfo.hProcess)) {
        TerminateProcess(processInfo.hProcess, errorCode = -1);
        return (void)(cout << "Failed to AssignProcessToJobObject()\n");
    }
    ResumeThread(processInfo.hThread);
    if (WaitForSingleObject(processInfo.hProcess, timeLimit)
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
    system(("echo " + comment + to_string(score) + " " + UID +
        " %COMPUTERNAME% %USERNAME%>" + TID + "_" + UID + "." + LNG).c_str());
    getline(ifstream("Solution." + LNG), content, '\0');
    (ofstream(TID + "_" + UID + "." + LNG, ios::app) << content).close();
    cout << "Submission updated: " << TID + "_" + UID + "." + LNG << endl;
}
inline void printScoreAndExit() {
    cout << "\nTentative score = " << double(score) / max(total, 1) << "/1\n\n";
    exit(0);
}
int cpp = 2000, java = 3000, py = 6000, nBatch = 10;
int weight[] = { 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
int nTest[] = { 0, 2, 2, 20, 20, 2, 20000, 2000, 200, 20, 2 };
int maxNML[] = { 0, 100, 100, 100, 500, 5000, 50, 500, 5000, 50000, 500000 };
int maxAiBiCi[] = { 0, 100, 100, 100, 1000, 10000,
    100000, 1000000, 10000000, 100000000, 1000000000 };
int outputHash[] = { 0, 37476, 38759, 12873, 59476, 1269,
    60082, 54879, 30523, 59127, 17816 };
vector<string> OutputA;
vector<int> InputN, InputM, InputL, InputK;
vector<vector<int>> InputA, InputB, InputC;
inline int getRandInt(int low, int high) {
    return uniform_int_distribution<int>(low, high)(rng);
}
inline void prepareInput() {
    if (batch == 1) {
        InputN = { 3, 4 };
        InputM = { 6, 4 };
        InputL = { 2, 2 };
        InputK = { 8, 5 };
        InputA = { {2, 10, 12}, {1, 3, 5, 7} };
        InputB = { {3, 4, 6, 7, 8, 9}, {2, 2, 4, 8} };
        InputC = { {11, 12}, {5, 5} };
    }
    else if (batch == 2) {
        InputN = { 7, 4 };
        InputM = { 9, 1 };
        InputL = { 4, 5 };
        InputK = { 15, 2 };
        InputA = { {2, 3, 8, 8, 10, 12, 14}, {1, 2, 3, 4} };
        InputB = { {1, 1, 4, 5, 6, 8, 13, 15, 16}, {10} };
        InputC = { {15, 15, 16, 16}, {2, 2, 2, 2, 2} };
    }
    else {
        InputN.resize(nTest[batch]);
        InputM.resize(nTest[batch]);
        InputL.resize(nTest[batch]);
        InputK.resize(nTest[batch]);
        InputA.resize(nTest[batch]);
        InputB.resize(nTest[batch]);
        InputC.resize(nTest[batch]);
        for (test = 0; test < nTest[batch]; ++test) {
            int& N = InputN[test] = getRandInt(1, maxNML[batch] - 2);
            int& M = InputM[test] = getRandInt(1, maxNML[batch] - 1 - N);
            int& L = InputL[test] = getRandInt(1, maxNML[batch] - N - M);
            if (getRandInt(0, 1) & 1) swap(N, M);
            if (getRandInt(0, 1) & 1) swap(M, L);
            if (getRandInt(0, 1) & 1) swap(L, N);
            int K = InputK[test] = getRandInt(1, N + M + L);
            InputA[test].resize(N);
            InputB[test].resize(M);
            InputC[test].resize(L);
            for (int i = 0; i < N; ++i)
                InputA[test][i] = getRandInt(1, maxAiBiCi[batch]);
            for (int i = 0; i < M; ++i)
                InputB[test][i] = getRandInt(1, maxAiBiCi[batch]);
            for (int i = 0; i < L; ++i)
                InputC[test][i] = getRandInt(1, maxAiBiCi[batch]);
            sort(InputA[test].begin(), InputA[test].end());
            sort(InputB[test].begin(), InputB[test].end());
            sort(InputC[test].begin(), InputC[test].end());
        }
    }
    ofstream fout("in.txt");
    for (fout << nTest[batch] << "\n", test = 0; test < nTest[batch]; ++test) {
        fout << InputN[test] << " " << InputM[test] <<
            " " << InputL[test] << " " << InputK[test] << "\n";
        for (int i = 0; i < InputN[test]; ++i)
            fout << InputA[test][i] << (i + 1 < InputN[test] ? " " : "\n");
        for (int i = 0; i < InputM[test]; ++i)
            fout << InputB[test][i] << (i + 1 < InputM[test] ? " " : "\n");
        for (int i = 0; i < InputL[test]; ++i)
            fout << InputC[test][i] << (i + 1 < InputL[test] ? " " : "\n");
    }
    fout.close();
}
int base = 257, mod = 65537;
inline int getHash(string str, int ret = 0) {
    for (auto& c : str) ret = (ret * base + int(c)) % mod;
    return ret;
}
inline int getHash(vector<string> vec, int ret = 0) {
    for (auto& str : vec) ret = (ret * base + getHash(str)) % mod;
    return ret;
}
inline void assertThrow(bool condition) {
    if (!condition) throw exception();
}
inline void validateOutput() {
    try {
        OutputA.clear();
        for (ifstream fin("out.txt"); fin >> word; OutputA.push_back(word));
        assertThrow(getHash(OutputA) == outputHash[batch]);
        // cout << getHash(OutputA) << endl;
    }
    catch (...) {
        endBatch("WrongAnswer");
    }
}
int main(int argc, char** argv) {
    TID = argv[1], UID = argv[2], LNG = argv[3];
    if (LNG == "cpp") timeLimit = cpp, strcpy(cmd, "b.exe");
    else if (LNG == "java") timeLimit = java, strcpy(cmd, "java Solution");
    if (LNG != "py") comment = "// ";
    else comment = "## ", timeLimit = py, strcpy(cmd, "pypy Solution.py");
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
    for (batch = 1; batch <= nBatch; errorCode = 0, total += weight[batch++]) {
        rng.seed(batch), cout << "Running on Batch " << batch << endl;
        prepareInput(), start = chrono::system_clock::now();
        runSolution(), finish = chrono::system_clock::now();
        if (errorCode == TLE) endBatch("TimeLimitExceeded");
        else if (errorCode) endBatch("RunTimeError");
        else if (validateOutput(), !errorCode && (endBatch("Accepted"),
            best <= (score += weight[batch]))) updateSubmission();
    }
    cout.unsetf(ios::fixed), printScoreAndExit();
}