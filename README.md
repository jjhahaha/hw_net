# NP_hw3
## 題目要求
### pcap讀檔與統計程式
請撰寫一個pcap封包檔讀檔程式，具有下列幾項功能。

1. 可在command option使用-r pcap_file，從pcap_file中讀取封包。

2. 對每個讀進來的封包，顯示其時間戳記(timestamp, 以年、月、日、時、分、秒為單PL)、來源的MAC位址與目的MAC位址。

3. 若封包是IP封包，還可以顯示來源IP位址與目的IP位址。

4. 若封包是TCP/UDP封包，還可以顯示TCP/UDP的port號碼(含顯示是TCP還是UDP)

5. 可統計每對(來源IP,目的IP)的封包數量(若不是IP封包則略過不計)，並顯示出來。
## 程式流程
1.設定讀取封包的基礎設定。

  (1).若是在command option有使用-r pcap_file，即設定從pcap_file中讀取封包。
  
  (2).若是在command option使用-n packet_num，從可取得的device中讀取pcap_num個封包。
  
  (3).若是沒有多餘的command option，則是從device中不斷讀取封包直到process被終止。
  
2.利用pcap_loop開始讀取封包。

3.在getPacket中處理讀到的封包以產生符合題目要求的輸出並統計每對(來源IP,目的IP)的封包數。

4.等pcap_loop讀完pcap_file中的封包，或是pcap_num個封包後，輸出每對(來源IP,目的IP)的封包數量。

### 參考資料
https://www.itread01.com/content/1546926183.html

https://dotblogs.com.tw/leo_codespace/2019/03/29/203853

### 希望加分
多做了sudo ./getPacket_num -n packet_num可以從裝置中讀取特定數量packet的功能，希望能加一點點的分。
