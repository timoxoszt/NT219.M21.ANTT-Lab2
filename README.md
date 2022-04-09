# Cài đặt library Crypto++ trên Ubuntu

## Bước 1: Mở terminal
```bash
sudo apt update
```

```bash
sudo apt install libcrypto++-dev libcrypto++-doc libcrypto++-utils
```

## Bước 2: Compile [đoạn code c++ này](https://github.com/timoxoszt/NT219.M21.ANTT-Lab2/blob/main/sample_AES_CBC.cpp) với lệnh

```bash
g++ -g3 -ggdb -O0 -Wall -Wextra -Wno-unused -o AES_CBC sample_AES_CBC.cpp -lcryptopp
```

## Bước 4: Thực thi file vừa tạo

```bash
./AES_CBC
```

### Một số lưu ý:
- Trong quá trình compile có thể xuất hiện `Warning` tuy nhiên khi thực thi file không bị ảnh hưởng.
