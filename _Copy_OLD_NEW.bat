for /r %%a in (*Cleaner.bat) do start "%%~nxa" /min /d %%~dpa cmd /c %%a
set /p OLD="OLD: "
set /p NEW="NEW: "
md _%NEW%
for %%a in ("_%OLD%\*") do copy /v /y %%a _%NEW%\
for %%a in ("_%NEW%\*") do (
powershell -Command "[System.IO.File]::WriteAllText('%%a', (Get-Content '%%a' -Raw).Replace('_%OLD%', '_%NEW%'), (New-Object System.Text.UTF8Encoding($false)))"
call set "NME=%%~nxa"
call ren "%%a" "%%NME:_%OLD%=_%NEW%%%"
)
pause