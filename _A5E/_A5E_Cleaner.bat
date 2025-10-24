@echo off
set TID=_A5E
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_A5E_0*
del /f /q .\_A5E_1*
del /f /q .\_A5E_2*
del /f /q .\inp*
del /f /q .\out*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%