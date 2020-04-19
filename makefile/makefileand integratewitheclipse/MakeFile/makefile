include config.mk

allObjs = $(allSrcs:.c=.o)
allDeps = $(allSrcs:.c=.d)

$(FinalTargetName) : CFLAG = 
$(allObjs): CFLAG = -c
$(allDeps): CFLAG = -MM

$(FinalTargetName) : $(allObjs)
	cmd /C progress.bat
	cmd /C progress.py 13
	$(CC) $(CFLAG) $^ -o $@ 

$(allObjs) : %.o : %.c 
	cmd /C progress.bat
	cmd /C progress.py 13
	$(CC) $(CFLAG) $< -o $@ 

$(allDeps) : %.d : %.c | Dependencies
	$(CC) $(CFLAG) $< -o $@
	cmd /C progress.bat
	cmd /C progress.py 13
	@copy /y $@ Dependencies\
	

Dependencies:
	
	@mkdir $@

.PHONY: clean link onlyCompile depend all

clean: 
	DEL /Q $(FinalTargetName) $(allObjs) $(allDeps) Dependencies\*
	rmdir Dependencies
	DEL /Q progress.txt

link: 
	$(CC) $(CFLAG) $(allObjs) -o $(FinalTargetName)

onlyCompile: $(allObjs)

depend: $(allDeps)

all: $(allDeps) 
	$(MAKE) $(FinalTargetName)

