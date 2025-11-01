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
lll nTest[] = { 0, 2, 2, 10000, 400, 100 };
lll maxN[] = { 0, 5, 5, 10, 50, 100 };
lll maxW[] = { 0, 10, 100, 1000, 1000, 1000 };
lll outputHash[] = { 0, 12820, 16922, 9436, 62660, 58534 };
vector<string> OutputH;
vector<lll> InputN, InputM;
vector<vector<lll>> InputU, InputV, InputW;
vector<vector<vector<lll>>> InputAM, OutputAM;
inline lll getRandInt(lll low, lll high) {
    return uniform_int_distribution<lll>(low, high)(RNG);
}
inline void prepareInput() {
    if (batch == 1) {
        InputN = { 1, 4 };
        InputM = { 0, 5 };
        InputU = { {}, {4, 1, 4, 3, 3} };
        InputV = { {}, {3, 2, 2, 2, 1} };
        InputW = { {}, {4, 4, 10, 8, 5} };
    }
    else if (batch == 2) {
        InputN = { 2, 4 };
        InputM = { 1, 4 };
        InputU = { {1}, {3, 3, 2, 4} };
        InputV = { {2}, {2, 1, 1, 3} };
        InputW = { {30}, {9, 5, 8, 10} };
    }
    else {
        InputN.resize(nTest[batch]);
        InputM.resize(nTest[batch]);
        InputU.resize(nTest[batch]);
        InputV.resize(nTest[batch]);
        InputW.resize(nTest[batch]);
        for (test = 0; test < nTest[batch]; ++test) {
            InputU[test].clear(), InputV[test].clear(), InputW[test].clear();
            lll N = InputN[test] = getRandInt(1, maxN[batch]);
            lll K = N * N - N, M = getRandInt(0, K);
            for (lll i = 0; i < N; ++i)
                for (lll j = 0; j < N; ++j)
                    if (i != j && M < getRandInt(1, K))
                        InputU[test].push_back(i + 1),
                        InputV[test].push_back(j + 1),
                        InputW[test].push_back(getRandInt(1, maxW[batch]));
            InputM[test] = M = InputW[test].size();
            for (lll k = 3; k--;)
                for (lll i = 1, j; i < M; ++i)
                    j = getRandInt(0, i - 1),
                    swap(InputU[test][i], InputU[test][j]),
                    swap(InputV[test][i], InputV[test][j]),
                    swap(InputW[test][i], InputW[test][j]);
        }
    }
    ofstream fout(inp);
    InputAM.resize(nTest[batch]);
    OutputAM.resize(nTest[batch]);
    for (fout << nTest[batch] << "\n", test = 0; test < nTest[batch]; ++test) {
        fout << InputN[test] << " " << InputM[test] << "\n";
        InputAM[test] = OutputAM[test] = vector<vector<lll>>(InputN[test],
            vector<lll>(InputN[test], 0));
        if (!InputM[test]) fout << "\n\n\n";
        for (lll i = 0; i < InputM[test]; ++i)
            fout << InputU[test][i] << (i + 1 == InputM[test] ? "\n" : " ");
        for (lll i = 0; i < InputM[test]; ++i)
            fout << InputV[test][i] << (i + 1 == InputM[test] ? "\n" : " ");
        for (lll i = 0; i < InputM[test]; ++i)
            fout << InputW[test][i] << (i + 1 == InputM[test] ? "\n" : " ");
        for (lll i = 0; i < InputM[test]; ++i)
            InputAM[test][InputU[test][i] - 1][InputV[test][i] - 1]
            = InputW[test][i];
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
        char c;
        test = -1;
        lll u, v, w;
        OutputH.clear();
        for (ifstream fin(out); fin >> word;)
            if (word.back() == ':') {
                word.pop_back(), OutputH.push_back(word);
                if (word == "1") ++test, u = 0;
                assertThrow(word == to_string(++u));
            }
            else if (word[0] == '(' && word.back() == ')') {
                assertThrow(sscanf(word.c_str(), "(%d,%d)%c", &v, &w, &c) == 2);
                assertThrow(1 <= u && u <= OutputAM[test].size());
                assertThrow(1 <= v && v <= OutputAM[test][u - 1].size());
                OutputAM[test][u - 1][v - 1] = w, OutputH.push_back("0");
            }
            else assertThrow(0);
        assertThrow(InputAM == OutputAM);
        assertThrow(getHash(OutputH) == outputHash[batch]);
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