# NP_hw3
## 題目要求
### pcap讀檔

1. 那個封包擷取的時間戳記

2. 來源MAC位址、目的MAC位址、Ethernet type欄位

3. 如果那個封包是IP封包，則再多顯示來源IP位址與目的地IP位址

4. 如果那個封包是TCP或UDP封包，則再多顯示來源port號碼與目的port號碼

## 自抓封包

sudo ./catch

## 從pcap_file中讀取封包

sudo ./get -r catch.pcap

sudo ./get -r test.pcap


## 從可取得的device中讀取pcap num個封包
sudo ./get -n 4

## 從device中讀取封包直到下命令中止
sudo ./get


https://www.itread01.com/content/1546926183.html

https://qbsuranalang.gitbooks.io/network-packet-programming/content/libpcap/capture_pcap_loop.html

http://qbsuranalang.blogspot.com/2016/11/libpcap-save-frames-to-file6.html

http://qbsuranalang.blogspot.com/2016/11/libpcap-capture-using-pcaploop-and.html

sudo apt-get install libpcap-dev


git clone https://github.com/jjhahaha/hw_net.git
