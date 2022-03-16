# Error-Detection(CRC,Checksum)

[CRC(Cyclic Redundancy Check)](https://ko.wikipedia.org/wiki/%EC%88%9C%ED%99%98_%EC%A4%91%EB%B3%B5_%EA%B2%80%EC%82%AC) 와 
[Checksum](https://ko.wikipedia.org/wiki/%EC%B2%B4%ED%81%AC%EC%84%AC )은 데이터통신에서 전송한 데이터에 오류가 있는지 없는지를 검출하는 기법입니다.

송신측에서 기존 데이터에 redundancy를 붙여 보내고, 수신측에서는 계산후에 전송받은 데이터에 오류가 있는지를 검사합니다. 

>코드 실행 예시

1. CRC(Cyclic Redundancy Check)
![CRC_Test](https://user-images.githubusercontent.com/75191916/158548901-d868b280-903d-41e7-9990-37510ef58ec9.png)


2. Checksum
![CheckSum_Test](https://user-images.githubusercontent.com/75191916/158548907-bc4a342d-648b-43e1-bd09-07b8eda34a0c.png)
