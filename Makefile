TITLE := GTA VI - PATCH DOWNLOADED
VERSION := 1.00
TITLE_ID := GTAD00001
CONTENT_ID := IV0000-GTAD00001_00-GTAVIPATCHDOWNLD

TOOLCHAIN := $(OO_PS4_TOOLCHAIN)
PROJDIR := app
COMMONDIR := $(TOOLCHAIN)/samples/_common
INTDIR := $(PROJDIR)/x64/Debug

CXXFILES := $(wildcard $(PROJDIR)/*.cpp)
OBJS := $(patsubst $(PROJDIR)/%.cpp,$(INTDIR)/%.o,$(CXXFILES))
COMMONOBJ := $(INTDIR)/graphics.o

CCX := clang++
LD := ld.lld

CXXFLAGS := --target=x86_64-pc-freebsd12-elf -fPIC -funwind-tables -c -isysroot $(TOOLCHAIN) -isystem $(TOOLCHAIN)/include -isystem $(TOOLCHAIN)/include/c++/v1 -I$(COMMONDIR)
LDFLAGS := -m elf_x86_64 -pie --script $(TOOLCHAIN)/link.x --eh-frame-hdr -L$(TOOLCHAIN)/lib -lc -lkernel -lc++ -lSceVideoOut -lScePad -lSceSysmodule $(TOOLCHAIN)/lib/crt1.o

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
  CDIR := linux
else ifeq ($(UNAME_S),Darwin)
  CDIR := macos
else
  $(error OpenOrbis Makefile currently supports Linux and macOS hosts)
endif

.PHONY: all clean
all: $(CONTENT_ID).pkg

$(INTDIR):
	mkdir -p $(INTDIR)

$(INTDIR)/%.o: $(PROJDIR)/%.cpp | $(INTDIR)
	$(CCX) $(CXXFLAGS) -o $@ $<

$(COMMONOBJ): $(COMMONDIR)/graphics.cpp $(COMMONDIR)/graphics.h $(COMMONDIR)/log.h | $(INTDIR)
	$(CCX) $(CXXFLAGS) -I$(COMMONDIR) -o $@ $(COMMONDIR)/graphics.cpp

eboot.bin: $(OBJS) $(COMMONOBJ)
	$(LD) $(OBJS) $(COMMONOBJ) -o $(INTDIR)/app.elf $(LDFLAGS)
	$(TOOLCHAIN)/bin/$(CDIR)/create-fself -in=$(INTDIR)/app.elf -out=$(INTDIR)/app.oelf --eboot "eboot.bin" --paid 0x3800000000000011

sce_sys/param.sfo:
	mkdir -p sce_sys/about
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core sfo_new $@
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core sfo_setentry $@ APP_TYPE --type Integer --maxsize 4 --value 1
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core sfo_setentry $@ APP_VER --type Utf8 --maxsize 8 --value '$(VERSION)'
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core sfo_setentry $@ CATEGORY --type Utf8 --maxsize 4 --value 'gd'
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core sfo_setentry $@ CONTENT_ID --type Utf8 --maxsize 48 --value '$(CONTENT_ID)'
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core sfo_setentry $@ TITLE --type Utf8 --maxsize 128 --value '$(TITLE)'
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core sfo_setentry $@ TITLE_ID --type Utf8 --maxsize 12 --value '$(TITLE_ID)'
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core sfo_setentry $@ VERSION --type Utf8 --maxsize 8 --value '$(VERSION)'

$(CONTENT_ID).pkg: eboot.bin sce_sys/param.sfo sce_sys/icon0.png
	$(TOOLCHAIN)/bin/$(CDIR)/create-gp4 -out pkg.gp4 --content-id=$(CONTENT_ID) --files "$^"
	$(TOOLCHAIN)/bin/$(CDIR)/PkgTool.Core pkg_build pkg.gp4 .

clean:
	rm -rf $(INTDIR) eboot.bin pkg.gp4 pkg sce_sys/param.sfo $(CONTENT_ID).pkg
