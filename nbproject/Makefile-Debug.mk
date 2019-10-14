#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=GNU-Linux
CND_DLIB_EXT=so
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Server.o \
	${OBJECTDIR}/TextException.o \
	${OBJECTDIR}/bipropellant-hoverboard-api/src/HoverboardAPI.o \
	${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/ascii_protocol.o \
	${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/machine_protocol.o \
	${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/protocol.o \
	${OBJECTDIR}/bipropellant-hoverboard-api/src/protocolFunctions.o \
	${OBJECTDIR}/main.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=-Llibwebsockets/build/lib -lwebsockets

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hoverbotd

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hoverbotd: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/hoverbotd ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/Server.o: Server.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibwebsockets/build/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/Server.o Server.cpp

${OBJECTDIR}/TextException.o: TextException.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibwebsockets/build/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/TextException.o TextException.cpp

${OBJECTDIR}/bipropellant-hoverboard-api/src/HoverboardAPI.o: bipropellant-hoverboard-api/src/HoverboardAPI.cpp
	${MKDIR} -p ${OBJECTDIR}/bipropellant-hoverboard-api/src
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibwebsockets/build/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bipropellant-hoverboard-api/src/HoverboardAPI.o bipropellant-hoverboard-api/src/HoverboardAPI.cpp

${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/ascii_protocol.o: bipropellant-hoverboard-api/src/hbprotocol/ascii_protocol.c
	${MKDIR} -p ${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol
	${RM} "$@.d"
	$(COMPILE.c) -g -Ilibwebsockets/build/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/ascii_protocol.o bipropellant-hoverboard-api/src/hbprotocol/ascii_protocol.c

${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/machine_protocol.o: bipropellant-hoverboard-api/src/hbprotocol/machine_protocol.c
	${MKDIR} -p ${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol
	${RM} "$@.d"
	$(COMPILE.c) -g -Ilibwebsockets/build/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/machine_protocol.o bipropellant-hoverboard-api/src/hbprotocol/machine_protocol.c

${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/protocol.o: bipropellant-hoverboard-api/src/hbprotocol/protocol.c
	${MKDIR} -p ${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol
	${RM} "$@.d"
	$(COMPILE.c) -g -Ilibwebsockets/build/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bipropellant-hoverboard-api/src/hbprotocol/protocol.o bipropellant-hoverboard-api/src/hbprotocol/protocol.c

${OBJECTDIR}/bipropellant-hoverboard-api/src/protocolFunctions.o: bipropellant-hoverboard-api/src/protocolFunctions.c
	${MKDIR} -p ${OBJECTDIR}/bipropellant-hoverboard-api/src
	${RM} "$@.d"
	$(COMPILE.c) -g -Ilibwebsockets/build/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bipropellant-hoverboard-api/src/protocolFunctions.o bipropellant-hoverboard-api/src/protocolFunctions.c

${OBJECTDIR}/main.o: main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -Ilibwebsockets/build/include -std=c++11 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
