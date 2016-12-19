.686
.model flat

public _srednia_harm

.code

_srednia_harm PROC
	push ebp
	mov ebp, esp
	push ebx

	mov ebx, [ebp+8]  ; adres tablicy
	mov ecx, [ebp+12] ; liczba elementow tablicy

	finit
	fldz

petla:
	fld1
	fld dword PTR [ebx]
	fdivp
	faddp
	add ebx, 4
	loop petla

	fild dword PTR [ebp+12]
	fdivp

	pop ebx
	pop ebp
	ret
_srednia_harm ENDP
END