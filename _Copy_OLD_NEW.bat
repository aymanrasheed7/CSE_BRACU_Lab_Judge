set /p OLD="Enter OLD: "
set /p NEW="Enter NEW: "
md _%NEW%
for %%a in ("_%OLD%\*") do copy /v /y %%a _%NEW%\
for %%a in ("_%NEW%\*") do (
    powershell -Command "(Get-Content '%%a' -Raw) -replace '_%OLD%', '_%NEW%' | Out-File '%%a' -NoNewline -Encoding utf8NoBOM"
    call set "NME=%%~nxa"
    call ren "%%a" "%%NME:_%OLD%=_%NEW%%%"
)
pause