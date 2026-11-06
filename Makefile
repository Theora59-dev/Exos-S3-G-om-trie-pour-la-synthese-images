# Makefile du projet Géométrie
#
# Cibles disponibles : all (défaut), run, rerun, test, clean, distclean, help
# Exemples :
#   make            # compile l'exécutable
#   make run        # compile puis lance le programme
#   make run ARGS="data/points.txt"
#   make test       # compile et exécute les tests

# --- Outils et options -------------------------------------------------------

CXX      ?= g++
CXXFLAGS ?= -std=c++17 -Wall -Wextra -Wpedantic -g -I$(IDIR) -U _DEBUG_
LDFLAGS  ?=
LDLIBS   ?= -lm

# --- Arborescence ------------------------------------------------------------

IDIR := include
SDIR := src
TDIR := tests
ODIR := obj
BDIR := bin

TARGET  := $(BDIR)/monaplie
ARGS    ?=

# --- Fichiers ----------------------------------------------------------------

SRCS      := $(wildcard $(SDIR)/*.cpp)
OBJS      := $(patsubst $(SDIR)/%.cpp,$(ODIR)/%.o,$(SRCS))
MAIN_OBJS := $(ODIR)/main.o
LIB_OBJS  := $(filter-out $(MAIN_OBJS),$(OBJS))

TEST_SRCS := $(wildcard $(TDIR)/*.cpp)
TEST_OBJS := $(patsubst $(TDIR)/%.cpp,$(ODIR)/tests/%.o,$(TEST_SRCS))
TEST_BINS := $(patsubst $(TDIR)/%.cpp,$(BDIR)/%,$(TEST_SRCS))

DEPS := $(OBJS:.o=.d) $(TEST_OBJS:.o=.d)

# --- Comportement ------------------------------------------------------------

.DEFAULT_GOAL := all
.DELETE_ON_ERROR:

.PHONY: all run rerun test clean distclean delete help

all: $(TARGET)

# --- Édition des liens -------------------------------------------------------

$(TARGET): $(OBJS) | $(BDIR)
	@echo "  LD      $@"
	@$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

$(BDIR)/%: $(ODIR)/tests/%.o $(LIB_OBJS) | $(BDIR)
	@echo "  LD      $@"
	@$(CXX) $(LDFLAGS) -o $@ $^ $(LDLIBS)

# --- Compilation -------------------------------------------------------------

$(ODIR)/%.o: $(SDIR)/%.cpp | $(ODIR)
	@echo "  CXX     $<"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<

$(ODIR)/tests/%.o: $(TDIR)/%.cpp | $(ODIR)/tests
	@echo "  CXX     $<"
	@$(CXX) $(CXXFLAGS) -MMD -MP -c -o $@ $<

# --- Répertoires -------------------------------------------------------------

$(ODIR) $(BDIR) $(ODIR)/tests:
	@mkdir -p $@

# --- Exécution ---------------------------------------------------------------

run: all
	./$(TARGET) $(ARGS)

rerun: clean run

test: $(TEST_BINS)
	@set -e; for t in $(TEST_BINS); do \
		echo "  TEST    $$t"; \
		./$$t; \
	done
	@echo "  Tests terminés."

# --- Nettoyage ---------------------------------------------------------------

clean:
	@echo "  RM      $(ODIR)"
	@rm -rf $(ODIR)

delete distclean: clean
	@echo "  RM      $(BDIR)"
	@rm -rf $(BDIR)

# --- Aide --------------------------------------------------------------------

help:
	@echo "Cibles disponibles :"
	@echo "  all        Compile $(TARGET) (défaut)"
	@echo "  run        Compile puis exécute le programme (ARGS=...)"
	@echo "  rerun      Recompile depuis zéro puis exécute"
	@echo "  test       Compile et exécute les tests de $(TDIR)/"
	@echo "  clean      Supprime les fichiers objets"
	@echo "  distclean  Supprime les objets et les binaires (alias : delete)"
	@echo "  help       Affiche cette aide"

# --- Dépendances générées automatiquement ------------------------------------

-include $(DEPS)
