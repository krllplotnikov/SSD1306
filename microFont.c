#include "microFont.h"

MicroSymbol_st microSymbols[255] = 
{
	{0, 0, {0x00}}, // 0 - NOP
	{0, 0, {0x00}}, // 1 - SOH
	{0, 6, {0x00}}, // 2 - 
	{0, 6, {0x00}}, // 3 - 
	{0, 0, {0x00}}, // 4 - 
	{0, 0, {0x00}}, // 5 - 
	{0, 0, {0x00}}, // 6 - 
	{0, 0, {0x00}}, // 7 - 
	{0, 0, {0x00}}, // 8 - 
	{0, 0, {0x00}}, // 9 - 
	{0, 0, {0x00}}, // 10 - 
	{0, 0, {0x00}}, // 11 - 
	{0, 0, {0x00}}, // 12 - 
	{0, 0, {0x00}}, // 13 - 
	{0, 0, {0x00}}, // 14 - 
	{0, 0, {0x00}}, // 15 - 
	{0, 0, {0x00}}, // 16 - 
	{0, 0, {0x00}}, // 17 - 
	{0, 0, {0x00}}, // 18 - 
	{0, 0, {0x00}}, // 19 - 
	{0, 0, {0x00}}, // 20 - 
	{0, 0, {0x00}}, // 21 - 
	{0, 0, {0x00}}, // 22 - 
	{0, 0, {0x00}}, // 23 - 
	{0, 0, {0x00}}, // 24 - 
	{0, 0, {0x00}}, // 25 - 
	{0, 0, {0x00}}, // 26 - 
	{0, 0, {0x00}}, // 27 - 
	{0, 0, {0x00}}, // 28 - 
	{0, 0, {0x00}}, // 29 - 
	{0, 0, {0x00}}, // 30 - 
	{0, 0, {0x00}}, // 31 - 
	{4, 8, {0x00, 0x00, 0x00, 0x00}}, // 32 - sp
	{1, 8, {0x5E}}, // 33 - !
	{3, 8, {0x06, 0x00, 0x06}}, // 34 - "
	{5, 8, {0x13, 0x3E, 0x13, 0x3E, 0x13}}, // 35 - #
	{5, 8, {0x48, 0x54, 0xFE, 0x54, 0x24}}, // 36 - $
	{5, 8, {0x22, 0x10, 0x08, 0x04, 0x33}}, // 37 - %
	{5, 8, {0x34, 0x4A, 0x54, 0x02, 0x05}}, // 38 - &
	{1, 8, {0x06}}, // 39 - '
	{2, 8, {0x3C, 0x42}}, // 40 - (
	{2, 8, {0x42, 0x3C}}, // 41 - )
	{3, 8, {0x0A, 0x04, 0x0A}}, // 42 - *
	{3, 8, {0x08, 0x1C, 0x08}}, // 43 - +
	{2, 8, {0x80, 0x60}}, // 44 - ,
	{3, 8, {0x08, 0x08, 0x08}}, // 45 - -
	{1, 8, {0x40}}, // 46 - .
	{4, 8, {0x20, 0x10, 0x08, 0x04}}, // 47 - /
	{4, 8, {0x3C, 0x52, 0x4A, 0x3C}}, // 48 - 0
	{3, 8, {0x44, 0x1E, 0x40}}, // 49 - 1
	{4, 8, {0x44, 0x62, 0x52, 0x4C}}, // 50 - 2
	{4, 8, {0x42, 0x4A, 0x4A, 0x34}}, // 51 - 3
	{4, 8, {0x18, 0x14, 0x12, 0x7E}}, // 52 - 4
	{4, 8, {0x4E, 0x4A, 0x4A, 0x32}}, // 53 - 5
	{4, 8, {0x3C, 0x4A, 0x4A, 0x30}}, // 54 - 6
	{4, 8, {0x02, 0x72, 0x0A, 0x06}}, // 55 - 7
	{4, 8, {0x34, 0x4A, 0x4A, 0x34}}, // 56 - 8
	{4, 8, {0x0C, 0x52, 0x52, 0x3C}}, // 57 - 9
	{1, 8, {0x44}}, // 58 - :
	{2, 8, {0x80, 0x64}}, // 59 - ;
	{3, 8, {0x10, 0x28, 0x44}}, // 60 - <
	{3, 8, {0x48, 0x48, 0x48}}, // 61 - =
	{3, 8, {0x44, 0x28, 0x10}}, // 62 - >
	{4, 8, {0x04, 0xA2, 0x12, 0x0C}}, // 63 - ?
	{5, 8, {0x7C, 0x82, 0xBA, 0xAA, 0x9C}}, // 64 - @
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}}, // 65 - A
	{4, 8, {0x7E, 0x4A, 0x4A, 0x34}}, // 66 - B
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}}, // 67 - C
	{4, 8, {0x7E, 0x42, 0x42, 0x3C}}, // 68 - D
	{4, 8, {0x7E, 0x4A, 0x4A, 0x42}}, // 69 - E
	{4, 8, {0x7E, 0x0A, 0x0A, 0x02}}, // 70 - F
	{4, 8, {0x73, 0x42, 0x52, 0x72}}, // 71 - G
	{4, 8, {0x7E, 0x08, 0x08, 0x7E}}, // 72 - H
	{3, 8, {0x42, 0x7E, 0x42}}, // 73 - I
	{3, 8, {0x62, 0x42, 0x3E}}, // 74 - J
	{4, 8, {0x7E, 0x08, 0x14, 0x62}}, // 75 - K
	{4, 8, {0x7E, 0x40, 0x40, 0x40}}, // 76 - L
	{5, 8, {0x7E, 0x04, 0x08, 0x04, 0x7E}}, // 77 - M
	{4, 8, {0x7E, 0x08, 0x10, 0x7E}}, // 78 - N
	{4, 8, {0x3C, 0x42, 0x42, 0x3C}}, // 79 - O
	{4, 8, {0x7E, 0x12, 0x12, 0x0C}}, // 80 - P
	{4, 8, {0x3C, 0x42, 0x42, 0x7C}}, // 81 - Q
	{4, 8, {0x7E, 0x12, 0x32, 0x4C}}, // 82 - R
	{4, 8, {0x44, 0x4A, 0x4A, 0x32}}, // 83 - S
	{5, 8, {0x02, 0x02, 0x7E, 0x02, 0x02}}, // 84 - T
	{5, 8, {0x3E, 0x40, 0x40, 0x40, 0x3E}}, // 85 - U
	{5, 8, {0x1E, 0x20, 0x40, 0x20, 0x1E}}, // 86 - V
	{5, 8, {0x7E, 0x20, 0x10, 0x20, 0x7E}}, // 87 - W
	{4, 8, {0x76, 0x08, 0x08, 0x76}}, // 88 - X
	{5, 8, {0x06, 0x08, 0x70, 0x08, 0x06}}, // 89 - Y
	{4, 8, {0x62, 0x52, 0x4A, 0x46}}, // 90 - Z
	{2, 8, {0x7E, 0x42}}, // 91 - [
	{4, 8, {0x20, 0x10, 0x08, 0x04}}, // 92 - 
	{2, 8, {0x42, 0x7E}}, // 93 - ]
	{3, 8, {0x04, 0x02, 0x04}}, // 94 - ^
	{4, 8, {0x40, 0x40, 0x40, 0x40}}, // 95 - _
	{2, 8, {0x02, 0x04}}, // 96 - `
	{3, 8, {0x78, 0x14, 0x78}}, // 97 - a
	{3, 8, {0x7C, 0x54, 0x28}}, // 98 - b
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{3, 8, {0x78, 0x14, 0x78}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{0, 0, {0x00}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}}, // 192 - �
	{4, 8, {0x7E, 0x4A, 0x4A, 0x7A}}, // 193 - �
	{4, 8, {0x7E, 0x4A, 0x4A, 0x34}}, // 194 - �
	{4, 8, {0x7E, 0x02, 0x02, 0x02}}, // 195 - �
	{4, 8, {0x7E, 0x42, 0x42, 0x3C}}, // 196 - �
	{4, 8, {0x7E, 0x4A, 0x4A, 0x42}}, // 197 - �
	{5, 8, {0x76, 0x08, 0x7E, 0x08, 0x76}}, // 198 - � 
	{4, 8, {0x42, 0x4A, 0x4A, 0x34}}, // 199 - �
	{4, 8, {0x7E, 0x10, 0x08, 0x7E}}, // 200 - �
	{4, 8, {0x7E, 0x10, 0x08, 0x7E}}, // 201 - �
	{4, 8, {0x7E, 0x08, 0x14, 0x62}}, // 202 - �
	{4, 8, {0x7C, 0x02, 002, 0x7E}}, // 203 - �
	{5, 8, {0x7E, 0x04, 0x08, 0x04, 0x7E}}, // 204 - �
	{4, 8, {0x7E, 0x08, 0x08, 0x7E}}, // 205 - �
	{4, 8, {0x3C, 0x42, 0x42, 0x3C}}, // 206 - �
	{4, 8, {0x7E, 0x02, 0x02, 0x7E}}, // 207 - �
	{4, 8, {0x7E, 0x12, 0x12, 0x0C}}, // 208 - �
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}}, // 209 - �
	{5, 8, {0x02, 0x02, 0x7E, 0x02, 0x02}}, // 210 - �
	{4, 8, {0x06, 0x48, 0x48, 0x3E}}, // 211 - �
	{5, 8, {0x0C, 0x12, 0x7E, 0x12, 0x0C}}, // 212 - �
	{4, 8, {0x76, 0x08, 0x08, 0x76}}, // 213 - �
	{5, 8, {0x7E, 0x04, 0x04, 0x7E, 0x0C}}, // 214 - �
	{4, 8, {0x0E, 0x10, 0x10, 0x7E}}, // 215 - �
	{5, 8, {0x7E, 0x40, 0x7E, 0x40, 0x7E}}, // 216 - �
	{6, 8, {0x7E, 0x40, 0x7E, 0x40, 0x7E, 0x0C}}, // 217 - �
	{4, 8, {0x02, 0x7E, 0x50, 0x70}}, // 218 - �
	{6, 8, {0x7E, 0x48, 0x48, 0x30, 0x00, 0x7E}}, // 219 - �
	{3, 8, {0x7E, 0x50, 0x70}}, // 220 - �
	{4, 8, {0x4A, 0x4A, 0x4A, 0x3C}}, // 221 - �
	{5, 8, {0x7E, 0x08, 0x3C, 0x42, 0x3C}}, // 222 - �
	{4, 8, {0x4C, 0x32, 0x12, 0x7E}}, // 223 - �
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}},
	{4, 8, {0x7C, 0x12, 0x12, 0x7C}}
};