unicode		macro page,string,zero
		irpc c,<string>
		db '&c', page
		endm
		ifnb <zero>
		dw zero
		endif
endm