@echo off
set TID=_A2A
@REM for %%a in ("%CD%") do set TID=%%~nxa
set SID=00000000
cmd /c .\%TID%_Cleaner.bat
for %%a in (cpp java py) do (
md %TID%\%%a\%TID%
copy /v /y Template.%%a %TID%\%%a\%TID%\Solution.%%a
copy /v /y %TID%_Checker_%%a.bat %TID%\%%a\%TID%\%TID%_Checker.bat
for %%b in (*) do echo %%b | findstr "Builder Checker Cleaner Solution Template" >nul || copy /v /y %%b %TID%\%%a\%TID%
)