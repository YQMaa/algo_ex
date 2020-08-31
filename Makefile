
# Copyright (C) 2015 Tudor Berariu <tudor.berariu@gmail.com>

# Permission is hereby granted, free of charge, to any person
# obtaining a copy of this software and associated documentation
# files (the “Software”), to deal in the Software without
# restriction, including without limitation the rights to use, copy,
# modify, merge, publish, distribute, sublicense, and/or sell copies
# of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS
# BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN
# ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
# CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
# SOFTWARE.

SHELL := /bin/sh

# compile options
CC := clang #cc
CCFLAGS := -Wall -std=c++0x
LIBS := -lm
LIBSTD := -lstdc++

LIBGUI :=
LIBBLAS :=
CCFLAGS_GUI :=
CCFLAGS_BLAS :=

ifneq ($(filter debug, $(MAKECMDGOALS)),)
	override CCFLAGS := -g -O0 $(CCFLAGS)
else
	override CCFLAGS := -Ofast $(CCFLAGS)
endif

ifneq ($(filter test_cblas, $(MAKECMDGOALS)),)
	override LIBBLAS := `cat cblas.libs`
	override CCFLAGS_BLAS := -DUSE_CBLAS `cat cblas.cflags`
endif

ifneq ($(filter cblas, $(MAKECMDGOALS)),)
	override LIBBLAS := `cat cblas.libs`
	override CCFLAGS_BLAS := -DUSE_CBLAS `cat cblas.cflags`
endif

ifneq ($(filter atlas, $(MAKECMDGOALS)),)
	override LIBBLAS := `pkg-config atlas --libs`
	override CCFLAGS_BLAS := -DUSE_CBLAS `pkg-config atlas --cflags`
endif

ifneq ($(filter gtkmm, $(MAKECMDGOALS)),)
	override LIBGUI := `pkg-config gtkmm-3.0 --libs`
	override CCFLAGS_GUI := -DUSE_GTKMM `pkg-config gtkmm-3.0 --cflags`
endif


LIB := $(LIBS) $(LIBGUI) $(LIBBLAS) $(LIBSTD)

C := $(CC) $(CCFLAGS) $(CCFLAGS_BLAS) $(CCFLAGS_GUI)

# git
GITIGNORE=.gitignore

# sources and objects folders