TITLE Sum and Average     (project06a.asm)

; Author:  Jason Fisher
; Course / Project ID:  CS271-400 / Project6a                 Date:  5/27/2016
; Description:  This program will use macros and user developed I/O procedures
; to get 10 integers from the user, then display the integers, their sum, and 
; their average.
; mReadString and mWriteString macros are based on macro examples in lecture 26

INCLUDE Irvine32.inc

; (insert constant definitions here)
mReadString	MACRO	inst2, vName
	push	ecx
	push	edx
	mov		edx, inst2
	call	WriteString
	mov		edx, vName
	mov		ecx, 21
	call	ReadString
	pop		edx
	pop		ecx
ENDM

mWriteString MACRO	vName
	push	edx
	mov		edx, vName
	call	WriteString
	pop		edx
ENDM

LSIZE = 10

.data

intro		BYTE	"Sum and Average		by Jason Fisher", 0
desc		BYTE	"This program will ask the user to input 10 "
	BYTE			"unsigned integers.", 0dh, 0ah
	BYTE			"Each integer must fit into a 32-bit register.", 0dh, 0ah
	BYTE			"It will display the integers, their sum, and their average.", 0
inst1		BYTE	"Please enter a number:  ", 0
error		BYTE	"That number is invalid.", 0
arrayOut	BYTE	"The numbers you entered are:", 0
sumOut		BYTE	"The sum of those numbers is:  ", 0
avgOut		BYTE	"The average of those numbers is:  ", 0
list		DWORD	LSIZE	DUP(?)
stringVar	BYTE	20	DUP(?); user input
spacing		BYTE	"   ", 0
dValue		DWORD	?
sum			DWORD	?
avg			DWORD	?

.code
main PROC

; (insert executable instructions here)
; Display title and instructions
	push		OFFSET intro
	push		OFFSET desc
	call		DisplayIntro

; Get and validate user input
	push		OFFSET list
	push		dValue
	push		OFFSET stringVar
	push		OFFSET	inst1
	push		OFFSET	error
	call		GetInput

; Calculate the sum and average
	push		OFFSET list
	push		OFFSET sum
	push		OFFSET avg
	call		Calc



; Display the inputted integers
	push		OFFSET list
	push		OFFSET stringVar
	push		OFFSET spacing
	push		OFFSET arrayOut
	call		Display

; Display the sum and average
	push		OFFSET sumOut
	push		OFFSET avgOut
	push		sum
	push		avg
	call		DisplaySumAvg


	exit	; exit to operating system
main ENDP

; Description: displays program name, author, and initial instructions.
; Receives:  intro and desc
; Returns:  Nothing
; Preconditions:  None
; Registers Changes:  edx

DisplayIntro PROC

; Display program title and program name
	push	ebp
	mov		ebp, esp
	mWriteString	[ebp+12]
	call	CrLf
	call	CrLf

; Display instructions
	mWriteString	[ebp+8]
	call	CrLf
	call	CrLf

	pop		ebp
	ret		8
DisplayIntro ENDP


; Description: Gets and validates user input
;	Gets 10 valid values and stores them in list
; Receives:  inst1, error, stringVar, list, dValue
; Returns:  list
; Preconditions:  None
; Registers Changes:  
GetInput PROC
	push	ebp
	mov		ebp, esp
	mov		ecx, LSIZE
input:
	mReadString	[ebp+12], [ebp+16]
	push	ecx
	mov		ecx, eax
	mov		ebx, 0
	mov		[ebp+20], ebx
	mov		esi, [ebp+16]
	cld
convert:
	lodsb
	sub		al, 48
	cmp		al, 0
	jb		eMessage
	cmp		al, 9
	ja		eMessage
	mov		bl, al; current digit in ebx
	mov		eax, [ebp+20]; value thus far in eax
	mov		edx, 10
	mul		edx; multiply by 10
	jc		eMessage
	add		eax, ebx; add current digit
	jc		eMessage
	mov		[ebp+20], eax; mov to dValue
	loop	convert

	pop		ecx
	mov		eax, LSIZE
	sub		eax, ecx; get array place
	mov		ebx, 4
	mul		ebx; adjust for DWORD

	mov		esi, [ebp+24]; move array address to esi
	add		esi, eax; add offset for array place
	mov		eax, [ebp+20]
	mov		[esi], eax; move value into array
	loop	input	
	jmp		done

eMessage:
	mWriteString	[ebp+8]
	call	CrLf
	pop		ecx
	jmp		input

done:
	pop		ebp
	ret		20

GetInput ENDP


; Description: Calculates the sum and average
; Receives:  list, sum, avg
; Returns:  Nothing
; Preconditions:  List has been created
; Registers Changes:  ecx, esi, eax, ebx

Calc PROC
	
	push	ebp
	mov		ebp, esp
	mov		ecx, LSIZE
	mov		esi, [ebp+16]
	mov		eax, 0
sumLoop:
	add		eax, [esi]
	add		esi, 4
	loop	sumLoop
	mov		ebx, [ebp+12]
	mov		[ebx], eax

;calculate average
	cdq
	mov		ebx, LSIZE
	div		ebx
	mov		ebx, [ebp+8]
	mov		[ebx], eax

	pop		ebp
	ret		12

Calc ENDP


; Description: Convert each list element to a string and display
; Receives:  list, stringVar, arrayOut, spacing
; Returns:  Nothing
; Preconditions:  list has been created, sum and avg are calculated
; Registers Changes:  edx, ecx, esi, eax, ebx, edi

Display PROC

	push	ebp
	mov		ebp, esp
	mWriteString	 [ebp+8]
	call	CrLf
	mov		ecx, LSIZE
	mov		esi, [ebp+20]; address of list
output:
	push	ecx
	mov		edi, [ebp+16]; address of stringVar
clearString:
	cld
	mov		ecx, 20
	mov		al, 0
	rep		stosb

	mov		edi, [ebp+16]; reset edi to @stringVar
	std
	mov		eax, [esi]
	mov		ebx, 0
count:
	push	ebx
	mov		ebx, 10
	cdq		
	div		ebx
	pop		ebx
	inc		ebx
	cmp		eax, 0
	jne		count
	add		edi, ebx
	dec		edi
	mov		eax, [esi]
convert2:	
	mov		ebx, 10
	cdq
	div		ebx
	add		edx, 48
	push	eax
	mov		eax, edx
	stosb
	pop		eax
	cmp		eax, 0
	jne		convert2
	mWriteString [ebp+16]
	mov		edx, [ebp+12]
	call	WriteString
	add		esi, 4
	pop		ecx
	loop	output

	call	CrLf	


	pop		ebp
	ret		16

Display ENDP


; Description: displays the sum and average
; Receives:  sumOut, avgOut, sum, avg
; Returns:  Nothing
; Preconditions:  list has been created, sum and avg are calculated
; Registers Changes: 
DisplaySumAvg PROC 

	push	ebp
	mov		ebp, esp
	mWriteString	[ebp+20]; @sumOut
	mov		eax, [ebp+12]; sum
	call	WriteDec
	call	CrLf

	mWriteString	[ebp+16]; @avgOut
	mov		eax, [ebp+8]; avg
	call	WriteDec
	call	CrLf


	pop		ebp
	ret		16
DisplaySumAvg ENDP

END main
