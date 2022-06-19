CFLAGS=-Wall -g

clean:
	rm -f ./main

exe:
	$(CXX) ./main.c $(CFLAGS) -o ./grep2

run:
	./grep2 lorem.txt dolor

debug:
	gdb --args ./grep2 lorem.txt
	# *press enter
	# $ lay next
	# *press enter
	# *press enter