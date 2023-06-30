res.exe:hammImp.o hammApp.o
        c++ hammImp.o hammApp.o -o res.exe
hammImp.o:hammImp.c++
        c++ -c hammImp.o
hammApp.o:hammApp.c++
        c++ -c hammApp.o
