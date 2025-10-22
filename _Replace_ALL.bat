for /r %%a in (*Cleaner.bat) do start "%%~nxa" /min /d %%~dpa cmd /c %%a
c++ ReplaceALL.cpp
for /r %%a in (_*.cpp) do (
.\a.exe %%a
echo %%a
)
del /f /q .\a.exe
pause