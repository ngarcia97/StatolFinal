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
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/src/Adedigado.o \
	${OBJECTDIR}/src/Adresse.o \
	${OBJECTDIR}/src/Atelier.o \
	${OBJECTDIR}/src/C_BDD.o \
	${OBJECTDIR}/src/C_Capteur.o \
	${OBJECTDIR}/src/C_Consignes.o \
	${OBJECTDIR}/src/C_Informations.o \
	${OBJECTDIR}/src/Capteur.o \
	${OBJECTDIR}/src/Climat.o \
	${OBJECTDIR}/src/Consignes.o \
	${OBJECTDIR}/src/Incident.o \
	${OBJECTDIR}/src/Information.o \
	${OBJECTDIR}/src/NatureInfo.o \
	${OBJECTDIR}/src/ProtocoleCapteurs.o \
	${OBJECTDIR}/src/TClimat.o \
	${OBJECTDIR}/src/TestIntegration.o \
	${OBJECTDIR}/src/Unite.o \
	${OBJECTDIR}/src/main.o \
	${OBJECTDIR}/src/serialib.o \
	${OBJECTDIR}/src/test.o \
	${OBJECTDIR}/src/testIntegrationCapteurClimat.o \
	${OBJECTDIR}/src/testIntegrationCapteurs.o \
	${OBJECTDIR}/src/testIntegrationClimat.o \
	${OBJECTDIR}/src/testUnitaireCapteurs.o \
	${OBJECTDIR}/src/testUnitaireClimat.o


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
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/statol2018

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/statol2018: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/statol2018 ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/src/Adedigado.o: src/Adedigado.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Adedigado.o src/Adedigado.cpp

${OBJECTDIR}/src/Adresse.o: src/Adresse.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Adresse.o src/Adresse.cpp

${OBJECTDIR}/src/Atelier.o: src/Atelier.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Atelier.o src/Atelier.cpp

${OBJECTDIR}/src/C_BDD.o: src/C_BDD.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/C_BDD.o src/C_BDD.cpp

${OBJECTDIR}/src/C_Capteur.o: src/C_Capteur.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/C_Capteur.o src/C_Capteur.cpp

${OBJECTDIR}/src/C_Consignes.o: src/C_Consignes.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/C_Consignes.o src/C_Consignes.cpp

${OBJECTDIR}/src/C_Informations.o: src/C_Informations.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/C_Informations.o src/C_Informations.cpp

${OBJECTDIR}/src/Capteur.o: src/Capteur.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Capteur.o src/Capteur.cpp

${OBJECTDIR}/src/Climat.o: src/Climat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Climat.o src/Climat.cpp

${OBJECTDIR}/src/Consignes.o: src/Consignes.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Consignes.o src/Consignes.cpp

${OBJECTDIR}/src/Incident.o: src/Incident.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Incident.o src/Incident.cpp

${OBJECTDIR}/src/Information.o: src/Information.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Information.o src/Information.cpp

${OBJECTDIR}/src/NatureInfo.o: src/NatureInfo.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/NatureInfo.o src/NatureInfo.cpp

${OBJECTDIR}/src/ProtocoleCapteurs.o: src/ProtocoleCapteurs.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/ProtocoleCapteurs.o src/ProtocoleCapteurs.cpp

${OBJECTDIR}/src/TClimat.o: src/TClimat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TClimat.o src/TClimat.cpp

${OBJECTDIR}/src/TestIntegration.o: src/TestIntegration.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/TestIntegration.o src/TestIntegration.cpp

${OBJECTDIR}/src/Unite.o: src/Unite.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/Unite.o src/Unite.cpp

${OBJECTDIR}/src/main.o: src/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/main.o src/main.cpp

${OBJECTDIR}/src/serialib.o: src/serialib.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/serialib.o src/serialib.cpp

${OBJECTDIR}/src/test.o: src/test.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/test.o src/test.cpp

${OBJECTDIR}/src/testIntegrationCapteurClimat.o: src/testIntegrationCapteurClimat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/testIntegrationCapteurClimat.o src/testIntegrationCapteurClimat.cpp

${OBJECTDIR}/src/testIntegrationCapteurs.o: src/testIntegrationCapteurs.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/testIntegrationCapteurs.o src/testIntegrationCapteurs.cpp

${OBJECTDIR}/src/testIntegrationClimat.o: src/testIntegrationClimat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/testIntegrationClimat.o src/testIntegrationClimat.cpp

${OBJECTDIR}/src/testUnitaireCapteurs.o: src/testUnitaireCapteurs.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/testUnitaireCapteurs.o src/testUnitaireCapteurs.cpp

${OBJECTDIR}/src/testUnitaireClimat.o: src/testUnitaireClimat.cpp 
	${MKDIR} -p ${OBJECTDIR}/src
	${RM} "$@.d"
	$(COMPILE.cc) -O2 -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/src/testUnitaireClimat.o src/testUnitaireClimat.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/statol2018

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
