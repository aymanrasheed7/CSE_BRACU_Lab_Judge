@echo off
set TID=_402
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_402_0*
del /f /q .\_402_1*
del /f /q .\_402_2*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%