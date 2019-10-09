TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        main.cpp \
    md5calculate.cpp

HEADERS += \
    md5calculate.h

#write to /etc/environment or
#export TBB_ROOT=/opt/intel/compilers_and_libraries/linux/tbb
#export PSTL_ROOT=/opt/intel/compilers_and_libraries/linux/pstl
#write to ~/.profile or
#export LD_LIBRARY_PATH="${TBB_ROOT}/lib/intel64/gcc4.7:${LD_LIBRARY_PATH:-}"

#unix:INCLUDEPATH += /usr/include
unix:INCLUDEPATH += $$(TBB_ROOT)/include \
                    $$(PSTL_ROOT)/include

unix:LIBS = -L$$(TBB_ROOT)/lib/intel64/gcc4.7 -ltbb
