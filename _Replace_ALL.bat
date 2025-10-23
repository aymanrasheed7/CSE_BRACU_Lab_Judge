c++ ReplaceALL.cpp
for /r %%a in (_*.cpp) do .\a.exe %%a
del /f /q .\a.exe
pause