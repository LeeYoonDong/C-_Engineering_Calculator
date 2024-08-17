# C++ 공학 계산기 프로젝트

이 프로젝트는 C++로 구현된 공학 계산기입니다.

## 기능

1. 일반 수식 계산
   - 사칙 연산 (+, -, *, /)
   - 삼각 함수 (sin, cos, tan)
   - 역삼각 함수 (asin, acos, atan)
   - 로그 함수 (log)
   - 제곱근 (sqrt)

2. 진수 변환
   - 10진수에서 2진수, 8진수, 16진수로 변환

## 사용 방법

1. 프로그램을 실행합니다.
2. 메인 메뉴에서 원하는 기능을 선택합니다:
   - 1: 수식 계산
   - 2: 진수 변환
   - 3: 종료
3. 선택한 기능에 따라 입력을 제공합니다:
   - 수식 계산: 계산할 수식을 입력합니다.
   - 진수 변환: 변환할 10진수 숫자와 변환하고자 하는 진수(2, 8, 16)를 입력합니다.
4. 결과를 확인합니다.

## 수식 입력 가이드

- 삼각 함수: s(sin), c(cos), t(tan) (예: s45)
- 역삼각 함수: S(asin), C(acos), T(atan) (예: S45)
- 로그: l (예: l2)
- 제곱근: L (예: L4)

## 컴파일 및 실행

```
g++ -o calculator main.cpp
./calculator
```

## 클래스 구조

- `CInterface`: 사용자 인터페이스 관리
- `CCharStack`: 문자 스택 구현
- `CIntStack`: 숫자 스택 구현
- `CCalc`: 계산 로직 구현

## 주의사항

- 수식 입력 시 공백 없이 입력해야 합니다.
- 진수 변환 시 음수는 지원하지 않습니다.
  <br/>
  <br/>
# C++ Engineering Calculator Project

This project is an engineering calculator implemented in C++.

## function

1. Calculate general formulas
- Four arithmetic operations (+, -, *, /)
- trigonometric functions (sin, cos, tan)
- Inverted trigonometric functions (asin, acos, atan)
- Log function (log)
- Square root (sqrt)

2. binary conversion
- Convert decimal to binary, octal, hexadecimal

## How to use it

1. Run the program.
2. Select the desired function from the main menu:
- 1: Calculate equations
- 2: Singular conversion
- 3: The end
3. Provide input based on the selected features:
- Calculate Formula: Enter the formula you want to calculate.
- Essence conversion: Enter the decimal number you want to convert and the binary number (2, 8, 16) you want to convert.
4. Check the results.

## Formula Input Guide

- Triangular functions: s(sin), c(cos), t(tan) (e.g., s45)
- Inverted trigonometric functions: S(asin), C(acos), T(atan) (e.g., S45)
- Log: l (e.g. l2)
- Square root: L (e.g., L4)

## Compile and run

```
g++ -o calculator main.cpp
./calculator
```

## Class structure

- 'C Interface': User interface management
- 'CCharStack': implementing character stack
- 'CIntStack': Implementing a numeric stack
- 'CCALC': Implement calculation logic

## Precautions

- When entering an expression, you must enter it without a space.
- Negative numbers are not supported when converting integers.
