@echo off
set TID=_A1G
@REM for %%a in ("%CD%") do set TID=%%~nxa
del /f /s /q /a .\RunTimeError.txt
del /f /s /q /a .\TimeLimitExceeded.txt
del /f /s /q /a .\WrongAnswer.txt
del /f /s /q /a .\_A1G_0*
del /f /s /q /a .\_A1G_1*
del /f /s /q /a .\_A1G_2*
del /f /s /q /a .\out.txt
del /f /s /q /a .\in.txt
del /f /s /q /a .\*.exe
del /f /s /q /a .\*.class
del /f /s /q /a .\*.log
rd /s /q __pycache__
rd /s /q %TID%
