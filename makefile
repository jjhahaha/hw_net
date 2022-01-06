all:
	gcc get.c -o get -lpcap
	gcc catch.c -o catch -lpcap
clean:
	rm get
run:
	sudo ./get
