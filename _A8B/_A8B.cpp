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
lll cpp = 1000, java = 1500, py = 3000, nBatch = 5;
double weight[] = { 0, 0.1, 0.1, 0.2, 0.3, 0.3 };
lll nTest[] = { 0, 2, 2, 5000, 50, 5 };
lll maxN[] = { 0, 10, 10, 20, 2000, 40000 };
lll maxM[] = { 0, 10, 10, 30, 3000, 60000 };
lll maxW[] = { 0, 10, 10, 100, 10000, 1000000 };
lll oHash[] = { 0, 3261895, 27296, 729116734, 1835616784, 1304418507 };
vector<string> OutputH;
vector<lll> InputN, InputM, InputD;
vector<vector<lll>> InputU, InputV, InputW;
vector<set<pair<lll, lll>>> InputE;
inline lll getRandInt(lll low, lll high) {
    return uniform_int_distribution<lll>(low, high)(RNG);
}
lll frt(lll x) {
    return InputD[x] < 0 ? x : InputD[x] = frt(InputD[x]);
}
inline lll uni(lll x, lll y) {
    if (x = frt(x), y = frt(y), x == y) return 0;
    if (InputD[x] < InputD[y]) swap(x, y);
    return InputD[y] += InputD[x], InputD[x] = y;
}
inline void prepareInput() {
    InputE.clear(), InputE.resize(nTest[batch]);
    if (batch == 1) {
        InputN = { 4, 6 };
        InputM = { 3, 5 };
        InputU = { {3, 3, 2}, {2, 2, 2, 6, 5} };
        InputV = { {4, 1, 1}, {6, 3, 1, 5, 4} };
        InputW = { {5, 5, 2}, {3, 3, 4, 1, 2} };
    }
    else if (batch == 2) {
        InputN = { 2, 5 };
        InputM = { 1, 7 };
        InputU = { {1}, {1, 1, 1, 2, 2, 4, 3} };
        InputV = { {2}, {2, 4, 5, 4, 3, 3, 5} };
        InputW = { {9}, {8, 3, 4, 8, 5, 4, 5} };
    }
    else {
        InputN.resize(nTest[batch]);
        InputM.resize(nTest[batch]);
        InputU.resize(nTest[batch]);
        InputV.resize(nTest[batch]);
        InputW.resize(nTest[batch]);
        for (test = 0; test < nTest[batch]; ++test) {
            lll u, v, w, & N = InputN[test], & M = InputM[test];
            N = getRandInt(2, maxN[batch]);
            M = getRandInt(1, min(N * N - N >> 1, maxM[batch]));
            InputD.clear(), InputD.resize(N + 1, -1);
            InputU[test].resize(M), InputV[test].resize(M);
            for (InputW[test].resize(M), w = M; w--;) {
                u = getRandInt(1, N), v = getRandInt(1, N);
                if (u == v || InputE[test].find(make_pair(u, v))
                    != InputE[test].end()) ++w;
                else InputU[test][w] = u, InputV[test][w] = v, uni(u, v),
                    InputW[test][w] = getRandInt(1, maxW[batch]),
                    InputE[test].insert(make_pair(u, v)),
                    InputE[test].insert(make_pair(v, u));
            }
            for (v = 2; v <= N; ++v) if (uni(u = v - 1, v)) ++M,
                InputU[test].push_back(u), InputV[test].push_back(v),
                InputW[test].push_back(getRandInt(1, maxW[batch])),
                InputE[test].insert(make_pair(u, v)),
                InputE[test].insert(make_pair(v, u));
        }
    }
    lll m = 1;
    for (auto e : InputE) m &= e.empty();
    if (m)
        for (test = 0; test < nTest[batch]; ++test)
            for (lll w = InputM[test]; w--; InputE[test].insert(make_pair(
                InputU[test][w], InputV[test][w])), InputE[test].insert(
                    make_pair(InputV[test][w], InputU[test][w])));
    ofstream fout(inp);
    for (fout << nTest[batch] << "\n", test = 0; test < nTest[batch]; ++test) {
        fout << InputN[test] << " " << InputM[test] << "\n";
        for (lll i = 0; i < InputM[test]; ++i) fout << InputU[test][i]
            << " " << InputV[test][i] << " " << InputW[test][i] << "\n";
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
        OutputH.clear();
        for (ifstream fin(out); fin >> word; OutputH.push_back(word));
        assertThrow(getHash(OutputH) == oHash[batch]);
        // cout << ", " << getHash(OutputH) << endl;
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
    ifstream(TID + "_" + UID + "." + LNG).ignore(3) >> best;
    getline(ifstream("Solution." + LNG), content, '\0');
    for (char& c : content) c = tolower(c);
    for (ifstream fin(TID + "_Forbidden.txt"); fin >> word;)
        if (content.find(word) != string::npos)
            cout << "ForbiddenKeyword: " << word << "\n", printScoreAndExit();
    if ((LNG == "cpp" && system("c++ Solution.cpp -o b.exe")) ||
        (LNG == "java" && system("javac Solution.java")) ||
        (LNG == "py" && system("pypy -m py_compile Solution.py")))
        cout << "CompilationError\n", printScoreAndExit();
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