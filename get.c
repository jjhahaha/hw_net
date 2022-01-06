#include <pcap.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <arpa/inet.h>

struct _ {int num;char ip[2000];	};
struct _ count[2000];
int t=0;
void getPacket(u_char * arg, const struct pcap_pkthdr * pkthdr, const u_char * packet)
{
	int * id = (int *)arg,i;
	char tmp[200];
	printf("id: %d\n", ++(*id));
	//printf("Packet length: %d\n", pkthdr->len);
	//printf("Number of bytes: %d\n", pkthdr->caplen);
	/*	printf("packet: \n");
	for(i = 0 ; i < pkthdr->len ; i++)
		printf("%02x ", packet[i]);
	*/
	printf("Recieved time: %s", ctime((const time_t *)&pkthdr->ts.tv_sec)); 
	printf("Dst MAC Address:");
	for(i=0;i<6;i++)printf("%02x ",packet[i]);
	printf("\n");
	printf("Src MAC Address:");
	for(i=6;i<12;i++)printf("%02x ",packet[i]);
	printf("\n");
	//printf("Ethernet type: ");
	//printf("0x%02x%02x\n", packet[12], packet[13]);
	int type1=packet[12],type2=packet[13];
	if(type1==8&&type2==0)//IP
	{
		printf("Type: IP\n");
		
		printf("Src IP Address: ");
		for(i=26;i<29;i++)printf("%d.",packet[i]);
		printf("%d",packet[29]);
		printf("\nDst IP Address: ");
		for(i=30;i<33;i++)printf("%d.",packet[i]);
		printf("%d",packet[33]);
		printf("\n");
		
		//printf("Packet length: %d\n", pkthdr->len);
		//printf("Number of bytes: %d\n", pkthdr->caplen);
		printf("Protocol: ");
		if(packet[23]==6)printf("TCP\n");
		else if(packet[23]==17)printf("UDP\n");
		else printf("Else\n");
		if(packet[23]==6||packet[23]==17){
		printf("Src port: %d\n",packet[34]*256+packet[35]);
		printf("Dst port: %d\n",packet[36]*256+packet[37]);}
		int flag=0;
		for(i=0;i<t;i++)
		{if(strcmp(count[i].ip,tmp)==0){
				flag=1;
				count[i].num++;
				break;
			}}
		if(flag==0){
			count[t].num=1;
			strcpy(count[t].ip,tmp);
			t++;}	
	}
	printf("\n\n\n");
}

int main(int argc ,char *argv[])
{
	int n=-1;
	char errBuf[PCAP_ERRBUF_SIZE], * devStr,filename[100]="";
	memset(count,0,sizeof(count));
	/* get a device */
	devStr = pcap_lookupdev(errBuf);

	if(devStr)
	{printf("success: device: %s\n", devStr);}
	else
	{
		printf("error: %s\n", errBuf);
		exit(1);
	}

	pcap_t *device = pcap_open_live(devStr, 65535, 1, 0, errBuf);
	if(argc==3)
	{
		/* sudo ./get -r <filename>.pcap */
		if(strcmp(argv[1],"-r")==0)
		{strcpy(filename,argv[2]);
			device = pcap_open_offline(filename, errBuf);
			if(!device) {
				fprintf(stderr, "pcap_open_offline(): %s\n", errBuf);
				exit(1);}
			printf("Open: %s\n", filename);
		}
		/* sudo ./get -n packet_num*/
		else if(strcmp(argv[1],"-n")==0)
		{n=atoi(argv[2]);}
	}
	int id = 0,i;
	pcap_loop(device, n, getPacket, (u_char*)&id);pcap_close(device);
	return 0;
}
