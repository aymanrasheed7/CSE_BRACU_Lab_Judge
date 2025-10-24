c++ ReplaceALL.cpp
for /r %%a in (_*_Instruction.txt) do .\a.exe %%a %%~nxa
del /f /q .\a.exe
pause