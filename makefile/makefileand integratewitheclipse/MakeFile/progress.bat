@echo Off

SETLOCAL EnableDelayedExpansion

if not exist progress.txt ( ECHO 1 > progress.txt 
) else (
	for /f %%i in ( progress.txt
	) do (
		set str=%%i
		set /A str=!str!+1
		echo !str! > progress.txt
	    )
)

exit 