@echo off
set TID=_602
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /q .\_602_0*
del /f /q .\_602_1*
del /f /q .\_602_2*
del /f /q .\inp*
del /f /q .\out*
del /f /q .\*.exe
del /f /q .\*.class
rd /s /q __pycache__
rd /s /q %TID%