all:
	gcc get.c -o get -lpcap
	gcc save.c -o save -lpcap
clean:
	rm get
run:
	sudo ./get
