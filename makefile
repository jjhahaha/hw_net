all:
	gcc getpacket2.c -o getpacket -lpcap
	gcc save.c -o save -lpcap
clean:
	rm getpacket
run:
	sudo ./getpacket
