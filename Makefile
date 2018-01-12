CXX = g++
CXXFLAGS = -lm -O2 -std=c++11 -pipe -DONLINE_JUDGE

run:
	$(CXX) $(CXXFLAGS) ${file} && ./a.out
rund:
	$(CXX) $(CXXFLAGS) -DDEBUG ${file} && ./a.out
debug:
	~/.dotfile/command/ctest.py ${file} debug
diff:
	~/.dotfile/command/ctest.py ${file} diff
diffall:
	~/.dotfile/command/ctest.py ${file} diff all
case:
	~/.dotfile/command/ctest.py ${file} diff case ${number}
clean:
	rm a.out
move:
	mv *.cpp finish-problem/
mv:
	mv *.cpp finish-problem/
