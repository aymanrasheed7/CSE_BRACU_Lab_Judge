c++ ReplaceALL.cpp
for /r %%a in (_*_Cleaner.bat) do .\a.exe %%a
del /f /q .\a.exe
pause