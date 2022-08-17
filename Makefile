# ------------------------------------------------
# @author Adrian Szczepanski
# @date 06-03-2023
# ------------------------------------------------

target := hexFormat

$(target).elf: Main.o
	$(CXX) Main.o -o $@

%.o: %.cpp
	$(CXX) -c -std=c++17 -Og -g -gdwarf-2 $< -o $@

clean:
	rm -rf ./*.o
	rm $(target).elf
