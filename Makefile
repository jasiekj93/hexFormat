# ------------------------------------------------
# @author Adrian Szczepanski
# @date 06-03-2023
# ------------------------------------------------

targets := hexFormat hexSequence

target_names := $(addsuffix .elf, $(targets))

.PHONY: all

all: $(target_names)

%.elf: %.o Makefile
	$(CXX) $< -o $@

%.o: %.cpp
	$(CXX) -c -std=c++17 -Og -g -gdwarf-2 $< -o $@

clean:
	rm -rf ./*.o
	rm $(target_names)
