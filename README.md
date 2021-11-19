https://jjhahaha.github.io/hw_net/index.html


(1)程式流程  

fork  
>開啟 Socket  
>設定網路連線(TCP/IP 協定、port、對外 IP)  
>開啟監聽器 bind()  
>監聽 listen()  
>等待客戶端連線 accept()  
>若有客戶連線 fork()出子行程  
>子行程讀寫瀏覽器要求  
>關掉父行程  

select  
>開啟 Socket
>設定網路連線(TCP/IP 協定、port、對外 IP)  
>開啟監聽器 bind()  
>監聽 listen()  
>初始化客戶端,設置最大連線可處理人數  
>等待客戶端連線 accept()  
>若有客戶連線 加入到客戶端 array  
>對有連線的客戶端進行讀寫瀏覽器要求  

(2)功能實作  
fork  
使用 pid=fork()建立子行程  
若 pid=0,為子行程,進行讀寫瀏覽器的要求  
非 0 則為父行程,可以關閉  
  
select  
像 stack 一樣使用 client[]存放來連線的客戶  
後一個個為客戶端進行讀寫瀏覽器要求  
讀寫瀏覽器要求  
最基本的要求:GET /index.html HTTP/1.0\r\n\r\n  
若讀到 GET 命令,進行字串處理,並開啟 index.html 網頁  # hw_net
