set /p OLD="Enter OLD: "
set /p NEW="Enter NEW: "
rd /s /q _%NEW%
md _%NEW%
for %%a in ("_%OLD%\*") do copy /v /y %%a _%NEW%\
setlocal enabledelayedexpansion
for %%a in ("_%NEW%\*") do (
    powershell -Command "(Get-Content '%%a' -Raw) -replace '_%OLD%', '_%NEW%' | Out-File '%%a' -NoNewline"
    set "NME=%%~nxa"
    ren "%%a" "!NME:_%OLD%=_%NEW%!"
)
pause