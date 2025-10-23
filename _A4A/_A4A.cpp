#include<bits/extc++.h>
#include<windows.h>
using namespace std;
using lll = long long;
lll test = 0, batch = 0, timeLimit = 0;
DWORD TLE = 9, errorCode = 0;
double best = 0, score = 0;
mt19937_64 rng;
chrono::system_clock::time_point start, finish;
string TID, UID, LNG, cmd, word, content, comment;
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
    if (!CreateProcessA(NULL, (LPSTR)cmd.c_str(), NULL, NULL, TRUE,
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
    if (best <= score) updateSubmission();
    cout << "\nTentative score = " << score << "/1\n\n";
    exit(0);
}
lll cpp = 1000, java = 1500, py = 3000, nBatch = 5;
lll weight[] = { 0, 1, 1, 2, 3, 3 };
lll nTest[] = { 0, 2, 2, 2500, 400, 100 };
lll maxN[] = { 0, 10, 10, 20, 50, 100 };
lll maxW[] = { 0, 10, 10, 100, 1000, 1000 };
lll outputHash[] = { 0, 49405, 54098, 6616, 10377, 62908 };
vector<string> OutputH;
vector<lll> InputN, InputM;
vector<vector<lll>> InputU, InputV, InputW;
inline lll getRandInt(lll low, lll high) {
    return uniform_int_distribution<lll>(low, high)(rng);
}
inline void prepareInput() {
    if (batch == 1) {
        InputN = { 6, 4 };
        InputM = { 7, 5 };
        InputU = { {1, 6, 1, 3, 4, 5, 6}, {4, 1, 4, 3, 3} };
        InputV = { {5, 3, 3, 4, 6, 6, 1}, {3, 2, 2, 2, 1} };
        InputW = { {6, 5, 9, 7, 1, 8, 6}, {4, 4, 10, 8, 5} };
    }
    else if (batch == 2) {
        InputN = { 4, 4 };
        InputM = { 3, 4 };
        InputU = { {1, 3, 1}, {3, 3, 2, 4} };
        InputV = { {3, 2, 4}, {2, 1, 1, 3} };
        InputW = { {8, 5, 2}, {9, 5, 8, 10} };
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
    ofstream fout("in.txt");
    for (fout << nTest[batch] << "\n", test = 0; test < nTest[batch]; ++test) {
        fout << InputN[test] << " " << InputM[test] << "\n";
        for (lll i = 0; i < InputM[test]; ++i) fout << InputU[test][i]
            << " " << InputV[test][i] << " " << InputW[test][i] << "\n";
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
        OutputH.clear();
        for (ifstream fin("out.txt"); fin >> word; OutputH.push_back(word));
        assertThrow(getHash(OutputH) == outputHash[batch]);
        // cout << getHash(OutputH) << endl;
        // system("pause");
    }
    catch (...) {
        endBatch("WrongAnswer");
    }
}
int main(int argc, char** argv) {
    TID = argv[1], UID = argv[2], LNG = argv[3];
    if (LNG == "cpp") timeLimit = cpp, cmd = "b.exe";
    else if (LNG == "java") timeLimit = java, cmd = "java Solution";
    if (LNG != "py") comment = "// ";
    else comment = "## ", timeLimit = py, cmd = "pypy Solution.py";
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