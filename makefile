# Compilation Settings
CINC = -I ./include
CDEF = -DDSTR_DEBUG
CFLAGS = -Wall
COPT = ${CFLAGS} ${CDEF} ${CINC}
CC = gcc ${COPT}


# Targets
DIR = ./build
HDR = ./include/Dstr.h ./include/Limb.h
OBJ = ${DIR}/Dstr.o ${DIR}/Limb.o
TOBJ = ${DIR}/testDstr.o ${DIR}/testLimb.o
TEXE = ${DIR}/testDstr.x ${DIR}/testLimb.x



############### BUILD RULES ###############

all: ${DIR} ${OBJ}



${DIR}:
	mkdir -p ${DIR}



${DIR}/Dstr.o: src/Dstr.c ${HDR}
	${CC} -c -o $@ $<



${DIR}/Limb.o: src/Limb.c include/Limb.h
	${CC} -c -o $@ $<


clean:
	@echo
	@echo "cleaning build directory"
	rm -rf ${OBJ}
	rm -rf ${TOBJ} ${TEXE}
	@echo



############### TEST SUITE ###############

test: ${DIR} ${TEXE}
	@echo
	@echo "running Dstring tests:"
	@echo
	@./${DIR}/testDstr.x
	@echo
	@./${DIR}/testLimb.x
	@echo



${DIR}/testDstr.x: ${DIR}/testDstr.o ${OBJ}
	${CC} -o $@ $^



${DIR}/testLimb.x: ${DIR}/testLimb.o ${DIR}/Limb.o
	${CC} -o $@ $^



${DIR}/testDstr.o: test/testDstr.c test/test.h include/Dstr.h
	${CC} -c -o $@ $<



${DIR}/testLimb.o: test/testLimb.c test/test.h include/Limb.h
	${CC} -c -o $@ $<





