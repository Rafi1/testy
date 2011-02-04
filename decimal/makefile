################################################################################
#przykladowy makefile - nie uzywany
################################################################################
SOURCES= decContext.c decDouble.c decimal128.c decimal32.c decimal64.c decNumber.c decPacked.c decQuad.c decSingle.c
OBJECTS= ${SOURCES:.c=.o}
INCSOURCES= decBasic.c decCommon.c 
HEADERS= decDouble.h decimal128.h decDPD.h decNumber.h decimal32.h decimal64.h decQuad.h decContext.h decPacked.h decSingle.h decNumberLocal.h
MYHEADERS= Decimal
EX_SOURC= example1.c example2.c example3.c example4.c example5.c example6.c example7.c example8.c
NUMLIBPREFIX= decimal
NUMLIB= lib${NUMLIBPREFIX}.a
DESTLIBDIR=${INSTALL_PREFIX}/lib
DESTINCDIR=${INSTALL_PREFIX}/include/${NUMLIBPREFIX}
################################################################################
all: ${OBJECTS} myTest

install: ${NUMLIB}
	test -d "${DESTLIBDIR}" || mkdir -p ${DESTLIBDIR}
	cp ${NUMLIB} ${DESTLIBDIR}
	test -d "${DESTINCDIR}" || mkdir -p ${DESTINCDIR}
	cp ${HEADERS} ${DESTINCDIR}
	cp ${MYHEADERS} ${DESTINCDIR}

${NUMLIB}: ${OBJECTS}
	ar crus ${NUMLIB} ${OBJECTS}

myTest: myTest.o ${NUMLIB}
	g++ myTest.o ${NUMLIB} -o myTest

example1: example1.o
	cc example1.o ${OBJECTS} -o example1

${OBJECTS}:${SOURCES}
################################################################################
