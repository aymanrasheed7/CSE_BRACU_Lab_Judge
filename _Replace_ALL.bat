for /r %%a in (*Cleaner.bat) do start "%%~nxa" /min /d %%~dpa cmd /c %%a
set /p OLD="OLD: "
set /p NEW="NEW: "
set /p ALL="ALL: "
for /r %%a in (%ALL%) do (
powershell -Command "[System.IO.File]::WriteAllText('%%a', (Get-Content '%%a' -Raw).Replace('%OLD%', ('%NEW%' -replace '\\n', \"`n\")), (New-Object System.Text.UTF8Encoding($false)))"
)
pause