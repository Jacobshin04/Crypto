# Cryptography Program  

**Published on:** September 22, 2024  

This program encrypts and decrypts messages using three different cryptographic methods: <br>
**Caesar Cipher, Linear Cipher, and RSA Cryptography**. 

![image](https://github.com/user-attachments/assets/70ce196f-a3d2-409b-8903-0559b2f7bdf5)


It was developed in a **Linux Ubuntu** environment using **C++**.  

## 🔹 Features  
- Select from three cipher methods: **Caesar Cipher, Linear Cipher, or RSA**  
- Support for key discovery in **Linear Cipher**
- Built-in brute-force decryption for unknown **Linear Cipher** keys
- Public and private key generation for **RSA encryption** 
- **Improved RSA encryption capacity (1 → 9 letters) using Boost Multiprecision (`cpp_int`)**  
- **Optimized RSA decryption (from hours → seconds) with modular exponentiation improvements**  


---

## 📌 How It Works  

### 1️⃣ **Caesar Cipher**  
A simple shift cipher where each letter is shifted by a fixed number of places.  

#### **Encryption Formula:**  
Encrypted Letter = (Original Letter + 3) mod 26


#### **Example:**  
Input: hello my name is Jacob
Output: khoor pb qqph lv mdfre

![image](https://github.com/user-attachments/assets/69af193e-6c5f-4a59-b2e7-8f646c397bbc)


#### **Decryption:**  
The user can input the encrypted message to retrieve the original text.

![image](https://github.com/user-attachments/assets/8255f137-64a0-4e39-bcf3-6e65f0287767)

---

### 2️⃣ **Linear Cipher**  
A more complex shift cipher that follows the formula:  

#### **Encryption Formula:**  
Encrypted Letter = (a * Original Letter + b) mod 26

Where **a** must be relatively prime to 26.

#### **Example:**  
a = 21, b = 23
Input: nice to meet you
Output: kjnd gf pddg hfb

![image](https://github.com/user-attachments/assets/87fb7d7b-6033-499d-b857-fc061127c793)



#### **Decryption Options:**  
1. **Decrypt with (a, b) keys**: Input known values of **a** and **b** to retrieve the original message.  
2. **Decrypt without (a, b) keys**: The program will try all possible **311 (a, b) combinations** and display potential decryptions.  
3. **Find (a, b) keys**: Given both the original and encrypted message, the program will calculate the encryption keys **a** and **b**.  

#### **Example 1 (Decrypt with a, b key):**  
Encrypted Message: kjnd gf pddg hfb
input keys: a = 21, b = 23
Original Message: nice to meet you

![image](https://github.com/user-attachments/assets/5bcef269-5da8-4842-93f3-f61b35c5a901)

#### **Example 2 (Decrypt without a, b key):**  
Encrypted Message: kjnd gf pddg hfb
results: all 311 combinations

![image](https://github.com/user-attachments/assets/54eb35a5-41e7-4dfc-8895-01c71878fea7)
![image](https://github.com/user-attachments/assets/78b76b53-416b-484f-a6b2-d04019a17187)

#### **Example 3 (Finding a, b key):** 
Original Message: nice to meet you
Encrypted Message: kjnd gf pddg hfb
output keys: a = 21, b = 23

![image](https://github.com/user-attachments/assets/c438d801-0c1d-46b1-8397-45f51cb7dc33)

---

### 3️⃣ **RSA Cryptography**  
An asymmetric encryption method that uses **public and private keys** for secure message encryption.  

#### **Key Generation:**  
- **Public key (n, e)**  
  - `n = p * q` (product of two prime numbers)  
  - `e` is a randomly selected number relatively prime to `Φ(n)`  
- **Private key (d)**  
  - `d` is calculated such that:  
    ```
    (e * d) ≡ 1 (mod Φ(n))
    ```
  
#### **Encryption Formula:**  
Encrypted Message = (Original Message ^ e) mod n
#### **Decryption Formula:**  
Original Message = (Encrypted Message ^ d) mod n
#### **Example (Encrypting & Decrypting with RSA):**  
Input: berkeley
Original int: 2505120511180502
Encryption Result:
Message: 666434558223740174
Public Key e: 19
Public Key n: 1000000610000092769
Private Key d: 631579331368479259
![image](https://github.com/user-attachments/assets/0faf3372-1c3d-4d52-9118-fdf5a1be2d8e)
Decryption Result:
Decrypted int: 2505120511180502
Decrypted Message: berkeley
![image](https://github.com/user-attachments/assets/b4999bba-fc2b-4234-9abc-d5aa2cffab56)
#### **Limitations:**  
- Each English letter requires **two digits** (e.g., `z → 26`).  
- The encryption process is **limited by the size of public key `n`**, making it difficult to encrypt long messages due to **integer overflow** in C++.  
🔹 **(Now Updated!) Future Improvement:** Exploring **large number handling** in C++ and optimizing **modular arithmetic with exponentiation**.  
---
#### **(Update!) Improvements:**  
✅ **Increased encryption capacity (1 → 9 letters) using Boost Multiprecision (`cpp_int`)**  
✅ **Reduced decryption time from hours → seconds by optimizing modular exponentiation**  
---
## 🛠 **Setup & Compilation**  
### **Requirements**  
- **C++ Compiler (g++)**  
- **Linux Ubuntu Environment**  
- **Boost Multiprecision Library**  
### **Compile & Run**  
```sh
make  # Generates 'a.out'
./a.out
🚀 Happy Encrypting & Decrypting!
