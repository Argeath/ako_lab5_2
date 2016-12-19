.686
.model flat

public _nowy_exp

.data
k dd 2

.code

_nowy_exp PROC
	push ebp
	mov ebp, esp
	push ebx

	fld dword PTR [ebp+8]  ; x
	fld dword PTR [ebp+8]  ; x
	fld1
	fadd ST(2), ST(0)

	mov ecx, 18
	mov ebx, OFFSET k
petla:
	fild k

	; 0 - k
	; 1 - silnia
	; 2 - x^k-1
	; 3 - suma
	fmulp ST(1), ST(0) ; (k-1)! * k

	fld dword PTR [ebp+8]
	fmulp ST(2), ST(0) ; x^k-1 * x

	; 0 - silnia
	; 1 - x^k
	; 2 - suma

	fld ST(1) ; x^k

	; 0 - x^k
	; 1 - silnia
	; 2 - x^k
	; 3 - suma

	fdiv ST(0), ST(1) ; x^k / silnia

	; 0 - wynik
	; 1 - silnia
	; 2 - x^k
	; 3 - suma

	faddp ST(3), ST(0)

	; 0 - silnia
	; 1 - x^k
	; 2 - suma

	
	inc k
	loop petla


	fstp ST(0)
	fstp ST(0)

	pop ebx
	pop ebp
	ret
_nowy_exp ENDP
END