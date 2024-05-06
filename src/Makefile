CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -lstdc++ -std=c++17 -pedantic
TESTLIBS = -lgtest
OBJECTS = *.o
ALL_SOURCES = Project/Model/*.cc Project/Model/*.h Project/Controller/*.h Project/Controller/*.cc Project/View/*.cc Project/View/*.h Project/main.cc Tests/s21_smartcalcplus_tests.cc
SOURCES = Project/Model/Model.cc Project/Model/CreditModel.cc
TEST = Tests/s21_smartcalcplus_tests.cc

all: clean s21_smartcalc.a

s21_smartcalcplus.a: clean
	$(CC) $(CFLAGS) $(CPPFLAGS) $(SOURCES) -c
	ar rcs s21_smartcalcplus.a $(OBJECTS)
	rm $(OBJECTS)

tests: s21_smartcalcplus.a
	g++ $(TEST) s21_smartcalcplus.a $(CPPFLAGS) $(TESTLIBS) $(CFLAGS) -o testing
	./testing

leaks: s21_smartcalcplus.a
	g++ $(TEST) s21_smartcalcplus.a $(CPPFLAGS) $(TESTLIBS) $(CFLAGS) -o testing
	leaks --atExit -- ./testing

clean:
	rm -rf s21_smartcalcplus.a testing *.html *.gcda *.gcno gcov_test *.info report *.o *.dSYM *.css

style:
	cppcheck --language=c++ $(ALL_SOURCES) --force
	clang-format -n $(ALL_SOURCES) -style=google

install:
	qmake -o Executables/Makefile Project/calccpp.pro
	cd Executables && make

start:
	cd Executables/calccpp.app/Contents/MacOS && ./calccpp

proc_leaks:
	cd Executables/calccpp.app/Contents/MacOS && leaks -atExit -- ./calccpp

uninstall:
	cd Executables && make clean
	cd Executables && rm -rf Makefile qmake_qmake_qm_files.qrc calccpp.app .qm .qmake.stash

dist:
	cd .. && tar -czf s21_SmartCalc_v2.0.tgz src

dvi:
	open Manual.md

.PHONY: all s21_smartcalcplus.a tests leaks clean check install start uninstall dist dvi proc_leaks