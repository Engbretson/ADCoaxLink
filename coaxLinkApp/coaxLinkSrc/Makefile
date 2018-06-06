TOP=../..
include $(TOP)/configure/CONFIG
#----------------------------------------
#  ADD MACRO DEFINITIONS AFTER THIS LINE

#======== DETECTOR LIBRARY ==============

# The following gets rid of the -fno-implicit-templates flag on vxWorks, 
# so we get automatic template instantiation.
# This is what we want for miscellaneous/asynPortDriver.cpp
ifeq (vxWorks,$(findstring vxWorks, $(T_A)))
CODE_CXXFLAGS=
endif

INC += coaxLink.h
#INC += NDFileRaw.h

LIBRARY_IOC = coaxLink
LIB_SRCS += coaxLink.cpp
#LIB_SRCS += NDFileRaw.cpp

DBD += coaxLinkSupport.dbd
#DBD += NDFileRaw.dbd

#LIB_LIBS  += FileRawPlugin
#DIRS += $(ADRAWPFILEPLUGIN)/App

include $(ADCORE)/ADApp/commonLibraryMakefile

#=============================

include $(TOP)/configure/RULES
#----------------------------------------
#  ADD RULES AFTER THIS LINE

