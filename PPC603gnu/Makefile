# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
PRJ_ROOT_DIR := C:/Users/Tanner/Desktop/FRC\ C++/Chimichanga
WS_ROOT_DIR := C:/Users/Tanner/Desktop/FRC\ C++



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = Chimichanga/$(MODE_DIR)/Chimichanga.out \
	 Chimichanga_partialImage/$(MODE_DIR)/Chimichanga_partialImage.o


#Rules

# Chimichanga
ifeq ($(DEBUG_MODE),1)
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Chimichanga/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
Chimichanga/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Chimichanga/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
Chimichanga/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Chimichanga/$(MODE_DIR)/% : DEFINES = 
Chimichanga/$(MODE_DIR)/% : EXPAND_DBG = 0
Chimichanga/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Chimichanga/$(MODE_DIR)/% : CPU = PPC603
Chimichanga/$(MODE_DIR)/% : TOOL_FAMILY = gnu
Chimichanga/$(MODE_DIR)/% : TOOL = gnu
Chimichanga/$(MODE_DIR)/% : TOOL_PATH = 
Chimichanga/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
Chimichanga/$(MODE_DIR)/% : LIBPATH = 
Chimichanga/$(MODE_DIR)/% : LIBS = 
Chimichanga/$(MODE_DIR)/% : OBJ_DIR := Chimichanga/$(MODE_DIR)

OBJECTS_Chimichanga = Chimichanga_partialImage/$(MODE_DIR)/Chimichanga_partialImage.o

Chimichanga/$(MODE_DIR)/Chimichanga.out : $(OBJECTS_Chimichanga)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_Chimichanga) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_Chimichanga) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Chimichanga/$(MODE_DIR)/Chimichanga_compile_file : $(FILE) ;

_clean :: Chimichanga/$(MODE_DIR)/Chimichanga_clean

Chimichanga/$(MODE_DIR)/Chimichanga_clean : 
	$(TRACE_FLAG)if [ -d "Chimichanga" ]; then cd "Chimichanga"; rm -rf $(MODE_DIR); fi


# Chimichanga_partialImage
ifeq ($(DEBUG_MODE),1)
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Chimichanga_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
Chimichanga_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Chimichanga_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
Chimichanga_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Chimichanga_partialImage/$(MODE_DIR)/% : DEFINES = 
Chimichanga_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
Chimichanga_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Chimichanga_partialImage/$(MODE_DIR)/% : CPU = PPC603
Chimichanga_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
Chimichanga_partialImage/$(MODE_DIR)/% : TOOL = gnu
Chimichanga_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
Chimichanga_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
Chimichanga_partialImage/$(MODE_DIR)/% : LIBPATH = 
Chimichanga_partialImage/$(MODE_DIR)/% : LIBS = 
Chimichanga_partialImage/$(MODE_DIR)/% : OBJ_DIR := Chimichanga_partialImage/$(MODE_DIR)

Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/Chimichanga.o : C:/Users/Tanner/Desktop/FRC\ C++/Chimichanga/Chimichanga.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/DistanceEncoder.o : C:/Users/Tanner/Desktop/FRC\ C++/Chimichanga/DistanceEncoder.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/Kicker.o : C:/Users/Tanner/Desktop/FRC\ C++/Chimichanga/Kicker.cpp
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_Chimichanga_partialImage = Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/Chimichanga.o \
	 Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/DistanceEncoder.o \
	 Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/Kicker.o

Chimichanga_partialImage/$(MODE_DIR)/Chimichanga_partialImage.o : $(OBJECTS_Chimichanga_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_Chimichanga_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Chimichanga_partialImage/$(MODE_DIR)/Chimichanga_partialImage_compile_file : $(FILE) ;

_clean :: Chimichanga_partialImage/$(MODE_DIR)/Chimichanga_partialImage_clean

Chimichanga_partialImage/$(MODE_DIR)/Chimichanga_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "Chimichanga_partialImage" ]; then cd "Chimichanga_partialImage"; rm -rf $(MODE_DIR); fi

DEP_FILES := Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/Chimichanga.d Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/DistanceEncoder.d Chimichanga_partialImage/$(MODE_DIR)/Objects/Chimichanga/Kicker.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
